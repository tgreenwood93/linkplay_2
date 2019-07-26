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
#ifndef debug_h
#define debug_h

////////////////////////////////////////////////////////////////////////////////
// Section: Included Files
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Section: Misc test routines
////////////////////////////////////////////////////////////////////////////////

// *****************************************************************************
// Misc defines, typdefs, structs, etc...
// *****************************************************************************

// *****************************************************************************
// Function prototypes
// *****************************************************************************
void Debug_Init(void);
void Debug_Printf(char* fmt, ...);
int  Debug_Read(char *buf, int max_bytes);
void Debug_Print(char *buf);

void _DEBUG_RecieveReadBuffer();
void _DEBUG_TransmitWriteBuffer();

#endif //_DEBUG_H
