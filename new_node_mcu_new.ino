#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h>  
#include <SoftwareSerial.h>
SoftwareSerial s(D5,D3);
#include <ArduinoJson.h>  
const char* ssid = "sonu";  
const char* password = "sonu11051998";  
WiFiClient client;  
unsigned long myChannelNumber =749889;  
const char * myWriteAPIKey = "Z95TLN5OGT8W05LE";  
 
void setup()  
{  
  Serial.begin(9600);  
  s.begin(9600);
  while (!Serial) continue;
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
}  
void loop()   
{  
  static boolean data_state = false;  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
 
  if (root == JsonObject::invalid())
  {
    return;
  }
  //Print the data in the serial monitor
  Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.println("");
  int data4=root["gasv"];
  Serial.println(data4);
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");
  Serial.println("");  
  ThingSpeak.writeField(myChannelNumber,1,data4, myWriteAPIKey);   
  delay(30000); // ThingSpeak will only accept updates every 15 seconds.  
} 
