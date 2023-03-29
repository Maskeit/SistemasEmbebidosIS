#include <Keypad.h> //Incluimos la librería para manejar el teclado matricial
#include <LiquidCrystal_I2C.h> //Incluimos la librería para manejar el display LCD
#include <EEPROM.h>

// Definimos los pines del teclado matricial
const byte ROWS = 4; // 4 filas
const byte COLS = 4; // 4 columnas
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Conectamos las filas del teclado a los pines digitales del 6 al 9
byte colPins[COLS] = {5, 4, 3, 2}; // Conectamos las columnas del teclado a los pines digitales del 2 al 5

#define buttonPin1 10
#define buttonPin2 11

// Creamos el objeto keypad para manejar el teclado matricial
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Definimos los pines del display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Configuramos la dirección del display (0x3F) y sus dimensiones (16x2)

long number = 0;

void setup() {
  
  int persona1 = 2001;
  int persona2 = 2003;
  int persona3 = 1945;
  // Configuramos el modo de los pines
  pinMode(13, OUTPUT); // Conectamos un LED al pin 13 para comprobar que el código está funcionando
  digitalWrite(13, HIGH); // Encendemos el LED
  
  // Inicializamos el display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presione una tecla");
}


void loop() {
  
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  if (digitalRead(buttonPin1) == LOW) {
    // Cambiar a la opción siguiente
    // ...
  }


  if (digitalRead(buttonPin2) == HIGH) {
    // Leer el número de 4 dígitos
    readNumber();

    // Mostrar el número ingresado en el display
    if(number == 2001 or number == 1492){
    lcd.clear();
    lcd.print("Autorizado!:");
    lcd.setCursor(0, 1);
    lcd.print("Bienvenido-Miguel");
    delay(5000); 
    } else {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("No autorizado");
      delay(5000); 
    }
  }
}
void saveNumber(){
  char key;
  int count=0;
  number = 0  ;
}

void readNumber() {
  char key;
  int count = 0;
  number = 0;
  lcd.clear();
  lcd.print("Ingrese numero:");
  switch(key){
        case 'A' : /*Opción 1*/ break; 
        case 'B' : /*Opción 2*/ break; 
        case 'C' : /*Opción 3*/ break; 
        while (count < 1) {
    key = keypad.getKey();
    if (isDigit(key)) {
      lcd.setCursor(count, 1);
      lcd.write(key);
      number = number * 10 + (key - '0');
      count++;
    }   
  }
  delay(500);
  }
  
}
