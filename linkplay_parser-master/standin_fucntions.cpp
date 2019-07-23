#include "standin_functions.h"
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
static test_vol = 20;
static test_vol_hp = 20;

void CS_GetOutputType()
{
    return e_OUTPUT_TYPE_Main;
}

void CS_GetHeadphoneVolume()
{
   return test_vol_hp
}

void CS_SetHeadphoneVolume(uint8_t volume)
{
    test_vol_hp = volume;
}

void CS_GetVolume()
{
    return test_vol;
}

void CS_SetVolume(uin8_t volume)
{
    test_vol = volume;
}