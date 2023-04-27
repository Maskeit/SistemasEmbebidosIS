#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int green = 2;
int red = 3;
int blue = 4;
int white = 5;
int buttonON = 6;
int buttonOFF = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(buttonON, INPUT_PULLUP);
  pinMode(buttonOFF, INPUT_PULLUP);
  lcd.init();                      // Inicializar el LCD
  lcd.backlight();                 // Encender el backlight
  lcd.setCursor(0, 0);             // Seleccionar la posición para el texto
  lcd.print("Presiona para");          // Imprimir el texto
  lcd.setCursor(0, 1); 
  lcd.print("Encender");            
}

void loop() {
  if (digitalRead(buttonON) == LOW && digitalRead(white) == LOW) {
    encender();
  }
  if (digitalRead(buttonOFF) == LOW && digitalRead(white) == HIGH) {
    apagar();
  }
}

void apagar(){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Apagando..");
    for (int i = 0; i < 2; i++) {
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      digitalWrite(blue, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
    }
        digitalWrite(white, LOW);//se apaga el led
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiona para");
        lcd.setCursor(0, 1); 
        lcd.print("Encender");   
}
void encender(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cargando..");
    
    for (int i = 0; i < 2; i++) {
      digitalWrite(blue, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      delay(500);
      digitalWrite(green, LOW);
    }
    digitalWrite(white, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Encendido");
    delay(2000);
}
