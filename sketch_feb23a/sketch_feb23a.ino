#include "SevSeg.h"

SevSeg sevseg;
int n = 0;

const int pushButton = 1;
const int ledPin = 13;
int buttonState = 0;
int buttonPin = 14;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton,INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  //                    A   B   C   D  E  F  G  dp
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
  sevseg.setNumber(n);
  
}

void loop() {
  buttonState = digitalRead(pushButton);
  static unsigned long ejectime = millis()+100; // Tiempo en milisegundos
  static int counter = 0;

  if(buttonState == HIGH){
    digitalWrite(ledPin, HIGH);
    if(millis()>= ejectime){
      ejectime+=300;// Tiempo en milisegundos
      counter++;
      if(counter==9999){ // Límite del contador
        counter=0;//reset
      }
      sevseg.setNumber(counter,10);
    }
    sevseg.refreshDisplay();
  } else{
    digitalWrite(ledPin, LOW);
    sevseg.refreshDisplay();
  }
}
