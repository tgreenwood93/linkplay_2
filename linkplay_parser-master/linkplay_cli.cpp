#include "linkplay_cli.h"
#include <stdarg.h>
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

static bool linkplay_bypass_status = false;

void Linkplay_Debug_Printf(char* message, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
    if (false == Get_linkplay_bypass_status())
        return;
    
    va_start(args, message);
    
    writebuf_len = vsprintf(writebuf, message, args);
    Debug_Print(writebuf);
}

void Linkplay_Printf(char* message, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
    if (false == Get_linkplay_bypass_status())
        return;
    
    va_start(args, message);
    
    writebuf_len = vsprintf(writebuf, message, args);
    Linkplay_Print(writebuf);
}


void Linkplay_Print(char* message)
{
    Serial1.print(message);
   /* uint16_t i = 0;
    
    if (strlen(buf) > 100)
        return;
    
    // Push to transmit queue. If the buffer wraps, old data will be discarded.
    for (i=0; i<strlen(buf); i++)
        qPush(&qDbgTxBuffer, &buf[i]);
        
    // Kick off the transmit interrupt
    _Linkplay_TransmitWriteBuffer();*/
}

void Set_linkplay_bypass_status(bool status)
{
    linkplay_bypass_status = status;
}

bool Get_linkplay_bypass_status()
{
    return linkplay_bypass_status;
}
