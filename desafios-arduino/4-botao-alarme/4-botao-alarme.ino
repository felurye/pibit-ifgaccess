/*
 * Possuir um botão para ligar e desligar um alarme;
 */

/*
 * Possuir um botão para ligar e desligar um alarme;
 */

const int botao = 2;
const int buzzer = 9;
int estadoBotao = 0;
int controle = 0;
void interrupcao() {
  if (controle == 0) {
    noTone(buzzer);
    controle = 1;
  } else {
    tone(buzzer, 200);
    controle = 0;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(botao, INPUT);
  attachInterrupt(0, interrupcao, RISING);
}

void loop() {
  estadoBotao = digitalRead(botao);
  Serial.println(estadoBotao);
}
