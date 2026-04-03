/*
 * Esse alarme também deve tocar, caso acionado e uma pessoa seja detectada;
 */

#include <Ultrasonic.h>
Ultrasonic ultrassom(8, 7);
// trig(8) e o echo(7)

const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  long distancia;
}

void loop() {
  distancia = ultrassom.Ranging(CM);

  if (distancia <= 40 && distancia > 0) {
    tone(buzzer, 200, 6000);
  } else {
    noTone(buzzer);
  }

  delay(100);
}
