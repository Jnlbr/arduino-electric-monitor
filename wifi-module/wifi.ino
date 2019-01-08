#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <SocketIoClient.h>
#include <ESP8266WiFiMulti.h>
#include <Hash.h>
#include "ESP8266HTTPClient.h"
#include "SoftwareSerial.h"
#include <ArduinoJson.h>

#define BAUD_RATE 9600
ESP8266WiFiMulti wiFiMulti;
SocketIoClient webSocket;
SoftwareSerial Arduino(13, 15, false, 256);

// Global variables
String readString = "";
bool isConnected = false;
const String ID = "22";
// Constants
const char* SSIDD     = "Inter u suck"; // Inter u suck
const char* PASSWORD = "t42af78va1aqua"; // t42af78va1aqua
const char* HOST = "192.168.0.107";
const int PORT = 10036;
const char* ADD_PARAM = "http://192.168.0.107:10036/hardware/params/add";
const char* UPDATE_ACTIVE = "http://192.168.0.107:10036/hardware/update/active";
const char* CHANGE_EVENT = "stateChange:22";
const char* CONNECT_EVENT = "connect";
const char* DISCONNECT_EVENT = "disconnect";

void setup() {
  Serial.begin(BAUD_RATE);
  Arduino.begin(BAUD_RATE);
  
  for(uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP]: Boot waiting %d...\n", t);
    Serial.flush();
    Arduino.flush();
    
    delay(1000);
  }

  // Connect to wifi
  wiFiMulti.addAP(SSIDD, PASSWORD);
  while(wiFiMulti.run() != WL_CONNECTED) {
      delay(100);
  }

  webSocket.on(CHANGE_EVENT, handleChange);
  webSocket.on(CONNECT_EVENT, handleActive);
  webSocket.on(DISCONNECT_EVENT, handleDesactive);
  webSocket.begin(HOST,PORT);
}

void loop() {
  webSocket.loop();
  arduinoEvent();
}
