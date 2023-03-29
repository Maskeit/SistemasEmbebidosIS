/*  A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D      */

int D1 = 2;
int D2 = 3;
int D3 = 4;
int D4 = 5;
int pinA = 6;
int pinB = 7;
int pinC = 8;
int pinD = 9;
int pinE = 10;
int pinF = 11;
int pinG = 12;

// the setup routine   runs once when you press reset:
void setup() {                
  // initialize   the digital pins as outputs.
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
}

// the loop routine runs over   and over again forever:
void loop() {
  //D1
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //2
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for   a second

  //D2
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //3
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second

  //D3
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
  //°
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);               // wait for a second

  //D4
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
  //C
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1);               // wait for a second
  /*  
  104  //4
  105  digitalWrite(pinA, HIGH);   
  106  digitalWrite(pinB, LOW);   
  107  digitalWrite(pinC, LOW);   
  108  digitalWrite(pinD, HIGH);   
  109  digitalWrite(pinE, HIGH);   
  110  digitalWrite(pinF, LOW);   
  111  digitalWrite(pinG, LOW);     
  112  delay(1000);                // wait for a second
  113  
  114  //5
  115  digitalWrite(pinA, LOW);    
  116  digitalWrite(pinB, HIGH);   
  117  digitalWrite(pinC, LOW);   
  118  digitalWrite(pinD, LOW);   
  119  digitalWrite(pinE, HIGH);   
  120  digitalWrite(pinF, LOW);   
  121  digitalWrite(pinG, LOW);     
  122  delay(1000);               // wait for a second
  123   
  124  //6
  125  digitalWrite(pinA, LOW);   
  126  digitalWrite(pinB, HIGH);   
  127  digitalWrite(pinC, LOW);   
  128  digitalWrite(pinD, LOW);   
  129  digitalWrite(pinE, LOW);   
  130  digitalWrite(pinF, LOW);   
  131  digitalWrite(pinG, LOW);     
  132  delay(1000);               // wait for a second
  133  
  134  //7
  135  digitalWrite(pinA, LOW);   
  136  digitalWrite(pinB, LOW);   
  137  digitalWrite(pinC, LOW);   
  138  digitalWrite(pinD, HIGH);   
  139  digitalWrite(pinE, HIGH);   
  140  digitalWrite(pinF, HIGH);   
  141   digitalWrite(pinG, HIGH);     
  142  delay(1000);               // wait for a second
  143   
  144  //8
  145  digitalWrite(pinA, LOW);   
  146  digitalWrite(pinB, LOW);   
  147   digitalWrite(pinC, LOW);   
  148  digitalWrite(pinD, LOW);   
  149  digitalWrite(pinE, LOW);   
  150  digitalWrite(pinF, LOW);   
  151  digitalWrite(pinG, LOW);     
  152   delay(1000);               // wait for a second
  153
  154  //9
  155  digitalWrite(pinA, LOW);   
  156  digitalWrite(pinB, LOW);   
  157  digitalWrite(pinC, LOW);   
  158  digitalWrite(pinD, HIGH);   
  159  digitalWrite(pinE, HIGH);   
  160  digitalWrite(pinF, LOW);   
  161  digitalWrite(pinG, LOW);     
  162  delay(1000);               // wait for a second
163   */
}
