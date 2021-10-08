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
  if (buttonState == HIGH) {
    buttonPushed();         // call buttonPushed function
  }
  if(buttonState == LOW){
    buttonNotPushed();
  }
}

void buttonNotPushed(){
  Serial.println("Button not pushed");
  timer=0;
  while(buttonState == LOW){
    buttonState = digitalRead(2);
    for (int timer = 0; timer <= 2000; timer += 1000) {
    // sets the value (range from 0 to 255):
    analogWrite(2, fadeValue);
    delay(1000);
  }
}

void buttonPushed() {
  Serial.println("Button is pushed");
  timer = 0;
  while (buttonState == HIGH) {
  buttonState = digitalRead(2)
  timer=timer + .5;
  Serial.print(timer);
  Serial.println("\t seconds");
  delay(500);
  }
}
