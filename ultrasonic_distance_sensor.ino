//program 3.2.2
#define buzzerpin 5
#include <Servo.h>

int position = 90;

int i = 0;

int j = 0;

Servo servo_5;

const int pingPin = 7;
long microsecondsToCentimeters(long microseconds) {
return microseconds / 29 / 2;
}
void setup() {
  
Serial.begin(9600);
pinMode(buzzerpin,OUTPUT);
  
servo_5.attach(5, 500, 2500);
  
}
void loop() {
  
long duration, cm;
  
pinMode(pingPin, OUTPUT);

digitalWrite(pingPin, LOW);
delayMicroseconds(2);
  
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);

digitalWrite(pingPin, LOW);
  
pinMode(pingPin, INPUT);

duration = pulseIn(pingPin, HIGH);

cm = microsecondsToCentimeters(duration);
    
  if(cm<100){
    digitalWrite(5, LOW);
  } 
  
  else{
  	digitalWrite(5, HIGH);
  }
  /////////////////////////
  position = 90;
  for (position = 1; position <= 179; position += 1) {
    servo_5.write(position);
    delay(2); // Wait for 20 millisecond(s)
  }
  for (position = 179; position >= 1; position -= 1) {
    servo_5.write(position);
  }
  /////////////////////////////
  
Serial.println();
delay(3000);
}