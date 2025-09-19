#define r 53
#define y 51
#define g 49
#define A 8
#define B 9
#define C 10

int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int reading = LOW;
int baca1, baca2;

int kondisi = 0;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void bacaButton() {
  reading = digitalRead(B);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;

        if (ledState == HIGH) {
          kondisi = 1;
        }
        else {
          kondisi = 4;
        }
      }
    }
  }

  lastButtonState = reading;
}

void jeda(int waktu) {
  for (int ulang = 0; ulang <= waktu; ulang++) {
    delay(1);
    bacaButton();
    Serial.println(kondisi);
  }
}

void setup() {
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);

  Serial.begin(9600);

  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
}

void loop() {
  while (kondisi == 0) {
    bacaButton();
  }

  while (kondisi == 1) {
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    kondisi = 2;
    jeda(100);
  }
  while (kondisi == 2) {
    digitalWrite(r, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(g, LOW);
    kondisi = 3;
    jeda(100);
  }
  while (kondisi == 3) {
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
    kondisi = 1;
    jeda(100);
  }
  while (kondisi == 4) {
    bacaButton();
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }
}
