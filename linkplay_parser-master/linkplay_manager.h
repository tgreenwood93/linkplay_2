#include "Arduino.h"



#ifndef linkplay_manager_h
#define linkplay_manager_h

const uint8_t MCU_COMMANDS_LEN = 41;
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

typedef enum {
    e_linkplay_stored,
    e_linkplay_raw,
}linkplay_log_level_t;

const char mcu_commands[MCU_COMMANDS_LEN][13] = 
{
    "MCU+FACTORY\n", // 0
    "MCU+FCRYPOW\n",
    "MCU+WIF+WPS\n",
    "MCU+WIF+EPS\n",
    "MCU+WIF+WSS\n",
    "MCU+STA++ON\n", // 5
    "MCU+STA+OFF\n",
    "MCU+STA+DEL\n",
    "MCU+RA0++ON\n",
    "MCU+RA0+OFF\n",
    "MCU+STA+GET\n", // 10
    "MCU+ETH+GET\n",
    "MCU+WWW+GET\n",
    "MCU+RA0+GET\n",
    "MCU+RTC+GET\n",
    "MCU+WEK+GET\n", // 15
    "MCU+SND+RTC\n",
    "MCU+AP+SCAN\n", 
    "MCU+STA+INF\n",
    "MCU+PLM+GET\n",
    "MCU+USB+GET\n", // 20
    "MCU+MMC+GET\n",
    "MCU+PLY+PUS\n",
    "MCU+PLY-PUS\n",
    "MCU+PLY-PLA\n",
    "MCU+PLY-STP\n", // 25
    "MCU+PLY+PUQ\n",
    "MCU+PLY+NXT\n",
    "MCU+PLY+PRV\n",
    "MCU+PLY+GET\n",
    "MCU+PLP+GET\n", // 30
    "MCU+INF+GET\n",
    "MCU+PINFGET\n",
    "MCU+STA+INF\n", 
    "MCU+WEA+GET\n",
    "MCU+DEV+GET\n", // 35
    "MCU+MEA+GET\n",
    "MCU+MEA+GBK\n",
    "MCU+AIR++ON\n",
    "MCU+AIR+OFF\n",
    "MCU+AIR+GET\n", // 40
};

const char weekdays[7][11] = 
{
    "Sunday\n",
    "Monday\n",
    "Tuesday\n",
    "Wednesday\n",
    "Thursday\n",
    "Friday\n",
    "Saturday"
};

const char porject_name[]  =  {"MCU+CAP+PRJPSAUDIO_Stellar&"};
const char capabilities_ptv[]  =  {"MCU+PTV+000"};
const char capabilities_spot_brand[]  =  {"MCU+SPY+BRNPSAUDIO&"};
const char capabilities_spot_name[]  =  {"MCU+SPY+NAMStellar Integrated&"};
const char capabilities_spot_type[]  =  {"MCU+SPY+TYP0&"};
const char capabilities_one[]  =  {"MCU+CAP+00100001100&"};
const char capabilities_two[]  =  {"MCU+CAP+00200000800&"};
const char capabilities_lang[] =  {"MCU+CAP+LAUen_us&"};
const char capabilities_streaming[] = {"MCU+CAP+STMfffffffc&"};
const char capabilities_playback[] = {"MCU+CAP+PLM00000000&"};
const char num_hardware_buttons[] = {"MCU+PRESET+3&"};
const char stock_ssid[] = {"MCU+SID+Stellar Integrated&"};

const char connection_status[2][13] = 
{
    "disconnected",
    "connected"
};

const char connection_yes_no[2][4] = 
{
    "no",
    "yes"
};

const char mute_status[][7] = 
{
    "mute",
    "unmute"
};

const char connetion_bool[][7] = 
{
    "true",
    "false"
};

const char connection_status_2[][9] = 
{
    "started",
    "stopped",
    "disabled"
};

const char connection_status_3[][12] = 
{
    "off",
    "on",
    "hidden",
    "not hidden"
};

