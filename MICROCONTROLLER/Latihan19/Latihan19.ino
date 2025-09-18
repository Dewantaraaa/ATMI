#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(A0);

  float voltage = map(analogValue, 0, 1023, 0, 5);

  lcd.setCursor(0, 2);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("v");
}
