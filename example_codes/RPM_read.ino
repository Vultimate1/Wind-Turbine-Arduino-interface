// Read RPM code
#include <Wire.h>

float rpm = 0;
int pid;
unsigned long millisBefore;
volatile int holes;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING); // falling is where detect happens
  delay(1000);
}

void loop()
{
  print_to_Serial();
  if (millis() - millisBefore > 1000) {
    rpm = (holes / 24.0)*60;
    holes = 0;
    millisBefore = millis();
  }
  delay(100);
}

void print_to_Serial() {
  Serial.print("RPM   : ");
  Serial.println(rpm);
}

void count() {
  holes++;
}
