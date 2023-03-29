#include <EEPROM.h>

int i = 0;

void setup() {
  for (i=0; i<256; i++){
    EEPROM.write(i, i);
  }
  /*EEPROM.write(1,1);
  EEPROM.write(2,2);
  EEPROM.write(3,4);
  EEPROM.write(4,8);
  EEPROM.write(5,16);
  EEPROM.write(6,32);
  EEPROM.write(7,64);
  EEPROM.write(8,128);*/
  /*i=0;
  do{
    EEPROM.write(i+1,128);
    EEPROM.write(i+2,64);
    EEPROM.write(i+3,32);
    EEPROM.write(i+4,16);
    EEPROM.write(i+5,8);
    EEPROM.write(i+6,4);
    EEPROM.write(i+7,2);
    EEPROM.write(i+8,1);
    i=i+8;
  }while(i<256);*/
}

void loop() {
}
