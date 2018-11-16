// Tested with Arduino 1.5.8 without ACS712-30
#define AVG_NUM 20
const int currentPin = A0;
// Pin asignado al relay
int relay = 8;
// Variable para llevar registro de estado del relay;
volatile byte relayState = LOW;

void setup()       
{
  // Configurando pin digital como salida;
  pinMode(relay, OUTPUT);
  // Inicialmente se coloca el pin en LOW;
  digitalWrite(relay, LOW);
  Serial.begin(9600);
  Serial.println(F("Current Sketch"));
}

void loop()      
{
  // The ASC712-30 has 66mV/A
  // That is 1 amp for every 0.066V.
  // The middle of 2.5V is zero amps.
  float voltage = read_volt (currentPin);
  float amps = (voltage - 2.5) / 0.066;
  Serial.print("Voltage: "); Serial.println(voltage);
  Serial.print("Current: "); Serial.println(amps);
  delay(500);
}


// Read voltage from a certain analog pin.
// AVG_NUM can be up to 60, more does not fit into a unsigned integer.
float read_volt(int pin)
{
  unsigned int total = 0;         // start with zero, this is used for the total value.
  for (int i=0; i<AVG_NUM; i++)   // loop through reading raw adc values AVG_NUM number of times
  {                                               
    total += analogRead(pin);     // read the input pin

    // The delay is arbitrary.
    // It can be 0 to 20ms.
    // Test for your own circuit what is best.
    delayMicroseconds(50);        // pauses for 50 microseconds
  }
  // The voltage is raw_adc / 1023 * 5V and also divided by the amount of samples for average.
  // Convert every integer to float before calculating something.
  // This way, the extra bits gained by averaging are used in the calculation.
  float volt = (float) total / 1023.0 * 5.0 / (float) AVG_NUM;
  return(volt);
}
