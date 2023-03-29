#include <LiquidCrystal.h>

#define COLS 16
#define ROWS 2
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

// Custom characters:
byte Heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};
byte Bell[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};


void setup() {
  Serial.begin(9600);
  lcd.begin(COLS, ROWS);
  
  // Create new characters:
  lcd.createChar(0, Heart);
  lcd.createChar(1, Bell);
  
  lcd.clear();
  lcd.print("Custom Character...");
}

void loop() {
  // Print all the custom characters:
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(2, 1);
  lcd.write(byte(1));
}
