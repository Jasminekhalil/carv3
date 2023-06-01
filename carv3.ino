#define CUSTOM_SETTINGS

#define INCLUDE_GAMEPAD_MODULE

#include <Dabble.h>
// L293D Motor Driver Pins
int enR = 3;  
int enL = 6; 
int inAR = 4;
int inBR = 5;
int inAL = 7;
int inBL = 8;


void setup() 
{
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(inAR, OUTPUT); 
  pinMode(inBR, OUTPUT);
  pinMode(inAL, OUTPUT); 
  pinMode(inBL, OUTPUT);    
  Dabble.begin(9600);      
}

void loop() {
Dabble.processInput(); // <-- Gathering Input Data 
  
  if (GamePad.isUpPressed()) // <-- When upward button is pressed on gamepad      
  {
    analogWrite(enR, 255);
    analogWrite(enL, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH);
  }

  else if (GamePad.isDownPressed()) // <-- When downward button is pressed on gamepad 
  {
    analogWrite(enR, 255); 
    analogWrite(enL, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
  }

  else if (GamePad.isLeftPressed()) // <-- When left button is pressed on gamepad 
  {
    analogWrite(enR, 255);
    analogWrite(enL, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
  }

  else if (GamePad.isRightPressed()) // <-- When right button is pressed on gamepad 
  {
    analogWrite(enR, 255);
    analogWrite(enL, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH); 
  }
  else 
  {
    analogWrite(enR, 0); // <-- When no button is pressed on gamepad 
    analogWrite(enL, 0);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, LOW);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, LOW);
  }
}