// CONTROLE DE ACESSO RFID COM TRAVA ELÉTRICA
// USINAINFO < https://www.usinainfo.com.br >
// FACEBOOK  < https://www.facebook.com/usinainfo.arduino >
// YOUTUBE   < https://www.youtube.com/usinainfo >
// INSTAGRAM < @usinainfo >

#include <LiquidCrystal.h>
#include <RFID.h>
#include <SPI.h>
#include <Wire.h>

#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

const int solenoide = 8;
int serNum[5];

int cards[][5] = {{118, 157, 177, 171, 241},
                  {240, 193, 247, 54, 240},
                  {131, 95, 107, 154, 45}};

bool access = false;

int alarm = 0;
uint8_t alarmStat = 0;
uint8_t maxError = 5;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  SPI.begin();
  rfid.init();

  pinMode(solenoide, OUTPUT);
  digitalWrite(solenoide, LOW);

  lcd.setCursor(0, 0);
  lcd.print(F(" Controle RFID"));
  lcd.setCursor(0, 1);
  lcd.print(F("   de Acesso"));
  delay(3000);
  lcd.clear();
}

void loop() {
  if (alarm >= maxError) {
    alarmStat = 1;
  }

  if (alarmStat == 0) {
    lcd.setCursor(0, 0);
    lcd.print(F("Acesso UsinaInfo"));
    lcd.setCursor(0, 1);
    lcd.print(F(" Aguardando COD"));

    if (rfid.isCard()) {
      if (rfid.readCardSerial()) {
        Serial.print(rfid.serNum[0]);
        Serial.print(" ");
        Serial.print(rfid.serNum[1]);
        Serial.print(" ");
        Serial.print(rfid.serNum[2]);
        Serial.print(" ");
        Serial.print(rfid.serNum[3]);
        Serial.print(" ");
        Serial.print(rfid.serNum[4]);
        Serial.println("");

        for (int x = 0; x < sizeof(cards) / sizeof(cards[0]); x++) {
          for (int i = 0; i < sizeof(rfid.serNum); i++) {
            if (rfid.serNum[i] != cards[x][i]) {
              access = false;
              break;
            } else {
              access = true;
            }
          }
          if (access) break;
        }
      }

      if (access) {
        Serial.println("Bem-Vindo(a)!");
        lcd.print(rfid.serNum[0]);
        lcd.print(rfid.serNum[1]);
        lcd.print(rfid.serNum[2]);
        lcd.print(rfid.serNum[3]);
        lcd.print(rfid.serNum[4]);
        digitalWrite(solenoide, HIGH);
        lcd.setCursor(0, 0);
        lcd.print(F("  Bem-Vindo(a)  "));
        lcd.setCursor(0, 1);
        lcd.print(F("                "));
        for (int i = 5; i > 0; i--) {
          lcd.setCursor(8, 1);
          lcd.print(i);
          delay(1000);
        }
        digitalWrite(solenoide, LOW);
        lcd.clear();
      } else {
        alarm = alarm + 1;
        Serial.println("Acesso Negado!");
        lcd.print(rfid.serNum[0]);
        lcd.print(rfid.serNum[1]);
        lcd.print(rfid.serNum[2]);
        lcd.print(rfid.serNum[3]);
        lcd.print(rfid.serNum[4]);
        lcd.clear();
      }
    }
    rfid.halt();
  } else {
    lcd.setCursor(0, 0);
    lcd.print(F("  Acesso Negado "));
    lcd.setCursor(0, 1);
    lcd.print(F("                "));
    for (int i = 10; i > 0; i--) {
      lcd.setCursor(7, 1);
      lcd.print(i);
      lcd.print(F("  "));
      delay(1000);
    }
    alarmStat = 0;
    alarm = 0;
  }
}
