#include "standin_functions.h"
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
static uint8_t test_vol = 20;
static uint8_t test_vol_hp = 20;

Output_Type_t CS_GetOutputType()
{
    return e_OUTPUT_TYPE_Main;
}

uint8_t CS_GetHeadphoneVolume()
{
   return test_vol_hp;
}

void CS_SetHeadphoneVolume(uint8_t lp_volume)
{
    test_vol_hp = lp_volume;
}

uint8_t CS_GetVolume()
{
    return test_vol;
}

void CS_SetVolume(uint8_t lp_volume)
{
    test_vol = lp_volume;
}
