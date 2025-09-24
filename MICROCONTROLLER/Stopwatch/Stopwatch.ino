#include <LiquidCrystal.h>

#define inPin1 22  // Start
#define inPin2 23  // Pause
#define inPin3 24  // Reset

#define led1 25
#define led2 26
#define led3 27

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool isRunning = false;
bool isPaused = false;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
unsigned long currentTime = 0;

bool prevStartBtn = LOW;
bool prevPauseBtn = LOW;
bool prevResetBtn = LOW;

void start() {
  if (!isRunning && !isPaused) {
    startTime = millis() - elapsedTime;
    isRunning = true;
    lcd.clear();
    lcd.print("Running...");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  } else if (isPaused) {
    startTime = millis() - elapsedTime;
    isRunning = true;
    isPaused = false;
    lcd.clear();
    lcd.print("Running...");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}

void kedip() {
  for (int i = 0 ; i < 3 ; i++)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
  }
}

void pause() {
  if (isRunning && !isPaused) {
    elapsedTime = millis() - startTime;
    isRunning = false;
    isPaused = true;
    lcd.clear();
    lcd.print("Paused");

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
}

void reset() {
  if (isPaused) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
    isPaused = false;
    elapsedTime = 0;
    lcd.clear();
    lcd.print("Resetting...");
    delay(1000);
    lcd.clear();
    lcd.print("Stopwatch Ready");
    delay(1000);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);

  lcd.begin(16, 2);
  lcd.print("Stopwatch Ready");
  kedip();
}

void loop() {
  bool startBtn = digitalRead(inPin1);
  bool pauseBtn = digitalRead(inPin2);
  bool resetBtn = digitalRead(inPin3);

  if (startBtn == HIGH && prevStartBtn == LOW) {
    start();
  }

  if (pauseBtn == HIGH && prevPauseBtn == LOW) {
    pause();
  }

  if (resetBtn == HIGH && prevResetBtn == LOW) {
    reset();
  }

  prevStartBtn = startBtn;
  prevPauseBtn = pauseBtn;
  prevResetBtn = resetBtn;

  if (isRunning) {
    currentTime = millis() - startTime;
  } else {
    currentTime = elapsedTime;
  }

  int minutes = currentTime / 60000;
  int seconds = (currentTime % 60000) / 1000;
  int milliseconds = (currentTime % 1000) / 10;

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print(":");
  if (milliseconds < 10) lcd.print("0");
  lcd.print(milliseconds);
}
