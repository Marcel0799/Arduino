
int rot = 12;
int gelb = 10;
int gruen = 8;
int button = 2;
boolean goOrStop = false;
void setup() {
  Serial.begin(9600);
  pinMode (rot,OUTPUT);
  pinMode (gelb,OUTPUT);
  pinMode (gruen,OUTPUT);
  pinMode (button,INPUT);
}

void loop() {
  if(digitalRead(button) == HIGH) {
    digitalWrite(rot,LOW);
    digitalWrite(gelb,HIGH);
    digitalWrite(gruen,LOW);
    goOrStop = !goOrStop;
    delay(750);
  } else if (goOrStop) {
    digitalWrite(rot,LOW);
    digitalWrite(gelb,LOW);
    digitalWrite(gruen,HIGH);
    delay(100);
  } else if (!goOrStop) {
    digitalWrite(rot,HIGH);
    digitalWrite(gelb,LOW);
    digitalWrite(gruen,LOW);
    delay(100);
  }
}
