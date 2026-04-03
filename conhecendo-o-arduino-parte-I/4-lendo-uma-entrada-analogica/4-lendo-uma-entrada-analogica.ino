unsigned int valorLido;

void setup() {
  Serial.begin(9600);

  void loop() {
    valorLido = analogRead(A0);
    Serial.println(valorLido);
    delay(1000);
  }
