const int flamePin = 8; 
const int ledPin = 13;  
const int buzzerPin = 9;

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int flameDetected = digitalRead(flamePin);

  if (flameDetected == LOW) {
    Serial.println("No flame detected.");
    digitalWrite(ledPin, LOW); 
    digitalWrite(buzzerPin, LOW); 
  } else {
    Serial.println("Flame detected!");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH); 
  }

  delay(100); 
}
