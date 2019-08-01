#include "linkplay_cli.h"
#include <stdarg.h>
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

static bool linkplay_bypass_status = false;
static bool push_ap_data = false;
static bool linkplay_check_name_status = false;

void Linkplay_Debug_Printf(char* message, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
    if (false == Get_linkplay_bypass_status())
        return;
    
    va_start(args, message);
    
    writebuf_len = vsprintf(writebuf, message, args);
    Debug_Print(writebuf);
}

void Linkplay_Printf(char* message, ...)
{
    va_list args;
    char    writebuf[100];
    int     writebuf_len = 0;
    
    va_start(args, message);
    
    writebuf_len = vsprintf(writebuf, message, args);
    Linkplay_Print(writebuf);
}


void Linkplay_Print(char* message)
{
    Serial1.print(message);
   /* uint16_t i = 0;
    
    if (strlen(buf) > 100)
        return;
    
    // Push to transmit queue. If the buffer wraps, old data will be discarded.
    for (i=0; i<strlen(buf); i++)
        qPush(&qDbgTxBuffer, &buf[i]);
        
    // Kick off the transmit interrupt
    _Linkplay_TransmitWriteBuffer();*/
}

void Set_linkplay_bypass_status(bool status)
{
    linkplay_bypass_status = status;
}

bool Get_linkplay_bypass_status()
{
    return linkplay_bypass_status;
}

