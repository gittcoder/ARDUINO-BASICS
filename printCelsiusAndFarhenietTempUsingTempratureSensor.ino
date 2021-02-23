#include<Wire.h>
int temp_address=72;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  //Start talking
  Wire.beginTransmission(temp_address);
  //Ask for Register zero
  Wire.send(0);
  //Complete Transmission
  Wire.endTransmission();
  //Request 1 byte
  Wire.requestFrom(temp_address,1);
  //Wait for response
  while(Wire.available()==0);
  //get the temp
  int c=Wire.receive();
  //Convert from celsius to farheniet
  int f=round(c*9.0/5.0+32.0);
  
  //print the results
  Serial.print(c);
  Serial.print("C,");
  Serial.print(f);
  Serial.println("F");
  delay(500);
}
processing code

void setup()
{
  size(400,400);
  port= new Serial(this,"COM3",9600);
  port.bufferUntil('.');
  font=loadFont("AgencyFB-Bold-200.vlw");
  textFont(font,200);
}

void ddraw()
{
  background(0,0,0);
  fill(46,209,2);
  text(temp_c,70,175);
  fill(0,102,153);
  text(temp_f,70,370);
}

void serialEvent(Serial port)
{
  data=port.readStringUntil('.');
  data=data.substring(0,data.length()-1);
  //look for comma
  index=data.indexOf(",");
  //fetch celsius
  temp_c=data.substring(0,index);
  //fetch farenheit
  temp_f=data.substring(index+1,data.length());
  
  
}