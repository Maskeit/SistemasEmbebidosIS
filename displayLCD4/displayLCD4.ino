#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

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

#define ledPinGreen 12
#define ledPinRed 11

long number = 0;

void setup() {

  int passwd = 2001;
  // Inicializamos el display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presione una tecla");

  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);

  // Inicializamos el monitor serie
  Serial.begin(9600);
}

void loop(){
  //llamar a la funcion que nos pide la accion principal
  readAction();

}


void readAction(){
  char key = NO_KEY;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ingresar: 'A'");
  lcd.setCursor(0,1);
  lcd.print("admin: 'B'");

    while (true) {
    key = keypad.getKey();
    if (key != NO_KEY) {
      if (key == 'A') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiono A");
        delay(1000);
        readNumber();
          break;
      }
      else if (key == 'B') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Presiono B");
        delay(1000);
        readPasswdRoot();
        break;
      }
    }
//    delay(1000);
  }
}

/*Apartado para definir la contrasena del usuario en el root*/

void readPasswdRoot() {
  char key;
  int count = 0;
  number = 0;
  int passwd = 2001;
  lcd.clear();
  lcd.print("RootPswd:");
  while (count < 4) {
    key = keypad.getKey();
    if (key != NO_KEY && isDigit(key)) {
      lcd.setCursor(count, 1);
      lcd.write(key);
      number = number * 10 + (key - '0');
      count++;
    }   
  }
  if(number == passwd){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("AdminAutorizado:");
    delay(2000);
    menuConf();//nos manda  al menu de configuracion
  } else{//nos devuelve al inicio
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("No Autorizado");
    lcd.setCursor(1,1);
    lcd.print("Adios");
    delay(2000);
    }
  delay(1000);
}
/*menu de la configuracion del usuario root para poder manipular la clave*/
void menuConf(){
  
  char key;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("UpdatePW: press A");

    lcd.setCursor(0,1);
    lcd.print("Borrar: press B");
    key = NO_KEY;
    while(true){
    key = keypad.getKey();
    
    if(key == 'A'){
          //aqui se ingresa nueva clave
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("IngreseNClave");
          int addr = 0;
          char key;
          int count = 0;
          number = 0;
              while (count < 4) {
              key = keypad.getKey();
              if (key != NO_KEY && isDigit(key)) {
                lcd.setCursor(count, 1);
                lcd.write(key);
                number = number * 10 + (key - '0');
                count++;
              }   
            }
            delay(500);
            //termina el apartado para ingresar nuev clave
              
          writeLongIntoEEPROM(100, number); //guarda la nueva clave o la actualiza en la localidad 100
          long number = readLongFromEEPROM(100);
          
          Serial.print("clave: ");
          Serial.println(number);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("CambiandoClave");
          delay(1000);
          break;
  } else if(key == 'B'){  //si es b entonces preguntara si confirmara borrar pero aun no lo hace    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Seguro de borrar?");
      lcd.setCursor(0,1);
      lcd.print("Si->C   NO->D");
      while (true) {
        key = keypad.getKey();
        if (key != NO_KEY) {
        if (key == 'C') {
          //aqui reiniciamos la clave a cero de todos modos
          writeLongIntoEEPROM(100, 1928); //guarda la nueva clave o la actualiza en la localidad 100
          long number = readLongFromEEPROM(100);
          Serial.print("clave: ");
          Serial.println(number);
          //termina proceso de reincio de clave
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Se ha borrado");
        delay(1000);
          return;
      }
      else if (key == 'D') {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No se ha borrado");
        delay(1000);
        break;
        }
        }
       }
    }
  }
    
    delay(2000);
}
//funcion para leer la contrasena de acceso
void readNumber() {
  char key;
  int count = 0;
  number = 0;
  lcd.clear();
  lcd.print("Ingrese Passwd:");
  while (count < 4) {
    key = keypad.getKey();
    if (key != NO_KEY && isDigit(key)) {
      lcd.setCursor(count, 1);
      lcd.write(key);
      number = number * 10 + (key - '0');
      count++;
    }   
  }
  delay(500);
  long savedNumber = readLongFromEEPROM(100); // leer el número guardado en la dirección de memoria 0
  if (number == savedNumber) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Autorizado!");
    lcd.setCursor(0,1);
    lcd.print("Puede Pasar");
    digitalWrite(ledPinGreen,HIGH);
    delay(250);
    digitalWrite(ledPinGreen,LOW);
//    delay(2000)
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Autorizado!");
    digitalWrite(ledPinRed,HIGH);
    delay(300);
    digitalWrite(ledPinRed,LOW);
  }
  delay(2000); // Mostrar el resultado durante 2 segundos antes de borrar la pantalla
  lcd.clear(); // Borrar la pantalla

  // Mostrar el número guardado en la EEPROM en el monitor serie
 
  Serial.println(savedNumber);
  
}//fin de la funcion



/*funciones para escribir en la eeprom*/

void writeLongIntoEEPROM(int address, long number){ 
  EEPROM.write(address, (number >> 24) & 0xFF);
  EEPROM.write(address + 1, (number >> 16) & 0xFF);
  EEPROM.write(address + 2, (number >> 8) & 0xFF);
  EEPROM.write(address + 3, number & 0xFF);
}

long readLongFromEEPROM(int address){
  return ((long)EEPROM.read(address) << 24) +
         ((long)EEPROM.read(address + 1) << 16) +
         ((long)EEPROM.read(address + 2) << 8) +
         (long)EEPROM.read(address + 3);
}//fin de las funciones
