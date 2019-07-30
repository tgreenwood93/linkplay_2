<<<<<<< HEAD
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

void processCommand(char* linkplay_command)
{   
    LinkPlay_Error_t error_handler = e_no_error;
        
    if (strncmp(linkplay_command, "AXX", 3) == 0)
    {
        error_handler = process_linkplay_commands(linkplay_command);
    }
    else
    {  
        if (strlen(linkplay_command) < 5)
        {
            return; 
        }
        error_handler = e_unknown_AXX_command;
    }
    
    linkplay_error_handler(error_handler, linkplay_command);
}

 
LinkPlay_Error_t process_linkplay_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[4])
    {
        case 'B':
            error_handler = process_b_commands(linkplay_command);
            break;
        case 'C':
            error_handler = process_c_commands(linkplay_command);
            break;
        case 'D':
            error_handler = process_d_commands(linkplay_command);
            break;
        case 'E':
            error_handler = process_e_commands(linkplay_command);
            break;
        case 'F':
            error_handler = process_f_commands(linkplay_command);
            break;
        case 'G':
            error_handler = process_g_commands(linkplay_command);
            break;
        case 'I':
            error_handler = process_i_commands(linkplay_command);
            break;
        case 'K':
            error_handler = process_k_commands(linkplay_command);
            break;
        case 'L':
            error_handler = process_l_commands(linkplay_command);
            break;
        case 'M':
            error_handler = process_m_commands(linkplay_command);
            break;
        case 'N':
            error_handler = process_n_commands(linkplay_command);
            break;
        case 'P':
            error_handler = process_p_commands(linkplay_command);
            break; 
        case 'R':
            error_handler = process_r_commands(linkplay_command);
            break;
        case 'S':
            error_handler = process_s_commands(linkplay_command);
            break;
        case 'U':
            error_handler = process_v_commands(linkplay_command);
            break;
        case 'V':
            error_handler = process_v_commands(linkplay_command);
            break;
        case 'W':
            error_handler = process_w_commands(linkplay_command);
            break;
        default:
            error_handler =  e_unknown_command;
            break;
    }
    return error_handler; 
}
 
LinkPlay_Error_t process_b_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'O':
            error_handler = process_bot_command(linkplay_command);                      // Linkplay boot commnads
            break;
        case 'U':
            error_handler = process_bur_command(linkplay_command);                      // Linkplay firmware updating commands
            break;
        default:
            error_handler =  e_unknown_b_command;
            break;
    }
    return error_handler;     
}
 
LinkPlay_Error_t process_c_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_cap_command(linkplay_command);                      // Linkplay commands after factory reset
            break;
        case 'H':
            error_handler = process_chn_command(linkplay_command);                      // Linkplay channel information (stereo / mono left / mono right)
            break;
        default:
            error_handler =  e_unknown_c_command;
            break;
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_d_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error;
     
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_dev_command(linkplay_command);                      // Linkplay device query commands
            break;
        default:
            error_handler =  e_unknown_d_command;
            break;  
    }       
    return error_handler; 
}
 
LinkPlay_Error_t process_e_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error;
     
    switch (linkplay_command[5])
    {
        case 'T':
            error_handler = process_eth_command(linkplay_command);                      // Linkplay ethernet commands
            break;
        default:
            error_handler =  e_unknown_e_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_f_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_fac_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_f_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_g_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_get_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_g_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_i_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    { 
        case 'N':
            error_handler = process_inf_command(linkplay_command);                    // Linkplay i2s commands
            break;
        case '2':
            error_handler = process_i2s_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_i_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_k_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    { 
        case 'E':
            error_handler = process_key_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_k_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_l_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_led_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_l_command;
            break;  
    }    
    return error_handler;  
}
 
LinkPlay_Error_t process_m_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'C':
            error_handler = process_mcu_command(linkplay_command);                      // Linkplay queries of our microprocessor
            break;
        case 'E':
            error_handler = process_mea_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;
        case 'I':
            error_handler = process_mic_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;     
        case 'U':
            error_handler = process_mut_command(linkplay_command);                      // Linkplay command to mute audio
            break;
        case '2':
            error_handler = process_m2s_command(linkplay_command);                      // Linkplay master to slave command pass through
            break;        
        default:
            error_handler =  e_unknown_m_command;
            break;
    }    
    return error_handler; 
}

LinkPlay_Error_t process_n_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'X':
            error_handler = process_nxt_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_n_command;
            break;  
    }    
    return error_handler;  
}

LinkPlay_Error_t process_p_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[6])
    {
        case 'M':
            error_handler = process_plm_command(linkplay_command);                      // Linkplay playback mode commands
            break;
        case 'P':
            error_handler = process_plp_command(linkplay_command);                      // Linkplay repeat mode commands
            break;
        case 'T':
            error_handler = process_pmt_command(linkplay_command);
            break;
        case 'Y':
            error_handler = process_ply_command(linkplay_command);                      // Linkplay playback commands
            break;
        case 'W':
            error_handler = process_pow_command(linkplay_command);                      // Linkplay playback commands
            break;    
        default:
            error_handler =  e_unknown_p_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_r_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_ra0_command(linkplay_command);                      // Linkplay wifi access point information commands
            break;
        default:
            error_handler =  e_unknown_r_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_s_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_set_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case 'L':
            error_handler = process_sli_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case 'T':
            error_handler = process_sta_command(linkplay_command);                      // Linkplay wireless status commands
            break;
        case '2':
            error_handler = process_s2m_command(linkplay_command);                      // Linkplay slave to master command pass through
            break;  
        default:
            error_handler = e_unknown_s_command;
            break;
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_v_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'O':
            error_handler = process_vol_command(linkplay_command);                      // Linkplay volume adjusting commands
            break;
        default:
            error_handler =  e_unknown_v_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_w_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_wan_command(linkplay_command);
            break;
        case 'P':
            error_handler = process_wps_command(linkplay_command);                      // Linkplay wireless WPS config commands
            break;  
        case 'W':
            error_handler = process_www_command(linkplay_command);                      // Linkplay internet connection commands
            break;  
        default:
            error_handler = e_unknown_w_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_bot_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
    if (strncmp((linkplay_command + 8), "DON", 3) == 0)
    {   
        Linkplay_Log(e_linkplay_raw, "Linkplay is done booting. This is also the heartbeat command");
        return e_no_error;
    }
    else if (strncmp((linkplay_command + 8), "UP0", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay is done booting. This one time command acknowledges that");
        return e_no_error;  
    }
    return e_unknown_bot_command;
}


LinkPlay_Error_t process_bur_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
/*
        "AXX+BURNING"                                                   // wifi is updating firmware
        "AXX+BURN002"                                                   // wifi update was succesful
        "AXX+BURN003"                                                   // WiFi update failed
*/
    switch(linkplay_command[10])
    {
        case 'G':
            Linkplay_Log(e_linkplay_raw, "Linkplay is updating its firmware!");
            LP_Set_linkplay_firmware_update_status(e_firmware_updateing);
            break;
        case '2':
            Linkplay_Log(e_linkplay_raw, "Linkplay firmware update successful");
            LP_Set_linkplay_firmware_update_status(e_update_successful);
            break;
        case '3':
            Linkplay_Log(e_linkplay_raw, "Linkplay firmware update failed!");
            LP_Set_linkplay_firmware_update_status(e_update_failed); 
            break;  
        default:
            return e_unknown_bur_command;
            break;
    }     
    return e_no_error;   
}
 
LinkPlay_Error_t process_cap_command(char* linkplay_command)                   // Linkplay commands after factory reset
{   /*
        "AXX+CAP+GET"                                                   // command on the first boot after a factory reset. The returned information will be saved permanently.
    */
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay booted after factory reset,\nsending PSA branding and default settings");
        Serial1.println("MCU+CAP+PRJPSAUDIO_Stellar&");
        Serial1.println("MCU+PTV+000");
        Serial1.println("MCU+SPY+BRNPSAUDIO&");
        Serial1.println("MCU+SPY+NAMStellarIntegrated&");
        Serial1.println("MCU+SPY+TYP0&");
        Serial1.println("MCU+CAP+00100001100&");
        Serial1.println("MCU+CAP+00200000800&");
        Serial1.println("MCU+CAP+LAUen_us&");
        
        Serial1.println("MCU+CAP+STMfffffffc&");
        Serial1.println("MCU+CAP+PLM00000000&");
        Serial1.println("MCU+PRESET+3&");
        return e_no_error;
    }
    return e_unknown_cap_command;
}
 
LinkPlay_Error_t process_chn_command(char* linkplay_command)                    // Linkplay channel information (stereo / mono left / mono right)
{   /*
        "AXX+CHN+GET"                                                   // What is our output channel config set to?
        "AXX+CHN+nnn"                                                   // WiFi sends this command to update the channel information
                                                                        // 000 Stereo
                                                                        // 001 Left channel
                                                                        // 002 Right channel
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Retrieve output channel config: Stereo, Left, or Right");
        LP_get_pic_channel_config();
    }
    else if (linkplay_command[8] == '0')
    { 
        switch(linkplay_command_data_extraction(linkplay_command))
        {
          case e_stereo:
              Linkplay_Log(e_linkplay_raw, "audio is in stereo");
              LP_Set_linkplay_audio_channel_status(e_stereo);
              break;
          case e_left_chan:
              Linkplay_Log(e_linkplay_raw, "audio is only left chan");
              LP_Set_linkplay_audio_channel_status(e_left_chan);
              break;
          case e_right_chan:
              Linkplay_Log(e_linkplay_raw, "audio is only righ chan");
              LP_Set_linkplay_audio_channel_status(e_right_chan);
              break;
          default:
              error_handler = e_unknown_chan_config;
              break;
        }
        return error_handler; 
    }
    else
    {
        error_handler = e_unknown_chn_command;
    }
    
    return error_handler;
}
 
LinkPlay_Error_t process_dev_command(char* linkplay_command)                    // Linkplay device query commands
{
       // "AXX+DEV+RST"                                                   // MCU should NOT automatically reboot or power off WiFi module after updating the firmware.
                                                                        // It should wait for WiFi module to send AXX+DEV+RST or AXX+DEV+RST in case AXX+DEV+RST gets lost.
    if (strncmp((linkplay_command + 8), "RST", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "linkplay is resetting - stop polling it until it sends RDY command");
        LP_Set_linkplay_in_reset(true);
        return e_no_error;
    }

    return e_unknown_dev_command;  
}
 
LinkPlay_Error_t process_eth_command(char* linkplay_command)                    // Linkplay ethernet commands
{
    /*
        "AXX+ETH+xxx"                                                   // WiFi sends this command to update the Ethernet status to MCU,
                                                                        // or reply MCU's MCU+ETH+GET command where xxx is the status code
                                                                        // 000 Unplugged
                                                                        // 001 Plugged
                                                                        // FFF Disabled
    */
  
    LinkPlay_Error_t error_handler = e_no_error;

    if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Ethernet is disabled");
        return error_handler; 
    }
    else
    {     
        switch(linkplay_command_data_extraction(linkplay_command))
        {
            case e_ethernet_disconnected:
                Linkplay_Log(e_linkplay_raw, "Ethernet is disconnected");
                break;
            case e_ethernet_connected:
                Linkplay_Log(e_linkplay_raw, "Ethernet is connected!");
                break;
            default:
                error_handler = e_unknown_eth_command;
                break;
        }
    }
    return error_handler;
}
 
