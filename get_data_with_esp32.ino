#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
const char* ssid = "PLATFORUMA";
const char* password = "chetna@123";
#define fan 32
#define Lamp 33
#define AC 25
#define light 26

String serverName ="https://easy---control.herokuapp.com/deviceapi/DeviceApi/";        
unsigned long lastTime = 0;

// Set timer to 5 seconds (5000)
unsigned long timerDelay = 1000;


void setup() {
  Serial.begin(115200); 

  
  pinMode(fan,OUTPUT);
  pinMode(Lamp,OUTPUT);
  pinMode(AC,OUTPUT);
  pinMode(light,OUTPUT);
  
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
     StaticJsonDocument<768> doc;
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      String serverPath = serverName;
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();
 
      if (httpResponseCode>0) {
        String payload = http.getString();       
        Serial.println(payload);
          DeserializationError error = deserializeJson(doc, payload);
          for (JsonObject item : doc.as<JsonArray>()) {

                int id = item["id"]; // 1, 2, 3, 4
                int device_id = item["device_id"]; // 1, 2, 3, 3
                 String device_name = item["device_name"]; // "fan", "Lamp", "AC", "light"
                  const char* device_room = item["device_room"]; // "living room", "living room", "living room", "living ...
                  int device_status = item["device_status"]; // 1, 0, 0, 0
                  Serial.print(device_name);
                 Serial.print("  Status  ");
                Serial.println(device_status);
                if(device_name == "fan"){
                 
                  if(device_status == 1){
                      Serial.println(" fan high  ");
                   digitalWrite(fan,HIGH);
                       }
                    else{
                  digitalWrite(fan,LOW);
                  }
                }
                if(device_name == "Lamp"){
                  if(device_status == 1){
                    Serial.println("lamp high  ");
                   digitalWrite(Lamp,HIGH);
                       }
                    else{
                  digitalWrite(Lamp,LOW);
                  }
                }
                if(device_name == "AC"){
                  if(device_status == 1){
                    Serial.println(" AC high  ");
                   digitalWrite(AC,HIGH);
                       }
                    else{
                  digitalWrite(AC,LOW);
                  }
                }
                if(device_name == "light"){
                  if(device_status == 1){
                    Serial.println(" light high  ");
                   digitalWrite(light,HIGH);
                       }
                    else{
                  digitalWrite(light,LOW);
                  }
                }
                     
            }


      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
