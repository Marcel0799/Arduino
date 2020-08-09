
  int gruen = 10;
  int gelb = 8;
  int rot = 6;
  int button = 2;
  boolean state = false;
void setup() {
  Serial.begin(9600);
  pinMode(gruen,OUTPUT);
  pinMode(gelb,OUTPUT);
  pinMode(rot,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  if(digitalRead(button) == HIGH) {
    for(int i = 1; i<50;  i++) {
      digitalWrite(rot, HIGH);
      digitalWrite(gelb, HIGH);
      digitalWrite(gruen, HIGH);
      delay(50-i);
      Serial.println ( i );
      digitalWrite(rot, LOW);
      digitalWrite(gelb, LOW);
      digitalWrite(gruen, LOW);
      delay(50-i);
    }
  }
}
