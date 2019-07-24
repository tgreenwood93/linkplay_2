#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"

static LinkPlay_Firmware_Update_t linkplay_update_status; 
static LinkPlay_Audio_Channel_Options_t linkplay_channel_config; 
static LinkPlay_Playback_Mode_t linkplay_playback_mode;
static LinkPlay_Wireless_Status_t linkplay_wireless_status;
//static LinkPlay_Audio_Channel_Options_t linkplay_audio_channel_options;
static Linkplay_Ethernet_Status_t linkplay_ethernet_status;
static LinkPlay_Weekday_t linkplay_weekday; 
static LinkPlay_Shuffle_Repeat_Status_t linkplay_shuffle_repeat_status;
static Linkplay_Hotspot_status_t linkplay_hotspot_status;
static Linkplay_Playback_Status_t linkplay_playback_status;
static Linkplay_Mute_Status_t linkplay_mute_status; 
static bool linkplay_factory_reset_status;
static char linkplay_ssid[70];
static Linkplay_Language_t linkplay_language;
static bool linkplay_ssid_hidden_status;
static uint8_t linkplay_ssid_strategy; 
static char linkplay_firmware_version[20]; 
static char linkplay_firmware_build_type[20];
static char linkplay_project_title[30];
static char linkplay_private_project_title[30];
static uint16_t linkplay_firmware_release; 
static char linkplay_firmware_branch[30];
static uint16_t linkplay_group;
static bool linkplay_firmware_version_expierd; 
static char linkplay_mac_address[20];
static char linkplay_sta_mac_address[20];
static char linkplay_uuid[30];
static uint8_t linkplay_time_zone; 
static uint8_t linkplay_network_status; 
static char connected_ap_ssid[65];
static char linkplay_wifi_ip[20];
static char linkplay_ethernet_ip[20];
static char linkplay_hardware_module[5];
static bool linkplay_internet_status;
static uint16_t rtc_year;
static uint8_t rtc_month;
static uint8_t rtc_day;
static uint8_t rtc_hour;
static uint8_t rtc_minute;
static uint8_t rtc_second;

// ----------------------------------------------------------------------------
// Linkplay State Setters and Getters
// ----------------------------------------------------------------------------
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


void LP_Set_linkplay_internet_status (bool internet_status)
{
    linkplay_internet_status = internet_status;
}

bool LP_Get_linkplay_internet_status()
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


void LP_Set_linkplay_factory_status(bool factory_status)
{
    linkplay_factory_reset_status = factory_status;
}

bool LP_Get_linkplay_factory_status()
{
    return linkplay_factory_reset_status;
}


void LP_Set_linkplay_ssid(char* ssid)
{
    memset(linkplay_ssid, 0, 70);
    strncpy(linkplay_ssid, ssid, strlen(ssid));
}

char* LP_Get_linkplay_ssid()
{
    return linkplay_ssid; 
}


void LP_Set_linkplay_language(Linkplay_Language_t language)
{
    linkplay_language = language;
}

Linkplay_Language_t LP_Get_linkplay_language()
{
    return linkplay_language; 
}


void LP_Set_linkplay_ssid_hidden(bool ssid_hidden_status)
{
    linkplay_ssid_hidden_status = ssid_hidden_status;
}

bool LP_Get_linkplay_ssid_hidden()
{
    return linkplay_ssid_hidden_status;
}


/* !Need to figure out what the different strategys are! */
void LP_Set_linkplay_ssid_strategy(uint8_t ssid_strategy)
{
    linkplay_ssid_strategy = ssid_strategy; 
}

uint8_t LP_Get_linkplay_ssid_strategy()
{
    return linkplay_ssid_strategy; 
}


void LP_Set_linkplay_firmware_version(char* firmware_version)
{
    memset(linkplay_firmware_version, 0, 20);
    strncpy(linkplay_firmware_version, firmware_version, strlen(firmware_version));
}

char* LP_Get_linkplay_firmware_version()
{
    return linkplay_firmware_version;
}


void LP_Set_linkplay_build(char* firmware_build_type)
{
    memset(linkplay_firmware_build_type, 0, 20);
    strncpy(linkplay_firmware_build_type, firmware_build_type, strlen(firmware_build_type));
}

char* LP_Get_linkplay_build()
{
    return linkplay_firmware_build_type; 
}


void LP_Set_linkplay_project(char* project)
{
    memset(linkplay_project_title, 0, 30);
    strncpy(linkplay_project_title, project, strlen(project)); 
}

char* LP_Get_linkplay_project()
{
    return linkplay_project_title;
}


void LP_Set_linkplay_private_project(char* private_project)
{
    memset(linkplay_private_project_title, 0, 30);
    strncpy(linkplay_private_project_title, private_project, strlen(private_project)); 
}

