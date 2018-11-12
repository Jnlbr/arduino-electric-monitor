#include <SoftwareSerial.h>
#include <EEPROM.h>
//#include <Device.h>

// Variables
int addr = 0;
long id;
//Device _device();

// Structs
typedef struct device {
  String code;
  int deviceType;
  bool status;
  String deviceName;
} device; 

void setup() {
  Serial.begin(9600); // Baud rate
//  _device.setName("Jean");
  EEPROM.get(addr, id);
  if(id == 0) {
    // HTTP Request TO ask for an unique ID;
  } else {
    // CONNECT to ws;
  }
}

// Infinite loop
void loop() {
  Serial.println(id);
//  Serial.println(_device.getName());
  delay(5000); // 5s
}

device initialState() {
  device d;

  d.code = "";
  d.deviceType = 1;
  d.status = false;
  d.deviceName = "Some device";

  return d; 
}
