#include<Servo.h>
Servo yoServo;
int servoPin=9;

void setup()
{
  yoServo.attach(servoPin);
}

void loop()
{
  for(int i=0;i<=180;i=i+20)
  {
    yoServo.write(i);
    delay(1000);
  }
  
}