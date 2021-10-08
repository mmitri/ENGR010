/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int lightPin = 0;    //the analog pin the photo resistor is connected to
int ledPin = 9;      //the LED pin connected to
int lightLevel =0;
int analogValue=0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);                              //sets the led pin to output
}

void loop()
{
  
  analogValue = analogRead(lightPin);
  Serial.println(analogValue);
  delay(10);
  lightLevel = analogRead(ledPin);
  Serial.println(lightLevel);
  delay(10);
  
  if(analogValue >= 450){
    digitalWrite(ledPin,LOW);
  }
  if(analogValue < 450){
    digitalWrite(ledPin, HIGH);
  }
}
