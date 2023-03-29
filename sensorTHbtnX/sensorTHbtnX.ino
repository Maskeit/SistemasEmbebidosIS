#include "DHT.h"
#include "SevSeg.h"

//Display
SevSeg sevseg;
int n = 0;
int buttonPin = 14;
const int pushButton = 1;
const int ledPin = 13;
int buttonState = 0;

int D1 = 2;
int D2 = 3;
int D3 = 4;
int D4 = 5;
int pinA = 6;
int pinB = 7;
int pinC = 8;
int pinD = 9;
int pinE = 10;
int pinF = 11;
int pinG = 12;
boolean temp = false;

//Sensor
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //Display 
  /*
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton,INPUT_PULLUP);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  // Segmentos          A  B  C  D  E   F   G   dp
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
  //sevseg.setNumber(n);*/

  //Sensor
  Serial.begin(9600);
  Serial.println(F("^u^ Sensor de Ximenita!! ^.^ <3"));
  dht.begin();

  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
}

void loop() {
  /*if(millis()>= ejectime){
    ejectime+=300;// Tiempo en milisegundos
    if(buttonState == HIGH){
      digitalWrite(ledPin, HIGH);
      counter++;
    }
    if(counter==9999){ // Límite del contador
      counter=0;//reset
    }
    sevseg.setNumber(counter,1);
    sevseg.refreshDisplay();
  } else{
    digitalWrite(ledPin, LOW);
    sevseg.refreshDisplay();
  }*/

  buttonState = digitalRead(pushButton);
  //static unsigned long ejectime = millis()+100; // Tiempo en milisegundos
  //static int counter = 0;

  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Algo ha fallado!! :C"));
    return;
  }
  
  //////////////////////////////////////////////////////////
  
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("Humidity: "));
  Serial.print(h); //variable humedad
  Serial.print(F("%  Temperature: "));
  Serial.print(t); //variable temperatura
  Serial.print(F("°C "));
  //
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  int decH = h/10;
  int uniH = h-(decH*10);
  int decT = t/10;
  int uniT = t-(decT*10);

  if(buttonState == HIGH){
    temp = !temp;
    digitalWrite(ledPin, HIGH);
  }

  //humedad
  if(temp == true){ 
    dig1(decH);
    dig2(uniH);
    dig3();
    dig4(1);
  }

  //temperatura
  if(temp == false){
    dig1(decT);
    dig2(uniT);
    dig3();
    dig4(2);
  }
}

void dig1(int dec){
  //D1
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);

  switch(dec){
    case 0:cero();break;
    case 1:uno();break;
    case 2:dos();break;
    case 3:tres();break;
    case 4:cuatro();break;
    case 5:cinco();break;
    case 6:seis();break;
    case 7:siete();break;
    case 8:ocho();break;
    case 9:nueve();break;
  }
}

void dig2(int uni){
  //D2
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  switch(uni){
    case 0:cero();break;
    case 1:uno();break;
    case 2:dos();break;
    case 3:tres();break;
    case 4:cuatro();break;
    case 5:cinco();break;
    case 6:seis();break;
    case 7:siete();break;
    case 8:ocho();break;
    case 9:nueve();break;
  }
}

void dig3(){
  //D3
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  bar();
}

void dig4(int n){
  //D4
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  if(n==1){
    bab();
  }
  if(n==2){
    ce();
  }
}

void cero(){
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
}

void uno(){
  //2
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}

void dos(){
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW); 
}
void tres(){
  //3
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
  delay(1);
}

void cuatro(){
  //4
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);
}
void cinco(){
  //5
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);}

void seis(){
  //6
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);
}

void siete(){
  //7
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
  delay(1);
}

void ocho(){
  //8
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);
}

void nueve(){
  //9
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);
}

void bar(){
  //°
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);
}

void bab(){
  //%
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  delay(1);
}

void ce(){
  //C
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1);
}



//int my_array[10] = {B11111100, B01100000, B11011000, B11110010, B01100110, B10110110, B10111110, B11100010, B11111110, B11100110}; //cathode
//int my_array[10] = {B00000011, B10011111, B00100111, B00001101, B10011001, B01001001, B01000001, B00011101, B00000001, B00011001}; //anode
