/*
 * Um alarme, usando o buzzer, deverá tocar, caso a
 * temperatura do LM35 seja muito alta;
 */

const int buzzer = 9;
const int LM35 = A0;
float temperatura = 0;
#define LIMITE 40
#define FREQUENCIA 261.63

void setup() { Serial.begin(9600); }

void loop() {
  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;

  if (temperatura > LIMITE) {
    tone(buzzer, FREQUENCIA, 250);
  } else {
    noTone(buzzer);
  }

  delay(1000);
}
