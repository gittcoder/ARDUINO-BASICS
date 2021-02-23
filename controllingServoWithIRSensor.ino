#include<Servo.h>
Servo yoServo;
int servoPin=9;
int distPin=0;
void setup()
{
  yoServo.attach(servoPin);
}

void loop()
{
  int dist=analogRead(distPin);
  int pos=map(dist,0,1023,0,180);
  
  yoServo.write(pos);
   
  
  
}