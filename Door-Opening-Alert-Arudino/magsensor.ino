#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
String Link;
const int sensor = 14; //on which pin the magnetic sensor is connected
int state;
int stevec = 0; //counter
void setup()

{
  pinMode(sensor, INPUT_PULLUP);
  
  Serial.begin(115200);

  Serial.println();



  WiFi.begin("wifiname", "wifipassword");



  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)

  {

    delay(500);

    Serial.print(".");

  }

  Serial.println();



  Serial.print("Connected, IP address: ");

  Serial.println(WiFi.localIP());

}

void loop() {

  state = digitalRead(sensor);
  if(state == LOW && stevec ==0){
    stevec++;
  Serial.println("Works");
  state = HIGH;
    HTTPClient http;
    Link = "http://LOCALIP/PATH"; // replace LOCALIP with your server's IP, replace PATH with whatever you want

    http.begin(Link);
    int httpCode = http.GET();
    http.end();
    }

    else if(state == HIGH){
      Serial.println("does not work");
      stevec = 0;
    }
    delay(1000); 
     
  }

