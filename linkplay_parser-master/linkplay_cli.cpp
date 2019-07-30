#include "linkplay_cli.h"
#include <stdarg.h>
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

void Linkplay_Debug_Printf(char* message, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
  //  if (false == linkplay_bypass_status())
  //      return;
    
    va_start(args, message);
    
    writebuf_len = vsprintf(writebuf, message, args);
    Debug_Print(writebuf);
    Serial.println("got to lp debug printf");
}
 //   va_list args;
 //   char    writebuf[100];
 //   int     writebuf_len = 0;
 //   
 //   va_start(args, fmt);
 //   
 //   writebuf_len = vsprintf(writebuf, fmt, args);
 //   Debug_Print(writebuf);