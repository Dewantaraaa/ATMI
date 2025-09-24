#include <LiquidCrystal.h>
#include <Keypad.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 200;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo


  NOTE_E5, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, REST, 8, NOTE_C5, 8, NOTE_E5, 8, //1
  NOTE_G5, 4, REST, 4, NOTE_G4, 8, REST, 4,
  NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, // 3
  NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8,
  REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4,
  NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, // repeats from 3
  NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8,
  REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4,


  REST, 4, NOTE_G5, 8, NOTE_FS5, 8, NOTE_F5, 8, NOTE_DS5, 4, NOTE_E5, 8, //7
  REST, 8, NOTE_GS4, 8, NOTE_A4, 8, NOTE_C4, 8, REST, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_D5, 8,
  REST, 4, NOTE_DS5, 4, REST, 8, NOTE_D5, -4,
  NOTE_C5, 2, REST, 2,

  REST, 4, NOTE_G5, 8, NOTE_FS5, 8, NOTE_F5, 8, NOTE_DS5, 4, NOTE_E5, 8, //repeats from 7
  REST, 8, NOTE_GS4, 8, NOTE_A4, 8, NOTE_C4, 8, REST, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_D5, 8,
  REST, 4, NOTE_DS5, 4, REST, 8, NOTE_D5, -4,
  NOTE_C5, 2, REST, 2,

  NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, REST, 8, NOTE_C5, 8, NOTE_D5, 4, //11
  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2,

  NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, REST, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, //13
  REST, 1,
  NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, REST, 8, NOTE_C5, 8, NOTE_D5, 4,
  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2,
  NOTE_E5, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, REST, 8, NOTE_C5, 8, NOTE_E5, 4,
  NOTE_G5, 4, REST, 4, NOTE_G4, 4, REST, 4,
  NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, // 19

  NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8,
  REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4,

  NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, // repeats from 19
  NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8,
  REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4,

  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4, //23
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_D5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_G5, -8, NOTE_F5, -8,

  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2, //26
  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4,
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_B4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_F5, -8, NOTE_E5, -8, NOTE_D5, -8,
  NOTE_C5, 8, NOTE_E4, 4, NOTE_E4, 8, NOTE_C4, 2,

  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4, //repeats from 23
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_D5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_G5, -8, NOTE_F5, -8,

  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2, //26
  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4,
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_B4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_F5, -8, NOTE_E5, -8, NOTE_D5, -8,
  NOTE_C5, 8, NOTE_E4, 4, NOTE_E4, 8, NOTE_C4, 2,
  NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, REST, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8,
  REST, 1,

  NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, REST, 8, NOTE_C5, 8, NOTE_D5, 4, //33
  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2,
  NOTE_E5, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, REST, 8, NOTE_C5, 8, NOTE_E5, 4,
  NOTE_G5, 4, REST, 4, NOTE_G4, 4, REST, 4,
  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4,
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_D5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_A5, -8, NOTE_G5, -8, NOTE_F5, -8,

  NOTE_E5, 8, NOTE_C5, 4, NOTE_A4, 8, NOTE_G4, 2, //40
  NOTE_E5, 8, NOTE_C5, 4, NOTE_G4, 8, REST, 4, NOTE_GS4, 4,
  NOTE_A4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_A4, 2,
  NOTE_B4, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_F5, -8, NOTE_E5, -8, NOTE_D5, -8,
  NOTE_C5, 8, NOTE_E4, 4, NOTE_E4, 8, NOTE_C4, 2,

  //game over sound
  NOTE_C5, -4, NOTE_G4, -4, NOTE_E4, 4, //45
  NOTE_A4, -8, NOTE_B4, -8, NOTE_A4, -8, NOTE_GS4, -8, NOTE_AS4, -8, NOTE_GS4, -8,
  NOTE_G4, 8, NOTE_D4, 8, NOTE_E4, -2,

};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

#define inPin1 28  // Start
#define inPin2 22  // Pause
#define inPin3 23  // Reset
#define inPin4 24  // Clear

#define buzzer 53  // Clear

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long lastBeepTime = 0;
int beepInterval = 1000; // default 1 detik


const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

byte pin_rows[ROW_NUM] = {52, 51, 50, 49};
byte pin_column[COLUMN_NUM] = {48, 47, 46, 45};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

bool isRunning = false;
bool isPaused = false;
bool isInputMode = true;
bool isReset = false;

bool prevStartBtn = LOW;
bool prevPauseBtn = LOW;
bool prevResetBtn = LOW;
bool prevClearBtn = LOW;

bool stopNotification = true;
bool isNotifying = false;
int noteIndex = 0;
unsigned long noteStartTime = 0;


int cursorColumn = 0;

unsigned long totalTime = 0;       // waktu total dalam ms (input)
unsigned long remainingTime = 0;   // waktu yang tersisa
unsigned long lastUpdate = 0;

char inputBuffer[7];
int inputPos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);

  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("HELLOO BOS!");
  lcd.setCursor(0, 1);
  lcd.print("C4 Ready");
  delay(2000);

  lcd.clear();
  lcd.print("Input Time:");
  lcd.setCursor(0, 1);
  lcd.print("HHMMSS");
  memset(inputBuffer, 0, sizeof(inputBuffer));
}

