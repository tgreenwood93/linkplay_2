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
#include "Arduino.h"
#include <stdio.h>
#include "cli.h"
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "debug.h"


// Local (static) function prototypes for individual cli functions
static void cli_cmd_eraseEEPROM(char *arg_buf);
static void cli_cmd_help(char *arg_buf);
static void cli_cmd_i2c(char *arg_buf);
static void cli_cmd_ir(char *arg_buf);
static void cli_cmd_linkplay(char *arg_buf);
static void cli_cmd_muteVol(char *arg_buf);
static void cli_cmd_printEEPROM(char *arg_buf);
static void cli_cmd_printVol(char *arg_buf);
static void cli_cmd_qtest(char *arg_buf);
static void cli_cmd_setVol(char *arg_buf);
static void cli_cmd_test(char *arg_buf);



// **************************************************************************************
// **************************************************************************************
// ******                                                                          ****** 
// ******                        Local CLI routines                                ******
// ******                                                                          ******
// **************************************************************************************
// **************************************************************************************


// TODO: Idea - Modify this to be a function that registers a callback routine instead of a fixed array
// Add new commands to this array. Format is <command-name>, <function pointer>, <help message>
//   - For consistency, use the format cli_cmd_xxx for the function name and group them in the same section below.
//   - See comments in cli_cmd_help() for important information on accessing arguments passed into the function.
CLI_Func_t cli_functions[] = {  { "help",   cli_cmd_help,   "print help message" },
                                { "i2c",    cli_cmd_i2c,    "execute i2c cmd" },
                                { "ir",     cli_cmd_ir,     "toggles debug output for IR" },
                                { "test",   cli_cmd_test,   "run various tests" },
                                { "setVol", cli_cmd_setVol, "allow for setting the volume from cli"},
                                { "printVol", cli_cmd_printVol, "allow for printing the current volume onto the cli"},
                                { "muteVol", cli_cmd_muteVol, "mute the current output"},
                                { "printEEPROM", cli_cmd_printEEPROM, "allow for printing contents of the EEPROM"},
                                { "eraseEEPROM", cli_cmd_eraseEEPROM, "Erase the contents of the EEPROM"},
                                { "linkplay", cli_cmd_linkplay, "retrieve linkplay information"},
                                { NULL,     NULL,       NULL }};


// **************************************************************************************
//  cli_cmd_help
//      Prints help message with a list of all supported CLI functions
//      currently stored in the cli_functions array
//
//  Instructions/ caveats for new commands
//
//    Command limitations
//    -------------------
//    Command names must be less than CLI_CMD_MAXLEN, which is defined in app_cli.c (not the .h file). A full 
//    line must be less than CLI_READBUF_MAX chars and if it's over 120 chars the entire line will be discarded.  
//    Special characters will likely not be handled well, but I haven't tested it. Otherwise, you are free to 
//    make the command anything you want (including special characters) and the arguments following the command 
//    can be anything you want. See below for more info on parsing the argument list.
//
//        
//    Function prototype for all CLI commands
//    ---------------------------------------
//    The function must be declared in the following form:
//
//        static void cli_cmd_xxx(char *arg_buf)
//
//        
//    Naming commands
//    ---------------
//    When creating a new command, name the function cli_cmd_xxx, where xxx is the name of your command. 
//    For example, cli_cmd_help() or cli_cmd_i2c()
//
//        
//    Handling arguments to commands
//    ------------------------------
//    Every command is passed in a NUL termianted string that is the argument list.
//
//    arg_buf is a string that is the entire command line after the command itself. So if the user types in 
//    "foo arg1 arg2", then arg_buf will contain the text "arg1 arg2". The function is responsible for taking 
//    that arg_buf list and parsing it in a way that is useful for the function. arg_buf is on the stack within 
//    the context of cli_intepreter(),so the called function *must* parse it before it returns and store the 
//    parsed info somewhere besides arg_buf. You can parse into tokens using strtok() or do whatever else you 
//    like. The function is responsible for forwarding the argument list or specific settings to any module that 
//    needs it.
//
//    For example: If I have an I2C command such as "i2c read_temp 1", then my cli_cmd_i2c() function needs to 
//    parse out the "read_temp" and the "1". One approach would be to use the read_temp argument to call an i2c 
//    function to read the sensor for i2c bus identifier 1:
//
//        ex: i2c_read_tempsensor(1)
//    
//    Another option is to call a function to set test arguments such as i2c_test_setargs(i2c_cmd, bus_id) and 
//    then queue a command to do the actual testing.
//
//    The first method could be used if the actual work to do the test command is *very* short as it's 
//    happening in the context of cli_interpreter(). Most commands will want or need to be added to the 
//    queue, so you'll need a function to pass arguments to the module, then queue the command.
// **************************************************************************************
static void cli_cmd_help(char *arg_buf)
{
    CLI_Func_t *ptr = NULL;
    
    Debug_Printf("Command Help\n\n");

    // Traverse through all available functions and print "command + description"
    for (ptr = cli_functions; ptr->func_name != NULL; ptr++)
        Debug_Printf("  %s - %s\n", ptr->func_name, ptr->func_description);
    
    Debug_Printf("\n");
}


