#include "Arduino.h"


#ifndef linkplay_command_processor_h
#define linkplay_command_processor_h

static const uint8_t max_wan_status = 2; 
static const uint8_t num_status_per_wan = 3; 
static const uint8_t data_offset = 3; 
static const uint8_t title_offset = 23; 
static const uint8_t artist_offset = 14; 
static const uint8_t album_offset = 13; 
static const uint8_t no_error  = 0; 


typedef enum
{
    e_firmware_updateing = 1,
    e_update_successful, 
    e_update_failed
} LinkPlay_Firmware_Update_t;

typedef enum 
{
      e_no_internet_connection = 0,
      e_connected_to_internet,
}Linkplay_Internet_Status_t;

typedef enum {
    e_none = 0,
    e_airplay = 1,
    e_DLNA = 2,
    e_thumb_drive = 42,
    e_line_in = 40,
    e_bluetooth = 41,
    e_optical = 43,
    e_rca = 44,
    e_coaxial = 45,
    e_mirror = 50,
    e_slave = 99,
}LinkPlay_Playback_Mode_t;

typedef enum {
    e_failed_to_connect = 0,
    e_succesfully_connected,
    e_connecting_to_ap,
    e_bad_rssi,
    e_wrong_password,
    e_wrong_security_type,
    e_cant_find_ap,
    e_failed_to_get_ip_address
  }LinkPlay_Wireless_Status_t;

typedef enum {
    e_stereo = 0,
    e_left_chan,
    e_right_chan,
 }LinkPlay_Audio_Channel_Options_t;

typedef enum {
    e_ethernet_disconnected = 0,
    e_ethernet_connected  
}Linkplay_Ethernet_Status_t;

typedef enum {
    e_sunday = 0,
    e_monday,
    e_tuesday,
    e_wednesday,
    e_thursday,
    e_friday,
    e_saturday,
}LinkPlay_Weekday_t;

typedef enum {
    e_repeat_all = 0,
    e_repeat_current,
    e_shuffle_repeat,
    e_shuffle_no_repeat
}LinkPlay_Shuffle_Repeat_Status_t;

typedef enum {
    e_hotspot_off = 0,
    e_hotspot_on
}Linkplay_Hotspot_status_t;

typedef enum {
    e_stopped_playback = 0,
    e_playback_started
}Linkplay_Playback_Status_t;


typedef enum {
    e_linkplay_unmute = 0,
    e_linkplay_mute
}Linkplay_Mute_Status_t;

enum {
    e_ap_ssid = 0,
    e_ap_rssi,
    e_ap_channel,
 };

enum {
    e_inf_language = 0,
    e_inf_ssid,
    e_inf_hide_ssid,
    e_inf_ssid_strategy,
    e_inf_link_play_fimrware,
    e_inf_build,                              // 5
    e_inf_project,
    e_inf_firmware_private_project,
    e_inf_firmware_release,
    e_inf_firmware_branch,
    e_inf_group,                              // 10
    e_inf_expired,
    e_inf_internet,
    e_inf_uuid,
    e_inf_mac,
    e_inf_sta_mac,                            // 15
    e_inf_date,
    e_inf_time,
    e_inf_tz,
    e_inf_netstat,
    e_inf_essid,                              // 20
    e_inf_apcli0,
    e_inf_eth2,
    e_inf_hardware,
    e_inf_version_update,
    e_inf_new_version,                        // 25
    e_inf_mcu_version,
    e_inf_mcu_new_version,
    e_inf_dsp_ver_new,
    e_inf_ra0,
    e_inf_temp_uuid,                          // 30
    e_inf_cap1,
    e_inf_capability,
    e_inf_languages,
    e_inf_dsp_ver,
    e_inf_streams_all,                        // 35
    e_inf_streams,
    e_inf_region,
    e_inf_external,
    e_inf_preset_key,
    e_inf_plm_support,                        // 40
    e_inf_spotify_active,
    e_inf_WifiChannel,
    e_inf_RSSI,
    e_inf_battery,
    e_inf_battery_percent,                    // 45
    e_inf_securemode,
    e_inf_upnp_version,
    e_inf_upnp_uuid,
    e_inf_uart_pass_port,
    e_inf_communication_port,                 // 50
    e_inf_web_firmware_update_hide,
    e_inf_web_login_result,
    e_inf_ignore_talkstart,
    e_inf_silenceOTATime,
    e_inf_ignore_silenceOTATime,              // 55
    e_inf_iheartradio_new,
    e_inf_privacy_mode,
    e_inf_user1,
    e_inf_user2,
    e_inf_DeviceName,                         // 60
    e_inf_GroupName,
};

