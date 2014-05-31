#include <Servo.h>

Servo psuedoBob;

//TrigPin to Pin 2
//EchoPin to Pin 4

int trigPin = 7;
int echoPin = 6;

long cm;
long duration;
long distance;


void setup()
{
 psuedoBob.attach(5);
 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(13, OUTPUT);   
 

 Serial.begin(9600);
 psuedoBob.writeMicroseconds(1500);

}


void loop(){
  
  cm = getDistance(); 
  Serial.println(cm);
  
  if(cm< 50 && cm!=0 ){
    digitalWrite(13, HIGH);
    psuedoBob.writeMicroseconds(1700);//turns right
    delay(400);
  }
  else {
    digitalWrite(13, LOW);
    psuedoBob.writeMicroseconds(1300);//turns left
    delay(400);
  }
  
}





long getDistance()
{
  delay(10);  
  //trigger the device
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  

//how long it has been since we sent the ping  
  duration = pulseIn(echoPin, HIGH);

//convert the duration to centimeters ( div by 2 because to and frro)
  cm = duration/27/2;
  return cm;
}
