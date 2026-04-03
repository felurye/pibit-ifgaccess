#include <LiquidCrystal.h>  //Inclui biblioteca no programa

uint32_t timer;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
/* Cria objeto lcd da classe LiquidCrystal
RS     2
Enable 3
DB4    4
DB5    5
DB6    6
DB7    7 */

void setup() {
  analogReference(EXTERNAL);  // Muda a referência para a tensão no pino AREF
  lcd.begin(16, 2);           // Inicializa display de 2 linhas x 16 colunas
}

void loop() {
  if (millis() - timer > 1000) {
    float valorLido = analogRead(A0);
    float temp = valorLido / 1024 * 1562.5 / 10;
    lcd.clear();

    lcd.print("Temperatura: ");
    lcd.print(temp);
    timer = millis();
  }
}
