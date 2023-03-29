#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const byte filas = 4;
const byte columnas = 4;
char teclas[filas][columnas] = {{'1','2','3','A'},
                                {'4','5','6','B'},   
                                {'7','8','9','C'},
                                {'*','0','#','D'}};                         
byte filasPins[filas] = { 9, 8, 7, 6 };
byte colsPins[columnas] = { 5, 4, 3, 2 }; 

Keypad kpd = Keypad( makeKeymap(teclas), filasPins, colsPins, filas, columnas );
//int password = 1234;
//int a=0,b=0,c=0,d=0;
//int pass[4] = {1,2,3,4};
char pw[4] = {'1', '2', '3', '4'};
char pw2[4];
char cd[8] = {'*', '*', '#', '#', '*', '#', '*', '#'};
char cd2[8];
boolean cerradura=false;
int addr=0;
int aux;
byte value;

unsigned long lastMillis = 0; // almacena última vez que ejecutó función
const unsigned long interval = 120000; // tiempo en milisegundos (2 minutos)

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

void escribirEEPROM(int val){
  EEPROM.write(addr, val);
  addr+=1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
}

void leerEEPROM(){
  EEPROM.read(addr);
  Serial.print(addr);
  Serial.print("\t");
  for(int i=addr; i>=addr-4; i--){
    Serial.print(value, DEC);
  }
  Serial.println();
}

void leerNum(){
  char key;
  int i = 0;
  lcd.clear();
  lcd.print("Ingrese numero:");
  while (i < 4) {
    key = kpd.getKey();
    if (key != NO_KEY && isDigit(key)) {
      pw2[i]=' ';
      lcd.setCursor(i+4, 1);
      lcd.write(key);
      pw2[i] = key;
      i++;
    }   
  }
  delay(500);
}

void comparaContra(){
  delay(100);
  cerradura = true;
  for(int i=0; i<4; i++){
    if(pw2[i] != pw[i]){
      cerradura=false;
      break;
    }
    delay(500);
    break;
  }
}

void setup(){
  Serial.begin(9600);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.createChar(1, cora);
  lcd.setCursor(0, 0);
  lcd.print("LCD de Xime");
  lcd.setCursor(14, 0);
  lcd.write(byte(1));
  lcd.setCursor(15, 0);
  lcd.write(byte(1));
}

void loop() {
  char key = kpd.getKey();
  switch(key){
    case 'A':
      // P A N T A L L A   I N I C I A L
      lcd.clear();
      lcd.setCursor(0, 0);
               //1234567812345678
      lcd.print("Sistema...");
      if(cerradura==false){
        lcd.setCursor(0, 1);
        lcd.print("Bloqueado :(");
      }
      else if(cerradura==true){
        lcd.setCursor(0, 1);
        lcd.print("Abierto :D");
      }
      break;
    case 'B':
      key = ' ';
      // E N T R A R   A L   S I S T E M A
      lcd.clear();
      lcd.setCursor(0, 0);
               //1234567812345678
      lcd.print("Contrasena:");  
      lcd.setCursor(0, 1);
      lcd.print("=> ");
      leerNum();
      comparaContra();
      if(cerradura){
        lcd.clear();
        lcd.setCursor(0, 0);
                 //1234567812345678
        lcd.print("Contrasena...");  
        lcd.setCursor(0, 1);
        lcd.print("CORRECTA! :D");
        cerradura = true;
        delay(2000);
        cerradura = true;
        break;
      }else if(cerradura == false){
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          lcd.print("Contrasena...");  
          lcd.setCursor(0, 1);
          lcd.print("INCORRECTA! X(");
          delay(3500);
          break;
      }
      /*if(key){
        for(int i=0; i<4; i++){
          key = ' ';
          while (kpd.getKey() == NO_KEY) { // esperar hasta que se presione una tecla
            // no hacer nada mientras tanto
          }
          key = kpd.getKey();
          int n = key;
          lcd.print(n);
          pw2[i]=key;
        }
        delay(3000);
        if(pw[0]==pw2[0] && pw[1]==pw2[1] && pw[2]==pw2[2] && pw[3]==pw2[3]){
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          lcd.print("Contrasena...");  
          lcd.setCursor(0, 1);
          lcd.print("CORRECTA! :D");
          cerradura=true;
          break;
        }else{
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          lcd.print("Contrasena...");  
          lcd.setCursor(0, 1);
          lcd.print("INCORRECTA! X(");
          cerradura=false;
          break;
        }
      }*/
      break;
    case 'C':
      // C A M B I A R   C O N T R A S E Ñ A
      lcd.clear();
      lcd.setCursor(0, 0);
               //1234567812345678
      lcd.print("Nueva");  
      lcd.setCursor(0, 1);
      lcd.print("contrasena...");
      delay(3500);
      do{
        lcd.clear();
        lcd.setCursor(0, 0);
                 //1234567812345678
        lcd.print("Contrasena");  
        lcd.setCursor(0, 1);
        lcd.print("actual:");
        aux=1;
        for(int i=0; i<4; i++){
          lcd.print(key);
          pw2[i]=key;
        }
        if(pw[0]==pw2[0] && pw[1]==pw2[1] && pw[2]==pw2[2] && pw[3]==pw2[3]){
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          lcd.print("Nv Contrasena:");  
          lcd.setCursor(0, 1);
          lcd.print("=> ");
          for(int i=0; i<4; i++){
            lcd.print(key);
            pw[i]=key;
            pw2[i]=key;
            escribirEEPROM(pw[i]);
          }       
        }else{
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          lcd.print("Contrasena...");  
          lcd.setCursor(0, 1);
          lcd.print("INCORRECTA! X(");
          delay(3500);
          lcd.clear();
          lcd.setCursor(0, 0);
                   //1234567812345678
          int aux2 = 3-aux;
          lcd.print(aux2);
          lcd.print(" intentos más.");
          delay(3500);
          aux+=1;
        }
      }while(aux!=3);
      break;
    case 'D':
      // V E R   C O N T R A S E Ñ A
      lcd.clear();
      lcd.setCursor(0, 0);
               //1234567812345678
      lcd.print("Codigo secreto:");  
      lcd.setCursor(0, 1);
      lcd.print("=> ");
      for(int i=0; i<8; i++){
        lcd.print(key);
        cd2[i]=key;
      }
      if(cd[0]==cd2[0] && cd[1]==cd2[1] && cd[2]==cd2[2] && cd[3]==cd2[3] && cd[4]==cd2[4] && cd[5]==cd2[5] && cd[6]==cd2[6] && cd[7]==cd2[7]){
        leerEEPROM();
      }else{
        lcd.clear();
        lcd.setCursor(0, 0);
                 //1234567812345678
        lcd.print("Fallaste!!");  
        lcd.setCursor(0, 1);
        lcd.print("Menso :p");
        break;
      }
      break;
  }
  /*char key = kpd.getKey();
  lcd.setCursor(0, 1);
  lcd.print("SEG= ");
  lcd.print(millis() / 1000);
  if(key){
    lcd.setCursor(9, 1);
    lcd.print("TEC= ");
    lcd.print(key);
  }*/
  
  unsigned long currentMillis = millis(); // obtiene el tiempo actual en milisegundos
  if (currentMillis - lastMillis >= interval) { // verifica si ha transcurrido el intervalo de tiempo deseado
    lastMillis = currentMillis; // actualiza la variable lastMillis
    cerradura=false;
  }
}
