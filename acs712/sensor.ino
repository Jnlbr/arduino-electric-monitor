float voltagePerPoint = 0.0048828125;
float sensitivity = 0.066; // milivolts

sensor getSensor(float value) {
  sensor s;

  s.voltage = getVoltage(value);
  s.amperage = getAmperage(s.voltage);

  return s;
}

float getVoltage(float value) {
  float voltage = value*voltagePerPoint;
  return voltage-2.5;
}
float getAmperage(float voltage) {
  return voltage/sensitivity;
}
