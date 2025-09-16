#define buzzer 7
int i;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  while (i < 2)
  {
    tone(buzzer, 10000);
    delay(500);
    noTone(buzzer);
    delay(500);
    i++;
  }
}