void dump_stored_linkplay_data()
{
    Debug_Printf("Linkplay system information\n");
    Debug_Printf("linkplay firmware update status: %d\n", (uint8_t)LP_Get_linkplay_firmware_update_status());
    Debug_Printf("linkplay audio channel status: %d\n", (uint8_t)LP_Get_linkplay_audio_channel_status());
    Debug_Printf("linkplay in reset?: %s\n", connection_yes_no[LP_Get_linkplay_in_reset()]);
    Debug_Printf("internet status: %s\n", connection_status[(uint8_t)LP_Get_linkplay_internet_status()]);
    Debug_Printf("playback mode: %d\n", (uint8_t)LP_Get_linkplay_playback_mode());
    Debug_Printf("wireless access status: %d\n", (uint8_t)LP_Get_linkplay_wireless_access_status());
    Debug_Printf("ethernet access status: %d\n", (uint8_t)LP_Get_linkplay_ethernet_status());
    Debug_Printf("repeat/shuffle status: %d\n", (uint8_t)LP_Get_linkplay_repeat_shuffle());
    Debug_Printf("hotspot status: %d\n", (uint8_t)LP_Get_linkplay_hotspot_status());
    Debug_Printf("hotspot connection status: %d\n", (uint8_t)LP_Get_linkplay_hotspot_connections_status());
    Debug_Printf("playback status: %d\n", (uint8_t)LP_Get_linkplay_playback_status());
    Debug_Printf("mute status: %d\n", (uint8_t)LP_Get_linkplay_mute());
    Debug_Printf("in factory reset?: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_factory_status()]);
    Debug_Printf("ssid: %s\n", LP_Get_linkplay_ssid());
    Debug_Printf("language: %d\n", (uint8_t)LP_Get_linkplay_language());
    Debug_Printf("ssid hidden: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_ssid_hidden()]);
    Debug_Printf("ssid strategy: %d\n", (uint8_t)LP_Get_linkplay_ssid_strategy());
    Debug_Printf("firmware version: %s\n", LP_Get_linkplay_firmware_version());
    Debug_Printf("build: %s\n", LP_Get_linkplay_build());
    Debug_Printf("project: %s\n", LP_Get_linkplay_project());
    Debug_Printf("private project: %s\n", LP_Get_linkplay_private_project());
    Debug_Printf("firmware type: %d\n", LP_Get_linkplay_firmare_release());
    Debug_Printf("branch: %s\n", LP_Get_linkplay_firmare_branch());
    Debug_Printf("group: %d\n", LP_Get_linkplay_group());
    Debug_Printf("version is expiered: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_version_expierd()]);
    Debug_Printf("uuid: %s\n", LP_Get_linkplay_uuid());
    Debug_Printf("mac: %s\n", LP_Get_linkplay_mac_address());
    Debug_Printf("sta mac: %s\n", LP_Get_linkplay_sta_mac_address());
    Debug_Printf("time zone: %d\n", LP_Get_linkplay_time_zone());
    Debug_Printf("network status: %s\n", (uint8_t)LP_Get_linkplay_network_status());
    Debug_Printf("essid: %s\n", LP_Get_linkplay_essid());
    Debug_Printf("wifi ip: %s\n", LP_Get_linkplay_wifi_ip());
    Debug_Printf("ethernet ip: %s\n", LP_Get_linkplay_ethernet_ip());
    Debug_Printf("linkplay hardware: %s\n", LP_Get_linkplay_hardware());
    Debug_Printf("version update: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_version_update()]);
    Debug_Printf("new linkplay version: %d\n", LP_Get_linkplay_new_version());
    Debug_Printf("pic firmware version: %d\n", LP_Get_linkplay_pic_firmware_verison());
    Debug_Printf("pic new firmware version: %d\n", LP_Get_linkplay_pic_new_firmware_verison());
    Debug_Printf("dsp firmware: %d\n", LP_Get_linkplay_dsp_firmware_verison());
    Debug_Printf("dsp new firmware: %d\n", LP_Get_linkplay_dsp_new_firmware_verison());
    Debug_Printf("internal server port: %s\n", LP_Get_linkplay_internal_server_port());
    Debug_Printf("temp uuid: %s\n", LP_Get_linkplay_temp_uuid());
    Debug_Printf("capl: %d\n", LP_Get_linkplay_capl());
    Debug_Printf("linkplay languages: %d\n", LP_Get_linkplay_languages());
    Debug_Printf("dsp version: %d\n", LP_Get_linkplay_dsp_version());
    Debug_Printf("streaming settings: %d\n", LP_Get_linkplay_steaming_settings());
    Debug_Printf("streams: %d\n", LP_Get_linkplay_streams());
    Debug_Printf("region: %d\n", LP_Get_linkplay_region());
    Debug_Printf("external: %d\n", LP_Get_linkplay_external());
    Debug_Printf("reset keys: %d\n", LP_Get_linkplay_preset_keys());
    Debug_Printf("plm support: %d\n", LP_Get_linkplay_plm_support());
    Debug_Printf("spotify active: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_spotify_active()]);
    Debug_Printf("wifi chann: %d\n", LP_Get_linkplay_wifi_channel());
    Debug_Printf("rssi: %d\n", LP_Get_linkplay_rssi());
    Debug_Printf("batt: %s battery\n", connection_yes_no[(uint8_t)LP_Get_linkplay_battery()]);
    Debug_Printf("batt percent: %d\n", LP_Get_linkplay_battery_percent());
    Debug_Printf("secure mode: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_secure_mode()]);
    Debug_Printf("unpn version: %d\n", LP_Get_linkplay_upnp_version());
    Debug_Printf("unpn uuid: %s\n", LP_Get_linkplay_upnp_uuid());
    Debug_Printf("pass port: %s\n", LP_Get_linkplay_pass_port());
    Debug_Printf("comm port: %s\n", LP_Get_linkplay_communication_port());
    Debug_Printf("firmware update hidden: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_firmware_update_hidden()]);
    Debug_Printf("web login result: %d\n", LP_Get_linkplay_web_login_result());
    Debug_Printf("ignore talk start: %d\n", (uint8_t)LP_Get_linkplay_ignore_talk_start());
    Debug_Printf("silence ota time: %d\n", LP_Get_linkplay_silence_OTA_time());
    Debug_Printf("iHeartRadio new: %d\n", (uint8_t)LP_Get_linkplay_iHeartRadio_new());
    Debug_Printf("privacy mode: %d\n", (uint8_t)LP_Get_linkplay_privacy_mode());
    Debug_Printf("user1: %s\n", LP_Get_linkplay_user1());
    Debug_Printf("user2: %s\n", LP_Get_linkplay_user2());
    Debug_Printf("device name: %d\n", LP_Get_linkplay_device_name());
    Debug_Printf("sample rate: %d\n", (uint32_t)LP_Get_linkplay_sample_rate());
    Debug_Printf("bit depth: %d\n", (uint8_t)LP_Get_linkplay_bit_depth());
    Debug_Printf("comm status: %d\n", LP_Get_linkplay_communication_status());
    Debug_Printf("title: %s\n", LP_Get_linkplay_title());
    Debug_Printf("artist: %s\n", LP_Get_linkplay_artist());
    Debug_Printf("album: %s\n", LP_Get_linkplay_album());
    Debug_Printf("song time: %d\n", LP_Get_linkplay_song_time());
    Debug_Printf("microphone status: %d\n", LP_Get_linkplay_micrphones());
    Debug_Printf("alarm status: %d\n", LP_Get_linkplay_alarm());
    Debug_Printf("voice prompt: %d\n", LP_Get_linkplay_voice_promt());
    Debug_Printf("power status: %d\n", LP_Get_linkplay_power_status());
    Debug_Printf("year: %d\n", LP_Get_linkplay_year());
    Debug_Printf("month: %d\n", LP_Get_linkplay_month());
    Debug_Printf("day: %d\n", LP_Get_linkplay_day());
    Debug_Printf("hour: %d\n", LP_Get_linkplay_hour());
    Debug_Printf("minute: %d\n", LP_Get_linkplay_minute());
    Debug_Printf("second: %d\n", LP_Get_linkplay_second());
    Debug_Printf("weekday: %d\n", LP_Get_linkplay_weekday());
    Debug_Printf("silent firmware upgrade: %s\n", connection_yes_no[(uint8_t)LP_Get_linkplay_silent_firmware_update()]);
}


void get_IP()
{
    Debug_Printf("Linkplay IP addresses\n");
    Debug_Printf("wifi ip: %s\n", LP_Get_linkplay_wifi_ip());
    Debug_Printf("ethernet ip: %s\n", LP_Get_linkplay_wifi_ip());
}

void get_network_status()
{
    Debug_Printf("Linkplay network status\n");
    Debug_Printf("wireless access status: %d\n", (uint8_t)LP_Get_linkplay_wireless_access_status());
    Debug_Printf("ethernet access status: %d\n", (uint8_t)LP_Get_linkplay_ethernet_status());
    Debug_Printf("hotspot status: %d\n", (uint8_t)LP_Get_linkplay_hotspot_status());
    Debug_Printf("hotspot connection status: %d\n", (uint8_t)LP_Get_linkplay_hotspot_connections_status());
    Debug_Printf("ssid: %s\n", LP_Get_linkplay_ssid());
    Debug_Printf("ssid hidden: %d\n", (uint8_t)LP_Get_linkplay_ssid_hidden());
    Debug_Printf("ssid strategy: %d\n", (uint8_t)LP_Get_linkplay_ssid_strategy());
    Debug_Printf("mac: %s\n", LP_Get_linkplay_mac_address());
    Debug_Printf("sta mac: %s\n", LP_Get_linkplay_sta_mac_address());
    Debug_Printf("network status: %d\n", (uint8_t)LP_Get_linkplay_network_status());
    Debug_Printf("essid: %s\n", LP_Get_linkplay_essid());
    Debug_Printf("wifi ip: %s\n", LP_Get_linkplay_wifi_ip());
    Debug_Printf("ethernet ip: %s\n", LP_Get_linkplay_ethernet_ip());
    Debug_Printf("wifi chann: %d\n", LP_Get_linkplay_wifi_channel());
    Debug_Printf("rssi: %d\n", LP_Get_linkplay_rssi());
}

void get_meta_data()
{
    Debug_Printf("Linkplay meta data\n");
    Debug_Printf("title: %s\n", LP_Get_linkplay_title());
    Debug_Printf("artist: %s\n", LP_Get_linkplay_artist());
    Debug_Printf("album: %s\n", LP_Get_linkplay_album());
    Debug_Printf("song time: %d\n", LP_Get_linkplay_song_time());
}

void get_last_rtc()
{
    Debug_Printf("Linkplay real time clock\n");
    Debug_Printf("year: %d\n", LP_Get_linkplay_year());
    Debug_Printf("month: %d\n", LP_Get_linkplay_month());
    Debug_Printf("day: %d\n", LP_Get_linkplay_day());
    Debug_Printf("hour: %d\n", LP_Get_linkplay_hour());
    Debug_Printf("minute: %d\n", LP_Get_linkplay_minute());
    Debug_Printf("second: %d\n", LP_Get_linkplay_second());
    Debug_Printf("weekday: %d\n", LP_Get_linkplay_weekday());
}

void get_lp_version()
{
    Debug_Printf("Linkplay version\n");
    Debug_Printf("firmware version: %s\n", LP_Get_linkplay_firmware_version());
    Debug_Printf("firmware type: %s\n", LP_Get_linkplay_firmare_release());
    Debug_Printf("branch: %s\n", LP_Get_linkplay_firmare_branch());
}

void get_lp_pic_version()
{
    Debug_Printf("Linkplay pic version\n");
    Debug_Printf("pic firmware version: %d\n", LP_Get_linkplay_pic_firmware_verison());
    Debug_Printf("pic new firmware version: %d\n", LP_Get_linkplay_pic_new_firmware_verison());
}

void get_ap_ssid()
{   
    Debug_Printf("Linkplay connected ap\n");
    Debug_Printf("essid: %s\n", LP_Get_linkplay_essid());
}

void get_lp_ssid() 
{
    Debug_Printf("Linkplay internal ap\n");
    Debug_Printf("ssid: %s\n", LP_Get_linkplay_ssid());
}

void get_mac_address()
{
    Debug_Printf("Linkplay MAC addresses\n");
    Debug_Printf("mac: %s\n", LP_Get_linkplay_mac_address());
    Debug_Printf("sta mac: %s\n", LP_Get_linkplay_sta_mac_address());
}

void get_access_points()
{
    uint8_t i = 0;
    uint8_t num_aps = Linkplay_Get_num_aps();
    
    if (num_aps == 0)
    {
        Debug_Printf("Can't find any access points");
    }
    else
    {
        Debug_Printf("Found %d access points\n", num_aps);
        for (i = 0; i < num_aps; i++)
        {
            Debug_Printf("SSID: %s\nRSSI: %d\nChannel: %d\n", Linkplay_Get_visable_ssids(i), Linkplay_Get_ssid_rssi(i), Linkplay_Get_ssid_channel(i));
        }
    }
}

void lp_retrieve_rtc()
{
    Linkplay_Printf("%s", mcu_commands[14]);
}

void lp_retrieve_metadata()
{
    Linkplay_Printf("%s", mcu_commands[36]);
}

void lp_retrieve_system_info()
{
    Linkplay_Printf("%s", mcu_commands[31]);
}

void lp_set_ssid(char* lp_ssid)
{
    if (strlen(lp_ssid) > 32)
        return;

    Linkplay_Printf("MCU+SID+%s&\n",lp_ssid);
}


void lp_set_name(char* lp_name)
{
    if (strlen(lp_name) > 32)
        return;

    Linkplay_Printf("MCU+NAM+SET%s&\n",lp_name);
}

void lp_check_name(bool check_status)
{
    linkplay_check_name_status = check_status;
}

bool lp_check_name_incoming()
{    
    return linkplay_check_name_status;
}

void lp_activate_wps()
{ 
    Linkplay_Printf("%s", mcu_commands[2]);
}

void lp_deactivate_wps()
{
    Linkplay_Printf("%s", mcu_commands[3]);
}

void lp_activate_wifi()
{
    Linkplay_Printf("%s", mcu_commands[5]);
}

void lp_deactivate_wifi()
{
    Linkplay_Printf("%s", mcu_commands[6]);
}

void lp_forget_wifi()
{    
    Linkplay_Printf("%s", mcu_commands[7]);
}

void lp_activate_hotspot()
{    
    Linkplay_Printf("%s", mcu_commands[8]);
}

void lp_deactivate_hotspot()
{  
    Linkplay_Printf("%s", mcu_commands[9]);
}

void lp_play_next_track()
{ 
    Linkplay_Printf("%s", mcu_commands[27]);
}

void lp_play_previous_track()
{
    Linkplay_Printf("%s", mcu_commands[28]);
}

void lp_pause_track()
{
    Linkplay_Printf("%s", mcu_commands[23]);
}

void lp_play_track()
{
    Linkplay_Printf("%s", mcu_commands[24]);
}

void lp_stop_track()
{
    Linkplay_Printf("%s", mcu_commands[25]);
}

void lp_toggle_play_pause()
{
    Linkplay_Printf("%s", mcu_commands[22]);
}

void lp_factory_reset()
{
    Linkplay_Printf("%s", mcu_commands[0]);
}

void lp_scan_aps()
{
    Linkplay_Printf("%s", mcu_commands[17]);
    lp_push_ap_data(true);
}

void lp_push_ap_data(bool push_data)
{
    push_ap_data = push_data;
}

void lp_set_connap(char* lp_ap_pw)
{
    Linkplay_Printf("MCU+AP+CONN%s&\n", lp_ap_pw);
}
