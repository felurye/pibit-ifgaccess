#include <dht.h>

dht DHT;
timer = 0;

void setup() {
  Serial.begin(9600);

  void loop() {
    if (millis() - timer >= 2000) {
      DHT.read11(A1);

      Serial.print(DHT.humidity);
      Serial.println(" %");
      Serial.print(DHT.temperature);
      Serial.println(" Celsius");
      timer = millis();
    }
  }
