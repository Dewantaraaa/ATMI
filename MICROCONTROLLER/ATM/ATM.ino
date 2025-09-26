#include <Keypad.h>
#include <LiquidCrystal.h>
#define BUZZER 8

char keys[4][4] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '='},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[4] = {22, 24, 26, 28};
byte colPins[4] = {30, 32, 34, 36};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

LiquidCrystal lcd(40, 42, 50, 48, 46, 44);

String data;
int kondisi;

long saldo = 5000;
long input;
long nominal;

int tekan(int data) {
  input = data;
  nominal = (nominal * 10) + input;
  Serial.println(nominal);
  lcd.setCursor(0, 1);
  lcd.print(nominal);
}

void tombol_TARIK() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '0':
        tekan(0);
        break;
      case '1':
        tekan(1);
        break;
      case '2':
        tekan(2);
        break;
      case '3':
        tekan(3);
        break;
      case '4':
        tekan(4);
        break;
      case '5':
        tekan(5);
        break;
      case '6':
        tekan(6);
        break;
      case '7':
        tekan(7);
        break;
      case '8':
        tekan(8);
        break;
      case '9':
        tekan(9);
        break;
      default:
        kondisi = 7;
        break;
    }
  }
}

void tombol_SETOR() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '0':
        tekan(0);
        break;
      case '1':
        tekan(1);
        break;
      case '2':
        tekan(2);
        break;
      case '3':
        tekan(3);
        break;
      case '4':
        tekan(4);
        break;
      case '5':
        tekan(5);
        break;
      case '6':
        tekan(6);
        break;
      case '7':
        tekan(7);
        break;
      case '8':
        tekan(8);
        break;
      case '9':
        tekan(9);
        break;
      default:
        kondisi = 8;
        break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(BUZZER, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Masukan Pin ATM");
  lcd.setCursor(0, 1);
}

void loop() {
  while (kondisi == 0) {
    char key = keypad.getKey();
    if (key) {
      data = data + key;
      lcd.print('*');
      Serial.println(data);
      if (key == 'A') {
        if (data == "1234A") {
          kondisi = 1;
          lcd.clear();
        }
        else {
          kondisi = 2;
          lcd.clear();
        }
      }
    }
  }

  while (kondisi == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Pin Benar");
    delay(500);
    kondisi = 3;
  }

  while (kondisi == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Pin Salah");
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Masukan Pin ATM");
    lcd.setCursor(0, 1);
    data = "";
    kondisi = 0;
  }

  while (kondisi == 3) {
    lcd.setCursor(0, 0);
    lcd.print("1. CEK  3. TARIK");
    lcd.setCursor(0, 1);
    lcd.print("2. OUT  4. SETOR");
    char key = keypad.getKey();
    if (key) {
      switch (key) {
        case '1':
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("CEK SALDO");
          lcd.setCursor(0, 1);
          kondisi = 4;
          break;
        case '2':
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Masukan Pin ATM");
          lcd.setCursor(0, 1);
          data = "";
          kondisi = 0;
          break;
        case '3':
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("TARIK TUNAI");
          lcd.setCursor(0, 1);
          kondisi = 5;
          break;
        case '4':
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SETOR TUNAI");
          lcd.setCursor(0, 1);
          kondisi = 6;
          break;
        default:
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(" salah berpikir");
          delay(1000);
          lcd.setCursor(0, 0);
          lcd.print("Masukan Pin ATM");
          lcd.setCursor(0, 1);
          data = "";
          kondisi = 0;
          break;
      }
    }
  }

  while (kondisi == 4) { // CEK SALDO
    lcd.print("Saldo : ");
    lcd.print(saldo);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Masukan Pin ATM");
    lcd.setCursor(0, 1);
    data = "";
    kondisi = 0;
  }
  while (kondisi == 5) { // TARIK TUNAI
    tombol_TARIK();
  }
  while (kondisi == 6) { // SETOR TUNAI
    tombol_SETOR();
  }
  while (kondisi == 7) {
    lcd.clear();
    delay(1500);
    if (nominal < saldo) {
      saldo = saldo - nominal;
      lcd.setCursor(0, 0);
      lcd.print("  TARIK TUNAI  ");
      lcd.setCursor(0, 1);
      lcd.print("   BERHASIL    ");
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("  TARIK TUNAI  ");
      lcd.setCursor(0, 1);
      lcd.print("    GAGAL    ");
    }
    nominal = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Masukan Pin ATM");
    lcd.setCursor(0, 1);
    data = "";
    kondisi = 0;
  }
  while (kondisi == 8) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  SETOR TUNAI  ");
    lcd.setCursor(0, 1);
    lcd.print("   BERHASIL    ");
    delay(1500);
    saldo = saldo + nominal;
    nominal = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Masukan Pin ATM");
    lcd.setCursor(0, 1);
    data = "";
    kondisi = 0;
  }
}
