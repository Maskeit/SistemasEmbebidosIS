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

char pw[5] = {'1', '2', '3', '4'};
char pw2[5];
char pw3[5];
char cd[9] = {'*', '*', '#', '#', '*', '#', '*', '#'};
char cd2[9];
boolean cerradura=false;
boolean secret=false;
int addr=104;
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


void leerNum(){
  char key;
  int i = 0;
  while (i < 4){
    key = kpd.getKey();
    if (key != NO_KEY){
      if(isDigit(key)){
        lcd.setCursor(i+4, 1);
        lcd.write(key);
        pw2[i] = key;
        i++;
      }else{
        delay(200);
        break;
      }
    } 
  }
  delay(500);
}

void comparaContra(){
  delay(100);
  cerradura = false;
  for(int i=0; i<4; i++){
    if(pw2[i] == pw[i]){
      cerradura = true;
    }else{
      cerradura = false;
      break;
    }
  }
}

void setContra(){
  delay(100);
  for(int i=0; i<4; i++){
    //lcd.print(key);
    pw[i] = pw2[i];
    char c = pw[i];
    Serial.println(c);
    escribirEEPROM();
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Contrasenia");
  lcd.setCursor(0, 1);
  lcd.print("nueva lista!");
  delay(1500);
  loop();
}

void escribirEEPROM(){
  for(int i=0; i<4; i++){
    char c = pw[i];
    byte val = (byte)c;
    EEPROM.write(addr, val);
    Serial.println(val);
    Serial.println(addr);
    addr=addr+1;
  }
}

void leerEEPROM(){
  char caracter;
  int i=0;
  while(i<5){
    int temp = addr;
    int j=4;
    temp=temp-i;
    byte val = EEPROM.read(temp);
    pw3[j-i] = (char)val;
    i++;
  }
}

void leerSecret(){
  char key;
  int i = 0;
  while (i < 8){
    key = kpd.getKey();
    if (key != NO_KEY){
      lcd.setCursor(i+4, 1);
      lcd.write(key);
      cd2[i] = key;
      i++;
    } 
  }
  delay(500);
}

void comparaSecret(){
  delay(100);
  secret = true;
  for(int i=0; i<8; i++){
    if(cd2[i] == cd[i]){
      secret = true;
    }else{
      secret = false;
    }
  }
}

void pantallaInicial(){
  Serial.println('A');
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
  delay(2000);
  loop();
}

void entrarSistema(){
  char key = kpd.getKey();
  Serial.println('B');
  key = NO_KEY;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Contrasenia:");
  lcd.setCursor(0, 1);
  lcd.print("=> ");
  leerNum();
  comparaContra();
  Serial.println(pw);
  Serial.println(pw2);
  Serial.println(cerradura);
  delay(500);
  if(cerradura == true){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Contrasena...");  
    lcd.setCursor(0, 1);
    lcd.print("CORRECTA! :D");
    cerradura = true;
    delay(1500);
    cerradura = true;
    pantallaInicial();
  }else if(cerradura == false){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Contrasena...");  
      lcd.setCursor(0, 1);
      lcd.print("INCORRECTA! X(");
      delay(1500);
  }
  delay(500);
  loop();
}

void cambiarContrasenia(){
  Serial.println('C');
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nueva");  
  lcd.setCursor(0, 1);
  lcd.print("contrasenia...");
  delay(2500);
  aux=1;
  do{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Contra actual...");  
    lcd.setCursor(0, 1);
    lcd.print("=> ");
    leerNum();
    comparaContra();
    Serial.println(pw);
    Serial.println(pw2);
    Serial.println(cerradura);
    delay(1500);
    if(cerradura == true){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nv Contrasena:");  
      lcd.setCursor(0, 1);
      lcd.print("=> ");
      leerNum();
      setContra();
      break;
    }else if(cerradura == false){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Contrasena...");  
      lcd.setCursor(0, 1);
      lcd.print("INCORRECTA! X(");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      int aux2 = 3-aux;
      lcd.print(aux2);
      lcd.print(" intentos mas.");
      delay(500);
      aux=aux+1;
    }
  }while(aux<4);
  delay(500);
  loop();
}

void verContrasenia(){
  char key = kpd.getKey();
  Serial.println('D');
  lcd.clear();
  lcd.setCursor(0, 0);
           //1234567812345678
  lcd.print("Codigo secreto:");  
  lcd.setCursor(0, 1);
  lcd.print("=> ");
  leerSecret();
  comparaSecret();
  Serial.println(cd);
  Serial.println(cd2);
  Serial.println(secret);
  if(secret == true){
    lcd.clear();
    leerEEPROM();
    lcd.setCursor(0, 0);
    lcd.print("Contra activa:");  
    lcd.setCursor(0, 1);
    int i=0;
    Serial.println(pw3);
    while (i < 4){
      lcd.setCursor(i, 1);
      key = pw3[i];
      lcd.write(key);
      i++;
    }
    delay(2000);
    secret = false;
  }else if(secret == false){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fallaste!!");  
    lcd.setCursor(0, 1);
    lcd.print("Menso :p");
  }
  delay(500);
  loop();
}

/*void menu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*MENU PRINCIPAL*");
  lcd.setCursor(0, 1);
  lcd.print("presiona letra!");
  char key = kpd.getKey();
  switch(key){
    case 'A':
      // P A N T A L L A   I N I C I A L
      pantallaInicial();
      break;
    case 'B':
      // E N T R A R   A L   S I S T E M A
      entrarSistema();
      break;
    case 'C':
      // C A M B I A R   C O N T R A S E Ñ A
      cambiarContrasenia();
      break;
    case 'D':
      // V E R   C O N T R A S E Ñ A
      verContrasenia();
      break;
  }
  delay(1);
}*/

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
  
  for(int i=0; i<4; i++){
    byte val = (byte)pw[i];
    EEPROM.write(100+i, val);
  }

  delay(2500);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*MENU PRINCIPAL*");
  lcd.setCursor(0, 1);
  lcd.print("presiona letra!");
  char key = kpd.getKey();
  switch(key){
    case 'A':
      // P A N T A L L A   I N I C I A L
      pantallaInicial();
      break;
    case 'B':
      // E N T R A R   A L   S I S T E M A
      entrarSistema();
      break;
    case 'C':
      // C A M B I A R   C O N T R A S E Ñ A
      cambiarContrasenia();
      break;
    case 'D':
      // V E R   C O N T R A S E Ñ A
      verContrasenia();
      break;
  }
  delay(500);
  unsigned long currentMillis = millis(); // obtiene el tiempo actual en milisegundos
  if (currentMillis - lastMillis >= interval) { // verifica si ha transcurrido el intervalo de tiempo deseado
    lastMillis = currentMillis; // actualiza la variable lastMillis
    cerradura=false;
  }
}
