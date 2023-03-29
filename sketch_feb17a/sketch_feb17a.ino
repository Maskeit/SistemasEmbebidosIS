#include "SevSeg.h"
#include <Bounce2.h>

/*#define BUTTON_PIN 15*/
#define LED_PIN 13
int ledState = LOW;
SevSeg sevseg; //Se inicia un objeto controlador de los 7 segmentos
Bounce debouncer = Bounce();

int n = 0;
int buttonPin = 15;  // Conectamos la salida


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

  debouncer.attach(buttonPin);
  debouncer.interval(500);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
}

void loop() 
{    
  debouncer.update();
  if(debouncer.fell()){
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  pinMode(13, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  digitalWrite(18, LOW);
  digitalWrite(19, HIGH);
  int value = debouncer.read();

  static unsigned long timer = millis()+100;
  static int deciSeconds = 0;
  if(ledState == HIGH){
    if(millis() >= timer){
      /*deciSeconds--;*/
      timer += 200;
      if(deciSeconds == 9999){
        deciSeconds = 0;
      }
      sevseg.setNumber(deciSeconds, 10);
    }
    sevseg.refreshDisplay();
  }else{
    deciSeconds;
    timer;
    sevseg.setNumber(deciSeconds, 1);
    sevseg.refreshDisplay();
  }
  /*static unsigned long ejectime = millis()+100; // Tiempo en milisegundos
  static int counter = 0;

  if(millis()>= ejectime){
    ejectime+=150;// Tiempo en milisegundos
    counter++;
    if(counter==9999){ // Límite del contador
      counter=0;//reset
    }
    sevseg.setNumber(counter,10);
  }
  sevseg.refreshDisplay();*/
}
