#include<EEPROM.h>

int i = 0;

void setup() {
  for (i=0; i<1000; i++)
    EEPROM.write(i,1);

}

void loop() {
}