// **************************************************************************************
//  cli_cmd_i2c
// **************************************************************************************
enum
{
    CMD_I2C_MAINTEMP    = 0,
    CMD_I2C_ESS,
    CMD_I2C_HELP
} e_cmd_i2c_list;
static void cli_cmd_i2c(char *arg_buf)
{
    char*   sCmdList[] = {"maintemp", "ess", "help", NULL};
    char    sCmd[10];
    int     arg_cnt;
    int     nReg;
    int     nCmd;
    
    // Parse arg_buf into sCmd and nReg
    arg_cnt = sscanf(arg_buf, "%s %x", sCmd, &nReg);
    
    // If no args display i2c help
    if (arg_cnt <= 0)
        nCmd = CMD_I2C_HELP;
    
    // Get sCmd command index
    else
        nCmd = cli_arg_parsecmd(sCmd, sCmdList);
            
    // Act on nCmd
    switch (nCmd)
    {
        case CMD_I2C_MAINTEMP:
            //Debug_Printf("Main Temp Sensor = %d C\n", I2C_GetMainTemp());
            break;

        case CMD_I2C_ESS:
            // arg_cnt of 1 defaults to register 0x00
            //if (arg_cnt == 1)
                //Debug_Printf("ESS reg 0x00 = 0x%x\n", I2C_ReadByte(I2C_ESS_ADDRESS, 0x00));
            //else 
                //Debug_Printf("ESS reg 0x%x = 0x%x\n", nReg, I2C_ReadByte(I2C_ESS_ADDRESS, nReg));
            break;

        case CMD_I2C_HELP:
            Debug_Printf("Do an i2c read\n");
            Debug_Printf("i2c [target [reg]]\n");
            Debug_Printf("    target - maintemp or ess\n");
            Debug_Printf("    reg    - register to read from (in decimal or hex)\n");
            Debug_Printf("             if omitted, reads register 0x00\n\n");
        
        default:
            Debug_Printf("Invalid i2c command - %s\n\n", sCmd);
            break;
    };
}


// **************************************************************************************
//  cli_cmd_ir
// **************************************************************************************
static void cli_cmd_ir(char *arg_buf)
{
    static bool current_state = false;
    if (current_state)
        current_state = false;
    else
        current_state = true;

    Debug_Printf("IR debug is %s\n", current_state?"on":"off");
    //IR_CliDebug(current_state);
}

// **************************************************************************************
//  cli_cmd_test
// **************************************************************************************
static void cli_cmd_test(char *arg_buf)
{
    int test_case;
    
    if (arg_buf == NULL)
    {
        Debug_Printf("No test case specified\n");
        return;
    }
    
    // Get the test case number then call the test function. Range checking on test_case is done by 
    // Test_Run_TestID, but we at least verify the passed argument is a number. 
   /* if (isdigit(arg_buf[0]))
    {
        test_case = atoi(arg_buf);
        if (Test_Run_TestID(test_case) == true)
            Debug_Printf("Test %d - PASSED\n", test_case);
        else
            Debug_Printf("Test %d - FAILED\n", test_case);
    }
    else*/
        Debug_Printf("Invalid test arg\n");
        
}

// **************************************************************************************
//  cli_cmd_setVol
// **************************************************************************************
static void cli_cmd_setVol(char *arg_buf)
{
    if (arg_buf == NULL)
    {
        Debug_Printf("No volume setting specified\n");
        return;
    }

    int vol = 0;
    if (isdigit(arg_buf[0]))
    {
        vol = atoi(arg_buf);
        // pin vol to be o to 100
        vol =  (vol < 0) ? 0 : (vol > 100) ? 100 : vol;

        //(void)VOLMGR_SetVolume(vol);
        Debug_Printf("Volume set to %d\n", vol);
    }
    else
    {
        Debug_Printf("Volume setting of %s is invalid\n", arg_buf[0]);
    }
}

// **************************************************************************************
//  cli_cmd_printVol
// **************************************************************************************
static void cli_cmd_printVol(char *arg_buf)
{
    Output_Type_t oType = CS_GetOutputType();
    if (oType == e_OUTPUT_TYPE_Headphones) 
    {
        Debug_Printf("Current output is Headphones\n");
        Debug_Printf("The current volume is %d\n", (int)CS_GetHeadphoneVolume());
    }
    else if (oType == e_OUTPUT_TYPE_Main)
    {
        Debug_Printf("Current output is main\n");
        Debug_Printf("The current volume is %d\n", (int)CS_GetVolume());
    }
}

