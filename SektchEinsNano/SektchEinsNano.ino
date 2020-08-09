int ledABS = 6;
int ledAir = 12;
boolean hasRun = false;

void setup() {
  pinMode(ledABS,OUTPUT);
  pinMode(ledAir,OUTPUT);
}

void loop() {
  if(!hasRun) {
  digitalWrite(ledABS, HIGH);
  digitalWrite(ledAir, HIGH);
  delay(2800);
  digitalWrite(ledAir, LOW);
  delay(800);
  digitalWrite(ledABS, LOW);
  hasRun = true;
  }
}
