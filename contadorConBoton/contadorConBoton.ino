#include <SevSeg.h>

SevSeg sevseg; //Instanciamos el objeto SevSeg

int botonPin = 14; //pin analogo to digital
int estadoBoton = 0; //inicializamos el boton a 0 cuando no esta conectado
bool botonPresionado = false; //inicializamos el botón como no presionado
int contador = 0;

void setup() {
  byte Numdigits=4;
  byte Comunes[]={12,11,10,9}; //el acomodo de los digitos a,b,c,d,e,f,g
  byte Segmentos[]={2,3,4,5,6,7,8}; //los segmentos del arduino donde conectamos
  byte Tipo=COMMON_ANODE;
  sevseg.begin(Tipo,Numdigits,Comunes,Segmentos);
  pinMode(botonPin, INPUT_PULLUP);
}

void loop() {
    estadoBoton = digitalRead(botonPin); //leemos el estado el boton
    if (estadoBoton == HIGH) { // si el botón se presiona, cambiamos el estado del botón presionado
      botonPresionado = !botonPresionado;
      delay(0); // pequeño delay para evitar rebotes en el botón // sin delay
  }
  if(!botonPresionado){
    static unsigned long tiempoejec=millis()+100; //proximo evento
    if(estadoBoton == HIGH){
        if(millis()>=tiempoejec){
        tiempoejec+=100;// este es el tiempo de los ms
        contador++;
          if(contador==1000){ //el limite al cual se reinicia el contador
          contador=0;//reseteamos contador
            }
      sevseg.setNumber(contador,0);
      sevseg.refreshDisplay();
      }
    }
  } else { // si el botón está presionado, se muestra el último número del contador
      sevseg.setNumber(contador, 1);
      sevseg.refreshDisplay();
  }
}
