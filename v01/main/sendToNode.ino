void sendToNode(float voltage, float current, float power) {
  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.createObject();
  // Se setea el id a enviar;
  root["id"] = device.getId();  
  // Nested json
  JsonObject& params = root.createNestedObject("params");
  // Se setean los parametros obtenidos en el JSON
  params["amps"] = current;
  params["voltage"] = voltage;
  params["watts"] = power;
  // Se envian por comunicacion serial al modulo WIFI;
  root.printTo(node);
}
