void arduinoEvent() {
  while (Arduino.available()) {
    delay(3);
    char c = Arduino.read();
    readString += c;
  }
  readString.trim();
  
  if (readString.length() > 0) {
    Serial.println(readString);
    sendParam(readString);    
    readString = ""; // Clear the string
  }
}
