void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      isConnected = false;
      break;
    case WStype_CONNECTED: {
      Serial.printf("[WSc] Connected to url: %s\n",  payload);
      isConnected = true;

      // send message to server when Connected
      // socket.io upgrade confirmation message (required)
      webSocket.sendTXT("5"); 
    }
      break;
    case WStype_TEXT:
      Serial.printf("[WSc] get text: %s\n", payload);
//      char * pch = strtok ((char*)payload, ",");
//      while (pch != NULL) {
//        Serial.printf ("%s\n", pch);
//        // TODO store the values where you need them
//        pch = strtok (NULL, ",");
//      }

      // Sending data to the Arduino
      String str = (char*)payload;
      Serial.println(str);
      Arduino.print(str);      
      break;
  }
}