char* LP_Get_linkplay_private_project()
{
    return linkplay_private_project_title;
}


void LP_Set_linkplay_firmware_release(uint16_t firmware_release)
{
    linkplay_firmware_release = firmware_release;
}

uint16_t LP_Get_linkplay_firmare_release()
{
    return linkplay_firmware_release;    
}


void LP_Set_linkplay_firmware_branch(char* firmware_branch)
{
    memset(linkplay_firmware_branch, 0, 30);
    strncpy(linkplay_firmware_branch, firmware_branch, strlen(firmware_branch));
}

char* LP_Get_linkplay_firmare_branch()
{
    return linkplay_firmware_branch;
}


void LP_Set_linkplay_group(uint16_t group)
{
    linkplay_group = group;
}

uint16_t LP_Get_linkplay_group()
{
    return linkplay_group;
}


void LP_Set_linkplay_verion_expierd(bool firmware_expierd)
{
    linkplay_firmware_version_expierd = firmware_expierd;
}

bool LP_Get_linkplay_version_expierd()
{
    return linkplay_firmware_version_expierd;
}

void LP_Set_linkplay_uuid(char* uuid)
{
    memset(linkplay_uuid, 0, 30);
    strncpy(linkplay_uuid, uuid, strlen(uuid));
}

char* LP_Get_linkplay_uuid()
{
    return linkplay_uuid;
}

void LP_Set_linkplay_mac_address(char* mac_address)
{
    memset(linkplay_mac_address, 0, 20);
    strncpy(linkplay_mac_address, mac_address, strlen(mac_address));
}

char* LP_Get_linkplay_mac_address()
{
    return linkplay_mac_address;
}

void LP_Set_linkplay_sta_mac_address(char* sta_mac_address)
{
    memset(linkplay_sta_mac_address, 0, 20);
    strncpy(linkplay_sta_mac_address, sta_mac_address, strlen(sta_mac_address));
}

char* LP_Get_linkplay_sta_mac_address()
{
    return linkplay_sta_mac_address;
}


void LP_Set_linkplay_time_zone(uint8_t time_zone)
{
    linkplay_time_zone = time_zone;
}

uint8_t LP_Get_linkplay_time_zone()
{
    return linkplay_time_zone; 
}


void LP_Set_linkplay_network_status(uint8_t network_status)
{
    linkplay_network_status = network_status;
}

uint8_t LP_Get_linkplay_network_status()
{
    return linkplay_network_status;
}


void LP_Set_linkplay_essid(char* essid)
{
    memset(connected_ap_ssid, 0, 65);
    strncpy(connected_ap_ssid, essid, strlen(essid));
}

char* LP_Get_linkplay_essid()
{
    return connected_ap_ssid; 
}


void LP_Set_linkplay_wifi_ip(char* wifi_ip)
{
    memset(linkplay_wifi_ip, 0, 20);
    strncpy(linkplay_wifi_ip, wifi_ip, strlen(wifi_ip));
}

char* LP_Get_linkplay_wifi_ip()
{
    return linkplay_wifi_ip; 
}


void LP_Set_linkplay_ethernet_ip(char* ethernet_ip)
{
    memset(linkplay_ethernet_ip, 0, 20);
    strncpy(linkplay_ethernet_ip, ethernet_ip, strlen(ethernet_ip));
}

char* LP_Get_linkplay_ethernet_ip()
{
    return linkplay_ethernet_ip; 
}

void LP_Set_linkplay_hardware(char* hardware_module)
{
    memset(linkplay_hardware_module, 0, 5);
    strncpy(linkplay_hardware_module, hardware_module, strlen(hardware_module));
}

char* LP_Get_linkplay_hardware()
{
    return linkplay_hardware_module; 
}












void LP_Set_linkplay_year(uint16_t year)
{
    rtc_year = year;
}

uint8_t LP_Get_linkplay_year()
{
    return rtc_year;
}


void LP_Set_linkplay_month(uint8_t month)
{
    rtc_month = month;
}

uint8_t LP_Get_linkplay_month()
{
    return rtc_month;
}


void LP_Set_linkplay_day(uint8_t day)
{
    rtc_day = day;
}

uint8_t LP_Get_linkplay_day()
{
    return rtc_day;

}


void LP_Set_linkplay_hour(uint8_t hour)
{
    rtc_hour = hour;
}

uint8_t LP_Get_linkplay_hour()
{
    return rtc_hour;

}


void LP_Set_linkplay_minute(uint8_t minute)
{
    rtc_minute = minute;
}

uint8_t LP_Get_linkplay_minute()
{
    return rtc_minute;

}


void LP_Set_linkplay_second(uint8_t second)
{
    rtc_second = second;
}

uint8_t LP_Get_linkplay_second()
{
    return rtc_second;

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
