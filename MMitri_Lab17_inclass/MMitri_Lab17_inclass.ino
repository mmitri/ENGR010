int buttonState=0;
float timer=0;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(2);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait 
  Serial.println("Button not pushed");
  analogWrite(10,127);
  delay(2000);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    toohot();         // call buttonPushed function
  }
  analogWrite(10,197);
  delay(2000);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    toohot();         // call buttonPushed function
  }
}

void toohot(){
  Serial.println("Button is pushed");
  analogWrite(10,255);
  delay(5000);
}
