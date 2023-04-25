#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

#include "DHT.h"
#define DHTPIN 15  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
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

#define ledPinA 12
#define ledPinB 11
#define ledPinC 10
#define ledPinD 13


long number = 0;

void setup() {
  
  // Inicializamos el display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO!");

  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);

  // Inicializamos el monitor serie
  Serial.begin(9600);
    dht.begin();
}
void loop(){
   // temperatura
     // Wait a few seconds between measurements.
  delay(2000);
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
   //
    //readAction(t);
   //seleccionarBebida();
   readAmount(t,0);

}

int readAmount(int temp, int credito){
  int total = 0;
  int count = 0;
  int unPeso = 0;
  int dosPesos = 0;
  int cincPesos = 0;
  int diezPesos = 0;
  
  char key = NO_KEY;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("$");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(6,1);
  lcd.print(temp);
  lcd.setCursor(8,1);
  lcd.print("C");
  
  while (true) {
    key = keypad.getKey();
    if (key != NO_KEY && isDigit(key)) {
      switch(key - '0') {
        case 1:
          unPeso++;
          total += 1;
          break;
        case 2:
          dosPesos++;
          total += 2;
          break;
        case 5:
          cincPesos++;
          total += 5;
          break;
        case 0:
          diezPesos++;
          total += 10;
          break;
        default:
          break;
      }

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Insertado:");
      lcd.setCursor(0,1);
      lcd.print("$");
      lcd.print(total+credito);

      if(total >= 10) {
        credito = seleccionarBebida(temp, total, credito);
        return credito;
      }
    }

    delay(200); // espera un poco para que el usuario pueda soltar el botón
  }
}

int seleccionarBebida(int temp, int total, int credito){
    char key;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("A B C D");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.setCursor(6,1);
    lcd.print(temp);
    lcd.setCursor(8,1);
    lcd.print("C");
    while(true){
        key = keypad.getKey();
        if(key == 'A'){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Selecciono: ");  
            lcd.setCursor(13,0);
            lcd.print(key);
            lcd.setCursor(0,1);
            lcd.print("Temp: ");
            lcd.setCursor(6,1);
            lcd.print(temp);
            lcd.setCursor(8,1);
            lcd.print("C");
            delay(100);
            digitalWrite(ledPinA,HIGH);
            delay(3000);
            digitalWrite(ledPinA,LOW);
            break;
        } else if(key == 'B'){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Selecciono: ");  
            lcd.setCursor(13,0);
            lcd.print(key);
            lcd.setCursor(0,1);
            lcd.print("Temp: ");
            lcd.setCursor(6,1);
            lcd.print(temp);
            lcd.setCursor(8,1);
            lcd.print("C");
            delay(100);
            digitalWrite(ledPinB,HIGH);
            delay(3000);
            digitalWrite(ledPinB,LOW);
            break; 
        } else if(key == 'C'){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Selecciono: ");  
            lcd.setCursor(13,0);
            lcd.print(key);
            lcd.setCursor(0,1);
            lcd.print("Temp: ");
            lcd.setCursor(6,1);
            lcd.print(temp);
            lcd.setCursor(8,1);
            lcd.print("C");
            delay(100);
            digitalWrite(ledPinC,HIGH);
            delay(3000);
            digitalWrite(ledPinC,LOW);
            break;
        } else if(key == 'D'){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Selecciono: ");  
            lcd.setCursor(13,0);
            lcd.print(key);
            lcd.setCursor(0,1);
            lcd.print("Temp: ");
            lcd.setCursor(6,1);
            lcd.print(temp);
            lcd.setCursor(8,1);
            lcd.print("C");
            delay(100);
            digitalWrite(ledPinD,HIGH);
            delay(3000);
            digitalWrite(ledPinD,LOW);
            break;
        }  
    }
    if(key == 'A' ||key == 'B' ||key == 'C' ||key == 'D'){
        int cambio = total - 10;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Credito restante: ");
        lcd.setCursor(0,1);
        lcd.print(cambio + credito);
        delay(1000);
        readAmount(temp,cambio + credito);
        return cambio + credito;
    }
}


//En l apantalla se mostrara la cantidad de dinero insertado cada bebidad tiene un costo de $10 psos. 
//SI el mondto insertado no suma el total de 10 o mas no se debe entrar a la funcion entregar bebida
