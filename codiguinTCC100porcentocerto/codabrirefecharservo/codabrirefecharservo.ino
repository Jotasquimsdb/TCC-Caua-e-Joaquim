/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;

// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position 5 6 9 10 11

void setup() {
 myservo.attach(5);  // attaches the servo on pin 9 to the Servo object 
 servo.attach(6);
 servo1.attach(9);
 servo2.attach(10);
 servo3.attach(11);
}

void loop() {
  for (pos = 120; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                   // tell servo to go to position in variable 'pos'
    servo.write(pos);  
    servo1.write(pos);  
    servo2.write(pos);  
    servo3.write(pos);  
    delay(30);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 0; pos <= 70; pos += 1) {
     myservo.write(pos); 
      delay(30);
  }
  for (pos = 180; pos >= 120; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);  
    servo1.write(pos);  
    servo2.write(pos);  
    servo3.write(pos);            // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15 ms for the servo to reach the position
  }
   for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
     myservo.write(pos);      // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15 ms for the servo to reach the position
  }
}
