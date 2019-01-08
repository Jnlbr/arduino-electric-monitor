float calculateCurrent(float voltage) {
  float current = voltage / 0.066;
  return current;
}

float readVoltage(int pin) { 
  float total = 0;
  
  for (int i=0; i<AVG_NUM; i++) {                                               
    total += analogRead(pin); // read the input pin
    delayMicroseconds(20); // 50;
  }
  // The voltage is RAW_ADC / 1023 * 5V and also divided by the amount of samples for average.
  // Convert every integer to float before calculating something.
  // This way, the extra bits gained by averaging are used in the calculation.
  float voltage = (float) total / 1023.0 * 5.0 / (float) AVG_NUM;
  return voltage;
}
