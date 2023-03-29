// con la palomita se compila, con la flecha se envía al arduino
int LED = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as output.
  pinMode(LED, OUTPUT); // se coloca como salida

}

// the loop function runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); // UNO
  delay(5000); // 1 segundo
  digitalWrite(LED, LOW); // CERO
  delay(1000); // 1 segundo
}
