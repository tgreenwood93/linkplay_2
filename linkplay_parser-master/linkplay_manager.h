#include "Arduino.h"



#ifndef linkplay_manager_h
#define linkplay_manager_h


typedef enum 
{
    e_linkplay_lang_en_us = 0, 
    e_linkplay_lang_zh_cn,
    e_linkplay_lang_french,
    e_linkplay_lang_portuguese,
    e_linkplay_lang_italian,
    e_linkplay_lang_Ger_de,
    e_linkplay_lang_spanish,
} Linkplay_Language_t; 

// ----------------------------------------------------------------------------
// Linkplay State Setters and Getters
// ----------------------------------------------------------------------------
void LP_Set_linkplay_firmware_update_status(LinkPlay_Firmware_Update_t update_status);
LinkPlay_Firmware_Update_t LP_Get_linkplay_firmware_update_status(); 

void LP_Set_linkplay_audio_channel_status(LinkPlay_Audio_Channel_Options_t channel_config);
LinkPlay_Audio_Channel_Options_t LP_Get_linkplay_audio_channel_status();

void LP_Set_linkplay_in_reset();
uint8_t LP_Get_linkplay_in_reset();

void LP_Set_linkplay_ethernet_status (Linkplay_Ethernet_Status_t ethernet_status);
Linkplay_Ethernet_Status_t LP_Get_linkplay_ethernet_status();

void LP_Set_linkplay_factory_status(bool factory_status);
bool LP_Get_linkplay_factory_status();

void LP_Set_linkplay_ssid(char* ssid);
char* LP_Get_linkplay_ssid();

void LP_Set_linkplay_language(Linkplay_Language_t language);
Linkplay_Language_t LP_Get_linkplay_language();

void LP_Set_linkplay_ssid_hidden(bool ssid_hidden_status);
bool LP_Get_linkplay_ssid_hidden();

/* !Need to figure out what the different strategys are! */
void LP_Set_linkplay_ssid_strategy(uint8_t ssid_strategy);
uint8_t LP_Get_linkplay_ssid_strategy();

void LP_Set_linkplay_firmware_version(char* firmware);
char* LP_Get_linkplay_firmware_version();

void LP_Set_linkplay_build(char* firmware_build_type);
char* LP_Get_linkplay_build();

void LP_Set_linkplay_project(char* project);
char* LP_Get_linkplay_project();

void LP_Set_linkplay_private_project(char* private_project);
char* LP_Get_linkplay_private_project();

void LP_Set_linkplay_firmware_release(uint16_t firmware_release);
uint16_t LP_Get_linkplay_firmare_release();

void LP_Set_linkplay_firmware_branch(char* firmware_branch);
char* LP_Get_linkplay_firmare_branch();

void LP_Set_linkplay_group();
uint8_t LP_Get_linkplay_group();

void LP_Set_linkplay_verion_expierd(bool firmware_expierd);
bool LP_Get_linkplay_version_expierd();

void LP_Set_linkplay_internet_status (bool internet_status);
bool LP_Get_linkplay_internet_status();

void LP_Set_linkplay_uuid(char* );
char* LP_Get_linkplay_uuid();

void LP_Set_linkplay_mac_address(char* mac_address);
char* LP_Get_linkplay_mac_address();

void LP_Set_linkplay_sta_mac_address(char* sta_mac_address);
char* LP_Get_linkplay_sta_mac_address();

void LP_Set_linkplay_time_zone(uint8_t time_zone);
uint8_t LP_Get_linkplay_time_zone();

void void LP_Set_linkplay_network_status(uint8_t network_status);
uint8_t LP_Get_linkplay_network_status();

void LP_Set_linkplay_essid(char* router_ssid);
{

}

char* LP_Get_linkplay_essid();
{
    
}

void LP_Set_linkplay_wifi_ip();
uint8_t LP_Get_linkplay_wifi_ip();

void LP_Set_linkplay_ethernet_ip();
uint8_t LP_Get_linkplay_ethernet_ip();

