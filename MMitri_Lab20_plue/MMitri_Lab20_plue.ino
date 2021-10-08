int analogValue = 0;

void setup() {
  
}

void loop() {
  analogValue = analogRead(0);
  if(analogValue >= 450){
    analogWrite(10,200);
  }
  if(analogValue < 450){
    analogWrite(10,50);
  }
 
}
