#include <IRremote.h>
int RECV_PIN = 52;
const long TasteNULL = 16738455;
const long EINS = 16724175;
const long ZWEI = 16718055;
const long DREI = 16743045;
const long VIER = 16716015;
const long FUENF = 16726215;
const long SECHS = 16734885;
const long SIEBEN = 16728765;
const long ACHT = 16730805;
const long NEUN = 16732845;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8; 
int pinH = 13;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

int eingabe = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);
  pinMode(pinH, OUTPUT);    
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);  
}

void loop() {
 if (irrecv.decode(&results))             // wenn gedrückt
 {
  int merker = gedrueckteZahl();
  if ( merker != -1 ) {
    eingabe = eingabe * 10;
    eingabe = eingabe +  merker;
    if ( eingabe > 9999 || eingabe < 0 ) {
      eingabe = 0;
    }
  }
  irrecv.resume();
 }
 darstellen ( eingabe );
}
void darstellen (int zahl) {
  darstellen ( 1, zahl / 1000);
  zahl = zahl % 1000;
  darstellen ( 2, zahl / 100);
  zahl = zahl % 100;
  darstellen ( 3, zahl / 10);
  zahl = zahl % 10;
  darstellen ( 4 , zahl / 1);
}

void darstellen (int digit, int zahl) {
  switch (digit) {
    case 1: 
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    break;
    case 2: 
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);    
    break;
    case 3:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    break;
    case 4:
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    break;
    default: 
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    break;
  }

  switch(zahl) {
    case 0 :
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 1: 
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 2:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, LOW); 
    delay(4);
    break;
    case 3:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 4:
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 5:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 6:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 7:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 8:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    case 9:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, HIGH); 
    delay(4);
    break;
    default: 
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    digitalWrite(pinH, LOW); 
    delay(4);   
    break;
  }
}

int gedrueckteZahl () {
  switch(results.value) {
    case TasteNULL : return 0;
    case  EINS  : return 1;
    case  ZWEI : return 2;
    case  DREI : return 3;
    case  VIER : return 4;
    case  FUENF : return 5;
    case  SECHS : return 6;
    case  SIEBEN : return 7;
    case  ACHT : return 8;
    case  NEUN : return 9;
    default : return -1;
   }
}
