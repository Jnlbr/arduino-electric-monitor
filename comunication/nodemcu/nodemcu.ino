#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "SoftwareSerial.h"

#define BAUD_RATE 9600

SoftwareSerial Arduino(13, 15, false, 256);
String readString = "";

void setup() {
  Serial.begin(BAUD_RATE);
  Arduino.begin(BAUD_RATE);
}

void loop() {
  while (Arduino.available()) {
    delay(3); // Necessary delay
    char c = Arduino.read(); // Read the character
    readString += c; // Add the character to the string
  }

  readString.trim();

  if (readString.length() > 0) // If a string has been read...
  {
    Serial.println("Received: " + readString); // Send the parsed string to Serial for debugging
    readString = ""; // Clear the string
  }
}
