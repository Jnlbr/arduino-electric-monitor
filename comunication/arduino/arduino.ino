#include <SoftwareSerial.h>
SoftwareSerial Node(10, 11); // RX, TX

#define BAUD_RATE 9600

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
}

void loop() {
  // Se escribe en el puerto serial los datos obtenidos por el sensor de corriente;
  Node.print("{\"id\":21, \"params\": { \"amps\": 1, \"voltage\": 110, \"watts\": 12 }}");
  
  while (Node.available()) {
    delay(3); // Necessary delay
    char c = Node.read(); // Read the character
    readString += c; // Add the character to the string
  }
  if (readString.length() > 0) {
    Serial.println("Received: " + readString);
    readString = ""; // Clear the string
  }
  delay(2000);
}
