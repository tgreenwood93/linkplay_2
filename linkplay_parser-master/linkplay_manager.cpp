#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

static LinkPlay_Firmware_Update_t linkplay_update_status; 
static LinkPlay_Audio_Channel_Options_t linkplay_channel_config; 
static bool linkplay_resetting = false;
static LinkPlay_Playback_Mode_t linkplay_playback_mode;
static LinkPlay_Wireless_Status_t linkplay_wireless_status;
//static LinkPlay_Audio_Channel_Options_t linkplay_audio_channel_options;
static Linkplay_Ethernet_Status_t linkplay_ethernet_status;
static LinkPlay_Shuffle_Repeat_Status_t linkplay_shuffle_repeat_status;
static Linkplay_Hotspot_Status_t linkplay_hotspot_status;
static Linkplay_Hotspot_Connections_Status_t linkplay_hotspot_connections_status;
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
static uint32_t linkplay_firmware_release; 
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
static bool linkplay_update_available;
static bool linkplay_new_version_number;
static uint16_t linkplay_pic_firmware_version;
static uint16_t linkplay_pic_new_firmware_verison; 
static uint16_t linkplay_dsp_firmware_version;
static uint16_t linkplay_dsp_new_firmware_version;    
static char linkplay_internal_server_port[20]; 
static char linkplay_temp_uuid[20];
static uint16_t linkplay_capl;
static uint8_t linkplay_languages;
static uint16_t linkplay_dsp_version;
static uint32_t linkplay_streaming_settings;
static uint32_t linkplay_streams;
static uint16_t linkplay_region;
static uint16_t linkplay_external;
static uint8_t linkplay_preset_keys;
static uint8_t linkplay_inf_plm_support;
static bool linkplay_spotify_active;
static uint16_t linkplay_wifi_channel;
static int16_t linkplay_rssi;
static bool linkplay_battery;
static uint8_t linkplay_bat_percent;
static bool linkplay_secure_mode;
static uint16_t linkplay_unpn_version;
static char linkplay_unpn_uuid[40];
static char linkplay_pass_port[8];
static char linkplay_comm_port[8];
static bool linkplay_firmware_update_hidden;
static uint16_t linkplay_web_login_result;
static bool linkplay_ignore_talk_start;
static bool linkplay_iheartradio_new;
static bool linkplay_privacy_mode;
static char linkplay_user_1[20];
static char linkplay_user_2[20];
static char linkplay_device_name[65];
static uint16_t rtc_year;
static uint8_t rtc_month;
static uint8_t rtc_day;
static uint8_t rtc_hour;
static uint8_t rtc_minute;
static uint8_t rtc_second;
static LinkPlay_Weekday_t linkplay_day_of_the_week;
static Linkpaly_Sample_Rate_t linkplay_sample_rate;
static Linkpaly_Bit_Depth_t linkplay_bit_depth; 
static char linkplay_title[70];
static char linkplay_artist[70];
static char linkplay_album[70];
static uint32_t linkplay_songtime_ms;
static int16_t linkplay_alarm_status;
static Linkplay_Voice_Prompt_t linkplay_vprompt_status;
static Linlplay_Power_Status_t linkplay_power_status;
static bool linkplay_silent_firmware_update;
static uint8_t num_access_points_found;
static Linkplay_WPS_Status_t linkplay_wps_status;
static bool linkplay_ready_for_communication = false;
static uint16_t linkplay_ota_time;

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

void LP_Set_linkplay_in_reset(bool linkplay_in_reset)
{
    linkplay_resetting = linkplay_in_reset;
}

