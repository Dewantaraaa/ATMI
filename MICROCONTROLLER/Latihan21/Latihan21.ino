#include "Adafruit_Sensor.h"
#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 9

#define DHTTYPE DHT11   // DHT 11 

DHT dht = DHT(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" % ");
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.print("c");
  lcd.print(f);
  lcd.print("f");
//  lcd.print(hic);
//  lcd.print(hif);
}
