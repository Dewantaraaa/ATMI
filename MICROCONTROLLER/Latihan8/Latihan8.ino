#include <TM1637Display.h>

#define CLK 7
#define DIO 6

TM1637Display display = TM1637Display(CLK, DIO);

void setup() {
  display.clear();
  display.setBrightness(7);
}

void loop() {
  int i;
  for (i = 0; i < 10; i++) 
  {
    display.showNumberDec(i);
    delay(500);
    display.clear();
  }
  for (i =9 ; i >= 0; i--) 
  {
    display.showNumberDec(i);
    delay(500);
    display.clear();
  }
}
