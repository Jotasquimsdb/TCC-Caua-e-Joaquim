#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
 myservo.attach(5);  // attaches the servo on pin 9 to the Servo object 
 servo.attach(6);
 servo1.attach(9);
 servo2.attach(10);
 servo3.attach(11);
}

void loop() {
  
  myservo.write(0);
  servo.write(180);
  servo1.write(180);
  servo2.write(100);
  servo3.write(180);
  delay(1000);

}
