
int ledPin = 9;
int ldrPin = A0;
int ldrValor = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValor = analogRead(ldrPin);

  if (ldrValor >= 400) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  Serial.println(ldrValor);
  delay(100);
}

/*========== EXPLICAÇÃO ==========*/
/* Nesse programa será lido em todo momento o valor gerado pelo LDR.
 * Por meio do if else pode ser controlado o LED, caso o valor lido
 * seja maior ou igual à 400, ou seja, haja muita luz, o led permanece
 * apagado, senão, o LED acenderá.
 */