// **************************************************************************************
//  cli_cmd_muteVol
// **************************************************************************************
static void cli_cmd_muteVol(char *arg_buf)
{
/*
    int doMute = atoi(arg_buf);
    bool fMute = (doMute != 0);

    Output_Type_t oType = CS_GetOutputType();
    if (oType == e_OUTPUT_TYPE_Headphones)
    {
        if (fMute)
        {
            if (0 == CS_GetHeadphoneVolume())
            {
                Debug_Printf("Headphones are already muted.\n");
            }
            Debug_Printf("Muting Headphones\n");
        }
        else
        {
             if (0 == CS_GetHeadphoneVolume())
             {
                Debug_Printf("Unmuting Headphones\n");
             }
             Debug_Printf("Headphones were not muted\n");        
        }
    }
    else if (oType == e_OUTPUT_TYPE_Main)
    {
        if (fMute)
        {
            if (CS_GetOutputIsMuted())
            {
                Debug_Printf("Main output is already muted.\n");
            }
            else
            {
                Debug_Printf("Muting main output\n");
            }
            
        }
        else
        {
            if (CS_GetOutputIsMuted())
            {
                Debug_Printf("Unmutting main output\n");
            }
            else
            {
                Debug_Printf("Main output was not muted\n");
            }
        }
    }
    
    //VOLMGR_Mute(fMute);*/
}

// **************************************************************************************
//  cli_cmd_printEEPROM
// **************************************************************************************
static void cli_cmd_printEEPROM(char *arg_buf)
{
    //PrintEEPROM();
}

// **************************************************************************************
//  cli_cmd_eraseEEPROM
// **************************************************************************************
static void cli_cmd_eraseEEPROM(char *arg_buf)
{
    //EraseEEPROM();
}

// **************************************************************************************
//  cli_cmd_linkplay
// **************************************************************************************
enum
{
    CMD_LINKPLAY_IP    = 0,
    CMD_LINKPLAY_NET_STAT,
    CMD_LINKPLAY_MAC,
    CMD_LINKPLAY_VERS,
    CMD_LINKPLAY_PIC_VERS,
    CMD_LINKPLAY_GET_AP_SSID,
    CMD_LINKPLAY_SYS_INF,
    CMD_LINKPLAY_SET_NAME,
    CMD_LINKPLAY_SET_SSID,
    CMD_LINKPLAY_GET_APS,
    CMD_LINKPLAY_PASS_THROUGH,
    CMD_LINKPLAY_HELP
} e_cmd_linkplay_list;
static void cli_cmd_linkplay (char *arg_buf)
{
    char*   sCmdList[] = {  "ip", "netstat", "mac",
                            "version", "picver", "getap", "sysinf",
                            "setname", "setssid", "getaps",
                            "passthru", "help", NULL};
    char    sCmd[10];
    int     arg_cnt;
    int     nReg;
    int     nCmd;
    
    // Parse arg_buf into sCmd and nReg
    arg_cnt = sscanf(arg_buf, "%s %x", sCmd, &nReg);
    
    // If no args display i2c help
    if (arg_cnt <= 0)
        nCmd = CMD_LINKPLAY_HELP;
    
    // Get sCmd command index
    else
        nCmd = cli_arg_parsecmd(sCmd, sCmdList);
            
    // Act on nCmd
    switch (nCmd)
    {
        case CMD_LINKPLAY_IP:
            get_IP();
            break;
        case CMD_LINKPLAY_NET_STAT:
            get_network_status();
            break;
        case CMD_LINKPLAY_MAC:
            get_mac_address();
            break;
        case CMD_LINKPLAY_VERS:
            get_lp_version();
            //Debug_Printf("Main Temp Sensor = %d C\n", I2C_GetMainTemp());
            break;
        case CMD_LINKPLAY_PIC_VERS:
            get_lp_pic_version();
            break;
        case CMD_LINKPLAY_GET_AP_SSID:
            get_ap_ssid();
            break;
        case CMD_LINKPLAY_SYS_INF:
            dump_stored_linkplay_data();
            break;
        case CMD_LINKPLAY_SET_NAME:
            
            break;
        case CMD_LINKPLAY_SET_SSID:
            
            break;
        case CMD_LINKPLAY_GET_APS:
            
            break;
        case CMD_LINKPLAY_PASS_THROUGH:
            Debug_Printf("Linkplay bypass engaged\n");
            engage_linkplay_bypass();   
            break;
        case CMD_LINKPLAY_HELP:
            Debug_Printf("linkplay commands\n");
            Debug_Printf("    ip        - get the ip address of the wifi and ethernet\n");
            Debug_Printf("    netstat   - get the network status of linkplay\n");
            Debug_Printf("    mac       - get the mac address of the linkplay\n");
            Debug_Printf("    version   - get the fimrware version of the linkplay\n");
            Debug_Printf("    picver    - get the linkply's stored value of pic version\n");
            Debug_Printf("    getap     - get the name of the connected ap\n");
            Debug_Printf("    sysinf    - get system info\n");
            Debug_Printf("    setname   - set the name of the device ex: linkplay setname stellar\n");
            Debug_Printf("    setssid   - set the ssid of the internal ap ex: linkplay setssid integrated\n");
            Debug_Printf("    gettaps   - get list of aps linkplay can see\n");
            Debug_Printf("    passthru  - send commands directly to linkplay \n");
            Debug_Printf("    help      - list of linkplay commands\n");

            break;
        default:
            Debug_Printf("Invalid linkplay command - %s\n\n", sCmd);
            break;
    };
}
