// Sensor de temperatura usando o LM35

const int LM35 = A0;
float temperatura;
void setup() { Serial.begin(9600); }

void loop() {
  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;
  Serial.println("Temperatura: ");
  Serial.println(temperatura);

  delay(2000);
}
