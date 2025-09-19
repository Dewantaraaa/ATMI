#include <Servo.h>

int servoPin = 9;

Servo servo;

void setup()
{
  servo.attach(servoPin);
}


void loop()
{
  int analogValue = analogRead(A0);

  int angle = map(analogValue, 0, 1023, 0, 180);

  servo.write(angle);
  delay(15);

}
