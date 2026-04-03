/*
 * Detectar a presença de uma pessoa usando o sensor ultrassom.
 * (Você também poderá utilizar um sensor de presença PIR que,
 * apesar de não ter sido explicado em nossa apostila, é muito
 * simples de usar;
 */

#include <Ultrasonic.h>
#define LIMITE 40

Ultrasonic ultrassom(8, 7);
// e onde esta ligado o trig(8) e o echo(7) respectivamente.

void setup() {
  Serial.begin(9600);  // Habilita Comunicação Serial a uma taxa de 9600 bauds.
  long distancia;
}

void loop() {
  distancia = ultrassom.Ranging(
      CM);  // retorna a distancia em centímetros(CM) ou polegadas(INC)

  if (distancia <= LIMITE && distancia > 0) {
    Serial.println("Pessoa Detectada!");
  }
  delay(100);
}
