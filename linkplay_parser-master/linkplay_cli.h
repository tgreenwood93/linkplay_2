#include "Arduino.h"


#ifndef linkplay_cli_h
#define linkplay_cli_h

void Linkplay_Debug_Printf(char* message, ...);
void Linkplay_Printf(char* message, ...);
void Linkplay_Print(char* message);

void Set_linkplay_bypass_status(bool status);
bool Get_linkplay_bypass_status();

void dump_stored_linkplay_data(void);
void get_IP();
void get_network_status();
void get_meta_data();
void get_last_rtc();
void get_rtc();
void get_lp_version();
void get_lp_pic_version();
void get_ap_ssid();
void get_lp_ssid();
void get_mac_address();
void get_access_points();

void lp_retrieve_rtc();
void lp_retrieve_metadata();
void lp_retrieve_system_info();
void lp_set_ssid(char* lp_name);
void lp_set_name(char* lp_name);
void lp_check_name(bool check_status);
bool lp_check_name_incoming();
void lp_set_connap(char* lp_ap_pw);

void lp_activate_wps();
void lp_deactivate_wps();
void lp_activate_wifi();
void lp_deactivate_wifi();
void lp_forget_wifi();
void lp_activate_hotspot();
void lp_deactivate_hotspot();
void lp_play_next_track();
void lp_play_previous_track();
void lp_pause_track();
void lp_play_track();
void lp_stop_track();
void lp_toggle_play_pause();
void lp_factory_reset();
void lp_scan_aps();
void lp_push_ap_data(bool push_data);

#endif
