#include<DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11 
// Create dht object of type DHT:
DHT dht = DHT(DHTPIN, DHTTYPE);
 
// Create variable
int temperature_celsius;
int temperature_fahrenheit;


uint8_t C_symbol[] ={
  0b00111001, //C
  0b00111100  //Circulo
  };

uint8_t mapa_segmentado[] = {
 // gfedcba
  0b00111111,// 0
  0b00000110,// 1
  0b01011011,// 2
  0b01001111,// 3
  0b01100110,// 4
  0b01101101,// 5
  0b01111101,// 6
  0b00000111,// 7
  0b01111111,// 8
  0b01101111,// 9
  0b01110111,// A
  0b01111100,// b
  0b00111001,// C
  0b01011110,// d
  0b01111001,// E
  0b01110001,// F
};

int numB = sizeof mapa_segmentado / sizeof *mapa_segmentado;

#define DIGIT1 9
#define DIGIT2 10
#define DIGIT3 11
#define DIGIT4 12

int digitPins[] = {DIGIT1, DIGIT2, DIGIT3, DIGIT4};

void set_segment(int numero){
  PORTD =(~mapa_segmentado[numero])<<2;
  PORTB =(~mapa_segmentado[numero])>>6; //el ~ convierte todos los 0 a 1 y viceversa
  
  }
  
void setup(){
  DDRD = DDRD|0b11111100;//registro de salidas digitales
  DDRB = DDRB|0b00000001;//d8 al d13, son entradas o salidas

//este pequeno ciclo es para recorrer el array de digitos, del 1 al 4
  for(int p; p<=4; p++){
    pinMode(digitPins[p],OUTPUT);
    }


  pinMode(DHTPIN,INPUT);

  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  
  dht.begin();
  }
  
void loop(){
  // Wait a few seconds between measurements.
  delay(2000);
  
  // Read the temperature as Celsius and Fahrenheit
  float humidity = dht.readHumidity();
  float temp_c = dht.readTemperature();
  float temp_f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp_c ) || isnan(temp_f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.println(humidity);
  
  Serial.print(F("Grados Celsius: "));
  Serial.println(temp_c);
  
  Serial.print(F("Grados Farhenheit: "));
  Serial.println(temp_f);


  int dc = temp_c / 10;
  int uc = temp_c - (dc*10);
  Serial.print(dc);
  Serial.println(uc);
  
  /*
        for(int b = 0; b<numB; b++){
          bitRead(mapa_segmentado[2],b);
            Serial.print(b);
          }
   */
  if(dc == 0){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[0]);
      delay(0);
      }
    }
  if(dc == 1){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[1]);
      delay(0);
      }
    }
    if(dc == 2){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[2]);
      delay(0);
      }
    }
    if(dc == 3){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[3]);
      delay(0);
      }
    }
    if(dc == 4){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[4]);
      delay(0);
      }
    }
    if(dc == 5){
    for (int i = 0; i < 8; i++){
      digitalWrite(digitPins[3],mapa_segmentado[5]);
      delay(0);
      }
    }
  /*
  for(int n=0; n<16; n++){
    set_segment(n);
    delay(1000);
   }
  */
  
  }

/*
void displayDigit(byte digit, byte value) {
  digitalWrite(digitPins[digit], HIGH);//low
  for (int i = 0; i < 8; i++) {
    byte segmentBit = bitRead(segmentMap[value], i);
    digitalWrite(segmentPins[i], segmentBit);
  }
  delay(5);
  digitalWrite(digitPins[digit], LOW);//high
}
*/






  
