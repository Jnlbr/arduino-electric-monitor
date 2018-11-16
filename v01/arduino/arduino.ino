#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "ACS712.h"

#define BAUD_RATE 9600
ACS712 sensor(ACS712_30A, A1);

SoftwareSerial Node(10, 11); // RX, TX

// Pin asignado al relay
int relay = 8;
// Variable para llevar registro de estado del relay;
volatile byte relayState = LOW;
// String que contiene el mensaje obtenido por el puerto serial;
String readString = "";

void setup() {
  // Configurando pin digital como salida;
  pinMode(relay, OUTPUT);
  // Inicialmente se coloca el pin en LOW;
  digitalWrite(relay, LOW);

  // Se inician los puertos seriales a 9600 baud rate;
  Serial.begin(BAUD_RATE);
  Node.begin(BAUD_RATE);

  Serial.println("Calibrating...");
  Serial.println(sensor.calibrate());
}

void loop() {
  unsigned int x = 0;
  float acsValue = 0.0,
        samples = 0.0,
        avgAcs = 0.0,
        acsValueF = 0.0;
  
  float current = sensor.getCurrentDC();
  acsValue = analogRead(A0);
  Serial.println(String("I = ") + current + " A");
  Serial.println(String("NOSEQUE = ") + acsValue);
  
//  for (int x = 0; x < 1000; x++) {
//    acsValue = analogRead(A0);
//    samples = samples + acsValue;
//    Serial.print("Read it: "); Serial.println(acsValue);
//    delay (200); // 5
//  }
//  avgAcs = (samples / 1000.0);  
//  Serial.print("Avg Acs:  ");Serial.println(avgAcs);
//  
//  acsValueF = (2.5 - (avgAcs * (5.0 / 1024.0)) ) / 0.066;
//  Serial.print("Acs value:  ");Serial.println(acsValueF);
//
//  sendToNode(acsValueF);
  
  serialEvent();
  delay(1000);
}
