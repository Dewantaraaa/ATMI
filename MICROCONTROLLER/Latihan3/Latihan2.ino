int ledPin1 = 2; 
int ledPin2 = 3; 
int ledPin3 = 4; 
int inPin = 5;  
int val = 0;      

void setup() {
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);  
  pinMode(ledPin3, OUTPUT);  
  pinMode(inPin, INPUT);    
}

void loop() {
  val = digitalRead(inPin);  

  if(val == HIGH)
  {
    digitalWrite(ledPin1, HIGH);  
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
  else
  {
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}
