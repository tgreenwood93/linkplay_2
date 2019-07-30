#include "Arduino.h"
//******************************************************************************
//  PS Audio Application Source File
//
//  File Name:
//    app_cli.h
//
//  Summary:
//      This file contains header file info for a CLI interface.
//      The layout of the file is based on the MPLab Harmony app template.
//
//******************************************************************************
#ifndef cli_h
#define cli_h

// *****************************************************************************
// Section: Included Files
// *****************************************************************************

/*#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
*/

//  Typedef declaration of CLI handler function prototype
//      arg_buf - Null separated list of arguments
typedef void (*cli_handler_ptr)(char *arg_buf);

//  CLI support data structure for storing command handler, command name and description
typedef struct {
    char              *func_name;                 // command name. ex. "help"
    cli_handler_ptr   cli_handler;                // command handler
    char              *func_description;          // command description
} CLI_Func_t;

// *****************************************************************************
// Section: Function prototypes
// *****************************************************************************
void CLI_Init(void);
int CLI_Tasks(void);

int cli_arg_parsecmd(char* sCmd, char* sCmdList[]);
void engage_linkplay_bypass();


#endif /* _APPLI_H */
