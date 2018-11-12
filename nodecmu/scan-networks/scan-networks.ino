#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
#include "ESP8266WiFiMulti.h"
//#include "WebSocketsClient.h"
//#include "Hash.h"

const char* ssid     = "Inter u suck"; // Inter u suck
const char* password = "t42af78va1aqua"; // t42af78va1aqua 
const char* add = "http://192.168.0.104:10036/hardware/params/add";

void setup() {  
// Set WiFi to station mode and disconnect from an AP if it was previously connected  
//  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  
//  sendParams("{\"id\":21, \"params\": { \"amps\": 1, \"voltage\": 110, \"watts\": 12 }}");
  delay(10000);
}

void sendParams(String params) {
 
 if(WiFi.status() == WL_CONNECTED) {
    Serial.println("Is connected");
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
