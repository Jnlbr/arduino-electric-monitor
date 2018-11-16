void sendParams(String params) {
 
 if(wiFiMulti.run() == WL_CONNECTED) {
//    Serial.println("Is connected");
    HTTPClient http;
    http.begin(add);
    http.addHeader("Content-Type", "application/json");
    
    int httpCode = http.POST(params);
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }
 
    http.end();
  }  
}
