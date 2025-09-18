#include <Keypad.h>
#include <TM1637Display.h>

#define CLK 11
#define DIO 10

TM1637Display display = TM1637Display(CLK, DIO);

const int ROW_NUM = 4; 
const int COLUMN_NUM = 4; 

char keys[ROW_NUM][COLUMN_NUM] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
  display.clear();
  display.setBrightness(7);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key >= '0' && key <= '9') {
      int value = key - '0'; 
      display.showNumberDec(value, false, 4, 0);
    } else {
      const uint8_t segment;

      switch (key) {
        case 'A':
          display.setSegments((const uint8_t[]){SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G}, 1, 3);
          break;
        case 'B':
          display.setSegments((const uint8_t[]){SEG_C | SEG_D | SEG_E | SEG_F | SEG_G}, 1, 3); 
          break;
        case 'C':
          display.setSegments((const uint8_t[]){SEG_A | SEG_D | SEG_E | SEG_F}, 1, 3);
          break;
        case 'D':
          display.setSegments((const uint8_t[]){SEG_B | SEG_C | SEG_D | SEG_E | SEG_G}, 1, 3); 
          break;
        case '*':
          display.setSegments((const uint8_t[]){SEG_A | SEG_C | SEG_E | SEG_G}, 1, 3); 
          break;
        case '#':
          display.setSegments((const uint8_t[]){SEG_B | SEG_C | SEG_E | SEG_F | SEG_G}, 1, 3); 
          break;
        default:
          display.clear();
          break;
      }
    }
  }
}
