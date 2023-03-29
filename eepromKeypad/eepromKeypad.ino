#include <Keypad.h>
#include <LiquidCrystal.h>
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
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); // Configuramos la dirección del display (0x3F) y sus dimensiones (16x2)

long number = 0;

void setup() {
  // Inicializamos el display LCD
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
  long savedNumber = readLongFromEEPROM(100); // leer el número guardado en la dirección de memoria 0
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

void writeLongIntoEEPROM(int address, long number)
{ 
  EEPROM.write(address, (number >> 24) & 0xFF);
  EEPROM.write(address + 1, (number >> 16) & 0xFF);
  EEPROM.write(address + 2, (number >> 8) & 0xFF);
  EEPROM.write(address + 3, number & 0xFF);
}

long readLongFromEEPROM(int address)
{
  return ((long)EEPROM.read(address) << 24) +
         ((long)EEPROM.read(address + 1) << 16) +
         ((long)EEPROM.read(address + 2) << 8) +
         (long)EEPROM.read(address + 3);
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
   Serial.begin(9600);
  
  writeLongIntoEEPROM(100, number);
  long number = readLongFromEEPROM(100);
  
  Serial.print("Number: ");
  Serial.println(number);

    // Mostrar un mensaje de confirmación
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Clave guardada");
  delay(1000);
}  
