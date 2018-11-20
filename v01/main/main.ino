#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "Device.h"

#define AVG_NUM 100
#define BAUD_RATE 9600

SoftwareSerial node(10, 11); // RX, TX
Device device(21, "aef7842", "LED_SENSOR", true, 5);

// Pin asignado al modulo acs712;
const int sensorPIN = A0;
// Pin asignado al relay;
const int relay = 8;
// Variable para llevar registro de estado del relay;
volatile byte relayState = LOW;
// String que contiene el mensaje obtenido por el puerto serial;
String readString = "";

void setup() {
  // Se inician los puertos seriales a BAUD_RATE;
  Serial.begin(BAUD_RATE);
  node.begin(BAUD_RATE);
    
  // Configurando pin digital del relay como salida;
  pinMode(relay, OUTPUT);
  // Se coloca el estado inicial;
  digitalWrite(relay, relayState);
}

void loop() {
  float voltage = readVoltage(sensorPIN) - 2.5;
  float current = voltage / 0.066;
  float power = device.getVoltage() * current;
  sendToNode(voltage, current, power);
  Serial.println("Voltage: " + String(voltage));
  Serial.println("Current: " + String(current));
  Serial.println("Power: " + String(power));
  serialEvent();
  delay(2000);
}
