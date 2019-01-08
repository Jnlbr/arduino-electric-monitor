#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#define AVG_NUM 100
#define BAUD_RATE 9600

SoftwareSerial Node(10, 11); // RX, TX
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
  Node.begin(BAUD_RATE);
    
  // Configurando pin digital del relay como salida;
  pinMode(relay, OUTPUT);
  // Se coloca el estado inicial;
  digitalWrite(relay, relayState);
}

void loop() {
  float voltage = readVoltage(sensorPIN) - 2.5;
  float current = calculateCurrent(voltage);
  sendToNode(current);
  Serial.println("Voltage: " + String(voltage));
  Serial.println("Current: " + String(current));
  
  wifiEvent();
  delay(2000);
}
