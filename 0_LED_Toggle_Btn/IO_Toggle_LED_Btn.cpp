////////////////////////////////////////////////////////
// Filename : IO_Toggle_LED_Btn.cpp
// Author : Sed Centeno
// Date : 11/29/2024
//
// Description :
// Turns on/off an external LED depending on the Adafruit I/O
// Button on the dashboard.
//
// Arguments :
// None
//
// Example Invocation :
// ./IO_Toggle_LED_Btn
/////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MQTTClient.h"
#include "GPIO.h"
using namespace std;
using namespace exploringBB;

#define ADDRESS     "tcp://io.adafruit.com:1883"
#define CLIENTID    "Beagle2"
#define TOPIC       "Adasc592/feeds/project.led-toggle-btn"
#define AUTHMETHOD  "Adasc592"
#define AUTHTOKEN   "AIO_TOKENHERE"
#define QOS         1
#define TIMEOUT     10000L
#define LED_GPIO    60


volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt) {
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    // GPIO Declaration
    GPIO myGPIO(LED_GPIO);
    myGPIO.setDirection(OUTPUT);
    
    int i;
    char* payloadptr;
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");
    payloadptr = (char*) message->payload;
    
    // GPIO
    int Toggle = atoi(payloadptr);
    printf("The value is %d\n", Toggle);
    
    if (Toggle == 1){
      myGPIO.setValue(HIGH);
    }else{
      myGPIO.setValue(LOW);
    }
    
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause) {
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[]) {
    MQTTClient client;
    MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    opts.keepAliveInterval = 20;
    opts.cleansession = 1;
    opts.username = AUTHMETHOD;
    opts.password = AUTHTOKEN;
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    if ((rc = MQTTClient_connect(client, &opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
    MQTTClient_subscribe(client, TOPIC, QOS);

    do {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}

