#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

//se definen los pines del teclado matricial
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

// Creamos el objeto keypad para manejar el teclado matricial
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Definimos los pines del display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Configuramos la dirección del display (0x3F) y sus dimensiones (16x2)

long number = 0;

void setup() {
  // Inicializamos el display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presione una tecla");

  // Inicializamos el monitor serie
  Serial.begin(9600);
}

void loop() {
 //llamar a la funcion que nos pide la accion 
    readAction();
}

void readAction() {
  char key = NO_KEY; // inicializamos key con NO_KEY
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("'A' to Read");
  lcd.setCursor(0, 1);
  lcd.print("'B' to Save");

  while (true) {
    key = keypad.getKey();
    if (key != NO_KEY) {
      if (key == 'A') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiono A");
        delay(1000);
        readNumber();
        break;
      }
      else if (key == 'B') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiono B");
        delay(1000);
        saveNumber();
        break;
      }
    }
    delay(1000);
  }
}

void readNumber() {
  char key;
  int count = 0;
  number = 0;
  lcd.clear();
  lcd.print("Ingrese Passwd:");
  while (count < 4) {
    key = keypad.getKey();
    if (key != NO_KEY && isDigit(key)) {
      lcd.setCursor(count, 1);
      lcd.write(key);
      number = number * 10 + (key - '0');
      count++;
    }   
  }
  delay(500);
  int savedNumber = EEPROM.read(0); // leer el número guardado en la dirección de memoria 0
  if (number == savedNumber) {
    lcd.clear();
    lcd.print("Numero Correcto!");
    lcd.setCursor(0,1);
  } else {
    lcd.clear();
    lcd.print("Numero Incorrecto!");
    lcd.setCursor(0,1);
  }
  delay(2000); // Mostrar el resultado durante 2 segundos antes de borrar la pantalla
  lcd.clear(); // Borrar la pantalla

  // Mostrar el número guardado en la EEPROM en el monitor serie
  Serial.println(savedNumber);
}



void saveNumber(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IngreseNClave");
  int addr = 0;
  char key;
  int count = 0;
  number = 0;
      while (count < 4) {
      key = keypad.getKey();
      if (key != NO_KEY && isDigit(key)) {
        lcd.setCursor(count, 1);
        lcd.write(key);
        number = number * 10 + (key - '0');
        count++;
      }   
    }
    delay(500);
// Guardar el número en la EEPROM
  for (int i = 3; i >= 0; i--) {
    EEPROM.write(addr+i, (number >> (i * 8)) & 0xFF);
  }
  
  // Mostrar un mensaje de confirmación
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Clave guardada");
  delay(1000);
}
