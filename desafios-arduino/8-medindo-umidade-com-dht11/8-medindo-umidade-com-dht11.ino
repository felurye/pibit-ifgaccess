/*
 * H. Medir umidade através do DHT11;
 */
#include <dht.h>

dht DHT;
timer = 0;

void setup() { Serial.begin(9600); }

void loop() {
  if (millis() - timer >= 2000) {
    DHT.read11(A1);

    Serial.print("Umidade: ");
    Serial.print(DHT.humidity);
    Serial.println(" %");
    timer = millis();
  }
