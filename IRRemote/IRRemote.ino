#include <IRremote.h>

long eins = 16724175;
int gruen = 13;
int gelb = 12;
int rot = 9;
boolean state = false;
const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
    if(results.value == eins) {
      if(state) {
        state = !state;
          digitalWrite(rot,LOW);
          digitalWrite(gelb,HIGH);
          delay(1500);
          digitalWrite(gelb,LOW);
          digitalWrite(gruen,HIGH);
      } else {
          state = !state;
          digitalWrite(gruen,LOW);
          digitalWrite(gelb,HIGH);
          delay(1500);
          digitalWrite(gelb,LOW);
          digitalWrite(rot,HIGH);
      }
    }
      Serial.println(results.value, HEX);
      irrecv.resume();
  }
}
