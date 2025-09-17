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

char inputBuffer[4] = {' ', ' ', ' ', ' '};

void setup() {
  Serial.begin(9600);
  display.clear();
  display.setBrightness(7);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    for (int i = 0; i < 3; i++) {
      inputBuffer[i] = inputBuffer[i + 1];
    }

    inputBuffer[3] = key;

    uint8_t segments[4];

    for (int i = 0; i < 4; i++) {
      segments[i] = charToSegment(inputBuffer[i]);
    }
    display.setSegments(segments);
  }
}

uint8_t charToSegment(char c) {
  switch (c) {
    case '0': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F;
    case '1': return SEG_B | SEG_C;
    case '2': return SEG_A | SEG_B | SEG_D | SEG_E | SEG_G;
    case '3': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_G;
    case '4': return SEG_B | SEG_C | SEG_F | SEG_G;
    case '5': return SEG_A | SEG_C | SEG_D | SEG_F | SEG_G;
    case '6': return SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case '7': return SEG_A | SEG_B | SEG_C;
    case '8': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case '9': return SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G;
    case 'A': return SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case 'B': return SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'C': return SEG_A | SEG_D | SEG_E | SEG_F;
    case 'D': return SEG_B | SEG_C | SEG_D | SEG_E | SEG_G;
    case 'E': return SEG_A | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'F': return SEG_A | SEG_E | SEG_F | SEG_G;
    case '*': return SEG_A | SEG_C | SEG_E | SEG_G; 
    case '#': return SEG_B | SEG_C | SEG_E | SEG_F | SEG_G; 
    case ' ': return 0x00; 
    default:  return 0x00; 
  }
}
