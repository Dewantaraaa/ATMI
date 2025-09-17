

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue1 = analogRead(A0);
  int analogValue2 = analogRead(A1);
  int analogValue3 = analogRead(A2);

  float voltage1 = floatMap(analogValue1, 0, 1023, 0, 5); //0 min val, 5 max val
  float voltage2 = floatMap(analogValue2, 0, 1023, 0, 5);
  float voltage3 = floatMap(analogValue3, 0, 1023, 0, 5);

  Serial.print("Analog: ");
  Serial.print(analogValue1);
  Serial.print(", Voltage: ");
  Serial.print(voltage1);
  Serial.print(" | Analog: ");
  Serial.print(analogValue2);
  Serial.print(", Voltage: ");
  Serial.print(voltage2);
  Serial.print(" | Analog: ");
  Serial.print(analogValue3);
  Serial.print(", Voltage: ");
  Serial.println(voltage3);
  delay(1000);
}
