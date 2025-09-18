#define potensio A1
#define lampu 7

float voltage;
int analogValue;
int value;

void setup() {
  pinMode(lampu, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(potensio);

  voltage = map(analogValue, 0, 1023, 0, 255); //0 min val, 5 max val
  
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  value = analogRead(voltage);
  analogWrite(lampu, voltage);
}
