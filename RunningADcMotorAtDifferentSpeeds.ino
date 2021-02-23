int motorPin=9;
void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  //Accelerate motor from 0 to 255
  for( int i =0;i<=255;i++)
  {
    analogWrite(motorPin,i);
    delay(10);
  }
  
  //Hold at top speed
  delay(500);
  
  //decrease from 255 to 0
  for( int i =255;i>=0;i--)
  {
    analogWrite(motorPin,i);
    delay(10);
  }
  //hold at zero
  delay(500);
}