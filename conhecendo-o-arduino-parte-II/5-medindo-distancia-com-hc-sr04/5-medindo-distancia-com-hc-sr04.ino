#include <Ultrasonic.h>
Ultrasonic ultrassom(8, 7);
// trig(8) e o echo(7) respectivamente

void setup() { Serial.begin(9600); }

void loop() {
  distancia = ultrassom.Ranging(CM);

  Serial.print(distancia);
  Serial.println("cm");

  delay(100);
}
