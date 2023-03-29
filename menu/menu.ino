/* LCD:
   * LCD RS  pin to analog pin A0
   * LCD  Enable pin to analog pin A1
   * LCD D4  pin to analog pin A2
   * LCD D5  pin to analog pin A3
   * LCD D6  pin to analog pin A4
   * LCD D7  pin to analog pin A5
   * 
   Menu:
   * Select to digital pin 2
   * Menu to digital pin 3
   * Led1 to digital pin 5
   * Led1 to digital pin 6
   * Led1 to digital pin 7
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

enum funciones{med, cal, ini};
             //  0    1    2
             //roj amar verde
             
boolean t1=false, t2=false, t3=false;

const int btnSelPin = 2;
const int btnMenuPin = 3;
const int ledVerPin = 5;
const int ledAmaPin = 6;
const int ledRojoPin = 7;

int btnMenuState = 0;
int btnSelState = 0;
int opc = 0;


void medir(void){
  t1 = !t1;
  if(t1 == false){
    digitalWrite(ledRojoPin, LOW);
    //lcd.setCursor(0,1);
    //lcd.print("apagado");
  }
  if(t1 == true){
    digitalWrite(ledRojoPin, HIGH);
    //lcd.setCursor(0,1);
    //lcd.print("encendido");
  }
  Serial.println("medir");
}

void calibrar(void){
  t2 = !t2;
  if(t2 == false){
    digitalWrite(ledAmaPin, LOW);
    //lcd.setCursor(0,1);
    //lcd.print("apagado");
  }
  if(t2 == true){
    digitalWrite(ledAmaPin, HIGH);
    //lcd.setCursor(0,1);
    //lcd.print("encendido");
  }
  Serial.println("calibrar");
}

void inicializar(void){
  t3 = !t3;
  if(t3 == false){
    digitalWrite(ledVerPin, LOW);
    //lcd.setCursor(0,1);
    //lcd.print("apagado");
  }
  if(t3 == true){
    digitalWrite(ledVerPin, HIGH);
    //lcd.setCursor(0,1);
    //lcd.print("encendido");
  }
  Serial.println("inicializar");
}

void elegirFun(int numfun){
  switch(numfun){
    case 0:
      medir();
      break;
    case 1:
      calibrar();
      break;
    case 2:
      inicializar();
      break;
  }
}

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(2 , INPUT_PULLUP);
  pinMode(3 , INPUT_PULLUP);
  
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(7 , OUTPUT);
}

void loop(){
  char nmenu = 3;
  //btnMenuState = digitalRead(btnMenuPin);
  //btnSelState = digitalRead(btnSelPin);

  if(digitalRead(btnMenuPin) == HIGH){
    opc = opc + 1;
  }
  
  if(opc > (nmenu-1)){
    opc = 0;
  }

  Serial.println(opc);
  
  switch(opc){
    case 0:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MEDIR      ");
      lcd.setCursor(0,1);
      if(digitalRead(ledRojoPin) == HIGH){
        lcd.print("encendido");
      }
      if(digitalRead(ledRojoPin) == LOW){
        lcd.print("apagado  ");
      }
      break;
    case 1:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CALIBRAR   ");
      lcd.setCursor(0,1);
      if(digitalRead(ledAmaPin) == HIGH){
        lcd.print("encendido");
      }
      if(digitalRead(ledAmaPin) == LOW){
        lcd.print("apagado  ");
      }
      break;
    case 2:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("INICIALIZAR");
      lcd.setCursor(0,1);
      if(digitalRead(ledVerPin) == HIGH){
        lcd.print("encendido");
      }
      if(digitalRead(ledVerPin) == LOW){
        lcd.print("apagado  ");
      }
      break;
    default:
      lcd.clear();
  }

  if(digitalRead(btnSelPin) == HIGH){
    elegirFun(opc);
  }
  delay(500);
}
