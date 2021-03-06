/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int buttonState = 0;
int pos = 0;    // variable to store the servo position

void setup() {
 
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    buttonState = digitalRead(2);
    if(buttonState == HIGH){
        myservo.write(90);              // tell servo to go to position in variable 'pos'
                      // waits 15ms for the servo to reach the position
    }
    if(buttonState == LOW){
        myservo.write(0);              // tell servo to go to position in variable 'pos'
                      // waits 15ms for the servo to reach the position
    }
}
