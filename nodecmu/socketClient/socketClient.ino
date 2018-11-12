#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include <Hash.h>

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

#define USE_SERIAL Serial
#define MESSAGE_INTERVAL 30000
#define HEARTBEAT_INTERVAL 25000

uint64_t messageTimestamp = 0;
uint64_t heartbeatTimestamp = 0;
bool isConnected = false;
const char* ssid     = "Inter u suck"; // Inter u suck
const char* password = "t42af78va1aqua"; // t42af78va1aqua

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {


    switch(type) {
        case WStype_DISCONNECTED:
          USE_SERIAL.printf("[WSc] Disconnected!\n");
          isConnected = false;
          break;
        case WStype_CONNECTED: {
          USE_SERIAL.printf("[WSc] Connected to url: %s\n",  payload);
          isConnected = true;

          // send message to server when Connected
          // socket.io upgrade confirmation message (required)
          webSocket.sendTXT("5"); 
        }
          break;
        case WStype_TEXT:
          USE_SERIAL.printf("[WSc] get text: %s\n", payload);
          char * pch = strtok ((char*)payload, ",");
          while (pch != NULL) {
            Serial.printf ("%s\n", pch);
            // TODO store the values where you need them
            pch = strtok (NULL, ",");
          }
          break;
    }
}

void setup() {
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(115200);
    USE_SERIAL.setDebugOutput(true);
    USE_SERIAL.println();
    for(uint8_t t = 4; t > 0; t--) {
      USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
      USE_SERIAL.flush();
      delay(1000);
    }
    WiFiMulti.addAP(ssid, password);
    // WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }
    webSocket.beginSocketIO("192.168.0.104", 10036);    
    webSocket.onEvent(webSocketEvent);
}

void loop() {
    webSocket.loop();

//    if(isConnected) {
//
//        uint64_t now = millis();
//
//        if(now - messageTimestamp > MESSAGE_INTERVAL) {
//            messageTimestamp = now;
//            // example socket.io message with type "messageType" and JSON payload
//            USE_SERIAL.println("SEND PARAMS");
//            webSocket.sendTXT("42[\"params:21\",{\"greeting\":\"hello\"}]");
//        }
//        if((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
//            heartbeatTimestamp = now;
//            // socket.io heartbeat message
//            webSocket.sendTXT("2");
//        }
//    }
}
