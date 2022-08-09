// include necessary libraries
#include <TFT.h>  
#include <SPI.h>
#include <Keypad.h>

// pin definition for Arduino UNO
#define cs   10
#define dc   9
#define rst  8


// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

int count = 1;
boolean buzz;
float buttonPressed = 0;
float Number;
float tempMin = 70.00, tempMax = 100.00, gsMin = 40.00, gsMax = 60.00, tdMin = 20.00, tdMax = 50.00;
float tempVal = 75.00 , gsVal = 50.00 , tdVal = 35.00 ;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3',' '},
  {'4','5','6',' '},
  {'7','8','9',' '},
  {'N','0','P','E'}
};
byte rowPins[ROWS] = {A0, A1, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {

  Serial.begin(9600);
  
  //initialize the library
  TFTscreen.begin();
  
  //set the text size
  TFTscreen.setTextSize(1);
  
  pinMode(A2, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
  
  char buffer [7];

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  
  // set a white font color
  TFTscreen.stroke(255, 255, 255);
  
  // display table
  TFTscreen.text("Var", 5, 10);
  TFTscreen.text("Sensor", 33, 3);
  TFTscreen.text("Value", 35, 15);
  TFTscreen.text("Trigger", 95, 3);
  TFTscreen.text("Min", 85, 15);
  TFTscreen.text("Max", 130, 15);
  TFTscreen.text("Temp", 1, 30);
  TFTscreen.text("GS", 1, 50);
  TFTscreen.text("TD", 1, 70);

  // set a green font color
  TFTscreen.stroke(0, 255, 0);

  // print temp values
  if((tempVal > tempMax) || (tempVal < tempMin)){
    // set a red font color
    TFTscreen.stroke(0, 0, 255);
    TFTscreen.text(dtostrf(tempVal, 7, 2, buffer), 25, 30);
    digitalWrite(A2, HIGH);
  }
  else{
    TFTscreen.text(dtostrf(tempVal, 7, 2, buffer), 25, 30);
    digitalWrite(A2, LOW);
  }
  // set a green font color
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.text(dtostrf(tempMin, 7, 2, buffer), 70, 30);
  TFTscreen.text(dtostrf(tempMax, 7, 2, buffer), 115, 30);

  // print gas and smoke values
  if((gsVal > gsMax) || (gsVal < gsMin)){
    // set a red font color
    TFTscreen.stroke(0, 0, 255);
    TFTscreen.text(dtostrf(gsVal, 7, 2, buffer), 25, 50);
    digitalWrite(A2, HIGH);
  }
  else{
    TFTscreen.text(dtostrf(gsVal, 7, 2, buffer), 25, 50);
    digitalWrite(A2, LOW);
  }
  // set a green font color
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.text(dtostrf(gsMin, 7, 2, buffer), 70, 50);
  TFTscreen.text(dtostrf(gsMax, 7, 2, buffer), 115, 50);

  // print temp density values
  if((tdVal > tdMax) || (tdVal < tdMin)){
    // set a red font color
    TFTscreen.stroke(0, 0, 255);
    TFTscreen.text(dtostrf(tdVal, 7, 2, buffer), 25, 70);
    digitalWrite(A2, HIGH);
  }
  else{
    TFTscreen.text(dtostrf(tdVal, 7, 2, buffer), 25, 70);
    digitalWrite(A2, LOW);
  }
  // set a green font color
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.text(dtostrf(tdMin, 7, 2, buffer), 70, 70);
  TFTscreen.text(dtostrf(tdMax, 7, 2, buffer), 115, 70);

  printVar();

  char key = keypad.getKey();

  // set a yellow font color
  TFTscreen.stroke(0, 255, 255);
  TFTscreen.text(dtostrf(Number, 7, 2, buffer), 105, 100);
  
  if (key == '0'){ //If Button 0 is pressed
    Serial.println ("Button 0"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 0", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=0;
     }
    else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 0.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10); //Pressed twice
    }
  }
  
  if (key == '1'){ //If Button 1 is pressed
    Serial.println ("Button 1");
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 1", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=1;
     }
    else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 1.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 1; //Pressed twice
     }
  }
  
  if (key == '2'){ //If Button 2 is pressed
    Serial.println ("Button 2"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 2", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=2;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 2.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 2; //Pressed twice
     }
  }
  
  if (key == '3'){ //If Button 3 is pressed
    Serial.println ("Button 3"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 3", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=3;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 3.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 3; //Pressed twice
     }
  }
  
  if (key == '4'){ //If Button 4 is pressed
    Serial.println ("Button 4"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 4", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=4;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 4.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 4; //Pressed twice
     }
  }
  
  if (key == '5'){ //If Button 5 is pressed
    Serial.println ("Button 5"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 5", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=5;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 5.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 5; //Pressed twice
     }
  }
  
  if (key == '6'){ //If Button 6 is pressed
    Serial.println ("Button 6"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 6", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=6;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 6.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 6; //Pressed twice
     }
  }
  
  if (key == '7'){ //If Button 7 is pressed
    Serial.println ("Button 7"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 7", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=7;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 7.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 7; //Pressed twice
     }
  }
  
  if (key == '8'){ //If Button 8 is pressed
    Serial.println ("Button 8"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 8", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=8;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 8.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 8; //Pressed twice
     }
  }
  
  if (key == '9'){ //If Button 9 is pressed
    Serial.println ("Button 9"); 
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed 9", 1, 110);
    buttonPressed++;
     if (Number==0){
      Number=9;
     }
     else if (buttonPressed > 3){
      int x = (buttonPressed - 3);
      float y = 9.0/pow(10,x);
      Number = Number + y;
    }
    else{
      Number = (Number*10) + 9; //Pressed twice
     }
  }
  
  if (key == 'N'){
    Serial.println("Pressed Next");
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed Next", 1, 110);
    count++;
    if (count == 7){
      count = 1;
    }
  }
  
  if (key == 'P'){
    Serial.println("Pressed Prev");
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed Prev", 1, 110);
    count--;
    if (count == 0){
      count = 6;
    }
  }
  
  if (key == 'E'){
    Serial.println("Pressed Edit");
    // set a silver font color
    TFTscreen.stroke(192, 192, 192);
    TFTscreen.text("Pressed Edit", 1, 110);
    buttonPressed = 0;
    editValue();
  }  
}