LinkPlay_Error_t process_fac_command(char* linkplay_command)                    // Linkplay factory reset commands
{
    //   "AXX+FACTORY"                                                 // WiFi sends this command to notify MCU that it is going to do a factory reset

    LinkPlay_Error_t error_handler = e_no_error; 

    if (strncmp((linkplay_command + 8), "ORY", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay is factory resetting.\nWaiting to send it default settings.");
    }
    else if (strncmp((linkplay_command + 8), "POW", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay is factory resetting.\nUnit is not power cycling.");
    }
    else
    {
        error_handler = e_unknown_fac_command;
    }

    return error_handler; 
}

LinkPlay_Error_t process_get_command(char* linkplay_command)
{

    if (strncmp((linkplay_command + 8), "SID", 3) == 0)
    {    
        Linkplay_Log(e_linkplay_raw, "Set SSID of linkplay");
        Serial1.println("MCU+SID+StellarIntegrated");
        return e_no_error;
    }

    return e_unknown_get_command; 
}

LinkPlay_Error_t process_inf_command(char* linkplay_command)                    // Linkplay inf commands
{ 
/*
        AXX+INF+INF{ "language": "en_us", "ssid": "LinkPlayA31_1CB8", "hideSSID": "1", "SSIDStrategy": "2", 
        "firmware": "3.8.5710", "build": "release", "project": "a31srcoutwm8918", "priv_prj": "a31srcoutwm8918", 
        "Release": "20180510", "branch": "stable\/wiimu-3.8", "group": "0", "expired": "0", "internet": "0", 
        "uuid": "FF3100368405108353A7AD6C", "MAC": "00:22:6C:68:1C:B8", "STA_MAC": "00:22:6C:68:1C:BA", 
        "date": "1970:01:01", "time": "00:27:42", "tz": "-7", "netstat": "0", "essid": "", "apcli0": "0.0.0.0",    //22
        "eth2": "0.0.0.0", "hardware": "A31", "VersionUpdate": "0", "NewVer": "0", "mcu_ver": "0", "mcu_ver_new": "0", 
        "dsp_ver_new": "0", "ra0": "10.10.10.254", "temp_uuid": "58F491488457B1B7", "cap1": "0x500", 
        "capability": "0x280800", "languages": "0x0", "dsp_ver": "", "streams_all": "0x7ffffffe", "streams": "0x7f9833fe", //37
        "region": "unknown", "external": "0x0", "preset_key": "6", "plm_support": "0x2", "spotify_active": "0", 
        "WifiChannel": "11", "RSSI": "0", "battery": "0", "battery_percent": "0", "securemode": "0", 
        "upnp_version": "1004", "upnp_uuid": "uuid:FF31F008-8405-1083-53A7-AD6CFF31F008", "uart_pass_port": "8899", 
        "communication_port": "8819", "web_firmware_update_hide": "0", "web_login_result": "-1", "ignore_talkstart": "0", 
        "silenceOTATime": "", "ignore_silenceOTATime": "1", "iheartradio_new": "1", "privacy_mode": "0", 
        "user1": "315:524", "user2": "5935:6291", "DeviceName": "Linkplay Demo", "GroupName": "Linkplay Demo" }&
*/  
    LinkPlay_Error_t error_handler = e_no_error; 
    uint16_t num_args = 1;
    uint16_t data_start_point = 0;
    uint16_t data_end_point = 0;
    char char_buf[100];    
    uint16_t command_length = strlen(linkplay_command);

    if (strncmp((linkplay_command + 8), "INF", 3) == 0)
    {  
        for (data_start_point = 12; data_start_point < command_length; data_start_point++)
        {
            if ((linkplay_command[data_start_point] == ':') && (linkplay_command[data_start_point-1] == '"'))
            {
                for (data_end_point = (data_start_point+data_offset); data_end_point < command_length; data_end_point++)
                {     
                    if ((linkplay_command[data_end_point] == '"') && (linkplay_command[data_end_point+1] == ','))
                    {
                        strncpy(char_buf, (linkplay_command+(data_start_point+data_offset)), (data_end_point-(data_start_point+data_offset)));
                        error_handler = inf_command_parser((num_args-1), char_buf);
                        memset(char_buf, ASCII_NUL, 100);
                        break;
                    }  
                }
                num_args ++;
            }
        }
        return error_handler; 
    }
    return e_unknown_inf_command;
}

LinkPlay_Error_t inf_command_parser(uint16_t current_inf, char* char_buf)
{
    switch (current_inf)
    {
        case e_inf_language:
            Linkplay_Log(e_linkplay_raw, "language: %s", char_buf);
           // Linkplay_Log(e_linkplay_raw, char_buf);
            if (strncmp(char_buf, "en_us", 5) == 0)
            {
                LP_Set_linkplay_language(e_linkplay_lang_en_us);
            }
            else
            {
                /* error wrong language! */
                Linkplay_Log(e_linkplay_raw, "Wrong language set!!");
            }
            break;
        case e_inf_ssid:
            Linkplay_Log(e_linkplay_raw, "ssid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_ssid(char_buf);
            break;
        case e_inf_hide_ssid:
            Linkplay_Log(e_linkplay_raw, "hide ssid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_ssid_hidden(atoi(char_buf));
            break;
        case e_inf_ssid_strategy:
            Linkplay_Log(e_linkplay_raw, "ssid strategy: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_ssid_strategy(atoi(char_buf));
            break;
        case e_inf_link_play_fimrware:
            Linkplay_Log(e_linkplay_raw, "linkplay firmware: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_firmware_version(char_buf);
            break;
        case e_inf_build:
            Linkplay_Log(e_linkplay_raw, "linkplay build: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_build(char_buf);
            break;
        case e_inf_project:
            Linkplay_Log(e_linkplay_raw, "linkplay project: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_project(char_buf);
            break;
        case e_inf_firmware_private_project:
            Linkplay_Log(e_linkplay_raw, "linkplay private project: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_private_project(char_buf);
            break;
        case e_inf_firmware_release:
            Linkplay_Log(e_linkplay_raw, "linkplay firmware release: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_firmware_release(atoi(char_buf));
            break;
        case e_inf_firmware_branch:
            Linkplay_Log(e_linkplay_raw, "linkplay firmware branch: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_firmware_branch(char_buf);
            break;
        case e_inf_group:
            Linkplay_Log(e_linkplay_raw, "group: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_group(atoi(char_buf));
            break;
        case e_inf_expired:
            Linkplay_Log(e_linkplay_raw, "expired: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_verion_expierd(atoi(char_buf));
            break;
        case e_inf_internet:
            Linkplay_Log(e_linkplay_raw, "internet status: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_internet_status(atoi(char_buf));
            break;
        case e_inf_uuid:
            Linkplay_Log(e_linkplay_raw, "uuid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_uuid(char_buf);
            break;
        case e_inf_mac:
            Linkplay_Log(e_linkplay_raw, "mac address: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_mac_address(char_buf);
            break;
        case e_inf_sta_mac:
            Linkplay_Log(e_linkplay_raw, "sta mac address: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_sta_mac_address(char_buf);
            break;
        case e_inf_date:
            Linkplay_Log(e_linkplay_raw, "date: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            process_date(char_buf);
            break;
        case e_inf_time:
            Linkplay_Log(e_linkplay_raw, "time: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            process_time(char_buf);
            break;
        case e_inf_tz:
            Linkplay_Log(e_linkplay_raw, "time zone: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_time_zone(atoi(char_buf));
            break;
        case e_inf_netstat:
            Linkplay_Log(e_linkplay_raw, "network status: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_network_status(atoi(char_buf));
            break;
        case e_inf_essid:
            Linkplay_Log(e_linkplay_raw, "essid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            process_essid(char_buf);
            break;
        case e_inf_apcli0:
            Linkplay_Log(e_linkplay_raw, "wifi IP: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_wifi_ip(char_buf);
            break;
        case e_inf_eth2:
            Linkplay_Log(e_linkplay_raw, "ethernet IP: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_ethernet_ip(char_buf);
            break;
        case e_inf_hardware:
            Linkplay_Log(e_linkplay_raw, "hardware: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_hardware(char_buf);
            break;
        case e_inf_version_update:
            Linkplay_Log(e_linkplay_raw, "version update: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_version_update(atoi(char_buf));
            break;
        case e_inf_new_version:
            Linkplay_Log(e_linkplay_raw, "new linkplay firmware version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            break;
        case e_inf_mcu_version:
            Linkplay_Log(e_linkplay_raw, "pic firmware version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_new_version(atoi(char_buf));
            break;
        case e_inf_mcu_new_version:
            Linkplay_Log(e_linkplay_raw, "pic new firmware version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_pic_new_firmware_verison(atoi(char_buf));
            break;
        case e_inf_dsp_ver_new:
            Linkplay_Log(e_linkplay_raw, "dsp new firmware version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_dsp_new_firmware_verison(atoi(char_buf));
            break;
        case e_inf_ra0:
            Linkplay_Log(e_linkplay_raw, "internal server IP: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_internal_server_port(char_buf);
            break;
        case e_inf_temp_uuid:
            Linkplay_Log(e_linkplay_raw, "temp uuid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_temp_uuid(char_buf);
            break;
        case e_inf_cap1:
            Linkplay_Log(e_linkplay_raw, "capl: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_capl(atoi(char_buf));
            break;
        case e_inf_capability:
            Linkplay_Log(e_linkplay_raw, "capability: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            
            break;
        case e_inf_languages:
            Linkplay_Log(e_linkplay_raw, "language: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_languages(atoi(char_buf));
            break;
        case e_inf_dsp_ver:
            Linkplay_Log(e_linkplay_raw, "dsp version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_dsp_version(atoi(char_buf));
            break;
        case e_inf_streams_all:
            Linkplay_Log(e_linkplay_raw, "steaming settings: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_steaming_settings(atoi(char_buf));
            break;
        case e_inf_streams:
            Linkplay_Log(e_linkplay_raw, "streams: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_streams(hex2int(char_buf));
            break;
        case e_inf_region:
            Linkplay_Log(e_linkplay_raw, "region: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_region(hex2int(char_buf));
            break;
        case e_inf_external:
            Linkplay_Log(e_linkplay_raw, "external: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_external(atoi(char_buf));
            break;
        case e_inf_preset_key:
            Linkplay_Log(e_linkplay_raw, "preset key: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_preset_keys(atoi(char_buf));
            break;
        case e_inf_plm_support:
            Linkplay_Log(e_linkplay_raw, "plm support: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_plm_support(atoi(char_buf));
            break;
        case e_inf_spotify_active:
            Linkplay_Log(e_linkplay_raw, "spotify active: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_spotify_active(atoi(char_buf));
            break;
        case e_inf_WifiChannel:
            Linkplay_Log(e_linkplay_raw, "wifi channel: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_wifi_channel(atoi(char_buf));
            break;
        case e_inf_RSSI:
            Linkplay_Log(e_linkplay_raw, "rssi: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_rssi(atoi(char_buf));
            break;
        case e_inf_battery:
            Linkplay_Log(e_linkplay_raw, "battery: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_battery(atoi(char_buf));
            break;
        case e_inf_battery_percent:
            Linkplay_Log(e_linkplay_raw, "battery percent: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_battery_percent(atoi(char_buf));
            break;
        case e_inf_securemode:
            Linkplay_Log(e_linkplay_raw, "secure mode: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_secure_mode(atoi(char_buf));
            break;
        case e_inf_upnp_version:
            Linkplay_Log(e_linkplay_raw, "upnp version: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_upnp_version(atoi(char_buf));
            break;
        case e_inf_upnp_uuid:
            Linkplay_Log(e_linkplay_raw, "upnp uuid: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf + 5);
            LP_Set_linkplay_upnp_uuid(char_buf);
            break;
        case e_inf_uart_pass_port:
            Linkplay_Log(e_linkplay_raw, "pass port: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_pass_port(char_buf);
            break;
        case e_inf_communication_port:
            Linkplay_Log(e_linkplay_raw, "communication port: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_communication_port(char_buf);
            break;
        case e_inf_web_firmware_update_hide:
            Linkplay_Log(e_linkplay_raw, "firmware update hidden: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_firmware_update_hidden(atoi(char_buf));
            break;
        case e_inf_web_login_result:
            Linkplay_Log(e_linkplay_raw, "web login result: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_web_login_result(atoi(char_buf));
            break;
        case e_inf_ignore_talkstart:
            Linkplay_Log(e_linkplay_raw, "ignore talk start: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_ignore_talk_start(atoi(char_buf));
            break;
        case e_inf_silenceOTATime:
            Linkplay_Log(e_linkplay_raw, "silence OTA time: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            break;
        case e_inf_ignore_silenceOTATime:
            Linkplay_Log(e_linkplay_raw, "ignore silence OTA time: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_silence_OTA_time(atoi(char_buf));
            break;
        case e_inf_iheartradio_new:
            Linkplay_Log(e_linkplay_raw, "iHeartRadio new: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_iHeartRadio_new(atoi(char_buf));
            break;
        case e_inf_privacy_mode:
            Linkplay_Log(e_linkplay_raw, "privacy mode: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_privacy_mode(atoi(char_buf));
            break;
        case e_inf_user1:
            Linkplay_Log(e_linkplay_raw, "user1: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_user1(char_buf);
            break;
        case e_inf_user2:
            Linkplay_Log(e_linkplay_raw, "user2: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_user2(char_buf);
            break;
        case e_inf_DeviceName:
            Linkplay_Log(e_linkplay_raw, "device name: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            LP_Set_linkplay_device_name(char_buf);
            break;
        case e_inf_GroupName:
            Linkplay_Log(e_linkplay_raw, "group name: %s", char_buf);
            //Linkplay_Log(e_linkplay_raw, char_buf);
            break;
        default:
            break; 
    }
    return e_no_error;
}

void process_date(char* date)
{
    char c_current_year[6];
    char c_current_month[4];
    char c_current_day[4];

    memset(c_current_year, ASCII_NUL, 6); 
    memset(c_current_month, ASCII_NUL, 4); 
    memset(c_current_day, ASCII_NUL, 4); 

    strncpy(c_current_year, date, 4);
    strncpy(c_current_month, date+5, 2);
    strncpy(c_current_day, date+8, 2);
    
    LP_Set_linkplay_year(atoi(c_current_year));
    LP_Set_linkplay_month(atoi(c_current_month));
    LP_Set_linkplay_day(atoi(c_current_day));
}

void process_time(char* time)
{
    char c_current_hour[4];
    char c_current_minute[4];
    char c_current_second[4];

    memset(c_current_hour, ASCII_NUL, 4); 
    memset(c_current_minute, ASCII_NUL, 4); 
    memset(c_current_second, ASCII_NUL, 4); 

    strncpy(c_current_hour, time, 2);
    strncpy(c_current_minute, time+3, 2);
    strncpy(c_current_second, time+6, 2);
    
    LP_Set_linkplay_hour(atoi(c_current_hour));
    LP_Set_linkplay_minute(atoi(c_current_minute));
    LP_Set_linkplay_second(atoi(c_current_second));
}

void process_essid(char* hex_ap)
{           
    char ascii_ap[65];

    memset(ascii_ap, ASCII_NUL, 65); 
    hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
    LP_Set_linkplay_essid(ascii_ap);
}

LinkPlay_Error_t process_i2s_command(char* linkplay_command)
{
    // AXX+I2S+INF44100_16&
    char c_sample_rate[50];
    char c_bit_depth[50];
    uint8_t sample_rate_chars = 0; 
    uint16_t i = 0; 
    uint16_t off_set = 11; 
    
    
    if (strncmp((linkplay_command + 8), "INF", 3) == 0)
    {  
        if (linkplay_command[11] == '&')
        {
            return e_empty_i2s_command;  
        }
      
        for (i = off_set; i < strlen(linkplay_command); i++)
        {
            sample_rate_chars++; 
            if ((linkplay_command[i] == '_') || (linkplay_command[i] == '&'))
            {
                break; 
            }
        }
     
            strncpy(c_sample_rate,linkplay_command+11, sample_rate_chars);
            switch(atoi(c_sample_rate))
            {
                case e_linkplay_44100:
                    Linkplay_Log(e_linkplay_raw, "44.1 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_44100);
                    break;
                case e_linkplay_48000:
                    Linkplay_Log(e_linkplay_raw, "48 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_48000);
                    break;
                case e_linkplay_88200:
                    Linkplay_Log(e_linkplay_raw, "88.2 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_88200);
                    break;
                case e_linkplay_96000:
                    Linkplay_Log(e_linkplay_raw, "96 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_96000);
                    break;
                case e_linkplay_176400:
                    Linkplay_Log(e_linkplay_raw, "176.4 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_176400);
                    break;
                case e_linkplay_192000:
                    Linkplay_Log(e_linkplay_raw, "192.2 k");
                    LP_Set_linkplay_sample_rate(e_linkplay_192000);
                    break;
            }
    
            strncpy(c_bit_depth,linkplay_command+(11+sample_rate_chars), 2);
            Linkplay_Log(e_linkplay_raw, atoi(c_bit_depth));

            switch (atoi(c_bit_depth))
            {
                case e_linkplay_16:
                    Linkplay_Log(e_linkplay_raw, "%s", e_linkplay_16);
                    LP_Set_linkplay_bit_depth(e_linkplay_16);
                    break;
                case e_linkplay_24:
                    Linkplay_Log(e_linkplay_raw, "%s",  e_linkplay_24);
                    LP_Set_linkplay_bit_depth(e_linkplay_24);
                    break;
                default: 
                    break;
            }

            Linkplay_Log(e_linkplay_raw, " bit");
            return e_no_error;
    }
    return e_unknown_i2s_command; 
}

LinkPlay_Error_t process_key_command(char* linkplay_command)
{

    return e_unknown_key_command; 
}

LinkPlay_Error_t process_led_command(char* linkplay_command)                     // Linkplay factory teset commands
{
    //  "AXX+LED+TES"                                                   // Notify MCU that the module is in factory test mode
    Linkplay_Log(e_linkplay_raw, "Linkplay is in test mode. flashing LEDs (not hooked up)");
    return e_no_error;
}
 
LinkPlay_Error_t process_mcu_command(char* linkplay_command)                     // Linkplay queries of our microprocessor
{
    /*  
        "AXX+MCU+VER"                                                   // command to check MCU frimware version"
        "AXX+MCU+UPDversion:len:name&"                                  // command to request a MCU firmware upgrade, where version is the new version number,
                                                                        // len is the total length and name is the project name.
        "AXX+MCU+RUNindex:len:data&"                                    // command where index is the index of firmware packet, ranging from 000 to 999,
                                                                        // len is the length of this packet, usually 1024, and data is the actual data.
                                                                        // Data is sent as is, except special bytes, including '\0', '&', '0', '+'.
                                                                        // The first 4-byte is the check-sum, sent in little endian format.
                                                                        // Special bytes  '\0', '&', '0', '+' are converted as follows
                                                                        // '\0' -> "01"
                                                                        // '&' -> "02"
                                                                        // '0' -> "00"
                                                                        // '+' -> "03
    */
        
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay is ready for communication!");
        LP_Set_linkplay_ready_for_communication(true);
        return e_no_error;
    }
    else if (strncmp((linkplay_command + 8), "VER", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Send PIC firmware version ex: 0119");;
        Serial1.println("MCU+VER+0119&");
        return e_no_error;
    }
    
    return e_unknown_mcu_command;
}
 
LinkPlay_Error_t process_mea_command(char* linkplay_command)                    // Linkplay meadia metadata commands
{
    /*
        "AXX+MEA+RDY"                                                   // Notify MCU that the WiFi module is ready to respond to MCU+MEA+GET
        "AXX+MEA+DAT(metadata)&"                                        // Update metadata, where metadata is a JSON message
         AXX+MEA+DAT{ "title": "49277665204C6561726E656420546F204C6F7665204D7973656C66", "artist": "6C65746C6976652E", "album": "49662049276D2054686520446576696C2E2E2E", "vendor": "" }&

    */
    // linkplay song titles can only be 64 chars

    
    char hex_title[70];
    char hex_artist[70];
    char hex_album[70];
    
    char ascii_title[70];
    char ascii_artist[70];
    char ascii_album[70];
    
    uint16_t title_char_counter = 0; 
    uint16_t artist_char_counter = 0;     
    uint16_t album_char_counter = 0; 

    memset(hex_title, ASCII_NUL, 70);
    memset(hex_artist, ASCII_NUL, 70);    
    memset(hex_album, ASCII_NUL, 70);

    memset(ascii_title, ASCII_NUL, 70);
    memset(ascii_artist, ASCII_NUL, 70);    
    memset(ascii_album, ASCII_NUL, 70);
    
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "media is ready!");
        Serial1.write("MCU+MEA+GET");
        return e_no_error; 
    }
    else if (strncmp((linkplay_command + 8), "DAT", 3) == 0)
    {
        for(title_char_counter = title_offset; title_char_counter <= strlen(linkplay_command); title_char_counter++)
        {
            if (linkplay_command[title_char_counter] == '"')
            { 
                break; 
            }
        }
        strncpy(hex_title, (linkplay_command + title_offset), title_char_counter-title_offset);
        hex2ascii(hex_title, ascii_title, strlen(hex_title), strlen(ascii_title));
        Linkplay_Log(e_linkplay_raw, "Title: "); Linkplay_Log(e_linkplay_raw, ascii_title);
        LP_Set_linkplay_title(ascii_title);

        for(artist_char_counter = (title_char_counter+artist_offset); artist_char_counter < 1024; artist_char_counter++)
        {
            if (linkplay_command[artist_char_counter] == '"')
            {
                break; 
            }
        }   
        strncpy(hex_artist, (linkplay_command + (title_char_counter+artist_offset)), (artist_char_counter - (title_char_counter+artist_offset)));
        hex2ascii(hex_artist, ascii_artist, strlen(hex_artist), strlen(ascii_artist));
        Linkplay_Log(e_linkplay_raw, "Artist: "); Linkplay_Log(e_linkplay_raw, ascii_artist);
        LP_Set_linkplay_artist(ascii_artist);


        for(album_char_counter = (artist_char_counter+album_offset); album_char_counter < 1024; album_char_counter++)
        {
            if (linkplay_command[album_char_counter] == '"')
            {
                break; 
            }
        }   
        strncpy(hex_album, (linkplay_command + (artist_char_counter+album_offset)), (album_char_counter - (artist_char_counter+album_offset))); 
        hex2ascii(hex_album, ascii_album, strlen(hex_album), strlen(ascii_album));
        Linkplay_Log(e_linkplay_raw, "Album: "); Linkplay_Log(e_linkplay_raw, ascii_album);
        LP_Set_linkplay_album(ascii_album);

        return e_no_error; 
    }
    else
    {
        return e_unknown_mea_command;
    }
}

LinkPlay_Error_t process_mic_command(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case 0: 
            Linkplay_Log(e_linkplay_raw, "Microphones turned off");
            LP_Set_linkplay_microphones(0);
            break;
        default: 
            error_handler =  e_unknown_mic_command; 
            break;
    }
    return error_handler;
}
 
LinkPlay_Error_t process_mut_command(char* linkplay_command)                    // Linkplay command to mute audio
{
    /*
        "AXX+MUT+000"                                                   // WiFi sends this command to request MCU to unmute the spekaer
        "AXX+MUT+001"                                                   // WiFi sends this command to request MCU to mute the speaker
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case e_linkplay_unmute:
            Linkplay_Log(e_linkplay_raw, "unmute output");
            LP_Set_linkplay_mute(e_linkplay_unmute);
            break; 
        case e_linkplay_mute:
            Linkplay_Log(e_linkplay_raw, "mute output");
            LP_Set_linkplay_mute(e_linkplay_mute);
            break; 
        default:
            error_handler = e_unknown_mut_command; 
            break;  
    }
    return error_handler;
}
 
LinkPlay_Error_t process_m2s_command(char* linkplay_command)                    // Linkplay master to slave command pass through
{
       // "AXX+M2S+nnn"                                                // When a pass-through session starts, slave speakers will receive AXX+M2S+nnn
       return e_unknown_m2s_command;
}

LinkPlay_Error_t process_nxt_command(char* linkplay_command)                    // Linkplay alarm commands
{
    // Not supporting alarm commands
        
    if (linkplay_command[11] == '-')
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay alarm feature is disabled");
        LP_Set_linkplay_alarm(-1);
        return e_no_error; 
    }
    
    return e_unknown_nxt_command;   
}

LinkPlay_Error_t process_plm_command(char* linkplay_command)                    // Linkplay playback mode commands
{
    /*
        "AAX+PLM+GET"
        "AXX+PLM+nnn"                                                   // WiFi sends this command to notify MCU mode switch, where nnn is defined below
                                                                        // 000 None
                                                                        // 001 Airplay
                                                                        // 002 DLNA
                                                                        // 010 to 019 A play list played by Wiimu protocol, where 011 means a play list for music stroed in USB disk,
                                                                        // 016 means a play list for music stored in T-Flash card
                                                                        // 020 to 029 A play list played by third party HTTP APIs, where 021 means a play list for music stroed in USB disk,
                                                                        // 026 means a play list for music stored in T-Flash card
                                                                        // 040 - Line in (aka Aux-In)
                                                                        // 041 - BT
                                                                        // 042 - External USB Disk or T-Flash
                                                                        // 043 - Optical
                                                                        // 044 - RCA
                                                                        // 045 - Coaxial
                                                                        // 050 - Mirror
                                                                        // 099 - Slave
    */
 
    LinkPlay_Error_t error_handler = e_no_error;
    
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Get PICs linkplay input selection");
    }
    else
    {
        switch(linkplay_command_data_extraction(linkplay_command))   
        {
            case e_none:
                Linkplay_Log(e_linkplay_raw, "no Linkplay input selected");
                LP_Set_linkplay_playback_mode(e_none);
                break;
            case e_airplay:
                Linkplay_Log(e_linkplay_raw, "Airplay input selected");
                LP_Set_linkplay_playback_mode(e_airplay);
                break;
            case e_DLNA:
                Linkplay_Log(e_linkplay_raw, "DLNA input selected");
                LP_Set_linkplay_playback_mode(e_DLNA);
                break;
            case e_thumb_drive:
                Linkplay_Log(e_linkplay_raw, "thumb drive input selected");
                LP_Set_linkplay_playback_mode(e_thumb_drive);
                break;
            case e_line_in:
                Linkplay_Log(e_linkplay_raw, "line-in input selected");
                LP_Set_linkplay_playback_mode(e_line_in);
                break;
            case e_bluetooth:
                Linkplay_Log(e_linkplay_raw, "bluetooth input selected");
                LP_Set_linkplay_playback_mode(e_bluetooth);
                break;
            case e_optical:
                Linkplay_Log(e_linkplay_raw, "optical input selected");
                LP_Set_linkplay_playback_mode(e_optical);
                break;
            case e_rca:
                Linkplay_Log(e_linkplay_raw, "rca input selected");
                LP_Set_linkplay_playback_mode(e_rca);
                break;
            case e_coaxial:
                Linkplay_Log(e_linkplay_raw, "coaxial Linkplay input selected");
                LP_Set_linkplay_playback_mode(e_coaxial);
                break;
            case e_mirror:
                Linkplay_Log(e_linkplay_raw, "mirror input selected");
                LP_Set_linkplay_playback_mode(e_mirror);
                break;
            case e_slave:
                Linkplay_Log(e_linkplay_raw, "slave input selected");
                LP_Set_linkplay_playback_mode(e_slave);
                break;
            default:
                error_handler = e_unknown_plm_command;
                break; 
        }
    }
    return error_handler;
}
 
LinkPlay_Error_t process_plp_command(char* linkplay_command)                    // Linkplay repeat mode commands
{
    /*
        "AXX+PLP+xxx"                                                   // WiFi sends this command to update the repeat mode, where xxx is
                                                                        // 000 Repeat all
                                                                        // 001 Repeat current
                                                                        // 002 Shuffle, repeat all
                                                                        // 003 Shuffle, no repeat
                                                                        // Other No repeat
    */
    // spotify doesn't trigger these messages. 
    
    LinkPlay_Error_t error_handler = e_no_error;

    switch (linkplay_command_data_extraction(linkplay_command))
    {
        case e_repeat_all:
            Linkplay_Log(e_linkplay_raw, "repeat all songs");
            LP_Set_linkplay_repeat_shuffle(e_repeat_all);
            break;
        case e_repeat_current:
            Linkplay_Log(e_linkplay_raw, "repeat all currnet song");
            LP_Set_linkplay_repeat_shuffle(e_repeat_current);
            break;
        case e_shuffle_repeat:
            Linkplay_Log(e_linkplay_raw, "shuffle and repeat playlist");
            LP_Set_linkplay_repeat_shuffle(e_shuffle_repeat);
            break;
        case e_shuffle_no_repeat:
            Linkplay_Log(e_linkplay_raw, "shuffle, no repeat");
            LP_Set_linkplay_repeat_shuffle(e_shuffle_no_repeat);
            break;  
        default:
            error_handler = e_unknown_plp_command; 
            break;
    }
    return error_handler;
}
 
LinkPlay_Error_t process_ply_command(char* linkplay_command)                    // Linkplay playback commands
{
    /*
        "AXX+PLY+xxx"                                                   // WiFi sends this command to update the playback status, where xxx is the status
                                                                        // 000 Stopped
                                                                        // 001 Playing
        AXX+PLY+POStime&                                                // current time in ms                                                                
    */
  
    char playback_time[50];
    uint16_t i = 0; 
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "POS", 3) == 0)
    {
        if (linkplay_command[11] != '&')
        {  
            for (i = 11; i < strlen(linkplay_command); i++)
            {
                if (linkplay_command[i] == '&')
                {
                    break;
                }
            }
            memset(playback_time, ASCII_NUL, 50);
            strncpy(playback_time, linkplay_command+11, (i-11));
            Linkplay_Log(e_linkplay_raw, atoi(playback_time));
            LP_Set_linkplay_song_time(atoi(playback_time));
        }
    }
    else if (linkplay_command[8] == '0')
    {
        switch (linkplay_command_data_extraction(linkplay_command))
        {
            case e_stopped_playback:
                Linkplay_Log(e_linkplay_raw, "playback stopped");
                LP_Set_linkplay_playback_status(e_stopped_playback);
                break;  
            case e_playback_started:
                Linkplay_Log(e_linkplay_raw, "playback started");
                LP_Set_linkplay_playback_status(e_playback_started);
                break;
            default: 
                error_handler = e_unknown_playback_status; 
        }
    }
    else 
    {
        error_handler = e_unknown_ply_command;
    }
    return error_handler;
}

LinkPlay_Error_t process_pmt_command(char* linkplay_command)                    // Linkplay voice prompt commands
{
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case e_voice_prompt_start: 
            Linkplay_Log(e_linkplay_raw, "voice prompt start");
            LP_Set_linkplay_voice_promt(e_voice_prompt_start);
            break;
        case e_voice_prompt_stopped:
            Linkplay_Log(e_linkplay_raw, "voice prompt stopped");
            LP_Set_linkplay_voice_promt(e_voice_prompt_stopped);
            break; 
        case e_voice_prompt_disabled:
            Linkplay_Log(e_linkplay_raw, "voice prompt disabled");
            LP_Set_linkplay_voice_promt(e_voice_prompt_disabled);
            break; 
        case e_voice_prompt_can_be_triggered: 
            Linkplay_Log(e_linkplay_raw, "voice prompt can be triggered by PIC");
            LP_Set_linkplay_voice_promt(e_voice_prompt_can_be_triggered);
            break;        
    }
    return e_no_error;
}

LinkPlay_Error_t process_pow_command(char* linkplay_command)                    // Linkplay wifi access point information commands
{
  /*
    AXX+POW+OFF 
    AXX+POW+xxx                     000 = normal
                                    001 = power saving mode
                                    002 = firmware upgrade - cants power down
                                    003 = the device is restarting
  */
    if (linkplay_command[8] == '0')
    {
        switch(linkplay_command_data_extraction(linkplay_command))
        {
            case e_linkplay_power_normal: 
                Linkplay_Log(e_linkplay_raw, "voice prompt start");
                LP_Set_linkplay_power_status(e_linkplay_power_normal);
                break;
            case e_linkplay_saving_mode:
                Linkplay_Log(e_linkplay_raw, "voice prompt stopped");
                LP_Set_linkplay_power_status(e_linkplay_saving_mode);
                break; 
            case e_linkplay_firmware_upgrade:
                Linkplay_Log(e_linkplay_raw, "voice prompt disabled");
                LP_Set_linkplay_power_status(e_linkplay_firmware_upgrade);
                break; 
            case e_linkplay_device_restarting: 
                Linkplay_Log(e_linkplay_raw, "voice prompt can be triggered by PIC");
                LP_Set_linkplay_power_status(e_linkplay_device_restarting);
                break;
            default:
                return e_unknown_pow_command;        
        }
        return e_no_error;
    }   
    else
    {
        return e_unknown_pow_command;
    }
     
}

LinkPlay_Error_t process_ra0_command(char* linkplay_command)                    // Linkplay wifi access point information commands
{
    /*
        "AXX+RA0+xxx"                                                   // WiFi sends this command to update its hotspot status to MCU,
                                                                        // or reply MCU's MCU+RA0+GET command where xxx is the status code
                                                                        // 000 No client
                                                                        // 001 New client connected
                                                                        // 002 One client disconnected but there are still some clients connected
                                                                        // FFF Hotspot is hidden
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "+ON", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay hotspot is on");
        LP_Set_linkplay_hotspot_status(e_hotspot_on);         
    }
    else if (strncmp((linkplay_command + 8), "OFF", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay hotspot is off");
        LP_Set_linkplay_hotspot_status(e_hotspot_off);         
    }
    else if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay hotspot is hidden");
        LP_Set_linkplay_hotspot_status(e_hotspot_hidden);
    }
    else if (strncmp((linkplay_command + 8), "FFE", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Linkplay hotspot is not hidden");
        LP_Set_linkplay_hotspot_status(e_hotspot_not_hidden);
    }
    else if (linkplay_command[8] == '0')
    {
        switch (linkplay_command_data_extraction(linkplay_command))
        {
            case 0:
                Linkplay_Log(e_linkplay_raw, "no devices connected");
                LP_Set_linkplay_hotspot_connections_status(e_no_devices_connected);
                break; 
            case 1:
                Linkplay_Log(e_linkplay_raw, "a new device has connected to the hotspot");
                LP_Set_linkplay_hotspot_connections_status(e_new_devices_has_connected);
                break;
            case 2:
                Linkplay_Log(e_linkplay_raw, "Some devices are disconnected,\nbut there are other devices connected");
                LP_Set_linkplay_hotspot_connections_status(e_some_devices_are_connected);
                break;   
            default:
                error_handler = e_unknown_connection_status;
                break;
        }       
    }
    else
    {
        error_handler = e_unknown_ra0_command; 
    }
    return error_handler;
}
 
LinkPlay_Error_t process_set_command(char* linkplay_command)                    // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
{
    /*   
        "AXX+SET+RTCYYYYMMDDHHMMSS&"                                    // Notify MCU the time change, where YYYYMMDDHHMMSS is the new time                           
        "AXX+SET+WEKn&"                                                 // Notify MCU the day of week, where n means Sun to Sat 0 - Sun 1 - Mon ... 6 - Sat
    */
    uint8_t day_of_the_week = 0;
    char c_day_of_the_week[2];
    
    char c_current_year[5];
    char c_current_month[5];
    char c_current_day[5];
    char c_current_hour[5];
    char c_current_minute[5];
    char c_current_second[5];
    
    if (strncmp((linkplay_command + 8), "RTC", 3) == 0)
    {
        strncpy(c_current_year, linkplay_command+11, 4);
        strncpy(c_current_month, linkplay_command+15, 2);
        strncpy(c_current_day, linkplay_command+17, 2);
        strncpy(c_current_hour, linkplay_command+19, 2);
        strncpy(c_current_minute, linkplay_command+21, 2);
        strncpy(c_current_second, linkplay_command+23, 2);

        Linkplay_Log(e_linkplay_raw, "current YYYY: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_year)); 
        LP_Set_linkplay_year(atoi(c_current_year));

        Linkplay_Log(e_linkplay_raw, "MM: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_month)); 
        LP_Set_linkplay_month(atoi(c_current_month));

        Linkplay_Log(e_linkplay_raw, "DD: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_day)); 
        LP_Set_linkplay_day(atoi(c_current_day));

        Linkplay_Log(e_linkplay_raw, "HH: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_hour)); 
        LP_Set_linkplay_hour(atoi(c_current_hour));

        Linkplay_Log(e_linkplay_raw, "MM: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_minute)); 
        LP_Set_linkplay_minute(atoi(c_current_minute));

        Linkplay_Log(e_linkplay_raw, "SS: ");
        Linkplay_Log(e_linkplay_raw, atoi(c_current_second)); 
        LP_Set_linkplay_second(atoi(c_current_second));
    }
    else if (strncmp((linkplay_command + 8), "WEK", 3) == 0)
    {
        strncpy(c_day_of_the_week, linkplay_command+11, 1);
        day_of_the_week = atoi(c_day_of_the_week);
        
        switch(day_of_the_week)
        {
            case e_sunday:
                Linkplay_Log(e_linkplay_raw, "Sunday");
                LP_Set_linkplay_weekday(e_sunday);
                break;
            case e_monday:
                Linkplay_Log(e_linkplay_raw, "Monday");
                LP_Set_linkplay_weekday(e_monday);
                break;
            case e_tuesday:
                Linkplay_Log(e_linkplay_raw, "Tuesday");
                LP_Set_linkplay_weekday(e_tuesday);
                break;
            case e_wednesday:
                Linkplay_Log(e_linkplay_raw, "Wednesday");
                LP_Set_linkplay_weekday(e_wednesday);
                break;
            case e_thursday:
                Linkplay_Log(e_linkplay_raw, "Thursday");
                LP_Set_linkplay_weekday(e_thursday);
                break;
            case e_friday:
                Linkplay_Log(e_linkplay_raw, "Friday");
                LP_Set_linkplay_weekday(e_friday);
                break;
            case e_saturday:
                Linkplay_Log(e_linkplay_raw, "Saturday");
                LP_Set_linkplay_weekday(e_saturday);
                break;
            default:
                break;
        }    
    }
    return e_no_error;
}

LinkPlay_Error_t process_sli_command(char* linkplay_command)   
{
    //AXX+SLI+OTA
    //AXX+SLI+DON
    return e_unknown_sli_command;
}
 
LinkPlay_Error_t process_sta_command(char* linkplay_command)                    // Linkplay wireless status commands
{
    /*
        "AXX+STA+000"                                                   // Failed to connect to the AP
        "AXX+STA+001"                                                   // Successfully connected to the AP
        "AXX+STA+002"                                                   // Connecting to the AP
        "AXX+STA+003"                                                   // Following the AXX+STA+000 command, indicating bad RSSI
        "AXX+STA+004"                                                   // Following the AXX+STA+000 command, indicating wrong password
        "AXX+STA+005"                                                   // Following the AXX+STA+000 command, indicating wrong security type
        "AXX+STA+006"                                                   // Following the AXX+STA+000 command, can't find (scan) AP
        "AXX+STA+007"                                                   // Following the AXX+STA+000 command, failed to get IP address from a DHCP server
    */
    uint16_t wireless_status = 0;
 
    wireless_status = linkplay_command_data_extraction(linkplay_command);
 
    switch(wireless_status)
    {
      case e_failed_to_connect:
          Linkplay_Log(e_linkplay_raw, "failed to connect to access point"); 
          LP_Set_linkplay_wireless_access_status(e_failed_to_connect);
          break;
      case e_succesfully_connected:
          Linkplay_Log(e_linkplay_raw, "successfully connected to access point!");  
          LP_Set_linkplay_wireless_access_status(e_succesfully_connected);
          break;
      case e_connecting_to_ap:
          Linkplay_Log(e_linkplay_raw, "connecting to access point...");
          LP_Set_linkplay_wireless_access_status(e_connecting_to_ap);
          break;
      case e_bad_rssi:
          Linkplay_Log(e_linkplay_raw, "failed to connect, bad rssi");
          LP_Set_linkplay_wireless_access_status(e_bad_rssi);
          break;
      case e_wrong_password:
          Linkplay_Log(e_linkplay_raw, "failed to connect, wrong password"); 
          LP_Set_linkplay_wireless_access_status(e_wrong_password);
          break;
      case e_wrong_security_type:
          Linkplay_Log(e_linkplay_raw, "failed to connect, wrong security type"); 
          LP_Set_linkplay_wireless_access_status(e_wrong_security_type);
          break;
      case e_cant_find_ap:
          Linkplay_Log(e_linkplay_raw, "failed to connect, can't find access point"); 
          LP_Set_linkplay_wireless_access_status(e_cant_find_ap);
          break;
      case e_failed_to_get_ip_address: 
          Linkplay_Log(e_linkplay_raw, "failed to connect, can't get ip address"); 
          LP_Set_linkplay_wireless_access_status(e_failed_to_get_ip_address);
          break;
       default:
          break; 
    }
    return e_no_error;
}
 
LinkPlay_Error_t process_s2m_command(char* linkplay_command)                    // Linkplay slave to master command pass through
{
       // "AXX+S2M+nnn"                                                   // When a pass-through session starts, master speaker MCU will receive AXX+S2M+nnn
      Linkplay_Log(e_linkplay_raw, "PIC initiated master pass thorugh to slave linkplays");
      return e_no_error;
}
 
LinkPlay_Error_t process_vol_command(char* linkplay_command)                    // Linkplay volume adjusting commands
{
    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    uint16_t volume_int = 0;

    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Log(e_linkplay_raw, "Get the PIC current volume");
        LP_send_linkplay_pic_volume();
    }
    else if (linkplay_command[8] == '0' || linkplay_command[8] == '1')
    {
        volume_int = linkplay_command_data_extraction(linkplay_command);
        if (volume_int < 101)
        {
            Linkplay_Log(e_linkplay_raw, "set volume to: ");
            Linkplay_Log(e_linkplay_raw, volume_int);
            LP_set_pic_volume(volume_int);
        }
        else
        {
            return e_volume_out_of_bounds;
        }
        
    }
    else
    {
        return e_unknown_vol_command; 
    }
    return e_no_error;  
}

LinkPlay_Error_t process_wan_command(char *linkplay_command)
{
    //  AXX+WAN+LST4E4554474541523137,0,1;7866696E69747977696669,0,0;726F636C6F6E65,0,1&
    //  AXX+WAN+LST5053415544494F,10,1;50534755455354,10,1;5053417564696F5850,10,1&

    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    
    char hex_ap[100];
    char ascii_ap[100];
    
    uint16_t string_size = 0; 
    uint16_t current_wan_status = 0;
    uint16_t pos = 0;
    uint16_t status_type = 0;
    uint8_t num_aps = 0;
    uint16_t string_begin = 11;

    if (linkplay_command[11] != '&')
    {
        num_aps += 1;
    }
    else
    {
        Linkplay_Log(e_linkplay_raw, "Can't find any networks");
        set_num_access_points(0);
        return e_no_networks_found; 
    }
    
    for (pos = 12; pos < 1024; pos++)
    {
        if (linkplay_command[pos] == ';')
        {
            num_aps += 1;
        }
        else if (linkplay_command[pos] == '&')
        {
            break;
        }
    }
    
    Linkplay_Log(e_linkplay_raw, "Found ");
    Linkplay_Log(e_linkplay_raw, num_aps);
    Linkplay_Log(e_linkplay_raw, " network(s):");   
    set_num_access_points(num_aps);
    
    for ( current_wan_status = 0; current_wan_status < (num_aps * num_status_per_wan); current_wan_status++)
    {
        for (pos = string_begin; pos < 1024; pos++)
        {
            string_size++;
            if ((linkplay_command[pos] == ',') || (linkplay_command[pos] == ';') || ((linkplay_command[pos] == '&')))
            {
                break;
            } 
        }
        
        strncpy(hex_ap, (linkplay_command + string_begin), string_size-1); 
        strncat(hex_ap, "\0", string_size);

        switch (status_type)
        {
            case e_ap_ssid:
                hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
                Linkplay_Log(e_linkplay_raw, "Network: %s", ascii_ap);
                break;
            case e_ap_rssi: 
                Linkplay_Log(e_linkplay_raw, "RSSI: , %d", atoi(hex_ap));
                break;
            case e_ap_channel:
                Linkplay_Log(e_linkplay_raw, "Channel: %d", atoi(hex_ap));
                break;
        }
        
        status_type < max_wan_status ? status_type++ : status_type = 0;
        memset(hex_ap, ASCII_NUL, 100);
        memset(ascii_ap, ASCII_NUL, 100);
        string_begin += string_size;
        string_size = 0;
    }
    return e_no_error;
}

LinkPlay_Error_t process_wps_command(char* linkplay_command)                    // Linkplay wireless WPS config commands
{
    /*
        "AXX+WPS++ON"                                                   // WPS/Smart Config process starts
    */
     switch(linkplay_command[10])
     {
        case 'F':
            Linkplay_Log(e_linkplay_raw, "WPS has been turned off");
            Linkplay_Set_wps_status(e_wps_off);
            break;
        case 'N':
            Linkplay_Log(e_linkplay_raw, "WPS has been turned on");
            Linkplay_Set_wps_status(e_wps_on);
            break;
        case 'D':
            Linkplay_Log(e_linkplay_raw, "WPS connection setup has ended");
            Linkplay_Set_wps_status(e_wps_ended);
            break;
        default:
            break;
     }
     return e_no_error;      
}
 
LinkPlay_Error_t process_www_command(char* linkplay_command)                    // Linkplay internet connection commands
{  
    /*
        "AXX+WWW+xxx"                                                   // WiFi sends this command to update its Internet connection status to MCU,
                                                                        // or reply MCU's MCU+WWW+GET command where xxx is the status code
                                                                        // 000 No Internet connection 
                                                                        // 001 Internet connection is available
    */
    
    uint16_t cunnection_status = 0;
    
    cunnection_status = linkplay_command_data_extraction(linkplay_command);
    
    switch(cunnection_status)
    {
      case e_no_internet_connection:
          Linkplay_Log(e_linkplay_raw, "no internet connection!");
          LP_Set_linkplay_internet_status(false);
          break;
      case e_connected_to_internet:
          Linkplay_Log(e_linkplay_raw, "connected to the internet!");
          Serial1.println("MCU+INF+GET");
          LP_Set_linkplay_internet_status(true);
          break;   
      default: 
          break;
    }
    return e_no_error;
}
 
uint16_t linkplay_command_data_extraction(char* linkplay_command)
{
    char status_str[4] = "";
 
    strncpy(status_str, linkplay_command + 8, 3);                       // copy last three chars into string "AXX+WWW+xxx"
    strcat(status_str, "\0");  
    return(atoi(status_str));
}

int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t asciiArrayLength)
{
    int16_t i = 0;
    int16_t j = 0;
    memset(asciiArray, ASCII_NUL, asciiArrayLength);
    
    for (i = 0; i<hexArrayLength; i+=2 )
    {
        char val1 = hexArray[i];
        char val2 = hexArray[i+1];
            
        if( val1 > 0x60) 
        {
            val1 -= 0x57;
        }
        else if(val1 > 0x40) 
        {
            val1 -= 0x37;
        }
        else 
        {
            val1 -= 0x30;
        }
            
        if( val2 > 0x60)
        {
            val2 -= 0x57;
        }
        else if(val2 > 0x40)
        {
            val2 -= 0x37;
        }
        else 
        {
            val2 -= 0x30;
        }
            
        if(val1 > 15 || val2 > 15 || val1 < 0 || val2 < 0)
        {
            return e_no_error;
        }
                    
        asciiArray[j] = val1*16 + val2;        
        j++;
    }
    return j;
}

/**
 * hex2int
 * take a hex string and convert it to a 32bit number (max 8 hex digits)
 */
uint32_t hex2int(char *hex) {
    uint32_t val = 0;
    while (*hex) {
        // get current character then increment
        char byte = *hex++; 
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (byte & 0xF);
    }
    return val;
}
=======
#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"
#include "linkplay_cli.h"

void processCommand(char* linkplay_command)
{   
    LinkPlay_Error_t error_handler = e_no_error;
        
    if (strncmp(linkplay_command, "AXX", 3) == 0)
    {
        error_handler = process_linkplay_commands(linkplay_command);
    }
    else
    {  
        if (strlen(linkplay_command) < 5)
        {
            return; 
        }
        error_handler = e_unknown_AXX_command;
    }
    
    linkplay_error_handler(error_handler, linkplay_command);
}

 
LinkPlay_Error_t process_linkplay_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[4])
    {
        case 'B':
            error_handler = process_b_commands(linkplay_command);
            break;
        case 'C':
            error_handler = process_c_commands(linkplay_command);
            break;
        case 'D':
            error_handler = process_d_commands(linkplay_command);
            break;
        case 'E':
            error_handler = process_e_commands(linkplay_command);
            break;
        case 'F':
            error_handler = process_f_commands(linkplay_command);
            break;
        case 'G':
            error_handler = process_g_commands(linkplay_command);
            break;
        case 'I':
            error_handler = process_i_commands(linkplay_command);
            break;
        case 'K':
            error_handler = process_k_commands(linkplay_command);
            break;
        case 'L':
            error_handler = process_l_commands(linkplay_command);
            break;
        case 'M':
            error_handler = process_m_commands(linkplay_command);
            break;
        case 'N':
            error_handler = process_n_commands(linkplay_command);
            break;
        case 'P':
            error_handler = process_p_commands(linkplay_command);
            break; 
        case 'R':
            error_handler = process_r_commands(linkplay_command);
            break;
        case 'S':
            error_handler = process_s_commands(linkplay_command);
            break;
        case 'U':
            error_handler = process_v_commands(linkplay_command);
            break;
        case 'V':
            error_handler = process_v_commands(linkplay_command);
            break;
        case 'W':
            error_handler = process_w_commands(linkplay_command);
            break;
        default:
            error_handler =  e_unknown_command;
            break;
    }
    return error_handler; 
}
 
LinkPlay_Error_t process_b_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'O':
            error_handler = process_bot_command(linkplay_command);                      // Linkplay boot commnads
            break;
        case 'U':
            error_handler = process_bur_command(linkplay_command);                      // Linkplay firmware updating commands
            break;
        default:
            error_handler =  e_unknown_b_command;
            break;
    }
    return error_handler;     
}
 
LinkPlay_Error_t process_c_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_cap_command(linkplay_command);                      // Linkplay commands after factory reset
            break;
        case 'H':
            error_handler = process_chn_command(linkplay_command);                      // Linkplay channel information (stereo / mono left / mono right)
            break;
        default:
            error_handler =  e_unknown_c_command;
            break;
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_d_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error;
     
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_dev_command(linkplay_command);                      // Linkplay device query commands
            break;
        default:
            error_handler =  e_unknown_d_command;
            break;  
    }       
    return error_handler; 
}
 
LinkPlay_Error_t process_e_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error;
     
    switch (linkplay_command[5])
    {
        case 'T':
            error_handler = process_eth_command(linkplay_command);                      // Linkplay ethernet commands
            break;
        default:
            error_handler =  e_unknown_e_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_f_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_fac_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_f_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_g_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_get_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_g_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_i_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    { 
        case 'N':
            error_handler = process_inf_command(linkplay_command);                    // Linkplay i2s commands
            break;
        case '2':
            error_handler = process_i2s_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_i_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_k_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    { 
        case 'E':
            error_handler = process_key_command(linkplay_command);                     // Linkplay factory get commands
            break;
        default:
            error_handler =  e_unknown_k_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_l_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_led_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_l_command;
            break;  
    }    
    return error_handler;  
}
 
LinkPlay_Error_t process_m_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'C':
            error_handler = process_mcu_command(linkplay_command);                      // Linkplay queries of our microprocessor
            break;
        case 'E':
            error_handler = process_mea_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;
        case 'I':
            error_handler = process_mic_command(linkplay_command);                      // Linkplay meadia metadata commands
            break;     
        case 'U':
            error_handler = process_mut_command(linkplay_command);                      // Linkplay command to mute audio
            break;
        case '2':
            error_handler = process_m2s_command(linkplay_command);                      // Linkplay master to slave command pass through
            break;        
        default:
            error_handler =  e_unknown_m_command;
            break;
    }    
    return error_handler; 
}

LinkPlay_Error_t process_n_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'X':
            error_handler = process_nxt_command(linkplay_command);                      // Linkplay factory reset commands
            break;
        default:
            error_handler =  e_unknown_n_command;
            break;  
    }    
    return error_handler;  
}

LinkPlay_Error_t process_p_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[6])
    {
        case 'M':
            error_handler = process_plm_command(linkplay_command);                      // Linkplay playback mode commands
            break;
        case 'P':
            error_handler = process_plp_command(linkplay_command);                      // Linkplay repeat mode commands
            break;
        case 'T':
            error_handler = process_pmt_command(linkplay_command);
            break;
        case 'Y':
            error_handler = process_ply_command(linkplay_command);                      // Linkplay playback commands
            break;
        case 'W':
            error_handler = process_pow_command(linkplay_command);                      // Linkplay playback commands
            break;    
        default:
            error_handler =  e_unknown_p_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_r_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_ra0_command(linkplay_command);                      // Linkplay wifi access point information commands
            break;
        default:
            error_handler =  e_unknown_r_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_s_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'E':
            error_handler = process_set_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case 'L':
            error_handler = process_sli_command(linkplay_command);                      // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
            break;
        case 'T':
            error_handler = process_sta_command(linkplay_command);                      // Linkplay wireless status commands
            break;
        case '2':
            error_handler = process_s2m_command(linkplay_command);                      // Linkplay slave to master command pass through
            break;  
        default:
            error_handler = e_unknown_s_command;
            break;
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_v_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'O':
            error_handler = process_vol_command(linkplay_command);                      // Linkplay volume adjusting commands
            break;
        default:
            error_handler =  e_unknown_v_command;
            break;  
    }    
    return error_handler; 
}
 
LinkPlay_Error_t process_w_commands(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch (linkplay_command[5])
    {
        case 'A':
            error_handler = process_wan_command(linkplay_command);
            break;
        case 'P':
            error_handler = process_wps_command(linkplay_command);                      // Linkplay wireless WPS config commands
            break;  
        case 'W':
            error_handler = process_www_command(linkplay_command);                      // Linkplay internet connection commands
            break;  
        default:
            error_handler = e_unknown_w_command;
            break;  
    }    
    return error_handler; 
}

LinkPlay_Error_t process_bot_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
    if (strncmp((linkplay_command + 8), "DON", 3) == 0)
    {   
        Linkplay_Debug_Printf("Linkplay is done booting. This is also the heartbeat command\n");
        return e_no_error;
    }
    else if (strncmp((linkplay_command + 8), "UP0", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay is done booting. This one time command acknowledges that\n");
        return e_no_error;  
    }
    return e_unknown_bot_command;
}


LinkPlay_Error_t process_bur_command(char* linkplay_command)                   // Linkplay firmware updating commands
{
/*
        "AXX+BURNING"                                                   // wifi is updating firmware
        "AXX+BURN002"                                                   // wifi update was succesful
        "AXX+BURN003"                                                   // WiFi update failed
*/
    switch(linkplay_command[10])
    {
        case 'G':
            Linkplay_Debug_Printf("Linkplay is updating its firmware!\n");
            LP_Set_linkplay_firmware_update_status(e_firmware_updateing);
            break;
        case '2':
            Linkplay_Debug_Printf("Linkplay firmware update successful\n");
            LP_Set_linkplay_firmware_update_status(e_update_successful);
            break;
        case '3':
            Linkplay_Debug_Printf("Linkplay firmware update failed!\n");
            LP_Set_linkplay_firmware_update_status(e_update_failed); 
            break;  
        default:
            return e_unknown_bur_command;
            break;
    }     
    return e_no_error;   
}
 
LinkPlay_Error_t process_cap_command(char* linkplay_command)                   // Linkplay commands after factory reset
{   /*
        "AXX+CAP+GET"                                                   // command on the first boot after a factory reset. The returned information will be saved permanently.
    */
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay booted after factory reset, needs pertinent information\n");
        Serial1.println("MCU+CAP+PRJPSAUDIO_Stellar&\n");
        Serial1.println("MCU+PTV+000\n");
        Serial1.println("MCU+SPY+BRNPSAUDIO&\n");
        Serial1.println("MCU+SPY+NAMStellarIntegrated&\n");
        Serial1.println("MCU+SPY+TYP0&\n");
        Serial1.println("MCU+CAP+00100001100&\n");
        Serial1.println("MCU+CAP+00200000800&\n");
        Serial1.println("MCU+CAP+LAUen_us&\n");
        
        Serial1.println("MCU+CAP+STMfffffffc&\n");
        Serial1.println("MCU+CAP+PLM00000000&\n");
        Serial1.println("MCU+PRESET+3&\n");
        return e_no_error;
    }
    return e_unknown_cap_command;
}
 
LinkPlay_Error_t process_chn_command(char* linkplay_command)                    // Linkplay channel information (stereo / mono left / mono right)
{   /*
        "AXX+CHN+GET"                                                   // What is our output channel config set to?
        "AXX+CHN+nnn"                                                   // WiFi sends this command to update the channel information
                                                                        // 000 Stereo
                                                                        // 001 Left channel
                                                                        // 002 Right channel
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Debug_Printf("Get the output channel congifuration for linkplay: Stereo, Left, or Right\n");
        LP_get_pic_channel_config();
    }
    else if (linkplay_command[8] == '0')
    { 
        switch(linkplay_command_data_extraction(linkplay_command))
        {
          case e_stereo:
              Linkplay_Debug_Printf("audio is in stereo\n");
              LP_Set_linkplay_audio_channel_status(e_stereo);
              break;
          case e_left_chan:
              Linkplay_Debug_Printf("audio is only left chan\n");
              LP_Set_linkplay_audio_channel_status(e_left_chan);
              break;
          case e_right_chan:
              Linkplay_Debug_Printf("audio is only righ chan\n");
              LP_Set_linkplay_audio_channel_status(e_right_chan);
              break;
          default:
              error_handler = e_unknown_chan_config;
              break;
        }
        return error_handler; 
    }
    else
    {
        error_handler = e_unknown_chn_command;
    }
    
    return error_handler;
}
 
LinkPlay_Error_t process_dev_command(char* linkplay_command)                    // Linkplay device query commands
{
       // "AXX+DEV+RST"                                                   // MCU should NOT automatically reboot or power off WiFi module after updating the firmware.
                                                                        // It should wait for WiFi module to send AXX+DEV+RST or AXX+DEV+RST in case AXX+DEV+RST gets lost.
    if (strncmp((linkplay_command + 8), "RST", 3) == 0)
    {
        Linkplay_Debug_Printf("linkplay is resetting - don't poll it until it gives the ok\n");
        LP_Set_linkplay_in_reset(true);
        return e_no_error;
    }

    return e_unknown_dev_command;  
}
 
LinkPlay_Error_t process_eth_command(char* linkplay_command)                    // Linkplay ethernet commands
{
    /*
        "AXX+ETH+xxx"                                                   // WiFi sends this command to update the Ethernet status to MCU,
                                                                        // or reply MCU's MCU+ETH+GET command where xxx is the status code
                                                                        // 000 Unplugged
                                                                        // 001 Plugged
                                                                        // FFF Disabled
    */
  
    LinkPlay_Error_t error_handler = e_no_error;

    if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Linkplay_Debug_Printf("Ethernet is disabled\n");
        return error_handler; 
    }
    else
    {     
        switch(linkplay_command_data_extraction(linkplay_command))
        {
            case e_ethernet_disconnected:
                Linkplay_Debug_Printf("Ethernet is disconnected\n");
                break;
            case e_ethernet_connected:
                Linkplay_Debug_Printf("Ethernet is connected!\n");
                break;
            default:
                error_handler = e_unknown_eth_command;
                break;
        }
    }
    return error_handler;
}
 
LinkPlay_Error_t process_fac_command(char* linkplay_command)                    // Linkplay factory reset commands
{
    //   "AXX+FACTORY"                                                 // WiFi sends this command to notify MCU that it is going to do a factory reset

    LinkPlay_Error_t error_handler = e_no_error; 

    if (strncmp((linkplay_command + 8), "ORY", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay is factory resetting.\nWe'll need to supply it information upon it rebooting.\n");
    }
    else if (strncmp((linkplay_command + 8), "POW", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay is factory resetting.\nUnit is not power cycling.\n");
    }
    else
    {
        error_handler = e_unknown_fac_command;
    }

    return error_handler; 
}

LinkPlay_Error_t process_get_command(char* linkplay_command)
{

    if (strncmp((linkplay_command + 8), "SID", 3) == 0)
    {    
        Linkplay_Debug_Printf("Set SSID of linkplay\n");
        Serial1.println("MCU+SID+StellarIntegrated\n");
        return e_no_error;
    }

    return e_unknown_get_command; 
}

LinkPlay_Error_t process_inf_command(char* linkplay_command)                    // Linkplay inf commands
{ 
/*
        AXX+INF+INF{ "language": "en_us", "ssid": "LinkPlayA31_1CB8", "hideSSID": "1", "SSIDStrategy": "2", 
        "firmware": "3.8.5710", "build": "release", "project": "a31srcoutwm8918", "priv_prj": "a31srcoutwm8918", 
        "Release": "20180510", "branch": "stable\/wiimu-3.8", "group": "0", "expired": "0", "internet": "0", 
        "uuid": "FF3100368405108353A7AD6C", "MAC": "00:22:6C:68:1C:B8", "STA_MAC": "00:22:6C:68:1C:BA", 
        "date": "1970:01:01", "time": "00:27:42", "tz": "-7", "netstat": "0", "essid": "", "apcli0": "0.0.0.0",    //22
        "eth2": "0.0.0.0", "hardware": "A31", "VersionUpdate": "0", "NewVer": "0", "mcu_ver": "0", "mcu_ver_new": "0", 
        "dsp_ver_new": "0", "ra0": "10.10.10.254", "temp_uuid": "58F491488457B1B7", "cap1": "0x500", 
        "capability": "0x280800", "languages": "0x0", "dsp_ver": "", "streams_all": "0x7ffffffe", "streams": "0x7f9833fe", //37
        "region": "unknown", "external": "0x0", "preset_key": "6", "plm_support": "0x2", "spotify_active": "0", 
        "WifiChannel": "11", "RSSI": "0", "battery": "0", "battery_percent": "0", "securemode": "0", 
        "upnp_version": "1004", "upnp_uuid": "uuid:FF31F008-8405-1083-53A7-AD6CFF31F008", "uart_pass_port": "8899", 
        "communication_port": "8819", "web_firmware_update_hide": "0", "web_login_result": "-1", "ignore_talkstart": "0", 
        "silenceOTATime": "", "ignore_silenceOTATime": "1", "iheartradio_new": "1", "privacy_mode": "0", 
        "user1": "315:524", "user2": "5935:6291", "DeviceName": "Linkplay Demo", "GroupName": "Linkplay Demo" }&
*/  
    LinkPlay_Error_t error_handler = e_no_error; 
    uint16_t num_args = 1;
    uint16_t data_start_point = 0;
    uint16_t data_end_point = 0;
    char char_buf[100];    
    uint16_t command_length = strlen(linkplay_command);

    if (strncmp((linkplay_command + 8), "INF", 3) == 0)
    {  
        for (data_start_point = 12; data_start_point < command_length; data_start_point++)
        {
            if ((linkplay_command[data_start_point] == ':') && (linkplay_command[data_start_point-1] == '"'))
            {
                for (data_end_point = (data_start_point+data_offset); data_end_point < command_length; data_end_point++)
                {     
                    if ((linkplay_command[data_end_point] == '"') && (linkplay_command[data_end_point+1] == ','))
                    {
                        strncpy(char_buf, (linkplay_command+(data_start_point+data_offset)), (data_end_point-(data_start_point+data_offset)));
                        error_handler = inf_command_parser((num_args-1), char_buf);
                        memset(char_buf, ASCII_NUL, 100);
                        break;
                    }  
                }
                num_args ++;
            }
        }
        return error_handler; 
    }
    return e_unknown_inf_command;
}

LinkPlay_Error_t inf_command_parser(uint16_t current_inf, char* char_buf)
{
    switch (current_inf)
    {
        case e_inf_language:
            Linkplay_Debug_Printf("language: %s", char_buf);
            if (strncmp(char_buf, "en_us", 5) == 0)
            {
                LP_Set_linkplay_language(e_linkplay_lang_en_us);
            }
            else
            {
                /* error wrong language! */
                Linkplay_Debug_Printf("Wrong language set!!\n");
            }
            break;
        case e_inf_ssid:
            Linkplay_Debug_Printf("ssid: %s", char_buf);
            LP_Set_linkplay_ssid(char_buf);
            break;
        case e_inf_hide_ssid:
            Linkplay_Debug_Printf("hide ssid: %s", char_buf);
            LP_Set_linkplay_ssid_hidden(atoi(char_buf));
            break;
        case e_inf_ssid_strategy:
            Linkplay_Debug_Printf("ssid strategy: %s", char_buf);
            LP_Set_linkplay_ssid_strategy(atoi(char_buf));
            break;
        case e_inf_link_play_fimrware:
            Linkplay_Debug_Printf("linkplay firmware: %s", char_buf);
            LP_Set_linkplay_firmware_version(char_buf);
            break;
        case e_inf_build:
            Linkplay_Debug_Printf("linkplay build: %s", char_buf);
            LP_Set_linkplay_build(char_buf);
            break;
        case e_inf_project:
            Linkplay_Debug_Printf("linkplay project: %s", char_buf);
            LP_Set_linkplay_project(char_buf);
            break;
        case e_inf_firmware_private_project:
            Linkplay_Debug_Printf("linkplay private project: %s", char_buf);
            LP_Set_linkplay_private_project(char_buf);
            break;
        case e_inf_firmware_release:
            Linkplay_Debug_Printf("linkplay firmware release: %s", char_buf);
            LP_Set_linkplay_firmware_release(atoi(char_buf));
            break;
        case e_inf_firmware_branch:
            Linkplay_Debug_Printf("linkplay firmware branch: %s", char_buf);
            LP_Set_linkplay_firmware_branch(char_buf);
            break;
        case e_inf_group:
            Linkplay_Debug_Printf("group: %s", char_buf);
            LP_Set_linkplay_group(atoi(char_buf));
            break;
        case e_inf_expired:
            Linkplay_Debug_Printf("expired: %s", char_buf);
            LP_Set_linkplay_verion_expierd(atoi(char_buf));
            break;
        case e_inf_internet:
            Linkplay_Debug_Printf("internet status: %s", char_buf);
            LP_Set_linkplay_internet_status(atoi(char_buf));
            break;
        case e_inf_uuid:
            Linkplay_Debug_Printf("uuid: %s", char_buf);
            LP_Set_linkplay_uuid(char_buf);
            break;
        case e_inf_mac:
            Linkplay_Debug_Printf("mac address: %s", char_buf);
            LP_Set_linkplay_mac_address(char_buf);
            break;
        case e_inf_sta_mac:
            Linkplay_Debug_Printf("sta mac address: %s", char_buf);
            LP_Set_linkplay_sta_mac_address(char_buf);
            break;
        case e_inf_date:
            Linkplay_Debug_Printf("date: %s", char_buf);
            process_date(char_buf);
            break;
        case e_inf_time:
            Linkplay_Debug_Printf("time: %s", char_buf);
            process_time(char_buf);
            break;
        case e_inf_tz:
            Linkplay_Debug_Printf("time zone: %s", char_buf);
            LP_Set_linkplay_time_zone(atoi(char_buf));
            break;
        case e_inf_netstat:
            Linkplay_Debug_Printf("network status: %s", char_buf);
            LP_Set_linkplay_network_status(atoi(char_buf));
            break;
        case e_inf_essid:
            Linkplay_Debug_Printf("essid: %s", char_buf);
            process_essid(char_buf);
            break;
        case e_inf_apcli0:
            Linkplay_Debug_Printf("wifi IP: %s", char_buf);
            LP_Set_linkplay_wifi_ip(char_buf);
            break;
        case e_inf_eth2:
            Linkplay_Debug_Printf("ethernet IP: %s", char_buf);
            LP_Set_linkplay_ethernet_ip(char_buf);
            break;
        case e_inf_hardware:
            Linkplay_Debug_Printf("hardware: %s", char_buf);
            LP_Set_linkplay_hardware(char_buf);
            break;
        case e_inf_version_update:
            Linkplay_Debug_Printf("version update: %s", char_buf);
            LP_Set_linkplay_version_update(atoi(char_buf));
            break;
        case e_inf_new_version:
            Linkplay_Debug_Printf("new linkplay firmware version: %s", char_buf);
            Linkplay_Debug_Printf(char_buf);
            break;
        case e_inf_mcu_version:
            Linkplay_Debug_Printf("pic firmware version: %s", char_buf);
            LP_Set_linkplay_new_version(atoi(char_buf));
            break;
        case e_inf_mcu_new_version:
            Linkplay_Debug_Printf("pic new firmware version: %s", char_buf);
            LP_Set_linkplay_pic_new_firmware_verison(atoi(char_buf));
            break;
        case e_inf_dsp_ver_new:
            Linkplay_Debug_Printf("dsp new firmware version: %s", char_buf);
            LP_Set_linkplay_dsp_new_firmware_verison(atoi(char_buf));
            break;
        case e_inf_ra0:
            Linkplay_Debug_Printf("internal server IP: %s", char_buf);
            LP_Set_linkplay_internal_server_port(char_buf);
            break;
        case e_inf_temp_uuid:
            Linkplay_Debug_Printf("temp uuid: %s", char_buf);
            LP_Set_linkplay_temp_uuid(char_buf);
            break;
        case e_inf_cap1:
            Linkplay_Debug_Printf("capl: %s", char_buf);
            LP_Set_linkplay_capl(atoi(char_buf));
            break;
        case e_inf_capability:
            Linkplay_Debug_Printf("capability: %s", char_buf);
            break;
        case e_inf_languages:
            Linkplay_Debug_Printf("language: %s", char_buf);
            LP_Set_linkplay_languages(atoi(char_buf));
            break;
        case e_inf_dsp_ver:
            Linkplay_Debug_Printf("dsp version: %s", char_buf);
            LP_Set_linkplay_dsp_version(atoi(char_buf));
            break;
        case e_inf_streams_all:
            Linkplay_Debug_Printf("steaming settings: %s", char_buf);
            LP_Set_linkplay_steaming_settings(atoi(char_buf));
            break;
        case e_inf_streams:
            Linkplay_Debug_Printf("streams: %s", char_buf);
            LP_Set_linkplay_streams(atoi(char_buf));
            break;
        case e_inf_region:
            Linkplay_Debug_Printf("region: %s", char_buf);
            LP_Set_linkplay_region(atoi(char_buf));
            break;
        case e_inf_external:
            Linkplay_Debug_Printf("external: %s", char_buf);
            LP_Set_linkplay_external(atoi(char_buf));
            break;
        case e_inf_preset_key:
            Linkplay_Debug_Printf("preset key: %s", char_buf);
            LP_Set_linkplay_preset_keys(atoi(char_buf));
            break;
        case e_inf_plm_support:
            Linkplay_Debug_Printf("plm support: %s", char_buf);
            LP_Set_linkplay_plm_support(atoi(char_buf));
            break;
        case e_inf_spotify_active:
            Linkplay_Debug_Printf("spotify active: %s", char_buf);
            LP_Set_linkplay_spotify_active(atoi(char_buf));
            break;
        case e_inf_WifiChannel:
            Linkplay_Debug_Printf("wifi channel: %s", char_buf);
            LP_Set_linkplay_wifi_channel(atoi(char_buf));
            break;
        case e_inf_RSSI:
            Linkplay_Debug_Printf("rssi: %s", char_buf);
            LP_Set_linkplay_rssi(atoi(char_buf));
            break;
        case e_inf_battery:
            Linkplay_Debug_Printf("battery: %s", char_buf);
            LP_Set_linkplay_battery(atoi(char_buf));
            break;
        case e_inf_battery_percent:
            Linkplay_Debug_Printf("battery percent: %s", char_buf);
            LP_Set_linkplay_battery_percent(atoi(char_buf));
            break;
        case e_inf_securemode:
            Linkplay_Debug_Printf("secure mode: %s", char_buf);
            LP_Set_linkplay_secure_mode(atoi(char_buf));
            break;
        case e_inf_upnp_version:
            Linkplay_Debug_Printf("upnp version: %s", char_buf);
            LP_Set_linkplay_upnp_version(atoi(char_buf));
            break;
        case e_inf_upnp_uuid:
            Linkplay_Debug_Printf("upnp uuid: %s", (char_buf +5));
            LP_Set_linkplay_upnp_uuid(char_buf);
            break;
        case e_inf_uart_pass_port:
            Linkplay_Debug_Printf("pass port: %s", char_buf);
            LP_Set_linkplay_pass_port(char_buf);
            break;
        case e_inf_communication_port:
            Linkplay_Debug_Printf("communication port: %s", char_buf);
            LP_Set_linkplay_communication_port(char_buf);
            break;
        case e_inf_web_firmware_update_hide:
            Linkplay_Debug_Printf("firmware update hidden: %s", char_buf);
            LP_Set_linkplay_firmware_update_hidden(atoi(char_buf));
            break;
        case e_inf_web_login_result:
            Linkplay_Debug_Printf("web login result: %s", char_buf);
            LP_Set_linkplay_web_login_result(atoi(char_buf));
            break;
        case e_inf_ignore_talkstart:
            Linkplay_Debug_Printf("ignore talk start: %s", char_buf);
            LP_Set_linkplay_ignore_talk_start(atoi(char_buf));
            break;
        case e_inf_silenceOTATime:
            Linkplay_Debug_Printf("silence OTA time: %s", char_buf);
            Linkplay_Debug_Printf(char_buf);
            break;
        case e_inf_ignore_silenceOTATime:
            Linkplay_Debug_Printf("ignore silence OTA time: %s", char_buf);
            LP_Set_linkplay_silence_OTA_time(atoi(char_buf));
            break;
        case e_inf_iheartradio_new:
            Linkplay_Debug_Printf("iHeartRadio new: %s", char_buf);
            LP_Set_linkplay_iHeartRadio_new(atoi(char_buf));
            break;
        case e_inf_privacy_mode:
            Linkplay_Debug_Printf("privacy mode: %s", char_buf);
            LP_Set_linkplay_privacy_mode(atoi(char_buf));
            break;
        case e_inf_user1:
            Linkplay_Debug_Printf("user1: %s", char_buf);
            LP_Set_linkplay_user1(char_buf);
            break;
        case e_inf_user2:
            Linkplay_Debug_Printf("user2: %s", char_buf);
            LP_Set_linkplay_user2(char_buf);
            break;
        case e_inf_DeviceName:
            Linkplay_Debug_Printf("device name: %s", char_buf);
            LP_Set_linkplay_device_name(char_buf);
            break;
        case e_inf_GroupName:
            Linkplay_Debug_Printf("group name: %s", char_buf);
            break;
        default:
            break; 
    }
    return e_no_error;
}

void process_date(char* date)
{
    char c_current_year[6];
    char c_current_month[4];
    char c_current_day[4];

    memset(c_current_year, ASCII_NUL, 6); 
    memset(c_current_month, ASCII_NUL, 4); 
    memset(c_current_day, ASCII_NUL, 4); 

    strncpy(c_current_year, date, 4);
    strncpy(c_current_month, date+5, 2);
    strncpy(c_current_day, date+8, 2);
    
    LP_Set_linkplay_year(atoi(c_current_year));
    LP_Set_linkplay_month(atoi(c_current_month));
    LP_Set_linkplay_day(atoi(c_current_day));
}

void process_time(char* time)
{
    char c_current_hour[4];
    char c_current_minute[4];
    char c_current_second[4];

    memset(c_current_hour, ASCII_NUL, 4); 
    memset(c_current_minute, ASCII_NUL, 4); 
    memset(c_current_second, ASCII_NUL, 4); 

    strncpy(c_current_hour, time, 2);
    strncpy(c_current_minute, time+3, 2);
    strncpy(c_current_second, time+6, 2);
    
    LP_Set_linkplay_hour(atoi(c_current_hour));
    LP_Set_linkplay_minute(atoi(c_current_minute));
    LP_Set_linkplay_second(atoi(c_current_second));
}

void process_essid(char* hex_ap)
{           
    char ascii_ap[65];

    memset(ascii_ap, ASCII_NUL, 65); 
    hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
    LP_Set_linkplay_essid(ascii_ap);
}

LinkPlay_Error_t process_i2s_command(char* linkplay_command)
{
    // AXX+I2S+INF44100_16&
    char c_sample_rate[50];
    char c_bit_depth[50];
    uint8_t sample_rate_chars = 0; 
    uint16_t i = 0; 
    uint16_t off_set = 11; 
    
    
    if (strncmp((linkplay_command + 8), "INF", 3) == 0)
    {  
        if (linkplay_command[11] == '&')
        {
            return e_empty_i2s_command;  
        }
      
        for (i = off_set; i < strlen(linkplay_command); i++)
        {
            sample_rate_chars++; 
            if ((linkplay_command[i] == '_') || (linkplay_command[i] == '&'))
            {
                break; 
            }
        }
     
            strncpy(c_sample_rate,linkplay_command+11, sample_rate_chars);
            switch(atoi(c_sample_rate))
            {
                case e_linkplay_44100:
                    Linkplay_Debug_Printf("44.1k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_44100);
                    break;
                case e_linkplay_48000:
                    Linkplay_Debug_Printf("48k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_48000);
                    break;
                case e_linkplay_88200:
                    Linkplay_Debug_Printf("88.2k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_88200);
                    break;
                case e_linkplay_96000:
                    Linkplay_Debug_Printf("96k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_96000);
                    break;
                case e_linkplay_176400:
                    Linkplay_Debug_Printf("176.4k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_176400);
                    break;
                case e_linkplay_192000:
                    Linkplay_Debug_Printf("192.2k\n");
                    LP_Set_linkplay_sample_rate(e_linkplay_192000);
                    break;
            }
    
            strncpy(c_bit_depth,linkplay_command+(11+sample_rate_chars), 2);

            switch (atoi(c_bit_depth))
            {
                case e_linkplay_16:
                    Linkplay_Debug_Printf("%d bit\n", e_linkplay_16);
                    LP_Set_linkplay_bit_depth(e_linkplay_16);
                    break;
                case e_linkplay_24:
                    Linkplay_Debug_Printf("%d bit\n", e_linkplay_24);
                    LP_Set_linkplay_bit_depth(e_linkplay_24);
                    break;
                default: 
                    break;
            }
            return e_no_error;
    }
    return e_unknown_i2s_command; 
}

LinkPlay_Error_t process_key_command(char* linkplay_command)
{

    return e_unknown_key_command; 
}

LinkPlay_Error_t process_led_command(char* linkplay_command)                     // Linkplay factory teset commands
{
    //  "AXX+LED+TES"                                                   // Notify MCU that the module is in factory test mode
    Linkplay_Debug_Printf("Linkplay is in test mode. flashing LEDs (not hooked up)\n");
    return e_no_error;
}
 
LinkPlay_Error_t process_mcu_command(char* linkplay_command)                     // Linkplay queries of our microprocessor
{
    /*  
        "AXX+MCU+VER"                                                   // command to check MCU frimware version"
        "AXX+MCU+UPDversion:len:name&"                                  // command to request a MCU firmware upgrade, where version is the new version number,
                                                                        // len is the total length and name is the project name.
        "AXX+MCU+RUNindex:len:data&"                                    // command where index is the index of firmware packet, ranging from 000 to 999,
                                                                        // len is the length of this packet, usually 1024, and data is the actual data.
                                                                        // Data is sent as is, except special bytes, including '\0', '&', '0', '+'.
                                                                        // The first 4-byte is the check-sum, sent in little endian format.
                                                                        // Special bytes  '\0', '&', '0', '+' are converted as follows
                                                                        // '\0' -> "01"
                                                                        // '&' -> "02"
                                                                        // '0' -> "00"
                                                                        // '+' -> "03
    */
        
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay is ready for communication!\n");
        LP_Set_linkplay_ready_for_communication(true);
        return e_no_error;
    }
    else if (strncmp((linkplay_command + 8), "VER", 3) == 0)
    {
        Linkplay_Debug_Printf("Send PIC firmware version ex: 0119\n");
        Serial1.println("MCU+VER+0119&\n");
        return e_no_error;
    }
    
    return e_unknown_mcu_command;
}
 
LinkPlay_Error_t process_mea_command(char* linkplay_command)                    // Linkplay meadia metadata commands
{
    /*
        "AXX+MEA+RDY"                                                   // Notify MCU that the WiFi module is ready to respond to MCU+MEA+GET
        "AXX+MEA+DAT(metadata)&"                                        // Update metadata, where metadata is a JSON message
         AXX+MEA+DAT{ "title": "49277665204C6561726E656420546F204C6F7665204D7973656C66", "artist": "6C65746C6976652E", "album": "49662049276D2054686520446576696C2E2E2E", "vendor": "" }&

    */
    // linkplay song titles can only be 64 chars

    
    char hex_title[70];
    char hex_artist[70];
    char hex_album[70];
    
    char ascii_title[70];
    char ascii_artist[70];
    char ascii_album[70];
    
    uint16_t title_char_counter = 0; 
    uint16_t artist_char_counter = 0;     
    uint16_t album_char_counter = 0; 

    memset(hex_title, ASCII_NUL, 70);
    memset(hex_artist, ASCII_NUL, 70);    
    memset(hex_album, ASCII_NUL, 70);

    memset(ascii_title, ASCII_NUL, 70);
    memset(ascii_artist, ASCII_NUL, 70);    
    memset(ascii_album, ASCII_NUL, 70);
    
    if (strncmp((linkplay_command + 8), "RDY", 3) == 0)
    {
        Linkplay_Debug_Printf("media is ready!\n");
        Serial1.write("MCU+MEA+GET\n");
        return e_no_error; 
    }
    else if (strncmp((linkplay_command + 8), "DAT", 3) == 0)
    {
        for(title_char_counter = title_offset; title_char_counter <= strlen(linkplay_command); title_char_counter++)
        {
            if (linkplay_command[title_char_counter] == '"')
            { 
                break; 
            }
        }
        strncpy(hex_title, (linkplay_command + title_offset), title_char_counter-title_offset);
        hex2ascii(hex_title, ascii_title, strlen(hex_title), strlen(ascii_title));
        Serial.print("Title: \n"); Linkplay_Debug_Printf(ascii_title);
        LP_Set_linkplay_title(ascii_title);

        for(artist_char_counter = (title_char_counter+artist_offset); artist_char_counter < 1024; artist_char_counter++)
        {
            if (linkplay_command[artist_char_counter] == '"')
            {
                break; 
            }
        }   
        strncpy(hex_artist, (linkplay_command + (title_char_counter+artist_offset)), (artist_char_counter - (title_char_counter+artist_offset)));
        hex2ascii(hex_artist, ascii_artist, strlen(hex_artist), strlen(ascii_artist));
        Serial.print("Artist: \n"); Linkplay_Debug_Printf(ascii_artist);
        LP_Set_linkplay_artist(ascii_artist);


        for(album_char_counter = (artist_char_counter+album_offset); album_char_counter < 1024; album_char_counter++)
        {
            if (linkplay_command[album_char_counter] == '"')
            {
                break; 
            }
        }   
        strncpy(hex_album, (linkplay_command + (artist_char_counter+album_offset)), (album_char_counter - (artist_char_counter+album_offset))); 
        hex2ascii(hex_album, ascii_album, strlen(hex_album), strlen(ascii_album));
        Serial.print("Album: \n"); Linkplay_Debug_Printf(ascii_album);
        LP_Set_linkplay_album(ascii_album);

        return e_no_error; 
    }
    else
    {
        return e_unknown_mea_command;
    }
}

LinkPlay_Error_t process_mic_command(char* linkplay_command)
{
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case 0: 
            Linkplay_Debug_Printf("Microphones turned off\n");
            LP_Set_linkplay_microphones(0);
            break;
        default: 
            error_handler =  e_unknown_mic_command; 
            break;
    }
    return error_handler;
}
 
LinkPlay_Error_t process_mut_command(char* linkplay_command)                    // Linkplay command to mute audio
{
    /*
        "AXX+MUT+000"                                                   // WiFi sends this command to request MCU to unmute the spekaer
        "AXX+MUT+001"                                                   // WiFi sends this command to request MCU to mute the speaker
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case e_linkplay_unmute:
            Linkplay_Debug_Printf("unmute output\n");
            LP_Set_linkplay_mute(e_linkplay_unmute);
            break; 
        case e_linkplay_mute:
            Linkplay_Debug_Printf("mute output\n");
            LP_Set_linkplay_mute(e_linkplay_mute);
            break; 
        default:
            error_handler = e_unknown_mut_command; 
            break;  
    }
    return error_handler;
}
 
LinkPlay_Error_t process_m2s_command(char* linkplay_command)                    // Linkplay master to slave command pass through
{
       // "AXX+M2S+nnn"                                                // When a pass-through session starts, slave speakers will receive AXX+M2S+nnn
       return e_unknown_m2s_command;
}

LinkPlay_Error_t process_nxt_command(char* linkplay_command)                    // Linkplay alarm commands
{
    // Not supporting alarm commands
        
    if (linkplay_command[11] == '-')
    {
        Linkplay_Debug_Printf("Linkplay alarm feature is disabled\n");
        LP_Set_linkplay_alarm(-1);
        return e_no_error; 
    }
    
    return e_unknown_nxt_command;   
}

LinkPlay_Error_t process_plm_command(char* linkplay_command)                    // Linkplay playback mode commands
{
    /*
        "AAX+PLM+GET"
        "AXX+PLM+nnn"                                                   // WiFi sends this command to notify MCU mode switch, where nnn is defined below
                                                                        // 000 None
                                                                        // 001 Airplay
                                                                        // 002 DLNA
                                                                        // 010 to 019 A play list played by Wiimu protocol, where 011 means a play list for music stroed in USB disk,
                                                                        // 016 means a play list for music stored in T-Flash card
                                                                        // 020 to 029 A play list played by third party HTTP APIs, where 021 means a play list for music stroed in USB disk,
                                                                        // 026 means a play list for music stored in T-Flash card
                                                                        // 040 - Line in (aka Aux-In)
                                                                        // 041 - BT
                                                                        // 042 - External USB Disk or T-Flash
                                                                        // 043 - Optical
                                                                        // 044 - RCA
                                                                        // 045 - Coaxial
                                                                        // 050 - Mirror
                                                                        // 099 - Slave
    */
 
    LinkPlay_Error_t error_handler = e_no_error;
    
    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Debug_Printf("Get PICs linkplay input selection\n");
    }
    else
    {
        switch(linkplay_command_data_extraction(linkplay_command))   
        {
            case e_none:
                Linkplay_Debug_Printf("no Linkplay input selected\n");
                LP_Set_linkplay_playback_mode(e_none);
                break;
            case e_airplay:
                Linkplay_Debug_Printf("Airplay input selected\n");
                LP_Set_linkplay_playback_mode(e_airplay);
                break;
            case e_DLNA:
                Linkplay_Debug_Printf("DLNA input selected\n");
                LP_Set_linkplay_playback_mode(e_DLNA);
                break;
            case e_thumb_drive:
                Linkplay_Debug_Printf("thumb drive input selected\n");
                LP_Set_linkplay_playback_mode(e_thumb_drive);
                break;
            case e_line_in:
                Linkplay_Debug_Printf("line-in input selected\n");
                LP_Set_linkplay_playback_mode(e_line_in);
                break;
            case e_bluetooth:
                Linkplay_Debug_Printf("bluetooth input selected\n");
                LP_Set_linkplay_playback_mode(e_bluetooth);
                break;
            case e_optical:
                Linkplay_Debug_Printf("optical input selected\n");
                LP_Set_linkplay_playback_mode(e_optical);
                break;
            case e_rca:
                Linkplay_Debug_Printf("rca input selected\n");
                LP_Set_linkplay_playback_mode(e_rca);
                break;
            case e_coaxial:
                Linkplay_Debug_Printf("coaxial Linkplay input selected\n");
                LP_Set_linkplay_playback_mode(e_coaxial);
                break;
            case e_mirror:
                Linkplay_Debug_Printf("mirror input selected\n");
                LP_Set_linkplay_playback_mode(e_mirror);
                break;
            case e_slave:
                Linkplay_Debug_Printf("slave input selected\n");
                LP_Set_linkplay_playback_mode(e_slave);
                break;
            default:
                error_handler = e_unknown_plm_command;
                break; 
        }
    }
    return error_handler;
}
 
LinkPlay_Error_t process_plp_command(char* linkplay_command)                    // Linkplay repeat mode commands
{
    /*
        "AXX+PLP+xxx"                                                   // WiFi sends this command to update the repeat mode, where xxx is
                                                                        // 000 Repeat all
                                                                        // 001 Repeat current
                                                                        // 002 Shuffle, repeat all
                                                                        // 003 Shuffle, no repeat
                                                                        // Other No repeat
    */
    // spotify doesn't trigger these messages. 
    
    LinkPlay_Error_t error_handler = e_no_error;

    switch (linkplay_command_data_extraction(linkplay_command))
    {
        case e_repeat_all:
            Serial.print("repeat all songs\n");
            LP_Set_linkplay_repeat_shuffle(e_repeat_all);
            break;
        case e_repeat_current:
            Serial.print("repeat all currnet song\n");
            LP_Set_linkplay_repeat_shuffle(e_repeat_current);
            break;
        case e_shuffle_repeat:
            Serial.print("shuffle and repeat playlist\n");
            LP_Set_linkplay_repeat_shuffle(e_shuffle_repeat);
            break;
        case e_shuffle_no_repeat:
            Serial.print("shuffle, no repeat\n");
            LP_Set_linkplay_repeat_shuffle(e_shuffle_no_repeat);
            break;  
        default:
            error_handler = e_unknown_plp_command; 
            break;
    }
    return error_handler;
}
 
LinkPlay_Error_t process_ply_command(char* linkplay_command)                    // Linkplay playback commands
{
    /*
        "AXX+PLY+xxx"                                                   // WiFi sends this command to update the playback status, where xxx is the status
                                                                        // 000 Stopped
                                                                        // 001 Playing
        AXX+PLY+POStime&                                                // current time in ms                                                                
    */
  
    char c_playback_time[50];
    uint16_t i = 0; 
    uint32_t playback_time_ms = 0;
    
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "POS", 3) == 0)
    {
        if (linkplay_command[11] != '&')
        {  
            for (i = 11; i < strlen(linkplay_command); i++)
            {
                if (linkplay_command[i] == '&')
                {
                    break;
                }
            }
            memset(c_playback_time, ASCII_NUL, 50);
            strncpy(c_playback_time, linkplay_command+11, (i-11));
            playback_time_ms = atoi(c_playback_time);
            Linkplay_Debug_Printf("%d", playback_time_ms);
            LP_Set_linkplay_song_time(playback_time_ms);
        }
    }
    else if (linkplay_command[8] == '0')
    {
        switch (linkplay_command_data_extraction(linkplay_command))
        {
            case e_stopped_playback:
                Linkplay_Debug_Printf("playback stopped\n");
                LP_Set_linkplay_playback_status(e_stopped_playback);
                break;  
            case e_playback_started:
                Linkplay_Debug_Printf("playback started\n");
                LP_Set_linkplay_playback_status(e_playback_started);
                break;
            default: 
                error_handler = e_unknown_playback_status; 
        }
    }
    else 
    {
        error_handler = e_unknown_ply_command;
    }
    return error_handler;
}

LinkPlay_Error_t process_pmt_command(char* linkplay_command)                    // Linkplay voice prompt commands
{
    switch(linkplay_command_data_extraction(linkplay_command))
    {
        case e_voice_prompt_start: 
            Linkplay_Debug_Printf("voice prompt start\n");
            LP_Set_linkplay_voice_promt(e_voice_prompt_start);
            break;
        case e_voice_prompt_stopped:
            Linkplay_Debug_Printf("voice prompt stopped\n");
            LP_Set_linkplay_voice_promt(e_voice_prompt_stopped);
            break; 
        case e_voice_prompt_disabled:
            Linkplay_Debug_Printf("voice prompt disabled\n");
            LP_Set_linkplay_voice_promt(e_voice_prompt_disabled);
            break; 
        case e_voice_prompt_can_be_triggered: 
            Linkplay_Debug_Printf("voice prompt can be triggered by PIC\n");
            LP_Set_linkplay_voice_promt(e_voice_prompt_can_be_triggered);
            break;        
    }
    return e_no_error;
}

LinkPlay_Error_t process_pow_command(char* linkplay_command)                    // Linkplay wifi access point information commands
{
  /*
    AXX+POW+OFF 
    AXX+POW+xxx                     000 = normal
                                    001 = power saving mode
                                    002 = firmware upgrade - cants power down
                                    003 = the device is restarting
  */
    if (linkplay_command[8] == '0')
    {
        switch(linkplay_command_data_extraction(linkplay_command))
        {
            case e_linkplay_power_normal: 
                Linkplay_Debug_Printf("voice prompt start\n");
                LP_Set_linkplay_power_status(e_linkplay_power_normal);
                break;
            case e_linkplay_saving_mode:
                Linkplay_Debug_Printf("voice prompt stopped\n");
                LP_Set_linkplay_power_status(e_linkplay_saving_mode);
                break; 
            case e_linkplay_firmware_upgrade:
                Linkplay_Debug_Printf("voice prompt disabled\n");
                LP_Set_linkplay_power_status(e_linkplay_firmware_upgrade);
                break; 
            case e_linkplay_device_restarting: 
                Linkplay_Debug_Printf("voice prompt can be triggered by PIC\n");
                LP_Set_linkplay_power_status(e_linkplay_device_restarting);
                break;
            default:
                return e_unknown_pow_command;        
        }
        return e_no_error;
    }   
    else
    {
        return e_unknown_pow_command;
    }
     
}

LinkPlay_Error_t process_ra0_command(char* linkplay_command)                    // Linkplay wifi access point information commands
{
    /*
        "AXX+RA0+xxx"                                                   // WiFi sends this command to update its hotspot status to MCU,
                                                                        // or reply MCU's MCU+RA0+GET command where xxx is the status code
                                                                        // 000 No client
                                                                        // 001 New client connected
                                                                        // 002 One client disconnected but there are still some clients connected
                                                                        // FFF Hotspot is hidden
    */
    LinkPlay_Error_t error_handler = e_no_error; 
    
    if (strncmp((linkplay_command + 8), "+ON", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay hotspot is on\n");
        LP_Set_linkplay_hotspot_status(e_hotspot_on);         
    }
    else if (strncmp((linkplay_command + 8), "OFF", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay hotspot is off\n");
        LP_Set_linkplay_hotspot_status(e_hotspot_off);         
    }
    else if (strncmp((linkplay_command + 8), "FFF", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay hotspot is hidden\n");
        LP_Set_linkplay_hotspot_status(e_hotspot_hidden);
    }
    else if (strncmp((linkplay_command + 8), "FFE", 3) == 0)
    {
        Linkplay_Debug_Printf("Linkplay hotspot is not hidden\n");
        LP_Set_linkplay_hotspot_status(e_hotspot_not_hidden);
    }
    else if (linkplay_command[8] == '0')
    {
        switch (linkplay_command_data_extraction(linkplay_command))
        {
            case 0:
                Linkplay_Debug_Printf("no devices connected\n");
                LP_Set_linkplay_hotspot_connections_status(e_no_devices_connected);
                break; 
            case 1:
                Linkplay_Debug_Printf("a new device has connected to the hotspot\n");
                LP_Set_linkplay_hotspot_connections_status(e_new_devices_has_connected);
                break;
            case 2:
                Linkplay_Debug_Printf("Some devices are disconnected,\nbut there are other devices connected\n");
                LP_Set_linkplay_hotspot_connections_status(e_some_devices_are_connected);
                break;   
            default:
                error_handler = e_unknown_connection_status;
                break;
        }       
    }
    else
    {
        error_handler = e_unknown_ra0_command; 
    }
    return error_handler;
}
 
LinkPlay_Error_t process_set_command(char* linkplay_command)                    // Linkplay set time change commands (YYYYMMDDHHMMSS and mon/tue/wed/.../sun)
{
    /*   
        "AXX+SET+RTCYYYYMMDDHHMMSS&"                                    // Notify MCU the time change, where YYYYMMDDHHMMSS is the new time                           
        "AXX+SET+WEKn&"                                                 // Notify MCU the day of week, where n means Sun to Sat 0 - Sun 1 - Mon ... 6 - Sat
    */
    uint8_t day_of_the_week = 0;
    char c_day_of_the_week[2];
    
    char c_current_year[5];
    char c_current_month[5];
    char c_current_day[5];
    char c_current_hour[5];
    char c_current_minute[5];
    char c_current_second[5];
    
    if (strncmp((linkplay_command + 8), "RTC", 3) == 0)
    {
        strncpy(c_current_year, linkplay_command+11, 4);
        strncpy(c_current_month, linkplay_command+15, 2);
        strncpy(c_current_day, linkplay_command+17, 2);
        strncpy(c_current_hour, linkplay_command+19, 2);
        strncpy(c_current_minute, linkplay_command+21, 2);
        strncpy(c_current_second, linkplay_command+23, 2);

        Serial.print("current YYYY: \n");
        Linkplay_Debug_Printf("%s", c_current_year); 
        LP_Set_linkplay_year(atoi(c_current_year));

        Serial.print("MM: \n");
        Linkplay_Debug_Printf("%s", c_current_month); 
        LP_Set_linkplay_month(atoi(c_current_month));

        Serial.print("DD: \n");
        Linkplay_Debug_Printf("%s", c_current_day); 
        LP_Set_linkplay_day(atoi(c_current_day));

        Serial.print("HH: \n");
        Linkplay_Debug_Printf("%s", c_current_hour); 
        LP_Set_linkplay_hour(atoi(c_current_hour));

        Serial.print("MM: \n");
        Linkplay_Debug_Printf("%s", c_current_minute); 
        LP_Set_linkplay_minute(atoi(c_current_minute));

        Serial.print("SS: \n");
        Linkplay_Debug_Printf("%s", c_current_second); 
        LP_Set_linkplay_second(atoi(c_current_second));
    }
    else if (strncmp((linkplay_command + 8), "WEK", 3) == 0)
    {
        strncpy(c_day_of_the_week, linkplay_command+11, 1);
        day_of_the_week = atoi(c_day_of_the_week);
        
        switch(day_of_the_week)
        {
            case e_sunday:
                Linkplay_Debug_Printf("Sunday\n");
                LP_Set_linkplay_weekday(e_sunday);
                break;
            case e_monday:
                Linkplay_Debug_Printf("Monday\n");
                LP_Set_linkplay_weekday(e_monday);
                break;
            case e_tuesday:
                Linkplay_Debug_Printf("Tuesday\n");
                LP_Set_linkplay_weekday(e_tuesday);
                break;
            case e_wednesday:
                Linkplay_Debug_Printf("Wednesday\n");
                LP_Set_linkplay_weekday(e_wednesday);
                break;
            case e_thursday:
                Linkplay_Debug_Printf("Thursday\n");
                LP_Set_linkplay_weekday(e_thursday);
                break;
            case e_friday:
                Linkplay_Debug_Printf("Friday\n");
                LP_Set_linkplay_weekday(e_friday);
                break;
            case e_saturday:
                Linkplay_Debug_Printf("Saturday\n");
                LP_Set_linkplay_weekday(e_saturday);
                break;
            default:
                break;
        }    
    }
    return e_no_error;
}

LinkPlay_Error_t process_sli_command(char* linkplay_command)   
{
    //AXX+SLI+OTA
    //AXX+SLI+DON
    return e_unknown_sli_command;
}
 
LinkPlay_Error_t process_sta_command(char* linkplay_command)                    // Linkplay wireless status commands
{
    /*
        "AXX+STA+000"                                                   // Failed to connect to the AP
        "AXX+STA+001"                                                   // Successfully connected to the AP
        "AXX+STA+002"                                                   // Connecting to the AP
        "AXX+STA+003"                                                   // Following the AXX+STA+000 command, indicating bad RSSI
        "AXX+STA+004"                                                   // Following the AXX+STA+000 command, indicating wrong password
        "AXX+STA+005"                                                   // Following the AXX+STA+000 command, indicating wrong security type
        "AXX+STA+006"                                                   // Following the AXX+STA+000 command, can't find (scan) AP
        "AXX+STA+007"                                                   // Following the AXX+STA+000 command, failed to get IP address from a DHCP server
    */
    uint16_t wireless_status = 0;
 
    wireless_status = linkplay_command_data_extraction(linkplay_command);
 
    switch(wireless_status)
    {
      case e_failed_to_connect:
          Linkplay_Debug_Printf("failed to connect to access point\n"); 
          LP_Set_linkplay_wireless_access_status(e_failed_to_connect);
          break;
      case e_succesfully_connected:
          Linkplay_Debug_Printf("successfully connected to access point!\n");  
          LP_Set_linkplay_wireless_access_status(e_succesfully_connected);
          break;
      case e_connecting_to_ap:
          Linkplay_Debug_Printf("connecting to access point...\n");
          LP_Set_linkplay_wireless_access_status(e_connecting_to_ap);
          break;
      case e_bad_rssi:
          Linkplay_Debug_Printf("failed to connect, bad rssi\n");
          LP_Set_linkplay_wireless_access_status(e_bad_rssi);
          break;
      case e_wrong_password:
          Linkplay_Debug_Printf("failed to connect, wrong password\n"); 
          LP_Set_linkplay_wireless_access_status(e_wrong_password);
          break;
      case e_wrong_security_type:
          Linkplay_Debug_Printf("failed to connect, wrong security type\n"); 
          LP_Set_linkplay_wireless_access_status(e_wrong_security_type);
          break;
      case e_cant_find_ap:
          Linkplay_Debug_Printf("failed to connect, can't find access point\n"); 
          LP_Set_linkplay_wireless_access_status(e_cant_find_ap);
          break;
      case e_failed_to_get_ip_address: 
          Linkplay_Debug_Printf("failed to connect, can't get ip address\n"); 
          LP_Set_linkplay_wireless_access_status(e_failed_to_get_ip_address);
          break;
       default:
          break; 
    }
    return e_no_error;
}
 
LinkPlay_Error_t process_s2m_command(char* linkplay_command)                    // Linkplay slave to master command pass through
{
       // "AXX+S2M+nnn"                                                   // When a pass-through session starts, master speaker MCU will receive AXX+S2M+nnn
      Linkplay_Debug_Printf("PIC initiated master pass thorugh to slave linkplays\n");
      return e_no_error;
}
 
LinkPlay_Error_t process_vol_command(char* linkplay_command)                    // Linkplay volume adjusting commands
{
    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    uint16_t volume_int = 0;

    if (strncmp((linkplay_command + 8), "GET", 3) == 0)
    {
        Linkplay_Debug_Printf("Get the PIC current volume\n");
        LP_send_linkplay_pic_volume();
    }
    else if (linkplay_command[8] == '0' || linkplay_command[8] == '1')
    {
        volume_int = linkplay_command_data_extraction(linkplay_command);
        if (volume_int < 101)
        {
            Serial.print("set volume to: \n");
            Linkplay_Debug_Printf("set volume to: %d", volume_int);
        }
        else
        {
            return e_volume_out_of_bounds;
        }
        
    }
    else
    {
        return e_unknown_vol_command; 
    }
    return e_no_error;  
}

LinkPlay_Error_t process_wan_command(char *linkplay_command)
{
    //  AXX+WAN+LST4E4554474541523137,0,1;7866696E69747977696669,0,0;726F636C6F6E65,0,1&
    //  AXX+WAN+LST5053415544494F,10,1;50534755455354,10,1;5053417564696F5850,10,1&

    /*
        "AXX+VOL+GET"                                                   // Get the current volume level
        "AXX+VOL+xxx"                                                   // WiFi module will confirm volume change by replying AXX+VOL+xxx
        "AXX+VOL+nnn"                                                   // WiFi module sends this command to request volume change,
                                                                        // where nnn is the volume (0 to 100)
    */
    
    char hex_ap[100];
    char ascii_ap[100];
    
    uint16_t string_size = 0; 
    uint16_t current_wan_status = 0;
    uint16_t pos = 0;
    uint16_t status_type = 0;
    uint8_t num_aps = 0;
    uint16_t string_begin = 11;

    if (linkplay_command[11] != '&')
    {
        num_aps += 1;
    }
    else
    {
        Linkplay_Debug_Printf("Can't find any networks\n");
        set_num_access_points(0);
        return e_no_networks_found; 
    }
    
    for (pos = 12; pos < 1024; pos++)
    {
        if (linkplay_command[pos] == ';')
        {
            num_aps += 1;
        }
        else if (linkplay_command[pos] == '&')
        {
            break;
        }
    }
    
    Linkplay_Debug_Printf("Found %d network(s)", num_aps);
    set_num_access_points(num_aps);
    
    for ( current_wan_status = 0; current_wan_status < (num_aps * num_status_per_wan); current_wan_status++)
    {
        for (pos = string_begin; pos < 1024; pos++)
        {
            string_size++;
            if ((linkplay_command[pos] == ',') || (linkplay_command[pos] == ';') || ((linkplay_command[pos] == '&')))
            {
                break;
            } 
        }
        
        strncpy(hex_ap, (linkplay_command + string_begin), string_size-1); 
        strncat(hex_ap, "\0", string_size);

        switch (status_type)
        {
            case e_ap_ssid:
                hex2ascii(hex_ap, ascii_ap, strlen(hex_ap), strlen(ascii_ap));
                Linkplay_Debug_Printf("Network: %s", ascii_ap);
                break;
            case e_ap_rssi: 
                Linkplay_Debug_Printf("RSSI: %d", atoi(hex_ap));
                break;
            case e_ap_channel:
                Linkplay_Debug_Printf("Channel: %d", atoi(hex_ap));
                break;
        }
        
        status_type < max_wan_status ? status_type++ : status_type = 0;
        memset(hex_ap, ASCII_NUL, 100);
        memset(ascii_ap, ASCII_NUL, 100);
        string_begin += string_size;
        string_size = 0;
    }
    return e_no_error;
}

LinkPlay_Error_t process_wps_command(char* linkplay_command)                    // Linkplay wireless WPS config commands
{
    /*
        "AXX+WPS++ON"                                                   // WPS/Smart Config process starts
    */
     switch(linkplay_command[10])
     {
        case 'F':
            Linkplay_Debug_Printf("WPS has been turned off\n");
            Linkplay_Set_wps_status(e_wps_off);
            break;
        case 'N':
            Linkplay_Debug_Printf("WPS has been turned on\n");
            Linkplay_Set_wps_status(e_wps_on);
            break;
        case 'D':
            Linkplay_Debug_Printf("WPS connection setup has ended\n");
            Linkplay_Set_wps_status(e_wps_ended);
            break;
        default:
            break;
     }
     return e_no_error;      
}
 
LinkPlay_Error_t process_www_command(char* linkplay_command)                    // Linkplay internet connection commands
{  
    /*
        "AXX+WWW+xxx"                                                   // WiFi sends this command to update its Internet connection status to MCU,
                                                                        // or reply MCU's MCU+WWW+GET command where xxx is the status code
                                                                        // 000 No Internet connection 
                                                                        // 001 Internet connection is available
    */
    
    uint16_t cunnection_status = 0;
    
    cunnection_status = linkplay_command_data_extraction(linkplay_command);
    
    switch(cunnection_status)
    {
      case e_no_internet_connection:
          Linkplay_Debug_Printf("no internet connection!\n");
          LP_Set_linkplay_internet_status(false);
          break;
      case e_connected_to_internet:
          Linkplay_Debug_Printf("connected to the internet!\n");
          Serial1.println("MCU+INF+GET\n");
          LP_Set_linkplay_internet_status(true);
          break;   
      default: 
          break;
    }
    return e_no_error;
}
 
uint16_t linkplay_command_data_extraction(char* linkplay_command)
{
    char status_str[4] = "";
 
    strncpy(status_str, linkplay_command + 8, 3);                       // copy last three chars into string "AXX+WWW+xxx"
    strcat(status_str, "\0");  
    return(atoi(status_str));
}

int16_t hex2ascii(const char *hexArray, char *asciiArray, uint8_t hexArrayLength, uint8_t asciiArrayLength)
{
    int16_t i = 0;
    int16_t j = 0;
    memset(asciiArray, ASCII_NUL, asciiArrayLength);
    
    for (i = 0; i<hexArrayLength; i+=2 )
    {
        char val1 = hexArray[i];
        char val2 = hexArray[i+1];
            
        if( val1 > 0x60) 
        {
            val1 -= 0x57;
        }
        else if(val1 > 0x40) 
        {
            val1 -= 0x37;
        }
        else 
        {
            val1 -= 0x30;
        }
            
        if( val2 > 0x60)
        {
            val2 -= 0x57;
        }
        else if(val2 > 0x40)
        {
            val2 -= 0x37;
        }
        else 
        {
            val2 -= 0x30;
        }
            
        if(val1 > 15 || val2 > 15 || val1 < 0 || val2 < 0)
        {
            return e_no_error;
        }
                    
        asciiArray[j] = val1*16 + val2;        
        j++;
    }
    return j;
}
>>>>>>> 17065abea13cce02ee98c26819458a3a5b7b7155
