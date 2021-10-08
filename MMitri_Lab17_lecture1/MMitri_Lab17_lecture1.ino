int buttonState=0;

float timer=0;





void setup() {

  // initialize digital pin LED_BUILTIN as an output.

  pinMode(13, OUTPUT);

  pinMode(12, INPUT);

  Serial.begin(9600);

}





void loop() {

  buttonState = digitalRead(12);

  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(200);                       // wait 

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

  delay(200);                       // wait 

  if (buttonState == HIGH) {

    buttonPushed();         // call buttonPushed function

  }

}



void buttonPushed() {

  Serial.println("Button is pushed");

  timer = 0;

  while (buttonState == HIGH) {

  buttonState = digitalRead(12);

  timer=timer + .5;

  Serial.print(timer);

  Serial.println("\t seconds");

  delay(500);

  }

}