void LP_Set_linkplay_hardware();
uint8_t LP_Get_linkplay_hardware();

void LP_Set_linkplay_version_update();
uint8_t LP_Get_linkplay_version_update();

void LP_Set_linkplay_new_version();
uint8_t LP_Get_linkplay_new_version();

void LP_Set_linkplay_pic_firmware_verison();
uint8_t LP_Get_linkplay_pic_firmware_verison();

void LP_Set_linkplay_pic_new_firmware_verison();
uint8_t LP_Get_linkplay_pic_new_firmware_verison();

void LP_Set_linkplay_dsp_firmware_verison();
uint8_t LP_Get_linkplay_dsp_firmware_verison();

void LP_Set_linkplay_dsp_new_firmware_verison();
uint8_t LP_Get_linkplay_dsp_new_firmware_verison();

void LP_Set_linkplay_internal_server_port();
uint8_t LP_Get_linkplay_internal_server_port();

void LP_Set_linkplay_temp_uuid();
uint8_t LP_Get_linkplay_temp_uuid();

void LP_Set_linkplay_pass_port();
uint8_t LP_Get_linkplay_pass_port();

void LP_Set_linkplay_capl();
uint8_t LP_Get_linkplay_capl();

void LP_Set_linkplay_languages();
uint8_t LP_Get_linkplay_languages();

void LP_Set_linkplay_dsp_version();
uint8_t LP_Get_linkplay_dsp_version();

void LP_Set_linkplay_steaming_settings();
uint8_t LP_Get_linkplay_steaming_settings();

void LP_Set_linkplay_streams();
uint8_t LP_Get_linkplay_streams();

void LP_Set_linkplay_region();
uint8_t LP_Get_linkplay_region();

void LP_Set_linkplay_external();
uint8_t LP_Get_linkplay_external();

void LP_Set_linkplay_preset_key();
uint8_t LP_Get_linkplay_preset_key();

void LP_Set_linkplay_plm_support();
uint8_t LP_Get_linkplay_plm_support();

void LP_Set_linkplay_spotify_active();
uint8_t LP_Get_linkplay_spotify_active();

void LP_Set_linkplay_wifi_channel();
uint8_t LP_Get_linkplay_wifi_channel();

void LP_Set_linkplay_rssi();
uint8_t LP_Get_linkplay_rssi();

void LP_Set_linkplay_battery();
uint8_t LP_Get_linkplay_battery();

void LP_Set_linkplay_battery_percent();
uint8_t LP_Get_linkplay_battery_percent();

void LP_Set_linkplay_secure_mode();
uint8_t LP_Get_linkplay_secure_mode();

void LP_Set_linkplay_upnp_version();
uint8_t LP_Get_linkplay_upnp_version();

void LP_Set_linkplay_upnp_uuid();
uint8_t LP_Get_linkplay_upnp_uuid();

void LP_Set_linkplay_pass_port();
uint8_t LP_Get_linkplay_pass_port();

void LP_Set_linkplay_communication_port();
uint8_t LP_Get_linkplay_communication_port();

void LP_Set_linkplay_firmware_update_hidden();
uint8_t LP_Get_linkplay_firmware_update_hidden();

void LP_Set_linkplay_web_login_result();
uint8_t LP_Get_linkplay_web_login_result();

void LP_Set_linkplay_ignore_talk_start();
uint8_t LP_Get_linkplay_ignore_talk_start();

void LP_Set_linkplay_silence_OTA_time();
uint8_t LP_Get_linkplay_silence_OTA_time();

void LP_Set_linkplay_ignore_silence_OTA_time();
uint8_t LP_Get_linkplay_ignore_silence_OTA_time();

void LP_Set_linkplay_iHeartRadio_new();
uint8_t LP_Get_linkplay_iHeartRadio_new();

void LP_Set_linkplay_privacy_mode();
uint8_t LP_Get_linkplay_privacy_mode();