void notifikasi() {
  if (!isNotifying) return;

  unsigned long currentMillis = millis();

  // Cek jika sudah selesai semua notifikasi
  if (noteIndex >= notes * 2) {
    noTone(buzzer);
    isNotifying = false;
    noteIndex = 0;
    noteStartTime = 0;
    return;
  }

  // Cek waktu untuk mainkan nada selanjutnya
  if (noteStartTime == 0 || currentMillis - noteStartTime >= noteDuration) {
    noTone(buzzer);  // pastikan nada sebelumnya dimatikan

    int note = melody[noteIndex];
    int divider = melody[noteIndex + 1];

    if (divider > 0) {
      noteDuration = wholenote / divider;
    } else {
      noteDuration = (wholenote / abs(divider)) * 1.5;
    }

    noteStartTime = currentMillis;

    if (note != REST) {
      tone(buzzer, note, noteDuration * 0.9);
    }

    noteIndex += 2;
  }
}



void start() {
  if (isInputMode) {
    lcd.clear();
    lcd.print("Input Time:");
    lcd.setCursor(0, 1);
    lcd.print("HHMMSS");
    return;
  }
  if (!isRunning && !isPaused && remainingTime > 0) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    isRunning = true;
    isPaused = false;
    lastUpdate = millis();
  } else if (isPaused && remainingTime > 0) {
    isRunning = true;
    isPaused = false;
    lastUpdate = millis();
  }
}

void pause() {
  if (isRunning && !isPaused) {
    isPaused = true;
    isRunning = false;
    displayTime(remainingTime);
  }
}

void reset() {
  if (isRunning || isPaused || isNotifying) {
    isRunning = false;
    isPaused = false;

    if (isNotifying) {
      isNotifying = false;
      noTone(buzzer);
    }

    remainingTime = totalTime;
    lcd.clear();
    isReset = true;
    lcd.print("Reset Time");
    delay(500);
    lcd.clear();
    displayTime(remainingTime);
  }
}

void clearInput() {
  if (!isRunning && !isPaused || isReset) {
    stopNotification = false;
    isInputMode = true;
    isRunning = false;
    isPaused = false;
    isReset = false;

    if (isNotifying) {
      isNotifying = false;
      noTone(buzzer);
    }

    totalTime = 0;
    remainingTime = 0;
    inputPos = 0;
    memset(inputBuffer, 0, sizeof(inputBuffer));
    lcd.clear();
    lcd.print("Input Time:");
    lcd.setCursor(0, 1);
    lcd.print("HHMMSS");
  }
}

void displayTime(unsigned long ms) {
  unsigned long totalSeconds = ms / 1000;
  int hours = totalSeconds / 3600;
  int minutes = (totalSeconds % 3600) / 60;
  int seconds = totalSeconds % 60;

  lcd.setCursor(0, 1);
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print("        ");
}

void loop() {
  bool startBtn = digitalRead(inPin1);
  bool pauseBtn = digitalRead(inPin2);
  bool resetBtn = digitalRead(inPin3);
  bool clearBtn = digitalRead(inPin4);

  if (isInputMode) {
    char key = keypad.getKey();
    if (key) {
      if (key >= '0' && key <= '9') {
        if (inputPos < 6) {

          inputBuffer[inputPos] = key;
          lcd.setCursor(inputPos, 1);
          lcd.print(key);
          inputPos++;
          digitalWrite(buzzer, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
        }
      }
      if (inputPos == 6) {
        int hh = (inputBuffer[0] - '0') * 10 + (inputBuffer[1] - '0');
        int mm = (inputBuffer[2] - '0') * 10 + (inputBuffer[3] - '0');
        int ss = (inputBuffer[4] - '0') * 10 + (inputBuffer[5] - '0');

        if (mm > 59 || ss > 59) {
          lcd.clear();
          lcd.print("Input Time:");
          lcd.setCursor(0, 1);
          lcd.print("HHMMSS");
          inputPos = 0;
          memset(inputBuffer, 0, sizeof(inputBuffer));
        } else {
          totalTime = ((unsigned long)hh * 3600 + (unsigned long)mm * 60 + (unsigned long)ss) * 1000UL;
          remainingTime = totalTime;
          isInputMode = false;
          lcd.clear();
          displayTime(remainingTime);
          lcd.clear();
          displayTime(remainingTime);
        }
      }
    }
  }

  if (startBtn == HIGH && prevStartBtn == LOW) {
    start();
  }
  if (pauseBtn == HIGH && prevPauseBtn == LOW) {
    pause();
  }
  if (resetBtn == HIGH && prevResetBtn == LOW) {
    reset();
  }
  if (clearBtn == HIGH && prevClearBtn == LOW) {
    clearInput();
  }

  prevStartBtn = startBtn;
  prevPauseBtn = pauseBtn;
  prevResetBtn = resetBtn;
  prevClearBtn = clearBtn;

  if (isRunning) {
    unsigned long now = millis();

    // Update waktu setiap 1 detik
    if (now - lastUpdate >= 1000) {
      lastUpdate = now;

      if (remainingTime >= 1000) {
        remainingTime -= 1000;
        displayTime(remainingTime);
      } else {
        remainingTime = 0;
        isRunning = false;
        lcd.clear();
        digitalWrite(buzzer, HIGH);
        delay(1500);
        digitalWrite(buzzer, LOW);
        lcd.setCursor(0, 0);
        lcd.print("BOOM!!");
        lcd.setCursor(0, 1);
        lcd.print("Reset for stop");
        isNotifying = true;
        noteIndex = 0;
        noteStartTime = 0;
      }
    }

    // Beep setiap detik (lebih cepat saat mendekati habis)
    if (remainingTime > 0) {
      if (remainingTime <= 3000) {
        beepInterval = 200;
      } else if (remainingTime <= 10000) {
        beepInterval = 500;
      } else {
        beepInterval = 1000;
      }

      if (now - lastBeepTime >= beepInterval) {
        lastBeepTime = now;
        tone(buzzer, 1000, 100);
      }
    }
  } else if (isPaused) {
    displayTime(remainingTime);
  }

  notifikasi();
}
