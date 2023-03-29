#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"

#define DHTPIN 14
#define DHTTYPE DHT11

//const int num[10] = {B11111100, B01100000, B11011000, B11110010, B01100110, B10110110, B10111110, B11100010, B11111110, B11100110}; //cathode
const int num[10] = {B00000011, B10011111, B00100111, B00001101, B10011001, B01001001, B01000001, B00011101, B00000001, B00011001}; //anode


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Sensor DHT de Ximena Manzo ^.^ <3"));
  //Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  //dht.setup(2);
  dht.begin
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Ups! No se puede leer el sensor :C"));
    return;
  }

  float hif
}
