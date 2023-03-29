#include <EEPROM.h>

int i = 0, j=0;
int val = 0;
int outPin[] = {2,3,4,5,6,7,8,9};
int delayValue = 250;
 
void setup()
{
  Serial.begin(9600);
  for (int k = 0; k < 8; k++)
    pinMode(outPin[k], OUTPUT);
}
 
void loop()
{
  int ii;
  for (ii = 0; ii < 256; ii++){
   for (j = 0; j < 8; j++){
     if ((((EEPROM.read(ii)) >> j) & 1 )  == 1){
         digitalWrite(outPin[j], HIGH);
       }else{
          digitalWrite(outPin[j], LOW);
       }
   }
   val = EEPROM.read(i);
   Serial.print(i);
   Serial.print("\t");
   Serial.print(val);
   Serial.println();
   i = i + 1;
   delay(delayValue);
 }
}
