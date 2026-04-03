/*
 * Acender 1 LED de alta intensidade, caso seja noite;
 */

int led = 13;
int ldrPin = 0;
int ldrValor = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (ldrValor <= 800) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(100);
}
