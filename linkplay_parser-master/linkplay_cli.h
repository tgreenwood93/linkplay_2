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
void lp_set_ssid();
void lp_set_name();

#endif
