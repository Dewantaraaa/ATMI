void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);

  float voltage = map(analogValue, 0, 1023, 0, 5); //0 min val, 5 max val
  
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  int value = analogRead(voltage);
  delay(1000);
}
