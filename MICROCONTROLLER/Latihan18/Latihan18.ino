#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int BUTTON_PIN = 6; 
int jumlah;

int lastState = HIGH; 
int currentState;  

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == LOW && currentState == HIGH)
  {
    jumlah++;
    lcd.setCursor(0, 0);
    lcd.print("TASBIH PINTAR");
    lcd.setCursor(0, 1);
    lcd.print("JUMLAH: ");
    lcd.print(jumlah);
    delay(1000);
  }

  lastState = currentState;
}
