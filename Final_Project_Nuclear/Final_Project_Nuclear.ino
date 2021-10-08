// Mark Mitri
// ENGR 10
// Final Project: Nuclear Power Plant
// 4/13/2020


// Declaring my variables
#include <Servo.h>
Servo myServo;
int ledPin = 4;
int brightness = 0;
int buttonPin = 2;
int buttonState = 0;
int motorPin = 5;
int motorSpeed = 0;
int servoPin = 11;
int servoPos = 0;
const int potenPin = A0;
int potenValue = 0;
int speakPin = 10;

static int totCov = 640;

// Setting up my inputs and outputs
// and starting my Serial monitor printing my variables
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(potenPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(speakPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(servoPos);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  potenValue = analogRead(potenPin);

  // If statement that checks if the coverage is at 0 OR
  // the emergency button is pressed.
  // Else, run normal operation.
  if(totCov == 0 || buttonState == HIGH){
    emergencyOperation();
  }else{
    normalOperation();
  }

  // Continual printing of the variables
  Serial.println(" ");
  Serial.print("Coverage of Reactor: ");
  Serial.print(totCov);
  Serial.println(" ");
  Serial.print("Pump Speed: ");
  Serial.print(motorSpeed);
  Serial.println(" ");
  Serial.print("Coolant Drain Valve: ");
  Serial.print(potenValue);
  Serial.println(" ");
  delay(1000);

/* These were if statements to check for working components.
 * if(potenValue > 600)
 *   analogWrite(motorPin, 120);
 * else if(potenValue < 400)
 *   analogWrite(motorPin, 0);
 *
 * if(potenValue > 100)
 *   myServo.write(90);
 * else if(potenValue < 50)
 *   myServo.write(0);
 * 
 * if(buttonState == HIGH)
 *   digitalWrite(ledPin, 255);
 * else
 * digitalWrite(ledPin, 0);
*/
  
}

/* Method for the normal operation.
 * Nested if statements to check which value
 * the potentiometer is at and changes the motor speed
 * and the valve accordingly.
 * Also updates the total coverage variable depending on
 * the speed of the motor and how far the valve is open.
*/
void normalOperation(){
  if(potenValue < 171){
    servoPos = 0;
    motorSpeed = 127.5;
    totCov = totCov - 10;
    myServo.write(servoPos);
    analogWrite(motorPin,motorSpeed);
  }else if(potenValue > 171 && potenValue < 341){
    servoPos = 30;
    motorSpeed = 114.75;
    totCov = totCov - 9;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }else if(potenValue > 341 && potenValue < 511.5){
    servoPos = 60;
    motorSpeed = 102;
    totCov = totCov - 8;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }else if(potenValue > 511.5 && potenValue < 682){
    servoPos = 90;
    motorSpeed = 89.25;
    totCov = totCov - 7;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }else if(potenValue > 682 && potenValue < 852.5){
    servoPos = 120;
    motorSpeed = 76.5;
    totCov = totCov - 6;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }else if(potenValue > 852.5 && potenValue < 1023){
    servoPos = 150;
    motorSpeed = 63.75;
    totCov = totCov - 5;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }else{
    servoPos = 180;
    motorSpeed = 51;
    totCov = totCov + 10;
    myServo.write(servoPos);
    analogWrite(motorPin, motorSpeed);
  }
}

/* Method for the emergency operation.
 * First, it resets the coverage and speeds up the pump.
 * Then, it prints a warning message, waits 10 seconds,
 * and sets the coverage to full
 */
void emergencyOperation(){
  totCov = 0;
  motorSpeed = 200;
  tone(speakPin, 1000);
  Serial.println(" ");
  Serial.println("----------------------------------");
  Serial.println("EMERGENCY: No coverage on reactor");
  Serial.print("Pump Speed: ");
  Serial.print(motorSpeed);
  Serial.println(" ");
  Serial.print("Coolant Drain Valve: ");
  Serial.print(potenValue);
  Serial.println(" ");
  digitalWrite(ledPin, HIGH);
  myServo.write(180);
  analogWrite(motorPin,motorSpeed);
  delay(10000);
  totCov = 640;
  noTone(speakPin); 
  Serial.print("Coverage of the Reactor: ");
  Serial.print(totCov);
  Serial.println(" ");
  Serial.println("----------------------------------");
  digitalWrite(ledPin, LOW);
  myServo.write(0);
  motorSpeed = 0;
  analogWrite(motorPin,motorSpeed);
}
