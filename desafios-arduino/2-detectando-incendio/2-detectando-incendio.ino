/*
 * Detectar um incêndio através da temperatura muito alta
 * da casa usando um LM35.
 */

#define LIMITE 40

const int LM35 = A0;
float temperatura = 0;

void setup() { Serial.begin(9600); }

void loop() {
  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;

  if (temperatura > LIMITE) {
    Serial.println("Temperatura alta!! Incêndio!!!!");
  }
  delay(1000);
}
