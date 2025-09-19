#define LaserPin 8


void setup ()
{
  pinMode (LaserPin, OUTPUT);
}
void loop () {
  digitalWrite (LaserPin, HIGH);
  //   delay (1000);
  //   digitalWrite (LaserPin, LOW);
  //   delay (1000);
}
