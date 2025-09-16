#include <TM1637Display.h>

#define CLK 11
#define DIO 10

TM1637Display display = TM1637Display(CLK, DIO);

int i;
int b;

void setup() {
  display.clear();
  display.setBrightness(7);
}

void loop() {
  display.clear();
  for (i = 0; i < 60; i++)
  {
    display.showNumberDecEx(b, 0b11100000, true, 2, 0); // displayed _28_
    display.showNumberDecEx(i, 0b11100000, true, 2, 2); // displayed _28_
    delay(100);
    if (i == 59)
    {
      i = 0;
      b++;

      if (b == 24)
      {
        b = 0;
      }
    }
  }
}
