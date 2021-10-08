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

int totCov = 640;
int timer = 1;


void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  potenValue = analogRead(potenPin);
//
//  while(timer != 0){
//    for(int i = 0; i<10;i++){
//      Serial.print("Coolant Coverage: ");
//      Serial.println(totCov);
//      Serial.print("Drain valve open Percent: ");
//      Serial.println(servoPos);
//      Serial.print("Pump Strength: ");
//      Serial.println(motorSpeed);
//    }
//    delay(1000);
//  }

  normalOperation();
  delay(100);
  if(totCov = 0 || buttonState == HIGH){
    emergencyOperation();
  }
  
//  if(potenValue > 600)
//    analogWrite(motorPin, 120);
//  else if(potenValue < 400)
//    analogWrite(motorPin, 0);
//
//  if(potenValue > 100)
//    myServo.write(90);
//  else if(potenValue < 50)
//    myServo.write(0);
//  
//  if(buttonState == HIGH)
//    digitalWrite(ledPin, 255);
//  else
//    digitalWrite(ledPin, 0);
  
}

void normalOperation(){
  if(potenValue > 0){
    servoPos = 0;
    myServo.write(servoPos);
    while(servoPos = 30){
      totCov = totCov - 9.9;
      delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue > 171 && potenValue < 341){
    servoPos = 30;
    myServo.write(servoPos);
    while(servoPos = 30){
      totCov = totCov - 8.0;
      delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue > 341 && potenValue < 511.5){
    servoPos = 60;
    myServo.write(servoPos);
    while(servoPos = 60){
      totCov = totCov - 7.0;
        delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue > 511.5 && potenValue < 682){
    servoPos = 90;
    myServo.write(servoPos);
    while(servoPos = 60){
      totCov = totCov - 6.0;
        delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue > 682 && potenValue < 852.5){
    servoPos = 120;
    myServo.write(servoPos);
    analogWrite(motorPin,200);
    while(servoPos = 60){
      totCov = totCov - 5.0;
        delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue > 852.5 && potenValue < 1023){
    servoPos = 150;
    myServo.write(servoPos);
    while(servoPos = 60){
      totCov = totCov - 4.0;
        delay(1000);
    }
    pumpSpeed();
  }
  delay(100);
  if(potenValue == 1023){
    servoPos = 180;
    myServo.write(servoPos);
    pumpSpeed();
  }
  delay(100);
}

void emergencyOperation(){
  totCov = 0;
  motorSpeed = 200;
  tone(speakPin, 1000);
  Serial.println("EMERGENCY: No coverage on reactor");
  digitalWrite(ledPin, HIGH);
  myServo.write(180);
  analogWrite(motorPin,motorSpeed);
  delay(10000);
  totCov = 640;
  noTone(speakPin);
  digitalWrite(ledPin, LOW);
  myServo.write(0);
  motorSpeed = 0;
  analogWrite(motorPin,motorSpeed);
}

void pumpSpeed(){
  if(totCov > 560){
    motorSpeed = 0;
    analogWrite(motorPin,motorSpeed);
  }
  delay(100);
  if(totCov > 480 && totCov < 560){
    motorSpeed = 140;
    analogWrite(motorPin,motorSpeed);
    while(motorSpeed = 140){
      totCov = totCov + 5.0;
      delay(1000);
    }
  }
  delay(100);
  if(totCov > 400 && totCov < 480){
    motorSpeed = 150;
    while(motorSpeed = 150){
      totCov = totCov + 6.0;
      delay(1000);
    }
  }
  delay(100);
  if(totCov > 320 && totCov < 400){
    motorSpeed = 160;
    while(motorSpeed = 160){
      totCov = totCov + 7.0;
      delay(1000);
    }
  }
  delay(100);
  if(totCov > 240 && totCov < 320){
    motorSpeed = 170;
    while(motorSpeed = 170){
      totCov = totCov + 8.0;
      delay(1000);
    }
  }
  delay(100);
  if(totCov < 240){
    motorSpeed = 200;
    while(motorSpeed = 200){
      totCov = totCov + 9.9;
      delay(1000);
    }
  }
}
