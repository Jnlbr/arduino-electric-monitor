#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include <Hash.h>
#include "ESP8266HTTPClient.h"
#include "SoftwareSerial.h"

#define BAUD_RATE 9600

ESP8266WiFiMulti wiFiMulti;
WebSocketsClient webSocket;
SoftwareSerial Arduino(13, 15, false, 256);
String readString = "";
bool isConnected = false;
const char* ssid     = "Inter u suck"; // Inter u suck
const char* password = "t42af78va1aqua"; // t42af78va1aqua
const char* add = "http://192.168.0.104:10036/hardware/params/add";

void setup() {
  Serial.begin(BAUD_RATE);
  Arduino.begin(BAUD_RATE);
  for(uint8_t t = 4; t > 0; t--) {
      Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
      Serial.flush();
      delay(1000);
    }
    wiFiMulti.addAP(ssid, password);
    // WiFi.disconnect();
    while(wiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }
    webSocket.beginSocketIO("192.168.0.104", 10036);    
    webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
  
  while (Arduino.available()) {
    delay(3); // Necessary delay
    char c = Arduino.read(); // Read the character
    readString += c; // Add the character to the string
  }
  readString.trim();
  if (readString.length() > 0) { // If a string has been read...
    sendParams(readString);    
    Serial.println("Received: " + readString); // Send the parsed string to Serial for debugging
    readString = ""; // Clear the string
  }
}
