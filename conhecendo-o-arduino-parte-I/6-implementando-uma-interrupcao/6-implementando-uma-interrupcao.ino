int led = 3;

void interrupcao() {
  digitalWrite(led, HIGH);
  delay(5000);
}

void setup() {
  pinMode(led, OUTPUT);
  attachInterrupt(0, interrupcao, RISING);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);

  /*  =============== EXPLICAÇÃO ===============   */

  /*
  Esse programa em seu funcionamento padrão ocorre apenas um blink, que nada
  mais é que o led acender e apagar repetidamente, mas assim que o botão é
  pressionado a função attachInterrupt, configurada no setup é ativada, pois o
  botão mudou o seu estado, de 0V para 5V, occorrendo isso o led permanece
  ligado durante 5 segundo (5000 milisegundos), isso porque foi configurado na
  função interrupcao que é chamada no attachInterrupt , e depois volta ao seu
  funcionamento padrão.
  */
