// **************************************************************************************
//  PS Audio Application Source File
//
//  File Name:
//    test.c
//
//  Summary:
//      This file contains test routines for PSAudio created application code.
//
// **************************************************************************************

// **************************************************************************************
// Section: Included Files
// **************************************************************************************
#include <string.h>
#include <stdarg.h>
#include "debug.h"
#include "queue.h"
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "linkplay_cli.h"


////////////////////////////////////////////////////////////////////////////////
//  Test variables, defines, etc...
////////////////////////////////////////////////////////////////////////////////
// static DRV_HANDLE Debug_UART3_Handle = NULL;

////////////////////////////////////////////////////////////////////////////////
//  Debug output functions. Can use either the UART or the USB CDC.
////////////////////////////////////////////////////////////////////////////////

/* Set up a circular buffer */
#define DEBUG_BUFFER_SIZE   512
static QUEUE qDbgTxBuffer;
static QUEUE qDbgRxBuffer;


void Debug_Init()
{
    //if (Debug_UART3_Handle == NULL)
    //{
        // Init the transmit and receive queues
        qInit(&qDbgTxBuffer, DEBUG_BUFFER_SIZE, char);
        qInit(&qDbgRxBuffer, DEBUG_BUFFER_SIZE, char);
        
        // Open UART3
       // Debug_UART3_Handle = DRV_USART_Open(DRV_USART_INDEX_1, DRV_IO_INTENT_READWRITE);
   // }
}


void Debug_Print(char *buf)
{
    uint16_t i = 0;
    
    if (strlen(buf) > 100)
        return;
    
    // Push to transmit queue. If the buffer wraps, old data will be discarded.
    for (i=0; i<strlen(buf); i++)
        qPush(&qDbgTxBuffer, &buf[i]);
        
    // Kick off the transmit interrupt
    _DEBUG_TransmitWriteBuffer();
}


void Debug_Printf(char* fmt, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
    va_start(args, fmt);
    
    writebuf_len = vsprintf(writebuf, fmt, args);
    Debug_Print(writebuf);
}

int Debug_Read(char *buf, int max_bytes)
{
    char ch;
    int  nBytes = 0;

    // Read data until we have read max_bytes. qPop() returns false if the buffer is empty.
    while ((nBytes < max_bytes) && qPop(&qDbgRxBuffer, &ch))
        buf[nBytes++] = ch;

    return nBytes;
}


// ******************************************************************************
// void _DEBUG_RecieveReadBuffer()
//
// Called from UART3 receive interrupt handler to read bytes into a local buffer.
// ******************************************************************************
void _DEBUG_RecieveReadBuffer()
{
    char ch;

    // If there is data in the UART rx buffer, copy them to our local RX queue.
    while (Serial.available())
    {       
        ch = Serial.read();
        qPush(&qDbgRxBuffer, &ch);
    }
}


// ******************************************************************************
// void _DEBUG_TransmitWriteBuffer()
//
// Called from UART3 transmit interrupt handler to write bytes from the buffer.
// ******************************************************************************
void _DEBUG_TransmitWriteBuffer()
{
    char ch;
    
    // Send out data until the UART Tx buffer is full. qPop() returns false if the queue is empty.
    while (qPop(&qDbgTxBuffer, &ch))
        Serial.print(ch);
}
