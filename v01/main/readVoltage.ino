float readVoltage(int pin) { 
  unsigned int total = 0;
  
  for (int i=0; i<AVG_NUM; i++) {                                               
    total += analogRead(pin);     // read the input pin
//    float volt = analogRead(pin)*(5.0 / 1023.0);
//    Serial.println(volt);
    // The delay is arbitrary.
    // It can be 0 to 20ms.
    // Test for your own circuit what is best.
    delayMicroseconds(20); // 50;
  }
  // The voltage is RAW_ADC / 1023 * 5V and also divided by the amount of samples for average.
  // Convert every integer to float before calculating something.
  // This way, the extra bits gained by averaging are used in the calculation.
  float voltage = (float) total / 1023.0 * 5.0 / (float) AVG_NUM;
  return voltage;
}