const char wireless_status[][31] = {
    "failed to connect to ap\n",
    "successfully connected to ap!\n", 
    "connecting to ap...\n",
    "bad rssi\n",
    "wrong password\n",
    "wrong security type\n", 
    "can't find access point\n",
    "can't get ip address\n"
};


/* 
    "MCU+VER+version&"
    "MCU+UPGRADEstart&"
    "MCU+UPGRADErun:index&"      
    "MCU+UPGRADEerror:reason&"
    "MCU+AP+CONNapname:password&"
    "MCU+WCH+SETn&"
    "MCU+PWD+SETname&"
    "MCU+SID+SETssid&"
    "MCU+NAM+SETname&"
    "MCU+M2S+nnn"
    "MCU+S2M+nnn"
    "MCU+PLM-xxx"
    "MCU+PLP+xxx"
    "MCU+BYP+000"
    "MCU+BYP+001"
    "MCU+BYP+002"
*/

// ----------------------------------------------------------------------------
// Linkplay State Setters and Getters
// ----------------------------------------------------------------------------
void LP_Set_linkplay_firmware_update_status(LinkPlay_Firmware_Update_t update_status);
LinkPlay_Firmware_Update_t LP_Get_linkplay_firmware_update_status(); 

void LP_Set_linkplay_audio_channel_status(LinkPlay_Audio_Channel_Options_t channel_config);
LinkPlay_Audio_Channel_Options_t LP_Get_linkplay_audio_channel_status();

void LP_Set_linkplay_in_reset(bool linkplay_in_reset);
bool LP_Get_linkplay_in_reset();

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

void LP_Set_linkplay_firmware_release(uint32_t firmware_release);
uint32_t LP_Get_linkplay_firmare_release();

void LP_Set_linkplay_firmware_branch(char* firmware_branch);
char* LP_Get_linkplay_firmare_branch();

void LP_Set_linkplay_group(uint16_t group);
uint16_t LP_Get_linkplay_group();

void LP_Set_linkplay_verion_expierd(bool firmware_expierd);
bool LP_Get_linkplay_version_expierd();

void LP_Set_linkplay_internet_status (bool internet_status);
bool LP_Get_linkplay_internet_status();

void LP_Set_linkplay_uuid(char* uuid);
char* LP_Get_linkplay_uuid();

void LP_Set_linkplay_mac_address(char* mac_address);
char* LP_Get_linkplay_mac_address();

void LP_Set_linkplay_sta_mac_address(char* sta_mac_address);
char* LP_Get_linkplay_sta_mac_address();

void LP_Set_linkplay_time_zone(uint8_t time_zone);
uint8_t LP_Get_linkplay_time_zone();

void LP_Set_linkplay_network_status(uint8_t network_status);
uint8_t LP_Get_linkplay_network_status();

void LP_Set_linkplay_essid(char* router_ssid);
char* LP_Get_linkplay_essid();

void LP_Set_linkplay_wifi_ip(char* wifi_ip);
char* LP_Get_linkplay_wifi_ip();

void LP_Set_linkplay_ethernet_ip(char* etherent_ip);
char* LP_Get_linkplay_ethernet_ip();

void LP_Set_linkplay_hardware(char* hardware_module);
char* LP_Get_linkplay_hardware();

void LP_Set_linkplay_version_update(bool update_available);
bool LP_Get_linkplay_version_update();

void LP_Set_linkplay_new_version(uint16_t new_firmware_version);
uint16_t LP_Get_linkplay_new_version();

void LP_Set_linkplay_pic_firmware_verison(uint16_t pic_firmware_verison);
uint16_t LP_Get_linkplay_pic_firmware_verison();

void LP_Set_linkplay_pic_new_firmware_verison(uint16_t pic_new_firmware_verison);
uint16_t LP_Get_linkplay_pic_new_firmware_verison();

void LP_Set_linkplay_dsp_firmware_verison(uint16_t dsp_firmware_verison);
uint16_t LP_Get_linkplay_dsp_firmware_verison();

void LP_Set_linkplay_dsp_new_firmware_verison(uint16_t dsp_new_firmware_verison);
uint16_t LP_Get_linkplay_dsp_new_firmware_verison();

