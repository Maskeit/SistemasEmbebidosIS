#include<EEPROM.h>

int pinA = 9;  //defines the pin number
int pinB =10;
int pinC = 11;
int pinD = 12;
int pinE = 13;
int pinF = 14;
int pinG = 15;
int D1 = 5;
int D2 = 6;
int D3 = 7;
int D4 = 8;
int sec1;
int sec2;
int sec3; 
int sec4;
unsigned long int counter;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  /*digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  //determines the counter 
 if (counter >= 1000){
  counter = 0;
  //increment of first digit unit place
  sec4= sec4+1;
 }
 //if unit place = 9 then it will be zero and tenth place will be counting with unit place
 if (sec4 == 10){
  sec4 = 0;
  //increment of tenth place
  sec3 = sec3 + 1;
  //when tenth place = 9 it makes it zero and hundereth place starts counting 
  if (sec3 ==10){
    sec3=0;
    //increment the hundereth place
    sec2= sec2 +1;
  }
  //when hundereth place = 9 it makes zero and starts counting at thousandth place
  if(sec2 == 10){
    sec2=0;
    //increment the thousandth place
    sec1=sec1 + 1;
  }
  //when thousandth place equals to 9 makes it zero and makes the counter restart
  if (sec1 == 10){
    sec1=0;
  }
 }
led1(sec1);  //dispay unit place
delay(3);
led2(sec2);  // display tenth place
delay(3); 
led3(sec3);  // display hundereth place
delay(3);
led4(sec4);  // display thousandth place
delay(3);
counter = counter+100;
}

//define first LED segment to turn on and diplay specific numbers
void led4(int a){
  int t1=100;
  digitalWrite(D4, HIGH); 
  digitalWrite(D3,LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
  //switch to the number to call specific it and display
  switch (a) {
    case 0:
      zero(t1);
      break;
    case 1:
      one(t1);
      break;
    case 2:
      two(t1);
      break;
    case 3:
      three(t1);
      break;
    case 4:
      four(t1);
      break;
    case 5:
      five(t1);
      break;
    case 6:
      six(t1);
      break;
    case 7:
      seven(t1);
      break;
    case 8:
      eight(t1);
      break;
    case 9:
      nine(t1);
      break;
  }
}
//define second LED segment to turn on and diplay specific numbers
void led3(int b){
  int t2=10;
  digitalWrite(D4,LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW); 
  //switch to the number to call specific it and display 
  switch (b) {
    case 0:
      zero(t2);
      break;
    case 1:
      one(t2);
      break;
    case 2:
      two(t2);
      break;
    case 3:
      three(t2);
      break;
    case 4:
      four(t2);
      break;
    case 5:
      five(t2);
      break;
    case 6:
      six(t2);
      break;
    case 7:
      seven(t2);
      break;
    case 8:
      eight(t2);
      break;
    case 9:
      nine(t2);
      break;
  }
}
void led2(int c){
  int t1=100;
  digitalWrite(D4, LOW); 
  digitalWrite(D3,LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D1, LOW);
  //switch to the number to call specific it and display
  switch (c) {
    case 0:
      zero(t1);
      break;
    case 1:
      one(t1);
      break;
    case 2:
      two(t1);
      break;
    case 3:
      three(t1);
      break;
    case 4:
      four(t1);
      break;
    case 5:
      five(t1);
      break;
    case 6:
      six(t1);
      break;
    case 7:
      seven(t1);
      break;
    case 8:
      eight(t1);
      break;
    case 9:
      nine(t1);
      break;
  }
}
void led1(int d){
  int t1=100;
  digitalWrite(D4, LOW); 
  digitalWrite(D3,LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, HIGH);
  //switch to the number to call specific it and display
  switch (d) {
    case 0:
      zero(t1);
      break;
    case 1:
      one(t1);
      break;
    case 2:
      two(t1);
      break;
    case 3:
      three(t1);
      break;
    case 4:
      four(t1);
      break;
    case 5:
      five(t1);
      break;
    case 6:
      six(t1);
      break;
    case 7:
      seven(t1);
      break;
    case 8:
      eight(t1);
      break;
    case 9:
      nine(t1);
      break;
  }
}
// 0 to 9 number outputs to display on the segment
void zero(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  //delay(t);
}
void one(int t ){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
  //delay(t);               // wait for a second
  
}
void two(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  //delay(t); 
}
void three(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  //delay(t);  
}
void four(int t){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  //delay(t);               // wait for a second
  
}
void five(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  //delay(t);               // wait for a second 
}
void six(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  //delay(t);               // wait for a second
  
}
void seven(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  //delay(t);               // wait for a second
  
  
}
void eight(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  //delay(t); 
}
void nine(int t){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  //delay(t);               // wait for a second
  
}
