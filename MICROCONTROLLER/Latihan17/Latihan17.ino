#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte customChar[8] = {
  B00100,
  B01111,
  B10100,
  B10100,
  B01110,
  B00101,
  B11110,
  B00100
};
 

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, customChar);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("E-Wallet");
  lcd.setCursor(0, 1);
  lcd.print("Balance : 100");
  lcd.write((byte)0);
}