void LP_Set_linkplay_user1();
uint8_t LP_Get_linkplay_user1();

void LP_Set_linkplay_user2();
uint8_t LP_Get_linkplay_user2();

void LP_Set_linkplay_device_name();
uint8_t LP_Get_linkplay_device_name();

void LP_Set_linkplay_sample_rate();
uint8_t LP_Get_linkplay_sample_rate();

void LP_Set_linkplay_bit_depth();
uint8_t LP_Get_linkplay_bit_depth();

void LP_Set_linkplay_communication_status();
uint8_t LP_Get_linkplay_communication_status();

void LP_Set_linkplay_title();
uint8_t LP_Get_linkplay_title();

void LP_Set_linkplay_artist();
uint8_t LP_Get_linkplay_artist();

void LP_Set_linkplay_album();
uint8_t LP_Get_linkplay_album();

void LP_Set_linkplay_song_time();
uint8_t LP_Get_linkplay_song_time();

void LP_Set_linkplay_microphones();
uint8_t LP_Get_linkplay_micrphones();

void LP_Set_linkplay_mute (Linkplay_Mute_Status_t mute_status);
Linkplay_Mute_Status_t LP_Get_linkplay_mute();

void LP_Set_linkplay_microphones();
uint8_t LP_Get_linkplay_micrphones();

void LP_Set_linkplay_alarm();
uint8_t LP_Get_linkplay_alarm();

void LP_Set_linkplay_playback_mode (LinkPlay_Playback_Mode_t playback_mode);
LinkPlay_Playback_Mode_t LP_Get_linkplay_playback_mode();

void LP_Set_linkplay_repeat_shuffle (LinkPlay_Shuffle_Repeat_Status_t shuffle_repeat_status);
LinkPlay_Shuffle_Repeat_Status_t LP_Get_linkplay_repeat_shuffle();

void LP_Set_linkplay_playback_status (Linkplay_Playback_Status_t playback_status);
Linkplay_Playback_Status_t LP_Get_linkplay_playback_status();

void LP_Set_linkplay_playback_time();
uint8_t LP_Get_linkplay_playback_time();

void LP_Set_linkplay_voice_promt();
uint8_t LP_Get_linkplay_voice_promt();

void LP_Set_linkplay_power_status();
uint8_t LP_Get_linkplay_power_status();

void LP_Set_linkplay_hotspot_status (Linkplay_Hotspot_status_t hotspot_status);
Linkplay_Hotspot_status_t LP_Get_linkplay_hotspot_status();

void LP_Set_linkplay_rtc_year();
uint8_t LP_Get_linkplay_rtc_year();

void LP_Set_linkplay_rtc_month();
uint8_t LP_Get_linkplay_rtc_month();

void LP_Set_linkplay_rtc_day();
uint8_t LP_Get_linkplay_rtc_day();

void LP_Set_linkplay_rtc_hour();
uint8_t LP_Get_linkplay_rtc_hour();

void LP_Set_linkplay_rtc_minute();
uint8_t LP_Get_linkplay_rtc_minute();

void LP_Set_linkplay_rtc_second();
uint8_t LP_Get_linkplay_rtc_second();

void LP_Set_linkplay_rtc_weekday (LinkPlay_Weekday_t weekday);
LinkPlay_Weekday_t LP_Get_linkplay_rtc_weekday();

void LP_Set_linkplay_silent_firmware_update();
uint8_t LP_Get_linkplay_silent_firmware_update();

void LP_Set_linkplay_wireless_access_status (LinkPlay_Wireless_Status_t wireless_status);
LinkPlay_Wireless_Status_t LP_Get_linkplay_wireless_access_status();

void LP_send_linkplay_pic_volume(); 
void LP_set_pic_volume(uint8_t lp_volume); 

void LP_Set_linkplay_access_points(); 
uint8_t LP_Get_linkplay_access_points();

void LP_get_pic_channel_config(); 

#endif
