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
  if (digitalRead(buttonON) == LOW) {
    digitalWrite(white, LOW);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
    digitalWrite(white, HIGH);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cargando..");

    // Esperar 5 segundos
    unsigned long start_time = millis();
    while (millis() - start_time < 5000) {
      if (digitalRead(buttonON) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Se ha pulsado");
        digitalWrite(white, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        while (digitalRead(buttonON) == LOW) {
          // Esperar a que se suelte el botón
        }
        return;
      }
      if (digitalRead(buttonOFF) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Apagando..");
        digitalWrite(white, LOW);
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
        delay(1000);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(white, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiona para");
        lcd.setCursor(0, 1); 
        lcd.print("Encender");   
        while (digitalRead(buttonOFF) == LOW) {
          // Esperar a que se suelte el botón
        }
        return;
      }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Encendido");
    delay(2000);
  }
}
