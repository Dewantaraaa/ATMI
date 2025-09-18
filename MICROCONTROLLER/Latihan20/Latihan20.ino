#include <Keypad.h>
#include <TM1637Display.h>

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ROW_NUM = 4; 
const int COLUMN_NUM = 4; 

int cursorColumn = 0; 

char keys[ROW_NUM][COLUMN_NUM] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

byte pin_rows[ROW_NUM] = {47, 46, 45, 44};
byte pin_column[COLUMN_NUM] = {43, 42, 41, 40};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(cursorColumn, 0); 
    lcd.print(key);                 

    cursorColumn++;            
    if(cursorColumn == 16) {
      lcd.clear();
      cursorColumn = 0;
    }
  }
}
