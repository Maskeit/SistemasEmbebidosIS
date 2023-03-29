#include<EEPROM.h>

int my_array[10] = {B00000011, B10011111, B00100111, B00001101, 
B10011001, B01001001, B01000001, B00011101, B00000001, B00011001};

void setup() {  
  // Configurar pin 7 en modo salida (OUTPUT)
  DDRD = B10000000;
  // Puerto B salida
  DDRB = B11111111;

}

void loop() {
  // Establecer HIGH
  //PORTD = B10000000;
  //delay(1000);
  // Establecer LOW
  //PORTD = B00000000;
  //delay(1000);

  for(int i=0; i<10; i++){
    PORTD = my_array[i];
  }
}