bool LP_Get_linkplay_in_reset()
{
    return linkplay_resetting;
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


void LP_Set_linkplay_repeat_shuffle (LinkPlay_Shuffle_Repeat_Status_t shuffle_repeat_status)
{
    linkplay_shuffle_repeat_status = shuffle_repeat_status;
}

LinkPlay_Shuffle_Repeat_Status_t LP_Get_linkplay_repeat_shuffle()
{
    return linkplay_shuffle_repeat_status; 
}


void LP_Set_linkplay_hotspot_status (Linkplay_Hotspot_Status_t hotspot_status)
{
    linkplay_hotspot_status = hotspot_status;
}

Linkplay_Hotspot_Status_t LP_Get_linkplay_hotspot_status()
{
    return linkplay_hotspot_status;
}

void LP_Set_linkplay_hotspot_connections_status (Linkplay_Hotspot_Connections_Status_t hotspot_connections_status)
{
    linkplay_hotspot_connections_status = hotspot_connections_status;
}

Linkplay_Hotspot_Connections_Status_t LP_Get_linkplay_hotspot_connections_status()
{
    return linkplay_hotspot_connections_status;
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
    memset(linkplay_ssid, ASCII_NUL, 70);
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
    memset(linkplay_firmware_version, ASCII_NUL, 20);
    strncpy(linkplay_firmware_version, firmware_version, strlen(firmware_version));
}

char* LP_Get_linkplay_firmware_version()
{
    return linkplay_firmware_version;
}


void LP_Set_linkplay_build(char* firmware_build_type)
{
    memset(linkplay_firmware_build_type, ASCII_NUL, 20);
    strncpy(linkplay_firmware_build_type, firmware_build_type, strlen(firmware_build_type));
}

char* LP_Get_linkplay_build()
{
    return linkplay_firmware_build_type; 
}


void LP_Set_linkplay_project(char* project)
{
    memset(linkplay_project_title, ASCII_NUL, 30);
    strncpy(linkplay_project_title, project, strlen(project)); 
}

char* LP_Get_linkplay_project()
{
    return linkplay_project_title;
}


void LP_Set_linkplay_private_project(char* private_project)
{
    memset(linkplay_private_project_title, ASCII_NUL, 30);
    strncpy(linkplay_private_project_title, private_project, strlen(private_project)); 
}

char* LP_Get_linkplay_private_project()
{
    return linkplay_private_project_title;
}


void LP_Set_linkplay_firmware_release(uint32_t firmware_release)
{
    linkplay_firmware_release = firmware_release;
}

uint32_t LP_Get_linkplay_firmare_release()
{
    return linkplay_firmware_release;    
}


void LP_Set_linkplay_firmware_branch(char* firmware_branch)
{
    memset(linkplay_firmware_branch, ASCII_NUL, 30);
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
    memset(linkplay_uuid, ASCII_NUL, 30);
    strncpy(linkplay_uuid, uuid, strlen(uuid));
}

char* LP_Get_linkplay_uuid()
{
    return linkplay_uuid;
}

void LP_Set_linkplay_mac_address(char* mac_address)
{
    memset(linkplay_mac_address, ASCII_NUL, 20);
    strncpy(linkplay_mac_address, mac_address, strlen(mac_address));
}

char* LP_Get_linkplay_mac_address()
{
    return linkplay_mac_address;
}

void LP_Set_linkplay_sta_mac_address(char* sta_mac_address)
{
    memset(linkplay_sta_mac_address, ASCII_NUL, 20);
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
    memset(connected_ap_ssid, ASCII_NUL, 65);
    strncpy(connected_ap_ssid, essid, strlen(essid));
}

char* LP_Get_linkplay_essid()
{
    return connected_ap_ssid; 
}


void LP_Set_linkplay_wifi_ip(char* wifi_ip)
{
    memset(linkplay_wifi_ip, ASCII_NUL, 20);
    strncpy(linkplay_wifi_ip, wifi_ip, strlen(wifi_ip));
}

char* LP_Get_linkplay_wifi_ip()
{
    return linkplay_wifi_ip; 
}


void LP_Set_linkplay_ethernet_ip(char* ethernet_ip)
{
    memset(linkplay_ethernet_ip, ASCII_NUL, 20);
    strncpy(linkplay_ethernet_ip, ethernet_ip, strlen(ethernet_ip));
}

char* LP_Get_linkplay_ethernet_ip()
{
    return linkplay_ethernet_ip; 
}

void LP_Set_linkplay_hardware(char* hardware_module)
{
    memset(linkplay_hardware_module, ASCII_NUL, 5);
    strncpy(linkplay_hardware_module, hardware_module, strlen(hardware_module));
}

char* LP_Get_linkplay_hardware()
{
    return linkplay_hardware_module; 
}


void LP_Set_linkplay_version_update(bool update_available)
{
    linkplay_update_available = update_available; 
}

bool LP_Get_linkplay_version_update()
{
    return linkplay_update_available;
}


void LP_Set_linkplay_new_version(uint16_t new_firmware_version)
{
    linkplay_new_version_number = new_firmware_version;
}

uint16_t LP_Get_linkplay_new_version()
{
    return linkplay_new_version_number;
}


void LP_Set_linkplay_pic_firmware_verison(uint16_t pic_firmware_verison)
{
    linkplay_pic_firmware_version = pic_firmware_verison;
}

uint16_t LP_Get_linkplay_pic_firmware_verison()
{
    return linkplay_pic_firmware_version; 
}


void LP_Set_linkplay_pic_new_firmware_verison(uint16_t pic_new_firmware_verison)
{
    linkplay_pic_new_firmware_verison = pic_new_firmware_verison;
}

uint16_t LP_Get_linkplay_pic_new_firmware_verison()
{
    return linkplay_pic_new_firmware_verison; 
}

void LP_Set_linkplay_dsp_firmware_verison(uint16_t dsp_firmware_verison)
{
    linkplay_dsp_firmware_version = dsp_firmware_verison;
}

uint16_t LP_Get_linkplay_dsp_firmware_verison()
{
    return linkplay_dsp_firmware_version;
}

void LP_Set_linkplay_dsp_new_firmware_verison(uint16_t dsp_new_firmware_verison)
{
    linkplay_dsp_new_firmware_version = dsp_new_firmware_verison;
}

uint8_t LP_Get_linkplay_dsp_new_firmware_verison()
{
    return linkplay_dsp_new_firmware_version;    
}


void LP_Set_linkplay_internal_server_port(char* internal_server_port)
{
    memset(linkplay_internal_server_port, ASCII_NUL, 20);
    strncpy(linkplay_internal_server_port, internal_server_port, strlen(internal_server_port));
}

char* LP_Get_linkplay_internal_server_port()
{
    return linkplay_internal_server_port; 
}   


void LP_Set_linkplay_temp_uuid(char* temp_uuid)
{
    memset(linkplay_temp_uuid, ASCII_NUL, 20);
    strncpy(linkplay_temp_uuid, temp_uuid, strlen(temp_uuid));
}

char* LP_Get_linkplay_temp_uuid()
{
    return linkplay_temp_uuid; 
}


void LP_Set_linkplay_capl(uint16_t capl)
{
    linkplay_capl = capl;
}

uint16_t LP_Get_linkplay_capl()
{
    return linkplay_capl;
}


void LP_Set_linkplay_languages(uint8_t languages)
{
    linkplay_languages = languages;
}

uint8_t LP_Get_linkplay_languages()
{
    return linkplay_languages;
}


void LP_Set_linkplay_dsp_version(uint16_t dsp_version)
{
    linkplay_dsp_version = dsp_version;
}

uint16_t LP_Get_linkplay_dsp_version()
{
    return linkplay_dsp_version;
}


void LP_Set_linkplay_steaming_settings(uint32_t streaming_settings)
{
    linkplay_streaming_settings = streaming_settings;
}

uint32_t LP_Get_linkplay_steaming_settings()
{
    return linkplay_streaming_settings;
}


void LP_Set_linkplay_streams(uint32_t streams)
{
    linkplay_streams = streams;
}

uint32_t LP_Get_linkplay_streams()
{
    return linkplay_streams;
}


void LP_Set_linkplay_region(uint16_t region)
{
    linkplay_region = region;
}

uint16_t LP_Get_linkplay_region()
{
    return linkplay_region;
}


void LP_Set_linkplay_external(uint16_t external)
{
    linkplay_external = external;
}

uint16_t LP_Get_linkplay_external()
{
    return linkplay_external;
}


void LP_Set_linkplay_preset_keys(uint8_t preset_keys)
{
    linkplay_preset_keys = preset_keys; 
}

uint8_t LP_Get_linkplay_preset_keys()
{
    return linkplay_preset_keys;
}


void LP_Set_linkplay_plm_support(uint8_t inf_plm_support)
{
    linkplay_inf_plm_support = e_inf_plm_support;
}

uint8_t LP_Get_linkplay_plm_support()
{
    return linkplay_inf_plm_support;
}


void LP_Set_linkplay_spotify_active(bool spotify_active)
{
    linkplay_spotify_active = spotify_active;
}

bool LP_Get_linkplay_spotify_active()
{
    return linkplay_spotify_active;
}


void LP_Set_linkplay_wifi_channel(uint16_t wifi_channel)
{
    linkplay_wifi_channel = wifi_channel;
}

uint16_t LP_Get_linkplay_wifi_channel()
{
    return linkplay_wifi_channel;
}


void LP_Set_linkplay_rssi(int16_t rssi)
{
    linkplay_rssi = rssi;
}

int16_t LP_Get_linkplay_rssi()
{
    return linkplay_rssi;
}


void LP_Set_linkplay_battery(bool battery)
{
    linkplay_battery = battery;
}

bool LP_Get_linkplay_battery()
{
    return linkplay_battery;
}


void LP_Set_linkplay_battery_percent(uint8_t bat_percent)
{
    linkplay_bat_percent = bat_percent;
}

uint8_t LP_Get_linkplay_battery_percent()
{
    return linkplay_bat_percent;
}


void LP_Set_linkplay_secure_mode(bool secure_mode)
{
    linkplay_secure_mode = secure_mode;
}

bool LP_Get_linkplay_secure_mode()
{
    return linkplay_secure_mode;
}


void LP_Set_linkplay_upnp_version(uint16_t unpn_version)
{
    linkplay_unpn_version = unpn_version;
}

uint16_t LP_Get_linkplay_upnp_version()
{
    return linkplay_unpn_version;
}


void LP_Set_linkplay_upnp_uuid(char* unpn_uuid)
{
    memset(linkplay_unpn_uuid, ASCII_NUL, 40);
    strncpy(linkplay_unpn_uuid, unpn_uuid+5, (strlen(unpn_uuid)-5));
}

char* LP_Get_linkplay_upnp_uuid()
{
    return linkplay_unpn_uuid;
}


void LP_Set_linkplay_pass_port(char* pass_port)
{
    memset(linkplay_pass_port, ASCII_NUL, 8);
    strncpy(linkplay_pass_port, pass_port, strlen(pass_port));
}

char* LP_Get_linkplay_pass_port()
{
    return linkplay_pass_port;
}


void LP_Set_linkplay_communication_port(char* comm_port)
{
    memset(linkplay_comm_port, ASCII_NUL, 8);
    strncpy(linkplay_comm_port, comm_port, strlen(comm_port));
}

char* LP_Get_linkplay_communication_port()
{
    return linkplay_comm_port;
}


void LP_Set_linkplay_firmware_update_hidden(bool firmware_update_hidden)
{
    linkplay_firmware_update_hidden = firmware_update_hidden;
}

bool LP_Get_linkplay_firmware_update_hidden()
{
    return linkplay_firmware_update_hidden;
}


void LP_Set_linkplay_web_login_result(int16_t web_login_result)
{
    linkplay_web_login_result = web_login_result;
}

int16_t LP_Get_linkplay_web_login_result()
{
    return linkplay_web_login_result;
}


void LP_Set_linkplay_ignore_talk_start(bool ignore_talk_start)
{
    linkplay_ignore_talk_start = ignore_talk_start;
}

bool LP_Get_linkplay_ignore_talk_start()
{
    return linkplay_ignore_talk_start;
}


void LP_Set_linkplay_silence_OTA_time(uint16_t ota_time)
{
    linkplay_ota_time = ota_time;
}

uint16_t LP_Get_linkplay_silence_OTA_time()
{
    return linkplay_ota_time;
}

void LP_Set_linkplay_iHeartRadio_new(bool iheartradio_new)
{
    linkplay_iheartradio_new = iheartradio_new;
}

bool LP_Get_linkplay_iHeartRadio_new()
{
    return linkplay_iheartradio_new;
}


void LP_Set_linkplay_privacy_mode(bool privacy_mode)
{
    linkplay_privacy_mode = privacy_mode;
}

bool LP_Get_linkplay_privacy_mode()
{
    return linkplay_privacy_mode;
}


void LP_Set_linkplay_user1(char* user_1)
{
    memset(linkplay_user_1, ASCII_NUL, 20);
    strncpy(linkplay_user_1, user_1, strlen(user_1));
}

char* LP_Get_linkplay_user1()
{
    return linkplay_user_1;
}


void LP_Set_linkplay_user2(char* user_2)
{
    memset(linkplay_user_2, ASCII_NUL, 20);
    strncpy(linkplay_user_2, user_2, strlen(user_2));
}

char* LP_Get_linkplay_user2()
{
    return linkplay_user_2;
}


void LP_Set_linkplay_device_name(char* device_name)
{
    memset(linkplay_device_name, ASCII_NUL, 65);
    strncpy(linkplay_device_name, device_name, strlen(device_name));
}

char* LP_Get_linkplay_device_name()
{
    return linkplay_device_name;
}


void LP_Set_linkplay_sample_rate(Linkpaly_Sample_Rate_t sample_rate)
{
    linkplay_sample_rate = sample_rate;
}
Linkpaly_Sample_Rate_t LP_Get_linkplay_sample_rate()
{
    return linkplay_sample_rate;
} 

void LP_Set_linkplay_bit_depth(Linkpaly_Bit_Depth_t bit_depth)
{
    linkplay_bit_depth = bit_depth;
}

Linkpaly_Bit_Depth_t LP_Get_linkplay_bit_depth()
{
    return linkplay_bit_depth; 
}

void LP_Set_linkplay_communication_status()
{

}

uint8_t LP_Get_linkplay_communication_status()
{
    return 0;     
}

void LP_Set_linkplay_title(char* title)
{
    memset(linkplay_title, ASCII_NUL, 70);
    strncpy(linkplay_title, title, strlen(title));
}
char* LP_Get_linkplay_title()
{
    return linkplay_title;
}

void LP_Set_linkplay_artist(char* artist)
{
    memset(linkplay_artist, ASCII_NUL, 70);
    strncpy(linkplay_artist, artist, strlen(artist));
}
char* LP_Get_linkplay_artist()
{
    return linkplay_artist;
}

void LP_Set_linkplay_album(char* album)
{
    memset(linkplay_album, ASCII_NUL, 70);
    strncpy(linkplay_album, album, strlen(album));
}
char* LP_Get_linkplay_album()
{
    return linkplay_album;
}

void LP_Set_linkplay_song_time(uint32_t songtime_ms)
{
    linkplay_songtime_ms = songtime_ms;
}

uint32_t LP_Get_linkplay_song_time()
{
    return linkplay_songtime_ms;
}

void LP_Set_linkplay_microphones(uint8_t mic_status)
{

}

uint8_t LP_Get_linkplay_micrphones()
{
    return 0;
}

void LP_Set_linkplay_alarm(int16_t alarm_status)
{
    linkplay_alarm_status = alarm_status;
}
int16_t LP_Get_linkplay_alarm()
{
    return linkplay_alarm_status;
}

void LP_Set_linkplay_voice_promt(Linkplay_Voice_Prompt_t vprompt_status)
{
    linkplay_vprompt_status = vprompt_status;
}

Linkplay_Voice_Prompt_t LP_Get_linkplay_voice_promt()
{
    return linkplay_vprompt_status;
}

void LP_Set_linkplay_power_status(Linlplay_Power_Status_t power_status)
{
    linkplay_power_status = power_status;
}

Linlplay_Power_Status_t LP_Get_linkplay_power_status()
{
    return linkplay_power_status;
}


void LP_Set_linkplay_year(uint16_t year)
{
    rtc_year = year;
}

uint16_t LP_Get_linkplay_year()
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

void LP_Set_linkplay_weekday (LinkPlay_Weekday_t weekday)
{
    linkplay_day_of_the_week = weekday;
}

LinkPlay_Weekday_t LP_Get_linkplay_rtc_weekday()
{
    return linkplay_day_of_the_week; 
}


void LP_Set_linkplay_silent_firmware_update(bool silent_firmware_update)
{
    linkplay_silent_firmware_update = silent_firmware_update;
}

bool LP_Get_linkplay_silent_firmware_update()
{
    return linkplay_silent_firmware_update;
}

void set_num_access_points(uint8_t num_aps)
{
    num_access_points_found = num_aps;
}

uint8_t get_num_access_points(uint8_t num_aps)
{
    return num_access_points_found;
}


void Linkplay_Set_wps_status(Linkplay_WPS_Status_t wps_status)
{
    linkplay_wps_status = wps_status;
}

Linkplay_WPS_Status_t Linkplay_Set_wps_status()
{
    return linkplay_wps_status;
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

void LP_Set_linkplay_ready_for_communication(bool ready)
{
    linkplay_ready_for_communication = ready;
}

bool LP_Set_linkplay_ready_for_communication()
{
    return linkplay_ready_for_communication;
}

void dump_stored_linkplay_data()
{
    Serial.print("linkplay firmware update status: ");
    Serial.println(LP_Get_linkplay_firmware_update_status());
    Serial.print("linkplay audio channel status: ");
    Serial.println(LP_Get_linkplay_audio_channel_status());
    Serial.print("linkplay in reset?: ");
    Serial.println(LP_Get_linkplay_in_reset());
    Serial.print("internet status: ");
    Serial.println(LP_Get_linkplay_internet_status());
    Serial.print("playback mode: ");
    Serial.println(LP_Get_linkplay_playback_mode());
    Serial.print("wireless access status: ");
    Serial.println(LP_Get_linkplay_wireless_access_status());
    Serial.print("ethernet access status: ");
    Serial.println(LP_Get_linkplay_ethernet_status());
    Serial.print("repeat/shuffle status: ");
    Serial.println(LP_Get_linkplay_repeat_shuffle());
    Serial.print("hotspot status: ");
    Serial.println(LP_Get_linkplay_hotspot_status());
    Serial.print("hotspot connection status: ");
    Serial.println(LP_Get_linkplay_hotspot_connections_status());
    Serial.print("playback status: ");
    Serial.println(LP_Get_linkplay_playback_status());
    Serial.print("mute status: ");
    Serial.println(LP_Get_linkplay_mute());
    Serial.print("factory init status: ");
    Serial.println(LP_Get_linkplay_factory_status());
    Serial.print("ssid: ");
    Serial.println(LP_Get_linkplay_ssid());
    Serial.print("language: ");
    Serial.println(LP_Get_linkplay_language());
    Serial.print("ssid hidden?: ");
    Serial.println(LP_Get_linkplay_ssid_hidden());
    Serial.print("ssid strategy: ");
    Serial.println(LP_Get_linkplay_ssid_strategy());
    Serial.print("firmware version: ");
    Serial.println(LP_Get_linkplay_firmware_version());
    Serial.print("build: ");
    Serial.println(LP_Get_linkplay_build());
    Serial.print("project: ");
    Serial.println(LP_Get_linkplay_project());
    Serial.print("private project: ");
    Serial.println(LP_Get_linkplay_private_project());
    Serial.print("firmware type: ");
    Serial.println(LP_Get_linkplay_firmare_release());
    Serial.print("branch: ");
    Serial.println(LP_Get_linkplay_firmare_branch());
    Serial.print("group: ");
    Serial.println(LP_Get_linkplay_group());
    Serial.print("version is expiered?: ");
    Serial.println(LP_Get_linkplay_version_expierd());
    Serial.print("uuid: ");
    Serial.println(LP_Get_linkplay_uuid());
    Serial.print("mac: ");
    Serial.println(LP_Get_linkplay_mac_address());
    Serial.print("sta mac: ");
    Serial.println(LP_Get_linkplay_sta_mac_address());
    Serial.print("time zone: ");
    Serial.println(LP_Get_linkplay_time_zone());
    Serial.print("network status: ");
    Serial.println(LP_Get_linkplay_network_status());
    Serial.print("essid: ");
    Serial.println(LP_Get_linkplay_essid());
    Serial.print("wifi ip: ");
    Serial.println(LP_Get_linkplay_wifi_ip());
    Serial.print("ethernet ip: ");
    Serial.println(LP_Get_linkplay_ethernet_ip());
    Serial.print("linkplay hardware: ");
    Serial.println(LP_Get_linkplay_hardware());
    Serial.print("version update?: ");
    Serial.println(LP_Get_linkplay_version_update());
    Serial.print("new linkplay version: ");
    Serial.println(LP_Get_linkplay_new_version());
    Serial.print("pic firmware version: ");
    Serial.println(LP_Get_linkplay_pic_firmware_verison());
    Serial.print("pic new firmware version: ");
    Serial.println(LP_Get_linkplay_pic_new_firmware_verison());
    Serial.print("dsp firmware: ");
    Serial.println(LP_Get_linkplay_dsp_firmware_verison());
    Serial.print("dsp new firmware: ");
    Serial.println(LP_Get_linkplay_dsp_new_firmware_verison());
    Serial.print("internal server port: ");
    Serial.println(LP_Get_linkplay_internal_server_port());
    Serial.print("temp uuid: ");
    Serial.println(LP_Get_linkplay_temp_uuid());
    Serial.print("capl: ");
    Serial.println(LP_Get_linkplay_capl());
    Serial.print("linkplay languages: ");
    Serial.println(LP_Get_linkplay_languages());
    Serial.print("dsp version: ");
    Serial.println(LP_Get_linkplay_dsp_version());
    Serial.print("streaming settings: ");
    Serial.println(LP_Get_linkplay_steaming_settings());
    Serial.print("streams: ");
    Serial.println(LP_Get_linkplay_streams());
    Serial.print("region: ");
    Serial.println(LP_Get_linkplay_region());
    Serial.print("external: ");
    Serial.println(LP_Get_linkplay_external());
    Serial.print("reset keys: ");
    Serial.println(LP_Get_linkplay_preset_keys());
    Serial.print("plm support: ");
    Serial.println(LP_Get_linkplay_plm_support());
    Serial.print("spotify active: ");
    Serial.println(LP_Get_linkplay_spotify_active());
    Serial.print("wifi chann: ");
    Serial.println(LP_Get_linkplay_wifi_channel());
    Serial.print("rssi: ");
    Serial.println(LP_Get_linkplay_rssi());
    Serial.print("batt: ");
    Serial.println(LP_Get_linkplay_battery());
    Serial.print("batt percent: ");
    Serial.println(LP_Get_linkplay_battery_percent());
    Serial.print("secure mode: ");
    Serial.println(LP_Get_linkplay_secure_mode());
    Serial.print("unpn version: ");
    Serial.println(LP_Get_linkplay_upnp_version());
    Serial.print("unpn uuid: ");
    Serial.println(LP_Get_linkplay_upnp_uuid());
    Serial.print("pass port: ");
    Serial.println(LP_Get_linkplay_pass_port());
    Serial.print("comm port: ");
    Serial.println(LP_Get_linkplay_communication_port());
    Serial.print("firmware update hidden: ");
    Serial.println(LP_Get_linkplay_firmware_update_hidden());
    Serial.print("web login result: ");
    Serial.println(LP_Get_linkplay_web_login_result());
    Serial.print("ignore talk start: ");
    Serial.println(LP_Get_linkplay_ignore_talk_start());
    Serial.print("silence ota time: ");
    Serial.println(LP_Get_linkplay_silence_OTA_time());
    Serial.print("iHeartRadio new: ");
    Serial.println(LP_Get_linkplay_iHeartRadio_new());
    Serial.print("privacy mode: ");
    Serial.println(LP_Get_linkplay_privacy_mode());
    Serial.print("user1: ");
    Serial.println(LP_Get_linkplay_user1());
    Serial.print("user2: ");
    Serial.println(LP_Get_linkplay_user2());
    Serial.print("device name: ");
    Serial.println(LP_Get_linkplay_device_name());
    Serial.print("sample rate: ");
    Serial.println(LP_Get_linkplay_sample_rate());
    Serial.print("bit depth: ");
    Serial.println(LP_Get_linkplay_bit_depth());
    Serial.print("comm status: ");
    Serial.println(LP_Get_linkplay_communication_status());
    Serial.print("title: ");
    Serial.println(LP_Get_linkplay_title());
    Serial.print("artist: ");
    Serial.println(LP_Get_linkplay_artist());
    Serial.print("album: ");
    Serial.println(LP_Get_linkplay_album());
    Serial.print("song time: ");
    Serial.println(LP_Get_linkplay_song_time());
    Serial.print("microphone status: ");
    Serial.println(LP_Get_linkplay_micrphones());
    Serial.print("alarm status: ");
    Serial.println(LP_Get_linkplay_alarm());
    Serial.print("voice prompt: ");
    Serial.println(LP_Get_linkplay_voice_promt());
    Serial.print("power status: ");
    Serial.println(LP_Get_linkplay_power_status());
    Serial.print("year: ");
    Serial.println(LP_Get_linkplay_year());
    Serial.print("month: ");
    Serial.println(LP_Get_linkplay_month());
    Serial.print("day: ");
    Serial.println(LP_Get_linkplay_day());
    Serial.print("hour: ");
    Serial.println(LP_Get_linkplay_hour());
    Serial.print("minute: ");
    Serial.println(LP_Get_linkplay_minute());
    Serial.print("second: ");
    Serial.println(LP_Get_linkplay_second());
    Serial.print("weekday: ");
    Serial.println(LP_Get_linkplay_rtc_weekday());
    Serial.print("silent firmware upgrade: ");
    Serial.println(LP_Get_linkplay_silent_firmware_update());
}


void get_IP()
{
    Serial.print("wifi ip: ");
    Serial.println(LP_Get_linkplay_wifi_ip());
    Serial.print("ethernet ip: ");
    Serial.println(LP_Get_linkplay_ethernet_ip());
}

void get_network_status()
{
    Serial.print("wireless access status: ");
    Serial.println(LP_Get_linkplay_wireless_access_status());
    Serial.print("ethernet access status: ");
    Serial.println(LP_Get_linkplay_ethernet_status());
    Serial.print("hotspot status: ");
    Serial.println(LP_Get_linkplay_hotspot_status());
    Serial.print("hotspot connection status: ");
    Serial.println(LP_Get_linkplay_hotspot_connections_status());
    Serial.print("ssid: ");
    Serial.println(LP_Get_linkplay_ssid());
    Serial.print("ssid hidden?: ");
    Serial.println(LP_Get_linkplay_ssid_hidden());
    Serial.print("ssid strategy: ");
    Serial.println(LP_Get_linkplay_ssid_strategy());
    Serial.print("mac: ");
    Serial.println(LP_Get_linkplay_mac_address());
    Serial.print("sta mac: ");
    Serial.println(LP_Get_linkplay_sta_mac_address());
    Serial.print("network status: ");
    Serial.println(LP_Get_linkplay_network_status());
    Serial.print("essid: ");
    Serial.println(LP_Get_linkplay_essid());
    Serial.print("wifi ip: ");
    Serial.println(LP_Get_linkplay_wifi_ip());
    Serial.print("ethernet ip: ");
    Serial.println(LP_Get_linkplay_ethernet_ip());
    Serial.print("wifi chann: ");
    Serial.println(LP_Get_linkplay_wifi_channel());
    Serial.print("rssi: ");
    Serial.println(LP_Get_linkplay_rssi());
}

void get_meta_data()
{
    Serial.print("title: ");
    Serial.println(LP_Get_linkplay_title());
    Serial.print("artist: ");
    Serial.println(LP_Get_linkplay_artist());
    Serial.print("album: ");
    Serial.println(LP_Get_linkplay_album());
    Serial.print("song time: ");
    Serial.println(LP_Get_linkplay_song_time());
}

void get_last_rtc()
{
    Serial.print("year: ");
    Serial.println(LP_Get_linkplay_year());
    Serial.print("month: ");
    Serial.println(LP_Get_linkplay_month());
    Serial.print("day: ");
    Serial.println(LP_Get_linkplay_day());
    Serial.print("hour: ");
    Serial.println(LP_Get_linkplay_hour());
    Serial.print("minute: ");
    Serial.println(LP_Get_linkplay_minute());
    Serial.print("second: ");
    Serial.println(LP_Get_linkplay_second());
    Serial.print("weekday: ");
    Serial.println(LP_Get_linkplay_rtc_weekday());
}

void get_rtc()
{
    Serial1.println("MCU+RTC+GET");
}

void get_lp_version()
{
    Serial.print("firmware version: ");
    Serial.println(LP_Get_linkplay_firmware_version());
    Serial.print("firmware type: ");
    Serial.println(LP_Get_linkplay_firmare_release());
    Serial.print("branch: ");
    Serial.println(LP_Get_linkplay_firmare_branch());
}

void get_lp_pic_version()
{
    Serial.print("pic firmware version: ");
    Serial.println(LP_Get_linkplay_pic_firmware_verison());
    Serial.print("pic new firmware version: ");
    Serial.println(LP_Get_linkplay_pic_new_firmware_verison());
}

void get_ap_ssid()
{   
    Serial.print("essid: ");
    Serial.println(LP_Get_linkplay_essid());
}

void get_lp_ssid() 
{
    Serial.print("ssid: ");
    Serial.println(LP_Get_linkplay_ssid());
}

void get_mac_address()
{
    Serial.print("mac: ");
    Serial.println(LP_Get_linkplay_mac_address());
    Serial.print("sta mac: ");
    Serial.println(LP_Get_linkplay_sta_mac_address());
}

void get_access_points()
{

}


void lp_retrieve_rtc()
{

}

void lp_retrieve_metadata()
{

}

void lp_retrieve_system_info()
{
    Serial1.println(mcu_commands[31]);
}

void lp_set_ssid()
{
    Serial1.println("MCU+SID+Stellar Integrated");
}

void lp_set_name()
{
    Serial1.println("MCU+NAM+SETStellar Integrated&");
}