void LP_Set_linkplay_internal_server_port(char* internal_server_port);
char* LP_Get_linkplay_internal_server_port();

void LP_Set_linkplay_temp_uuid(char* temp_uuid);
char* LP_Get_linkplay_temp_uuid();

void LP_Set_linkplay_capl(uint16_t capl);
uint16_t LP_Get_linkplay_capl();

void LP_Set_linkplay_languages(uint8_t languages);
uint8_t LP_Get_linkplay_languages();

void LP_Set_linkplay_dsp_version(uint16_t dsp_version);
uint16_t LP_Get_linkplay_dsp_version();

void LP_Set_linkplay_steaming_settings(uint32_t streaming_settings);
uint32_t LP_Get_linkplay_steaming_settings();

void LP_Set_linkplay_streams(uint32_t streams);
uint32_t LP_Get_linkplay_streams();

void LP_Set_linkplay_region(uint16_t region);
uint16_t LP_Get_linkplay_region();

void LP_Set_linkplay_external(uint16_t external);
uint16_t LP_Get_linkplay_external();

void LP_Set_linkplay_preset_keys(uint8_t preset_keys);
uint8_t LP_Get_linkplay_preset_keys();

void LP_Set_linkplay_plm_support(uint8_t inf_plm_support);
uint8_t LP_Get_linkplay_plm_support();

void LP_Set_linkplay_spotify_active(bool spotify_active);
bool LP_Get_linkplay_spotify_active();

void LP_Set_linkplay_wifi_channel(uint16_t wifi_channel);
uint16_t LP_Get_linkplay_wifi_channel();

void LP_Set_linkplay_rssi(int16_t rssi);
int16_t LP_Get_linkplay_rssi();

void LP_Set_linkplay_battery(bool battery);
bool LP_Get_linkplay_battery();

void LP_Set_linkplay_battery_percent(uint8_t bat_percent);
uint8_t LP_Get_linkplay_battery_percent();

void LP_Set_linkplay_secure_mode(bool secure_mode);
bool LP_Get_linkplay_secure_mode();

void LP_Set_linkplay_upnp_version(uint16_t unpn_version);
uint16_t LP_Get_linkplay_upnp_version();

void LP_Set_linkplay_upnp_uuid(char* unpn_uuid);
char* LP_Get_linkplay_upnp_uuid();

void LP_Set_linkplay_pass_port(char* pass_port);
char* LP_Get_linkplay_pass_port();

void LP_Set_linkplay_communication_port(char* comm_port);
char* LP_Get_linkplay_communication_port();

void LP_Set_linkplay_firmware_update_hidden(bool firmware_update_hidden);
bool LP_Get_linkplay_firmware_update_hidden();

void LP_Set_linkplay_web_login_result(int16_t web_login_result);
int16_t LP_Get_linkplay_web_login_result();

void LP_Set_linkplay_ignore_talk_start(bool ignore_talk_start);
bool LP_Get_linkplay_ignore_talk_start();

void LP_Set_linkplay_silence_OTA_time(uint16_t ota_time);
uint16_t LP_Get_linkplay_silence_OTA_time();

void LP_Set_linkplay_iHeartRadio_new(bool iheartradio_new);
bool LP_Get_linkplay_iHeartRadio_new();

void LP_Set_linkplay_privacy_mode(bool privacy_mode);
bool LP_Get_linkplay_privacy_mode();

void LP_Set_linkplay_user1(char* user_1);
char* LP_Get_linkplay_user1();

void LP_Set_linkplay_user2(char* user_2);
char* LP_Get_linkplay_user2();

void LP_Set_linkplay_device_name(char* device_name);
char* LP_Get_linkplay_device_name();

void LP_Set_linkplay_sample_rate(Linkpaly_Sample_Rate_t sample_rate);
Linkpaly_Sample_Rate_t LP_Get_linkplay_sample_rate();

void LP_Set_linkplay_bit_depth(Linkpaly_Bit_Depth_t bit_depth);
Linkpaly_Bit_Depth_t LP_Get_linkplay_bit_depth();

void LP_Set_linkplay_communication_status();
uint8_t LP_Get_linkplay_communication_status();

