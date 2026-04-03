
const int botao = 2;
const int led = 3;
int estadoBotao = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  estadoBotao = digitalRead(botao);

  if (estadoBotao == 1) {
    digitalWrite(led, 1);
    Serial.println("1");
  } else {
    digitalWrite(led, 0);
    Serial.println("0");
  }
}
