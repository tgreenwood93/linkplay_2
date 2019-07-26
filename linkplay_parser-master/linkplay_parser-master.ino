#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"
#include "queue.h"
#include "cli.h"
#include "debug.h"

void checkSerial1(void); 
void checkSerialUSB(void);

char newMsgUSB[1050];
char newMsg[1600];

static bool doneRecieving = false; 
//static bool doneRecievingUSB = false; 
static uint8_t led = 13; 
static uint16_t i = 0;
static char tempCharLP = '\0';

    
void setup() 
{
  Serial.begin(9600);
  Serial1.begin(57600);
  memset(newMsg, ASCII_NUL, 1600);
  memset(newMsgUSB, ASCII_NUL, 1026);
  pinMode(led, OUTPUT);
  Serial.println("Booting up...");
  Debug_Init();
  CLI_Init();
}

void loop() {

    checkSerialUSB();
    CLI_Tasks();

    /*if (true == doneRecievingUSB)
    {
        Serial.println(newMsgUSB);
        if (strcmp(newMsgUSB, "lp dump") == 0)
        {
            dump_stored_linkplay_data();
        }
        else if (strcmp(newMsgUSB, "lp ip") == 0)
        {
            get_IP();
        }
        else if (strcmp(newMsgUSB, "lp netstat") == 0)
        {
            get_network_status();
        }
        else if (strcmp(newMsgUSB, "lp metadat") == 0)
        {
            get_meta_data();
        }
        else if (strcmp(newMsgUSB, "lp lastrtc") == 0)
        {
            get_last_rtc();
        }
        else if (strcmp(newMsgUSB, "lp vers") == 0)
        {
            get_lp_version();
        }
        else if (strcmp(newMsgUSB, "lp picv") == 0)
        {
            get_lp_pic_version();
        }
        else if (strcmp(newMsgUSB, "lp ssid") == 0)
        {
            get_ap_ssid();
        }
        else if (strcmp(newMsgUSB, "lp macadd") == 0)
        {
            get_mac_address();
        }
        else if (strcmp(newMsgUSB, "lp sysinf") == 0)
        {
            lp_retrieve_system_info();
        }
        else if (strcmp(newMsgUSB, "lp setssid") == 0)
        {
            lp_set_ssid();
            lp_set_name();

        }
        else if (strcmp(newMsgUSB, "lp help") == 0)
        {
            Serial.println("help menu");
            Serial.println("    lp dump         - dump all stored data");
            Serial.println("    lp netstat      - get network status");
            Serial.println("    lp metadat      - get track metadata");
            Serial.println("    lp lastrtc      - get the last stored clock value");
            Serial.println("    lp vers         - get linkplay firmware version");
            Serial.println("    lp picv         - get the pic version");
            Serial.println("    lp ssid         - get the ssid of the connected ap");
            Serial.println("    lp macadd       - get the mac address of the linkplay");
            Serial.println("    lp sysinf       - get linkplay system info");
            Serial.println("    lp setssid      - set the ssid and name of linkplay");
        }
        else
        {
            Serial1.println(newMsgUSB);
        }
        doneRecievingUSB = false; 
        memset(newMsgUSB, 0, 1026);
    }*/
/*
    checkSerial1();
    if (true == doneRecieving)
    {
        //Serial.println(newMsg);
        processCommand(newMsg); 
        memset(newMsg, 0, 1600);
        doneRecieving = false; 
        i = 0; 
    }*/
}


void checkSerialUSB()
{

        _DEBUG_RecieveReadBuffer();
       
   
//    static uint16_t i = 0;
//    static char tempChar = ASCII_NUL;
//
//    i = 0;
//    while (Serial.available()) 
//    {
//        doneRecievingUSB = true; 
//        tempChar = Serial.read();
//        if (tempChar != ASCII_CR)
//        {
//            newMsgUSB[i] = tempChar;
//            i++;
//            if (i > 1023)
//            {
//                newMsgUSB[i+1] = ASCII_NUL;
//                i = 0;
//                break;
//            } 
//        }
//        else
//        {
//            Serial.flush();
//            i = 0;
//            break;
//        }
//    }
}


void checkSerial1()
{
  
    while (Serial1.available()) 
    {
        tempCharLP = Serial1.read();
        if ((tempCharLP != ASCII_CR))
        {
            newMsg[i++] = tempCharLP;            
            if (i > 1598)
            {
                doneRecieving = true; 
                break;
            } 
            if (tempCharLP == '&')
            {
                doneRecieving = true; 
                break;
            }
        }
        else
        {
            doneRecieving = true; 
            newMsg[i+1] = ASCII_NUL;
            break;
        }
    }
}
