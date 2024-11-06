/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/5da216f2-c89f-4df2-b1df-fffcd7719861 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool a;
  bool d;
  bool l;
  bool r;
  bool u;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  Serial2.begin(9600,SERIAL_8N1,16,17);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1000); 
  
  pinMode(19,OUTPUT);
  pinMode(a,INPUT_PULLUP);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  
}


/*
  Since A is READ_WRITE variable, onAChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAChange()  {
  // Add your code here to act upon A change
  if(a == 1){
    Serial2.println("a");
    digitalWrite(19,HIGH);
  }else{
    Serial2.println("n");
    digitalWrite(19,LOW);
  }
}


/*
  Since U is READ_WRITE variable, onUChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onUChange()  {
  // Add your code here to act upon U change
  if(u == 1){
    Serial2.println("u");
    digitalWrite(19,HIGH);
  }else{
    Serial2.println("n");
    digitalWrite(19,LOW);
  }
  
}

/*
  Since D is READ_WRITE variable, onDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onDChange()  {
  // Add your code here to act upon D change
  if(d == 1){
    Serial2.println("d");
    digitalWrite(19,HIGH);
  }else{
    Serial2.println("n");
    digitalWrite(19,LOW);
  }
}

/*
  Since R is READ_WRITE variable, onRChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onRChange()  {
  // Add your code here to act upon R change
  if(r == 1){
    Serial2.println("r");
    digitalWrite(19,HIGH);
  }else{
    Serial2.println("n");
    digitalWrite(19,LOW);
  }
}

/*
  Since L is READ_WRITE variable, onLChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLChange()  {
  // Add your code here to act upon L change
  if(l == 1){
    Serial2.println("l");
    digitalWrite(19,HIGH);
  }else{
    Serial2.println("n");
    digitalWrite(19,LOW);
  }
}