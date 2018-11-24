void relayHandler(String event) {
  prepareJSON(event);
  if(relayState == LOW) {
    digitalWrite(relay, HIGH);
    relayState = HIGH;
  } else {
    digitalWrite(relay, LOW);
    relayState = LOW;
  }
}


void prepareJSON(String json) {
  json.remove(0,2);
  json.remove(0,1);
  int length = strlen(json);
  json.remove(length-1,1);
  Serial.print(json);

//  char * pch = strtok(json, 
}
