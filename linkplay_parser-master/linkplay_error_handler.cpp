#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"

void linkplay_error_handler(uint8_t error_handler, char* linkplay_command)
{
    Serial.print(linkplay_command);
    Serial.print(" ");
               
    switch (error_handler)
    {
        case e_no_error: 
            //Serial.println("command read sucess");
            break;
        case e_unknown_AXX_command:
            Serial.println("not a formatted AXX command");
            break; 
        case e_unknown_command:    
            Serial.println("command was not found in first layer of filtering");
            break;
        case e_unknown_b_command: 
            Serial.println("command was not found in b commands");
            break;
        case e_unknown_c_command:
            Serial.println("command was not found in c commands");
            break;
        case e_unknown_d_command: 
            Serial.println("command was not found in d commands");
            break;
        case e_unknown_e_command:
            Serial.println("command was not found in e commands");
            break;
        case e_unknown_f_command: 
            Serial.println("command was not found in f commands");
            break;
        case e_unknown_g_command:
            Serial.println("command was not found in g commands");
            break;
        case e_unknown_i_command:
            Serial.println("command was not found in i commands");
            break;
        case e_unknown_k_command:
            Serial.println("command was not found in k commands");
            break;
        case e_unknown_l_command: 
            Serial.println("command was not found in l commands");
            break;
        case e_unknown_m_command:
            Serial.println("command was not found in m commands");
            break;        
        case e_unknown_n_command:
            Serial.println("command was not found in n commands");
            break;
        case e_unknown_p_command: 
            Serial.println("command was not found in p commands");
            break;
        case e_unknown_r_command:
            Serial.println("command was not found in r commands");
            break;
        case e_unknown_s_command: 
            Serial.println("command was not found in s commands");
            break;
        case e_unknown_v_command:
            Serial.println("command was not found in v commands");
            break;
        case e_unknown_w_command:
            Serial.println("command was not found in w commands");
            break;
        case e_unknown_bot_command:
            Serial.println("command was not found in bot commands");
            break;
        case e_unknown_bur_command:
            Serial.println("command was not found in bur commands");
            break;
        case e_unknown_cap_command:
            Serial.println("command was not found in cap commands");
            break;
        case e_unknown_chn_command:
            Serial.println("command was not found in chn commands");
            break;
        case e_unknown_dev_command:
            Serial.println("command was not found in dev commands");
            break;
        case e_unknown_eth_command:
            Serial.println("command was not found in eth commands");
            break;
        case e_unknown_fac_command:
            Serial.println("command was not found in fac commands");
            break;
        case e_unknown_get_command:
            Serial.println("command was not found in get commands");
            break;
        case e_unknown_inf_command:
            Serial.println("command was not found in inf commands");
            break;
        case e_unknown_i2s_command:
            Serial.println("command was not found in i2s commands");
            break;
        case e_unknown_key_command:
            Serial.println("command was not found in key commands");
            break;
        case e_unknown_led_command:
            Serial.println("command was not found in led commands");
            break;
        case e_unknown_mcu_command:
            Serial.println("command was not found in mcu commands");
            break;
        case e_unknown_mea_command:
            Serial.println("command was not found in mea commands");
            break;
        case e_unknown_mic_command:
            Serial.println("command was not found in mic commands");
            break;
        case e_unknown_mut_command:
            Serial.println("command was not found in mut commands");
            break;
        case e_unknown_m2s_command:
            Serial.println("command was not found in m2s commands");
            break;
        case e_unknown_nxt_command:
            Serial.println("command was not found in nxt commands");
            break;
        case e_unknown_plm_command:
            Serial.println("command was not found in plm commands");
            break;
        case e_unknown_plp_command:
            Serial.println("command was not found in plp commands");
            break;
        case e_unknown_ply_command:
            Serial.println("command was not found in ply commands");
            break;
        case e_unknown_pmt_command:
            Serial.println("command was not found in pmt commands");
            break;
        case e_unknown_pow_command:
            Serial.println("command was not found in pow commands");
            break;
        case e_unknown_ra0_command:
            Serial.println("command was not found in ra0 commands");
            break;
        case e_unknown_set_command:
            Serial.println("command was not found in set commands");
            break;
        case e_unknown_sli_command:
            Serial.println("command was not found in sli commands");
            break;
        case e_unknown_sta_command:
            Serial.println("command was not found in sta commands");
            break;
        case e_unknown_s2m_command:
            Serial.println("command was not found in s2m commands");
            break;
        case e_unknown_uid_command:
            Serial.println("command was not found in uid commands");
            break;
        case e_unknown_vol_command:
            Serial.println("command was not found in vol commands");
            break;
        case e_unknown_wan_command:
            Serial.println("command was not found in wan commands");
            break;
        case e_unknown_wps_command:
            Serial.println("command was not found in wps commands");
            break;
        case e_unknown_www_command:
            Serial.println("command was not found in www commands");
            break;
        case e_unknown_chan_config:
            break;
        case e_unknown_playback_status:
            break;
    }
}
