#define acs712 A0

typedef struct sensor {
  float amperage;
  float voltage;
} sensor;

// Rellay pin is controlled with D8
int relay = 8;
volatile byte relayState = LOW;

void setup() {

  // Relay module as output
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
  Serial.begin(9600);
}

void loop() {
  
  if(relayState == HIGH) {
    int value = analogRead(acs712) + 1;
    sensor _sensor = getSensor(value);        
    
    Serial.println("Voltage: " + String(_sensor.voltage));
    Serial.println("Amperage: " + String(_sensor.amperage));
            
    // Turn OFF the device
    digitalWrite(relay, LOW);
    relayState = LOW;
  } else {
    // Turn ON the device
    Serial.println("Was ON, now is OFF");
    digitalWrite(relay, HIGH);
    relayState = HIGH;
  }
  
  delay(5000);
}
