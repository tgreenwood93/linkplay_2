#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"

static LinkPlay_Firmware_Update_t linkplay_update_status; 
static LinkPlay_Audio_Channel_Options_t linkplay_channel_config; 
static Linkplay_Internet_Status_t linkplay_internet_status;
static LinkPlay_Playback_Mode_t linkplay_playback_mode;
static LinkPlay_Wireless_Status_t linkplay_wireless_status;
static LinkPlay_Audio_Channel_Options_t linkplay_audio_channel_options;
static Linkplay_Ethernet_Status_t linkplay_ethernet_status;
static LinkPlay_Weekday_t linkplay_weekday; 
static LinkPlay_Shuffle_Repeat_Status_t linkplay_shuffle_repeat_status;
static Linkplay_Hotspot_status_t linkplay_hotspot_status;
static Linkplay_Playback_Status_t linkplay_playback_status;
static Linkplay_Mute_Status_t linkplay_mute_status; 


void LP_Set_linkplay_firmware_update_status(LinkPlay_Firmware_Update_t update_status)
{
    linkplay_update_status = update_status;
}

LinkPlay_Firmware_Update_t LP_Get_linkplay_firmware_update_status()
{
    return linkplay_update_status; 
}


void LP_Set_linkplay_audio_channel_status(LinkPlay_Audio_Channel_Options_t channel_config)
{
    linkplay_channel_config = channel_config;
}

LinkPlay_Audio_Channel_Options_t LP_Get_linkplay_audio_channel_status()
{
    return linkplay_channel_config;
}


void LP_Set_linkplay_internet_status (Linkplay_Internet_Status_t internet_status)
{
    linkplay_internet_status = internet_status;
}

Linkplay_Internet_Status_t LP_Get_linkplay_internet_status()
{
    return linkplay_internet_status;
}


void LP_Set_linkplay_playback_mode (LinkPlay_Playback_Mode_t playback_mode)
{
    linkplay_playback_mode = playback_mode;
}

LinkPlay_Playback_Mode_t LP_Get_linkplay_playback_mode()
{
    return linkplay_playback_mode;
}


void LP_Set_linkplay_wireless_access_status (LinkPlay_Wireless_Status_t wireless_status)
{
    linkplay_wireless_status = wireless_status;
}

LinkPlay_Wireless_Status_t LP_Get_linkplay_wireless_access_status()
{
    return linkplay_wireless_status;
}


void LP_Set_linkplay_ethernet_status (Linkplay_Ethernet_Status_t ethernet_status)
{
    linkplay_ethernet_status = ethernet_status;
}

Linkplay_Ethernet_Status_t LP_Get_linkplay_ethernet_status()
{
    return linkplay_ethernet_status;
}


void LP_Set_linkplay_rtc_weekday (LinkPlay_Weekday_t weekday)
{
    linkplay_weekday = weekday;
}

LinkPlay_Weekday_t LP_Get_linkplay_rtc_weekday()
{
    return linkplay_weekday;
}


void LP_Set_linkplay_repeat_shuffle (LinkPlay_Shuffle_Repeat_Status_t shuffle_repeat_status)
{
    linkplay_shuffle_repeat_status = shuffle_repeat_status;
}

LinkPlay_Shuffle_Repeat_Status_t LP_Get_linkplay_repeat_shuffle()
{
    return linkplay_shuffle_repeat_status; 
}


void LP_Set_linkplay_hotspot_status (Linkplay_Hotspot_status_t hotspot_status)
{
    linkplay_hotspot_status = hotspot_status;
}

Linkplay_Hotspot_status_t LP_Get_linkplay_hotspot_status()
{
    return linkplay_hotspot_status;
}


void LP_Set_linkplay_playback_status (Linkplay_Playback_Status_t playback_status)
{
    linkplay_playback_status = playback_status;
}

Linkplay_Playback_Status_t LP_Get_linkplay_playback_status()
{
    return linkplay_playback_status;
}

void LP_Set_linkplay_mute (Linkplay_Mute_Status_t mute_status)
{
    linkplay_mute_status = mute_status;
}
Linkplay_Mute_Status_t LP_Get_linkplay_mute()
{
    return linkplay_mute_status;
}

void LP_get_pic_channel_config()
{

}

void LP_send_linkplay_pic_volume()
{

}

void send_linkplay_pic_volume()
{
    switch (CS_GetOutputType())
    {   
        case(e_OUTPUT_TYPE_Headphones):
            Serial1.print("MCU+VOL+");
            Serial1.println(CS_GetHeadphoneVolume());
            break;    
        case(e_OUTPUT_TYPE_Main):
            Serial1.print("MCU+VOL+");
            Serial1.println(CS_GetVolume());
            break;
        default:
            break;
    }
}

void LP_set_pic_volume(uint8_t lp_volume)
{
    switch (CS_GetOutputType())
    {   
        case e_OUTPUT_TYPE_Headphones:
            CS_SetHeadphoneVolume(lp_volume);
            break;    
        case e_OUTPUT_TYPE_Main:
            CS_SetVolume(lp_volume);
            break;
        default:
            break;
    }
}
