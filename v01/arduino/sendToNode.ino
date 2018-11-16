void sendToNode(float amps) {
  StaticJsonBuffer<200> jsonBuffer;
//  Node.print("{\"id\":21, \"params\": { \"amps\": %f, \"voltage\": 110, \"watts\": 12 }}");
  
  JsonObject& root = jsonBuffer.createObject();
  root["id"] = 21;

  // Nested json
  JsonObject& params = root.createNestedObject("params");
  params["amps"] = amps;
  params["voltage"] = 110;
  params["watts"] = 12;

  root.printTo(Node);
}
