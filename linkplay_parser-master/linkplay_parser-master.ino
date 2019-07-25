#include "linkplay_command_processor.h"
#include "linkplay_manager.h"
#include "linkplay_error_handler.h"
#include "standin_functions.h"

void checkSerial1(void); 
void checkSerialUSB(void);

char newMsgUSB[1050];
char newMsg[1600];

static bool doneRecieving = false; 
static bool doneRecievingUSB = false; 
static uint8_t led = 13; 
static uint16_t i = 0;
static char tempCharLP = '\0';

    
void setup() 
{
  Serial.begin(9600);
  Serial1.begin(57600);
  memset(newMsg, 0, 1600);
  memset(newMsgUSB, 0, 1026);
  pinMode(led, OUTPUT);
  Serial.println("Booting up...");
}

void loop() {
  
    checkSerialUSB();
    if (true == doneRecievingUSB)
    {
        Serial.println(newMsgUSB);
        if (strcmp(newMsgUSB, "lp dump") == 0)
        {
            dump_stored_linkplay_data();
            digitalWrite(led, HIGH);
        }
        else
        {
            Serial1.println(newMsgUSB);
        }
        doneRecievingUSB = false; 
        memset(newMsgUSB, 0, 1026);
    }

    checkSerial1();
    if (true == doneRecieving)
    {
        //Serial.println(newMsg);
        processCommand(newMsg); 
        memset(newMsg, 0, 1600);
        doneRecieving = false; 
        i = 0; 
    }
}


void checkSerialUSB()
{
    static uint16_t i = 0;
    static char tempChar = '\0';

    i = 0;
    while (Serial.available()) 
    {
        doneRecievingUSB = true; 
        tempChar = Serial.read();
        if (tempChar != '\n')
        {
            newMsgUSB[i] = tempChar;
            i++;
            if (i > 1023)
            {
                newMsgUSB[i+1] = '\0';
                i = 0;
                break;
            } 
        }
        else
        {
            Serial.flush();
            i = 0;
            break;
        }
    }
}


void checkSerial1()
{
  
    while (Serial1.available()) 
    {
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
