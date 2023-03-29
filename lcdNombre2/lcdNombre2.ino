#include <LiquidCrystal.h>

#define COLS 16
#define ROWS 2
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
  Serial.begin(9600);
  lcd.begin(COLS, ROWS);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ximenita Chimi");
  lcd.setCursor(0,1);
  lcd.print("Probando mi LCD");
  delay(2000);
}
