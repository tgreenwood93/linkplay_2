// **************************************************************************************
//  PS Audio Application Source File
//
//  File Name:
//    app_cli.c
//
//  Summary:
//      This file contains header file info for a CLI interface.
//      The layout of the file is based on the MPLab Harmony app template.
//
// **************************************************************************************

// **************************************************************************************
// Section: Included Files
// **************************************************************************************

// Local (static) function prototypes
#include "Arduino.h"
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

static void cli_interpreter(void);
static void cli_parseline(char *cmd, char *arg_list);
static void cli_read();

// Defines
#define CLI_READBUF_MAX         120 
#define CLI_CMD_MAXLEN          15
#define CLI_ARGLIST_MAXLEN      120
#define CLI_MAX_READLINE        100
#define CLI_IO_UART             1
#define CLI_IO_USBCDC           2


// Local (static) global vars
static char     cli_readbuf[CLI_READBUF_MAX];
static uint8_t  cli_readbuf_len = 0;
static uint8_t  cli_IO_source;

// Externs
extern CLI_Func_t cli_functions[];

// ******************************************************************************
// CLI_Tasks
// ******************************************************************************
void CLI_Init()
{
    static bool bInit = false;
    
    if (bInit == false)
    {
        bInit = true;
        memset(cli_readbuf, ASCII_NUL, CLI_READBUF_MAX);
        cli_IO_source = CLI_IO_UART;
    }
}   


// ******************************************************************************
// CLI_Tasks
// ******************************************************************************
int CLI_Tasks()
{
    // The main task of APP_CLI_Tasks() is to read input. The cli_read() function
    // will send commands to the parser and interpreter. 
    cli_read();
    
    // TODO: Currently using UART3 for output as the USB CDC doesn't work. Would eventually
    //       like the option of using both. Note that writes using Test_Debug_Printf() and
    //       Test_Debug_Write() are automatically flushed by the UART3 transmit interrupt
    //       routine, there's nothing else to do here. 
//    if (cli_IO_source == CLI_IO_UART)
//        Test_Debug_Write(cli_writebuf);
//    else if (cli_IO_source == CLI_IO_USBCDC)
//        APP_CDC_Write(cli_writebuf, cli_writebuf_len);
}

// **************************************************************************************
// **************************************************************************************
//  Private functions to this module
// **************************************************************************************
// **************************************************************************************

// **************************************************************************************
//  cli_interpreter
//
//  CLI interpreter that reads an input string, parses out the command and args, and 
//  then executes the command. 
// **************************************************************************************
static void cli_interpreter(void)
{
    int cmdlen = 0;
    
    char cmd[CLI_CMD_MAXLEN];
    char arg_list[CLI_ARGLIST_MAXLEN];

    // Parse line string - this fills in cmd and arg_list
    cli_parseline(cmd, arg_list);
  
    // If the cmd is blank or just a CR, then ignore it
    cmdlen = strlen(cmd);
    if ((cmdlen > 0) &&
        !((cmdlen == 1) && (cmd[0] == ASCII_CR)))
    {
        CLI_Func_t *ptr = cli_functions;
        
        // Traverse through the supported commands table and compare the supported function name with one from line
        while (ptr->cli_handler != NULL) 
        {
            // Verify cmd and func_name are same length before comparing them
            if ((strlen(cmd) == strlen(ptr->func_name)) &&
                (strcmp(cmd, ptr->func_name) == 0))
            {
                ptr->cli_handler(arg_list);
                break;
            }
            ptr++;
        }

        // Invalid command
        if (ptr->cli_handler == NULL) 
            Debug_Printf("Unrecognized command\n");
    }

    Debug_Printf("> ");
    return;
}


// **************************************************************************************
//  cli_arg_parsecmd
//
//  Returns index into sCmdList that matches sCmd. Returned index is 0's based. If
//  the returned value is negative, there was no match or the input is invalid.
// **************************************************************************************
int cli_arg_parsecmd(char* sCmd, char* sCmdList[])
{
    char* pCmdList = sCmdList[0];
    int i = 0;                          

    // Range checking
    if ( (sCmd == NULL)      ||
         (sCmdList == NULL)  ||
         (strlen(sCmd) > 50) )          // Somewhat arbritrary check to make sure sCmd is NUL terminated
        return -1;                      // Negative value is an invalid cmd/ no match
    
    while (pCmdList != NULL)
    {
        if (strcmp(sCmd, pCmdList) == 0)
            return i;                   // Return index of matched command
        i++;
        pCmdList = sCmdList[i];
    }
}


