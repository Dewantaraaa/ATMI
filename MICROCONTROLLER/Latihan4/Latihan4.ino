#define ledPin1 2 
#define ledPin2 3 
#define ledPin3 4 
#define inPin 5  

int val1, val2, val = 0;      

void setup() {
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);  
  pinMode(ledPin3, OUTPUT);  
  pinMode(inPin, INPUT);    
}

void loop() {
  val1 = digitalRead(inPin);  
  if((val1 == HIGH) && (val2 == LOW))
  {
    val = 1 - val; 
    delay(100);
  }

  val2 = val1;

  if(val == 1)
  {
    digitalWrite(ledPin1, HIGH);  
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }else{
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
  
}
