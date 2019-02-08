void wifiEvent(){
  if(Node.available()) {
    while (Node.available()) {
      delay(3); // Delay necesario para leer el proximo caracter;
      char c = Node.read(); // Leer el caracter;
      readString += c; // Se anade el caracter al string;
    }
    if (readString.length() > 0) {
      Serial.println("Received from NodeMCU: " + readString);
      // Manejador de eventos del relay;
      relayHandler(readString);
      readString = ""; // Se limpia el String que contiene el valor obtenido;
    }
  }
}
