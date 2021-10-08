/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led1 = 9;           // the PWM pin the LED is attached to
int led2 = 10;
int led3 = 6;
int led4 = 5;
int brightness1 = 0;    // how bright the LED is
int brightness2 = 255;
int brightness3 = 0;
int brightness4 = 0;
int fadeAmount1 = 5;    // how many points to fade the LED by
int fadeAmount2 = 5;
int fadeAmount3 = 5;
int fadeAmount4 = 5;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);
  analogWrite(led3, brightness3);
  analogWrite(led4, brightness4);

  // change the brightness for next time through the loop:
  brightness1 = brightness1 + fadeAmount1;
  brightness2 = brightness2 - fadeAmount2;
if(brightness1 > 128){
    brightness3 = 255;
    brightness4 = 0;
}
  if(brightness2 > 128){
    brightness4 = 255;
    brightness3 = 0;
  }
  
  // reverse the direction of the fading at the ends of the fade:
  if (brightness1 <= 0 || brightness1 >= 255) {
    fadeAmount1 = -fadeAmount1;
  }

  if (brightness2 <= 0 || brightness2 >= 255) {
    fadeAmount2 = -fadeAmount2;
  }
//
//  if (brightness3 <= 0 || brightness3 >= 255) {
//    fadeAmount3 = -fadeAmount3;
//  }
//
//  if (brightness4 <= 0 || brightness4 >= 255) {
//    fadeAmount4 = -fadeAmount4;
//  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
