double voltage = 0;
double current = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 1000; i++) {
    voltage = (voltage + (.0049 * analogRead(A0)));
    delay(1);
  }

  voltage = voltage/1000;
  current = (voltage - 2.5)/0.185;

  Serial.print("Voltage = ");
  Serial.println(voltage, 2);
  
  Serial.print("Current = ");
  Serial.println(current, 2);

  delay(1000);
}
