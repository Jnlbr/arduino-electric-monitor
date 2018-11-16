void relayHandler() {
  if(relayState == LOW) {
    digitalWrite(relay, HIGH);
    relayState = HIGH;
  } else {
    digitalWrite(relay, LOW);
    relayState = LOW;
  }
}
