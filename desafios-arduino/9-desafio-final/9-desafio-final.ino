/*
 * Ter um display LCD que mostrará os valores lidos em cada sensor, se o
 * alarme está ligado ou desligado e o motivo do alarme, caso dispare.
 */

#include <LiquidCrystal.h>
#include <Ultrasonic.h>
#include <dht.h>

Ultrasonic ULTRASSOM(12, 11);
// trig(12) e o echo(11)
dht DHT;
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
/*Cria objeto LCD da classe LiquidCrystal
RS     2
Enable 3
DB4    4
DB5    5
DB6    6
DB7    7
*/

const int BUZZER = 9;
const int LED = 13;
const int LDR = A0;
const int LM35 = A1;
const int BOTAO = 10;

#define LIMITE_TEMPERATURA 40
#define FREQUENCIA_BUZZER 261.63
#define LIMITE_LUMINOSIDADE 800
#define LIMITE_DISTANCIA 40

int luminosidade = 0;
int funcaoA = 0;
int funcaoB = 0;
int estadoBotao = 0;
float temperatura = 0;
int distancia = 0;

void setup() {
  LCD.begin(16, 2);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop() {
  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;

  distancia = ULTRASSOM.Ranging(CM);

  DHT.read11(A2);

  luminosidade = analogRead(LDR);

  LCD.setCursor(0, 0);
  LCD.print("Temp: ");
  LCD.print(temperatura);
  LCD.print("C Umid: ");
  LCD.print(DHT.humidity);
  LCD.print(" %% Lum: ");
  LCD.print(luminosidade);
  LCD.print("Dist: ");
  LCD.print(distancia);
  LCD.print("CM");
  for (int i = 0; i < 40; i++) {
    lcd.scrollDisplayLeft();
    delay(80);
  }

  if (luminosidade <= LIMITE_LUMINOSIDADE) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  funcaoA = digitalRead(BOTAO);

  if ((funcaoA == HIGH) & amp; &amp; (funcaoB == LOW)) {
    estado = 1 - estado;
    delay(500);
  }
  funcaoB = funcaoA;

  if (estado == 1) {
    LCD.setCursor(0, 1);
    LCD.print("Alarme: ON ");
    if (distancia <= LIMITE_DISTANCIA && distancia > 0) {
      tone(BUZZER, 200, 6000);
      LCD.print("PRESENÇA!!");
      delay(5000);
    } else {
      noTone(BUZZER);
    }

    if (temperatura > LIMITE_TEMPERATURA) {
      tone(BUZZER, FREQUENCIA_BUZZER);
      LCD.print("TEMPERATURA!!");
      delay(5000);
    } else {
      noTone(BUZZER);
    }

  } else {
    LCD.print("Alarme: OFF");
  }

  delay(100);
}