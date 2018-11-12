#include <SoftwareSerial.h>
SoftwareSerial Node(10, 11); // RX, TX

#define BAUD_RATE 9600

String readString = "";

void setup() {
  Serial.begin(BAUD_RATE);
  Node.begin(BAUD_RATE);
}

void loop() {
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
