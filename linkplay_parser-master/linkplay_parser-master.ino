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
    checkSerial1();
    if (true == doneRecieving)
    {
        Serial.println(newMsg);
        processCommand(newMsg); 
        memset(newMsg, 0, 1600);
        doneRecieving = false; 
        i = 0; 
    }
}


void checkSerialUSB()
{
    _DEBUG_RecieveReadBuffer();
}


void checkSerial1()
{
  
    while (Serial1.available()) 
    {
        digitalWrite(13, HIGH);
        tempCharLP = Serial1.read();
        if ((tempCharLP != '\n'))
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
            newMsg[i+1] = '\0';
            break;
        }
    }
}