void LP_Set_linkplay_title(char* title);
char* LP_Get_linkplay_title();

void LP_Set_linkplay_artist(char* artist);
char* LP_Get_linkplay_artist();

void LP_Set_linkplay_album(char* album);
char* LP_Get_linkplay_album();

void LP_Set_linkplay_song_time(uint32_t songtime_ms);
uint32_t LP_Get_linkplay_song_time();

void LP_Set_linkplay_microphones(uint8_t mic_status);
uint8_t LP_Get_linkplay_micrphones();

void LP_Set_linkplay_mute (Linkplay_Mute_Status_t mute_status);
Linkplay_Mute_Status_t LP_Get_linkplay_mute();

void LP_Set_linkplay_alarm(int16_t alarm_status);
int16_t LP_Get_linkplay_alarm();

void LP_Set_linkplay_playback_mode (LinkPlay_Playback_Mode_t playback_mode);
LinkPlay_Playback_Mode_t LP_Get_linkplay_playback_mode();

void LP_Set_linkplay_repeat_shuffle (LinkPlay_Shuffle_Repeat_Status_t shuffle_repeat_status);
LinkPlay_Shuffle_Repeat_Status_t LP_Get_linkplay_repeat_shuffle();

void LP_Set_linkplay_playback_status (Linkplay_Playback_Status_t playback_status);
Linkplay_Playback_Status_t LP_Get_linkplay_playback_status();

void LP_Set_linkplay_voice_promt(Linkplay_Voice_Prompt_t vprompt_status);
Linkplay_Voice_Prompt_t LP_Get_linkplay_voice_promt();

void LP_Set_linkplay_power_status(Linlplay_Power_Status_t power_status);
Linlplay_Power_Status_t LP_Get_linkplay_power_status();

void LP_Set_linkplay_hotspot_status (Linkplay_Hotspot_Status_t hotspot_status);
Linkplay_Hotspot_Status_t LP_Get_linkplay_hotspot_status();

void LP_Set_linkplay_hotspot_connections_status (Linkplay_Hotspot_Connections_Status_t hotspot_connections_status);
Linkplay_Hotspot_Connections_Status_t LP_Get_linkplay_hotspot_connections_status();

void LP_Set_linkplay_year(uint16_t year);
uint16_t LP_Get_linkplay_year();

void LP_Set_linkplay_month(uint8_t month);
uint8_t LP_Get_linkplay_month();

void LP_Set_linkplay_day(uint8_t day);
uint8_t LP_Get_linkplay_day();

void LP_Set_linkplay_hour(uint8_t hour);
uint8_t LP_Get_linkplay_hour();

void LP_Set_linkplay_minute(uint8_t minute);
uint8_t LP_Get_linkplay_minute();

void LP_Set_linkplay_second(uint8_t second);
uint8_t LP_Get_linkplay_second();

void LP_Set_linkplay_weekday (LinkPlay_Weekday_t weekday);
LinkPlay_Weekday_t LP_Get_linkplay_weekday();

void LP_Set_linkplay_silent_firmware_update(bool silent_firmware_update);
bool LP_Get_linkplay_silent_firmware_update();

void LP_Set_linkplay_wireless_access_status (LinkPlay_Wireless_Status_t wireless_status);
LinkPlay_Wireless_Status_t LP_Get_linkplay_wireless_access_status();

void LP_send_linkplay_pic_volume(); 
void LP_set_pic_volume(uint8_t lp_volume); 

void set_num_access_points(uint8_t num_aps);
uint8_t get_num_access_points(uint8_t num_aps);

void Linkplay_Set_wps_status(Linkplay_WPS_Status_t wps_status);
Linkplay_WPS_Status_t Linkplay_Set_wps_status();

void LP_Set_linkplay_access_points(uint8_t ap_num, char* ap); 
char* LP_Get_linkplay_access_points();

void LP_get_pic_channel_config(); 

void Set_meta_data_ready();
void Get_meta_data_ready();

void LP_Set_linkplay_ready_for_communication(bool ready);
bool LP_Set_linkplay_ready_for_communication();

#endif
