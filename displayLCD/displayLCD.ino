#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definir los pines de los botones y los LEDs
#define buttonPin1 2 //seleccion
#define buttonPin2 3 //confirmacion
#define ledPin1 4
#define ledPin2 5
#define ledPin3 6
// Crear una instancia del display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir las opciones del menú
char option1[] = "1.Medir     ";
char option2[] = "2.Calibrar  ";
char option3[] = "3.Inicializar";
char* options[] = {option1, option2, option3};
int numOptions = 3;

// Definir el índice de la opción actual
int currentOption = 0;

void setup(){
  //Configurar los pines de los botones y los LEDs
  pinMode(buttonPin1, INPUT_PULLUP);  //BOTONES
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  //INICIALIZAR EL DISPLAY

    lcd.init();
    lcd.backlight();

    lcd.setCursor(7,0);
    lcd.print("Menu!");
    //mostrar el primer elemento del menu en el display

    
    lcd.setCursor(0,1);
    lcd.print(options[0]);
    digitalWrite(ledPin1, HIGH);
}

void loop(){
  //verificamos si se ha pulsado el boton 1, el de seleccion

  if(digitalRead(buttonPin1) == LOW){
    //cambiar a la opcion siguiente
    currentOption = (currentOption + 1) % numOptions; // esta operación permite recorrer en bucle un conjunto de opciones, asegurándose de que la opción seleccionada siempre se encuentra dentro del rango disponible.

    //Actualizar el display con la nueva opcion
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(options[currentOption]);

    //apagar todos los LEDs
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

    //Encender el led correspondiente a la opcion actual
    if(currentOption == 0){
      digitalWrite(ledPin1,HIGH);
    } else if(currentOption == 1){
      digitalWrite(ledPin2,HIGH);
    } else if(currentOption == 2){
      digitalWrite(ledPin3,HIGH);
    }
    delay(0);
  }

//verificamos si se ha pulsado el segundo boton
  if(digitalRead(buttonPin2) == LOW){
    //Mostrar la opcion seleccionada en el display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Seleccionaste:");
    lcd.setCursor(0,1);
    lcd.print(options[currentOption]);

    //Encender el led correspondiente a la opcion actual
    switch(currentOption) {
      case 0:
        digitalWrite(ledPin1, LOW);
        delay(100);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        break;
      case 1:
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        delay(100); 
        digitalWrite(ledPin3, HIGH);
        break;
      case 2:
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        delay(100);
        break;
      default:
        break;
    }
  }
}
