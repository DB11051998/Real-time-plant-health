#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(3,5);
 
void setup() {
  s.begin(9600);
  pinMode(A1,INPUT);
  pinMode(A2,OUTPUT);
  
}
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
void loop() {
  root["gasv"]= analogRead(A1);
  //root["gasv"] = (100-(double(root["gasv"])/1023.00)*100);
  if(root["gasv"]>=800){
    digitalWrite(A2,LOW);
  }
  else{
    digitalWrite(A2,HIGH);
  }
  //digitalWrite(A2,HIGH);
  //delay(2000);
  //digitalWrite(A2,LOW);
  //delay(2000);
  
  
 
if(s.available()>0)
{
 root.printTo(s);
}
}
