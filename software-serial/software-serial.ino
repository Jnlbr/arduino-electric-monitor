#include <SoftwareSerial.h>
#include <EEPROM.h>
#define RX 10
#define TX 11

// Variables
SoftwareSerial esp8266(RX,TX);

void setup() {
  Serial.begin(9600); // Baud rate

  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  
  esp8266.begin(115200);
  esp8266.println("AT");
  esp8266.println("AT+CWMODE=1");
}

// Main
void loop() {
  Serial.println(id);

  // TESTING esp8266
  String b = ".";
  if(esp8266.available()>0) {
    char c = esp8266.read();
    Serial.println(c);
  }
//  if(Serial.available()) {
//    char c = Serial.read();
//    esp8266.println(c);
//  }
  
  delay(5000); // 5s
}

//esp8266.println("AT");
//  if(esp8266.find("OK")) {
//    Serial.println("Works");
//  } else {
//    Serial.println("Shit");
//  }
