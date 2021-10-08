#include <Keypad.h>

//defines the password length as 4 (3 numbers, and then something called a null character at the end)
#define Password_Length 4

//defines the passcodes for the door. in the real world, they wouldn't be stored here,
//but instead be stored in a secure place. Fortunatly, this spy organization doesn't
//expect you to have a security team, so they're letting you store the codes here for 
//testing your prototype. 

//Also, if you want to get two extra points on this project, make a comment right below here 
//telling me what color shirt Professor Butler is wearing in the video explaining this project.

//If you're curious, static means that the variable will be saved in the same place on your computer
//for the whole program, and const means it will never change. We do that just to make sure we never
//change them by accident. Also, it just makes you a code programmer and saves some memory on your computer!

//YOU WILL HAVE TO CHANGE THESE TO BE THE CORRECT CODES. 
static const int spy = 0;
static const int analyst = 0;
static const int director = 0;

//Keypad setup
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char hexaKeys[ROWS][COLS] = {  //define the symbols on the buttons of the keypads

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad

byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad

int value = 0;

char customKey = 0;

void setup(){

  Serial.begin(9600);

}

void loop(){
  customKey = customKeypad.getKey();   //check keypad for input
  if (customKey != NO_KEY) {
    if ((customKey >= '0') && (customKey<='9')) {  //Only valid for number keys
      value = value*10;  //First time through is zero then multiply by ten for each input
      value = value + customKey - '0';  //CustomKey input is ASCII - zero is 48, one is 49, etc. Subtract ASCII zero to get to decimal zero
    }
    if(customKey =='#') {
      Serial.println(value);
      value=0;  //reset value once it is printed
    }
  }
}