void processCommand(char* msgAddr);
uint8_t process_linkplay_commands(char* linkplay_command);

uint8_t process_b_commands(char* linkplay_command);
uint8_t process_c_commands(char* linkplay_command);
uint8_t process_d_commands(char* linkplay_command);
uint8_t process_e_commands(char* linkplay_command);
uint8_t process_f_commands(char* linkplay_command);
uint8_t process_g_commands(char* linkplay_command);
uint8_t process_i_commands(char* linkplay_command);
uint8_t process_k_commands(char* linkplay_command);
uint8_t process_l_commands(char* linkplay_command);
uint8_t process_m_commands(char* linkplay_command);
uint8_t process_n_commands(char* linkplay_command);
uint8_t process_p_commands(char* linkplay_command);
uint8_t process_r_commands(char* linkplay_command);
uint8_t process_s_commands(char* linkplay_command);
uint8_t process_v_commands(char* linkplay_command);
uint8_t process_v_commands(char* linkplay_command);
uint8_t process_w_commands(char* linkplay_command);

uint8_t process_bur_command(char* linkplay_command);                    // Linkplay firmware updating commands
uint8_t process_bot_command(char* linkplay_command);                    // Linkplay firmware updating commands
uint8_t process_cap_command(char* linkplay_command);                    // Linkplay commands after factory reset
uint8_t process_chn_command(char* linkplay_command);                    // Linkplay channel information (stereo / mono left / mono right)
uint8_t process_dev_command(char* linkplay_command);                    // Linkplay device query commands
uint8_t process_eth_command(char* linkplay_command);                    // Linkplay ethernet commands
uint8_t process_fac_command(char* linkplay_command);                    // Linkplay factory reset commands
uint8_t process_get_command(char* linkplay_command);                    // Linkplay get commands
uint8_t process_inf_command(char* linkplay_command);                    // Linkplay i2s commands
uint8_t process_i2s_command(char* linkplay_command);                    // Linkplay i2s commands
uint8_t process_key_command(char* linkplay_command);                    // Linkplay key (button press) commands
uint8_t process_led_command(char* linkplay_command);                    // Linkplay factory teset commands
uint8_t process_mcu_command(char* linkplay_command);                    // Linkplay queries of our microprocessor
uint8_t process_mea_command(char* linkplay_command);                    // Linkplay meadia metadata commands
uint8_t process_mic_command(char* linkplay_command);                    // Linkplay process microphone commands
uint8_t process_mut_command(char* linkplay_command);                    // Linkplay command to mute audio
uint8_t process_m2s_command(char* linkplay_command);                    // Linkplay master to slave command pass through
uint8_t process_nxt_command(char* linkplay_command);                    // Linkplay alarm commands
uint8_t process_plm_command(char* linkplay_command);                    // Linkplay playback mode commands
uint8_t process_plp_command(char* linkplay_command);                    // Linkplay repeat mode commands
uint8_t process_ply_command(char* linkplay_command);                    // Linkplay playback commands
uint8_t process_pmt_command(char* linkplay_command);                    // Linkplay voice prompt commands
uint8_t process_pow_command(char* linkplay_command);                    // Linkplay power commands
uint8_t process_ra0_command(char* linkplay_command);                    // Linkplay wifi access point information commands
uint8_t process_set_command(char* linkplay_command);                    // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
uint8_t process_sli_command(char* linkplay_command);
uint8_t process_sta_command(char* linkplay_command);                    // Linkplay wireless status commands
uint8_t process_s2m_command(char* linkplay_command);                    // Linkplay slave to master command pass through
uint8_t process_uid_command(char* linkplay_command);                    // Linkplay uuid commands
uint8_t process_vol_command(char* linkplay_command);                    // Linkplay volume adjusting commands
uint8_t process_wan_command(char* linkplay_command);                    // Linkplay wireless acress points 
uint8_t process_wps_command(char* linkplay_command);                    // Linkplay wireless WPS config commands
uint8_t process_www_command(char* linkplay_command);                    // Linkplay internet connection commands

uint16_t linkplay_command_data_extraction(char* linkplay_command);

int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t charArrayLength);

uint8_t inf_command_parser(uint16_t current_inf, char* char_buf);

#endif
