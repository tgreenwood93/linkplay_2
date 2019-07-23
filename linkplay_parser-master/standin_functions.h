#include "Arduino.h"

#ifndef standin_functions_h
#define standin_functions_h
typedef enum 
{
    e_OUTPUT_TYPE_Headphones = 0,
    e_OUTPUT_TYPE_Main = 1,
    e_OUTPUT_TYPE_Unknown = 2
}Output_Type_t;

Output_Type_t CS_GetOutputType();
uint8_t CS_GetHeadphoneVolume();
void CS_SetHeadphoneVolume(uint8_t lp_volume);
uint8_t CS_GetVolume();
void CS_SetVolume(uint8_t lp_volume);

#endif
