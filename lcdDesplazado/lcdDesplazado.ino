#include <LiquidCrystal.h>

#define COLS 16
#define ROWS 2
#define VELOCIDAD 300

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
String texto_fila = "LCD de Ximenita Chimi";

void setup() {
  Serial.begin(9600);
  lcd.begin(COLS, ROWS);
}

void loop() {
  // Tamanio del texto
  int tam_texto = texto_fila.length();

  // Como entra el texto
  for(int i=tam_texto; i>0; i--){
    String texto = texto_fila.substring(i-1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(texto);
    delay(VELOCIDAD);
  }

  // Desplazamiento derecha
  for(int i=1; i<16; i++){
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(texto_fila);
    delay(VELOCIDAD);
  }

  //Desplazamiento izquierda 2da fila
  for(int i=16; i>=1; i--){
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print(texto_fila);
    delay(VELOCIDAD);
  }

  //Salida por la izquierda
  for(int i=1; i<= tam_texto; i++){
    String texto = texto_fila.substring(i-1);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(texto);
    delay(VELOCIDAD);
  }
}