void editValue(){
  if (count == 1){
      tempMin = Number;
      Number = 0;
    }
  if (count == 2){
      tempMax = Number;
      Number = 0;
    }
  if (count == 3){
      gsMin = Number;
      Number = 0;
    }
  if (count == 4){
      gsMax = Number;
      Number = 0;
    }
  if (count == 5){
      tdMin = Number;
      Number = 0;
    }
  if (count == 6){
      tdMax = Number;
      Number = 0;
    }
}

void printVar(){
  if (count == 1){
       TFTscreen.stroke(255, 0, 0);
       TFTscreen.text("Changing Temperature ", 1, 90);
       TFTscreen.text("Min Value = ", 1, 100);
    }
  if (count == 2){
      TFTscreen.stroke(255, 0, 0);
      TFTscreen.text("Changing Temperature ", 1, 90);
      TFTscreen.text("Max Value = ", 1, 100);
    }
  if (count == 3){
      TFTscreen.stroke(255, 0, 0);
      TFTscreen.text("Changing Gas and ", 1, 90);
      TFTscreen.text("Smoke Min Value = ", 1, 100);
    }
  if (count == 4){
      TFTscreen.stroke(255, 0, 0);
      TFTscreen.text("Changing Gas and ", 1, 90);
      TFTscreen.text("Smoke Max Value = ", 1, 100);
    }
  if (count == 5){
      TFTscreen.stroke(255, 0, 0);
      TFTscreen.text("Changing Temperature ", 1, 90);
      TFTscreen.text("Density Min Value = ", 1, 100);
    }
  if (count == 6){
      TFTscreen.stroke(255, 0, 0);
      TFTscreen.text("Changing Temperature ", 1, 90);
      TFTscreen.text("Density Max Value = ", 1, 100);
    }
}
