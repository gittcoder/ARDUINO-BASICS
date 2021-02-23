#include<SPI.h>
int SS=10;
void setup()
{
  //Set $$ pin direction
  //others are handeled automatically
  pinMode(SS,OUTPUT);
  //initialize SPI
  SPI.begin();
}

void setLed(int reg,int level)
{
  digitalWrite(SS,LOW);
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SS,HIGH);
}  

void loop()
{
  for(int i =0;i<=2;i++)
  {
    for(int j=50;j<=255;j++)
    {
      setLed(i,j);
      delay(20);
    }
    delay(500);
    for(int j =255;j>=50;j--)
    {
      setLed(i,j);
      delay(20);
    }
  }
}