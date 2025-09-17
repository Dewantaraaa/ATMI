

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);

  float voltage = floatMap(analogValue, 0, 1023, 0, 5); //0 min val, 5 max val
  
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  int value = analogRead(voltage);
  Serial.print("Nilai ADC: "); Serial.println(value);
  delay(1000);
}
