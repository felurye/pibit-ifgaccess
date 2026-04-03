/*
 * Detectar se está de noite através de um sensor de luz LDR;
 */

#define LIMITE 800

const int ldrPin = 0;
int ldrValor = 0;
void setup() { Serial.begin(9600); }

void loop() {
  ldrValor = analogRead(ldrPin);

  if (ldrValor <= LIMITE) {
    Serial.println("Noite!!");
  }

  delay(100);
}
