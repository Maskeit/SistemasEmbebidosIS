#include <SevSeg.h>
SevSeg sevseg; //Instanciamos el objeto SevSeg

void setup() {
  byte Numdigits=4;
  byte Comunes[]={2,3,4,5}; //el acomodo de los digitos, lo puedes experimentar
  byte Segmentos[]={6,7,8,9,10,11,12,13}; //los segmentos del arduino donde conectamos
  byte Tipo=COMMON_ANODE;
  sevseg.begin(Tipo,Numdigits,Comunes,Segmentos);
}

void loop() {
  static unsigned long tiempoejec=millis()+100; //proximo evento
  static int contador=0;

  if(millis()>=tiempoejec){
    tiempoejec+=100;// este es el tiempo de los ms
    contador++;
    if(contador==1000){ //el limite al cual se reinicia el contador, este lo puedes ajustar al gusto
      contador=0;//reseteamos contador
    }
    sevseg.setNumber(contador,1);
  }
  sevseg.refreshDisplay();
}
