#include "Arduino.h"


#ifndef linkplay_cli_h
#define linkplay_cli_h

void Linkplay_Debug_Printf(char* message, ...);
void Linkplay_Printf(char* message, ...);
void Linkplay_Print(char* message);

void Set_linkplay_bypass_status(bool status);
bool Get_linkplay_bypass_status();

#endif
