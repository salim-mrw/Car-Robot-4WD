//RX

#include <AFMotor.h>
#include <SoftwareSerial.h>

//Myserial

SoftwareSerial Myserial(10,-1); //Using -1 to disable tx pin

char msg = 'n';

//UltraSonic

  unsigned long du1;
  unsigned int di1;
  
  unsigned long du2;
  unsigned int di2;
  
  byte triq1 = 22;
  byte echo1 = 23;
  
  byte triq2 = 24;
  byte echo2 = 25;

//Buzzer

  byte buzzer = 14;

//DC Motor
  
  AF_DCMotor motor1(1,MOTOR12_64KHZ);
  AF_DCMotor motor2(2,MOTOR12_64KHZ);
  AF_DCMotor motor3(3,MOTOR12_64KHZ);
  AF_DCMotor motor4(4,MOTOR12_64KHZ);
  
void setup(){

  //Myserial

    Serial.begin(9600);
    Myserial.begin(9600);
    delay(1500);
    
  //UltraSonic1
    
    pinMode(echo1,INPUT);
    pinMode(triq1,OUTPUT);

  //Buzzer

    pinMode(buzzer,OUTPUT);

  //UltraSonic2
  
    pinMode(echo2,INPUT);
    pinMode(triq2,OUTPUT);
    
}

void loop(){

  digitalWrite(triq1,LOW);
  delayMicroseconds(2);
  digitalWrite(triq1,HIGH);
  delayMicroseconds(10);
  digitalWrite(triq1,LOW);
  du1=pulseIn(echo1,HIGH);
  di1 = (du1/2)*0.034 ;
  //Serial.println(di1);
  
  digitalWrite(triq2,LOW);
  delayMicroseconds(2);
  digitalWrite(triq2,HIGH);
  delayMicroseconds(10);
  digitalWrite(triq2,LOW);
  du2=pulseIn(echo2,HIGH);
  di2 = (du2/2)*0.034 ;
  //Serial.println(di2);

  //to read msg from cloud
  
  msg = Myserial.read();

  Serial.println(msg);
  
    switch(msg){
  
      case 'u':
        
        motor1.setSpeed(255);
        motor1.run(FORWARD);
      
        motor2.setSpeed(255);
        motor2.run(FORWARD);
      
        motor3.setSpeed(255);
        motor3.run(FORWARD);
      
        motor4.setSpeed(255);
        motor4.run(FORWARD);
        
      break;

      case'd':
        
        motor1.setSpeed(255);
        motor1.run(BACKWARD);
      
        motor2.setSpeed(255);
        motor2.run(BACKWARD);
      
        motor3.setSpeed(255);
        motor3.run(BACKWARD);
      
        motor4.setSpeed(255);
        motor4.run(BACKWARD);
        
      break;
      
      case'r':
        
        motor1.setSpeed(255);
        motor1.run(BACKWARD);
      
        motor2.setSpeed(255);
        motor2.run(FORWARD);
      
        motor3.setSpeed(255);
        motor3.run(FORWARD);
      
        motor4.setSpeed(255);
        motor4.run(BACKWARD);
        
      break;
        
      case'l':
        
        motor1.setSpeed(255);
        motor1.run(FORWARD);
      
        motor2.setSpeed(255);
        motor2.run(BACKWARD);
      
        motor3.setSpeed(255);
        motor3.run(BACKWARD);
      
        motor4.setSpeed(255);
        motor4.run(FORWARD);
      
      break;
      
      case 'n':
        
        motor1.setSpeed(0);
        motor1.run(RELEASE);
      
        motor2.setSpeed(0);
        motor2.run(RELEASE);
      
        motor3.setSpeed(0);
        motor3.run(RELEASE);
      
        motor4.setSpeed(0);
        motor4.run(RELEASE);
        
      break;
      
      case 'a':
        
        if(di1 < 30 && di2 < 30){
          
          motor1.setSpeed(250);
          motor1.run(BACKWARD);
        
          motor2.setSpeed(250);
          motor2.run(FORWARD);
        
          motor3.setSpeed(250);
          motor3.run(FORWARD);
        
          motor4.setSpeed(250);
          motor4.run(BACKWARD);
          
          tone(buzzer,600);
          delay(100);
          tone(buzzer,800);
          delay(100);
          
        }
        
        if(di1 > 30 && di2 > 30){
      
          motor1.setSpeed(250);
          motor1.run(FORWARD);
        
          motor2.setSpeed(250);
          motor2.run(FORWARD);
        
          motor3.setSpeed(250);
          motor3.run(FORWARD);
        
          motor4.setSpeed(250);
          motor4.run(FORWARD);
          noTone(buzzer);
          
        }
        
      break;
   }
}
