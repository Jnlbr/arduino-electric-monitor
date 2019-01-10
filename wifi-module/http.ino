void sendParam(String current) {
 if(wiFiMulti.run() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(ADD_PARAM);
    http.addHeader("Content-Type", "application/json");
    String body = paramFormat(current);
    Serial.println("The body of the PARAM_REQUEST is: \n" + body);
    int httpCode = http.POST(body);
    if (httpCode > 0) {
      String payload = http.getString();
      if(httpCode == 200) {
        Serial.println("Success: \n" + payload);
      } else {
        Serial.println("Failure: \n" + payload);
      }
    }
 
    http.end();
  }  
}

void activeDevice(String active) {
 if(wiFiMulti.run() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(UPDATE_ACTIVE);
    http.addHeader("Content-Type", "application/json");
    String body = activeFormat(active);
    Serial.println("The body of the ACTIVE_REQUEST is: \n" + body);
    int httpCode = http.POST(body);
    if (httpCode > 0) {
      String payload = http.getString();
      if(httpCode == 200) {
        Serial.println("Success: \n" + payload);
        // CODE ADDED! This turn OFF or ON the device based on the status save in DB;
        delay(3000);
        Arduino.print(payload);
      } else {
        Serial.println("Failure: \n" + payload);
      }
    }
 
    http.end();
  }  
}

String activeFormat(String active) {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["id"] = ID;
  root["active"] = active;
  String output;
  root.printTo(output);
  return output;
}
String paramFormat(String current) {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["id"] = ID;
  root["current"] = current;
  String output;
  root.printTo(output);
  return output;
}
