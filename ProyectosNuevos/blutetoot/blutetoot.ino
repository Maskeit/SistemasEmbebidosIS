#include<SoftwareSerial.h>
SoftwareSerial miBT(3,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Listo.");
  miBT.begin(38400);
}

void loop() {
  //lee BT y envia a Arduino
  if(miBT.available())
  Serial.write(miBT.read());
  //lee arduino y envia a BT
  if(Serial.available())
  miBT.write(Serial.read());
}
