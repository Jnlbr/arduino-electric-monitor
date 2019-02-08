void relayHandler(String event) {
  if(event == "true") {
    if(relayState != LOW) {
      relayState = LOW;  
      digitalWrite(relay, relayState);
    }
  } else if(event == "false") {    
    if(relayState != HIGH) {
      relayState = HIGH;  
      digitalWrite(relay, relayState);
    }
  }
}
