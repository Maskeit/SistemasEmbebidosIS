/* LCD:
   * LCD RS  pin to analog pin A0
   * LCD  Enable pin to analog pin A1
   * LCD D4  pin to analog pin A2
   * LCD D5  pin to analog pin A3
   * LCD D6  pin to analog pin A4
   * LCD D7  pin to analog pin A5
   * 
   Matriz:
   * ROW1 pin  to digital pin 5
   * ROW2 pin  to digital pin 4
   * ROW3 pin  to digital pin 3
   * ROW4 pin  to digital pin 2
   * COLUMN1  pin to digital pin 6
   * COLUMN2  pin to digital pin 7
   * COLUMN3  pin to digital pin 8
   * COLUMN4  pin to digital pin 9 
*/

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte ROWS = 4;
const byte COLS = 4;
/*char keys[COLS][ROWS] = {{'*','7','4','1'},
                         {'0','8','5','2'},   
                         {'#','9','6','3'},
                         {'D','C','B','A'}};    */
char keys[ROWS][COLS] = {{'1','2','3','A'},
                         {'4','5','6','B'},   
                         {'7','8','9','C'},
                         {'*','0','#','D'}};                         
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

byte xx[] = {
  B01110,
  B01110,
  B10101,
  B11011,
  B10101,
  B01110,
  B01110,
  B11111
};
byte ii[] = {
  B11011,
  B11111,
  B10011,
  B11011,
  B11011,
  B11011,
  B10001,
  B11111
};
byte mm[] = {
  B11111,
  B11111,
  B00101,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111
};
byte ee[] = {
  B11111,
  B11111,
  B10001,
  B01110,
  B00000,
  B01111,
  B10001,
  B11111
};
byte cora[] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, xx);
  lcd.createChar(1, ii);
  lcd.createChar(2, mm);
  lcd.createChar(3, ee);
  lcd.createChar(4, cora);
  lcd.setCursor(0, 0);
  lcd.print("LCD de Xime");
  /*lcd.setCursor(10, 0);
  lcd.write(byte(0));
  lcd.setCursor(11, 0);
  lcd.write(byte(1));
  lcd.setCursor(12, 0);
  lcd.write(byte(2));
  lcd.setCursor(13, 0);
  lcd.write(byte(3));*/
  lcd.setCursor(14, 0);
  lcd.write(byte(4));
  lcd.setCursor(15, 0);
  lcd.write(byte(4));
}

void loop() {
  char key = kpd.getKey();
  lcd.setCursor(0, 1);
  lcd.print("SEG= ");
  lcd.print(millis() / 1000);
  if(key){
    lcd.setCursor(9, 1);
    lcd.print("TEC= ");
    lcd.print(key);
  }
}
