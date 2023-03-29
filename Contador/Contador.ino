#include "SevSeg.h"

SevSeg sevseg; //Se inicia un objeto controlador de los 7 segmentos
int n = 0;
int buttonPin = 14;  // Conectamos la salida


void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  //                    A   B   C   D  E  F  G  dp
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
  sevseg.setNumber(n);
}

void loop() 
{    
  static unsigned long ejectime = millis()+100; // Tiempo en milisegundos
  static int counter = 0;

  if(millis()>= ejectime){
    ejectime+=1000;// Tiempo en milisegundos
    counter++;
    if(counter==9999){ // Límite del contador
      counter=0;//reset
    }
    sevseg.setNumber(counter,10);
  }
  sevseg.refreshDisplay();
}
