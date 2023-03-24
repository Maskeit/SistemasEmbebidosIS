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

}

void loop() {
  
 //Mostrar el número ingresado en el display
    readAction();
    readNumber();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Se ha guardado");
    lcd.setCursor(0, 1);
    lcd.print("su numero!");
    lcd.setCursor(11, 1);
    lcd.print("1111");
    delay(5000);
}
void readNumber() {
  char key;
  int count = 0;
  number = 0;
  lcd.clear();
  lcd.print("Ingrese numero:");
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
}

void readAction(){
  char key;
  int count = 0;
  number = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("'A' to Read");
  lcd.setCursor(0, 1);
  lcd.print("'B' to Save");
  
  if(key == 'A'){
//    saveNumber();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Presiono A");
  }else{
     while (count < 1) {
      key = keypad.getKey();
      if (key != NO_KEY && isDigit(key)) {
        lcd.setCursor(count, 1);
        lcd.write(key);
        number = number * 10 + (key - '0');
        count++;
      }   
    }
  }
  delay(100);
}
