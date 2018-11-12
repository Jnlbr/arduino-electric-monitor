#include <EEPROM.h>

// Variables
int idAddress = 0;
long id;

struct device {
  String code;
  int deviceType;
  bool status;
  String deviceName;
}

void setup() {
  Serial.begin(9600); // Baud rate
  
  EEPROM.get(idAddress, id);
  if(id == 0) {
    // HTTP Request TO ask for an unique ID;
  } else {
    // CONNECT to ws;
  }
}

// Main code
void loop() {
  
//  writeLong(1);
  Serial.println(id);
  
  delay(5000); // 5s
}
