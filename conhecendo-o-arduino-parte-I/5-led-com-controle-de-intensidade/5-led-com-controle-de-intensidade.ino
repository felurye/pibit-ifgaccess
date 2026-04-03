int led = 9;
unsigned int valorLido;
unsigned int pwm;

void setup() { pinMode(led, OUTPUT); }

void loop() {
  valorLido = analogRead(A0);
  pwm = map(valorLido, 0, 1023, 0, 255);
  analogWrite(led, pwm);
}

/*  =============== EXPLICAÇÃO ===============   */

/*
Neste programa estamos usando uma técnica, de transformar saídas digitais em
analógicas, isto é, ao invés de poder ser lido apenas dois estados do led (no
nosso caso), podemos ler 256 -> entre 0 à 225. Esse valor está sendo lido por
meio da função analogRead, que é responsável por ler o valor do potenciômetro,
que pode variar entre 0 à 1023, e com o auxílio da função map o valor pode ser
convertido, assim mudando a intensidade em que o led fica ligado.
*/