// **************************************************************************************
//  cli_parseline
//
//      cmd  - returns the parsed command as nul terminated text
//      arg_list - returns a buffer of the rest of the line (the argument list)
// **************************************************************************************
static void cli_parseline(char *cmd, char *arg_list)
{
    int line_idx = 0;
    int len = 0;
    int i;
    int j;

    // Init outputs to an empty string
    *cmd = ASCII_NUL;
    *arg_list = ASCII_NUL;

    // Return immediately on an empty string
    if (*cli_readbuf == ASCII_NUL)
        return;
    
    // Skip leading whitespace characters
    while (isspace(cli_readbuf[line_idx]))  
        line_idx++;

    // Parse out command token
    // TODO: Range checking on cmd_len??
    while (cli_readbuf[line_idx] != ASCII_NUL) 
    {
        if (isspace(cli_readbuf[line_idx]) || (len > CLI_CMD_MAXLEN) || (line_idx > CLI_READBUF_MAX))
            break;
        else
            cmd[len++] = cli_readbuf[line_idx++];           // Copy command to the cmd variable
    }
    cmd[len] = ASCII_NUL;                                   // NUL terminate cmd
        
    // Skip whitespace characters after command
    while ((cli_readbuf[line_idx] != ASCII_NUL) && (isspace(cli_readbuf[line_idx])) && (line_idx < CLI_READBUF_MAX))  
        line_idx++;

    // Everything else are the arguments
    len = strlen(cli_readbuf);
    if (len >= CLI_ARGLIST_MAXLEN)
        len = CLI_ARGLIST_MAXLEN - 1;
        
    // Copy from cli_readbuf with an offset of line_idx (where the args start) into arg_list
    //strncpy(arg_list, cli_readbuf, CLI_ARGLIST_MAXLEN-2);
    for (i=0, j=line_idx; j<len; i++, j++)
        arg_list[i] = cli_readbuf[j];

    arg_list[i] = ASCII_NUL;
}


// **************************************************************************************
//  cli_read
// **************************************************************************************
static void cli_read()
{
    char buf[CLI_MAX_READLINE];
    int     nbytes = 0;
    int     i;

    // Read into buf. If no chars available, then exit
    memset(buf, ASCII_NUL, CLI_MAX_READLINE);
    if (cli_IO_source == CLI_IO_UART)
        nbytes = Debug_Read(buf, CLI_MAX_READLINE);
    else if (cli_IO_source == CLI_IO_USBCDC)
        //nbytes = APP_CDC_Read(buf, CLI_MAX_READLINE);
    
    if (nbytes <= 0)
        return;
    
    // Copy characters to cli_readbuf[]]
    for (i=0; i<nbytes; i++)
    {
        cli_readbuf[cli_readbuf_len] = buf[i];
        
        // Carriage return indicates end of line
        if (buf[i] == ASCII_CR)
        {
            // Convert the CR into a NUL and execute the interpreter
            cli_readbuf[cli_readbuf_len] = ASCII_NUL;
            cli_interpreter();
            memset(cli_readbuf, ASCII_NUL, CLI_READBUF_MAX);
            cli_readbuf_len = 0;
        }
        else if (buf[i] == ASCII_BS)
        {
            cli_readbuf[cli_readbuf_len] = ASCII_NUL;
            if (cli_readbuf_len > 0)
                cli_readbuf_len--;          // Erase a character on a backspace
        }
        else 
        {
            cli_readbuf_len++;

            // If we've read more than CLI_READBUF_MAX chars, then the line is too long and we discard it
            if (cli_readbuf_len > CLI_READBUF_MAX)
            {
                memset(cli_readbuf, ASCII_NUL, CLI_READBUF_MAX);
                cli_readbuf_len = 0;
                break;
            }
        }
    }
}
