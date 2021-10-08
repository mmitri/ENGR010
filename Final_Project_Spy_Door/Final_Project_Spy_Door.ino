// Mark Mitri
// ENGR 010
// 04/16/2020
// Final Project: Spy Door

// Prof. Butler's shirt color was blue :)

#include <Servo.h>
Servo myServo;
const String spy = "700";
const String analyst = "314";
const String director = "161";
const int buttonPinStart = 7;
const int buttonPinClose = 2; 
int buttonStateStart = 0;
int buttonStateClose = 0;
int wrongCode = 0;
int speakPin = 6;
int servoPin = 3;
int servoPos = 90;
const int potenPin = A0;
int potenVal = 0;
int ledPin = 9;
int numLoop = 0;
int numOfEntries = 0;
int numOfSpy = 0;
int numOfAnalyst = 0;
int numOfDirector = 0;
int numOfOpenDoor = 0;
int numOfCloseDoor = 0;
int numOfError = 0;
long randNumber;
String code = " ";
boolean entered = false;
boolean closeDoor = false;
boolean exitApproach = false;
boolean exitInfo = false;
boolean rightCode = false;
boolean exitPower = false;
boolean randPowerOut = false;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPinStart, INPUT);
  pinMode(buttonPinClose, INPUT);
  pinMode(speakPin, OUTPUT);
  pinMode(potenPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(servoPos);
  Serial.begin(9600);
  digitalWrite(ledPin, LOW);
}

void loop(){
  buttonStateStart = digitalRead(buttonPinStart);
  buttonStateClose = digitalRead(buttonPinClose);
  potenVal = analogRead(potenPin);
  if(buttonStateStart == HIGH){
    entered = true;
  }
  if(entered == true){
    Serial.println("Welcome Secret Agent");
    delay(10);
    Serial.println("Enter the access code: ");
    delay(10);
    entered = false;
    exitApproach = false;
    rightCode = false;
    numLoop = 0;
    approach();
  }
  if(buttonStateClose == HIGH || randPowerOut == true){
    closeDoor = true;
  }
  if(closeDoor == true){
    delay(10);
    Serial.println("Closing Door...");
    delay(10);
    closeDoor = false;
    randPowerOut = false;
    numOfEntries++;
    leave();
  }
}
void approach(){
  while(!exitApproach){
    if(Serial.available()>0){
      code = Serial.readStringUntil('\n');
      delay(10);
      if(code.equals(spy)){
        Serial.println("Nice to see you again, Spy. Welcome!");
        wrongCode = 0;
        numOfSpy++;
        myServo.write(180);
        numOfOpenDoor++;
        rightCode = true;
        exitApproach = true;
        powerOut();
      }else if(code.equals(director)){
        Serial.println("Nice to see you again, Director. Welcome!");
        wrongCode = 0;
        numOfDirector++;
        myServo.write(180);
        numOfOpenDoor++;
        rightCode = true;
        exitApproach = true;
        powerOut();
      }else if(code.equals(analyst)){
        Serial.println("Nice to see you again, Analyst. Welcome!");
        wrongCode = 0;
        numOfAnalyst++;
        myServo.write(180);
        numOfOpenDoor++;
        rightCode = true;
        exitApproach = true;
        powerOut();
      }else{
        numLoop++;
        delay(10);
      }
      if(numLoop == 1 && rightCode == false){
        wrongCode = 1;
        numOfError++;
        Serial.println("Wrong Code. Enter again:");
      }else if(numLoop == 2 && rightCode == false){
        wrongCode = 2;
        numOfError++;
        digitalWrite(ledPin, HIGH);
        tone(speakPin,1000);
        delay(3000);
        noTone(speakPin);
        Serial.println("Goodbye");
        Serial.println(" ");
        digitalWrite(ledPin, LOW);
        exitApproach = true;
        leave();
      }
    }
  }
}

void leave(){
  delay(1000);
  myServo.write(90);
  numOfCloseDoor++;
  printInfo();
  for(int x = 0; x < 50; x++) Serial.println();
}

void printInfo(){
    if(numOfEntries == 10 || numOfEntries == 20 || numOfEntries == 30 || numOfEntries == 40 || numOfEntries == 50 
    || numOfEntries == 60 || numOfEntries == 70 || numOfEntries == 80 || numOfEntries == 90 || numOfEntries == 100){
      for(int i = 0; i < 1; i++){
        Serial.println("====================================");
        Serial.print("Number of Spys: ");
        Serial.println(numOfSpy);
        Serial.print("Number of Directors: ");
        Serial.println(numOfDirector);
        Serial.print("Number of Analysts: ");
        Serial.println(numOfAnalyst);
        Serial.print("Number of Times an Error Occured: ");
        Serial.println(numOfError);
        Serial.print("Number of Times the Door Opened: ");
        Serial.println(numOfOpenDoor);
        Serial.print("Number of Times the Door Closed: ");
        Serial.println(numOfCloseDoor);
        Serial.println("====================================");
        }
    }else{
      exit;
    }
  }

void powerOut(){
  randNumber = random(1,10);
    if(randNumber == 3 || randNumber == 7){
      Serial.println("============================");
      Serial.println("RANDOM POWER OUTAGE!");
      Serial.println("Door must be closed manually");
      Serial.println("============================");
      while(randNumber == 3 || randNumber == 7){
        potenVal = analogRead(potenPin);
        delay(10);
        if(potenVal >= 512){
          numOfCloseDoor++;
          randPowerOut = true;
          rightCode = true;
          exitApproach = true;
          randNumber = 0;
        }
      }
    }else{
      exit;
    }
  }
