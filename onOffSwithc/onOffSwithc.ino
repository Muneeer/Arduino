const int POTENTIO=A13;
const int RED_LED=3;
int value;
int flag=1;
void setup()
{
  pinMode(POTENTIO,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int anal_val,voltage;
  float f_vol;
  anal_val=analogRead(POTENTIO);
  voltage=map(anal_val,0,1023,0,500);
  f_vol=voltage/100.0;
  
      value=Serial.read();
      if(value=='o'){
      Serial.print("Light Off.\n");
      analogWrite(RED_LED,0);
      flag=0;
      }
      if(value=='f')
      {
        analogWrite(RED_LED,anal_val/4);
        flag=1;
      }
  if(flag)
  {
      Serial.print("Value = ");
      Serial.print(anal_val,DEC);
      Serial.print("\tVoltage = ");
      Serial.println(f_vol,2);
  
      Serial.println("(V)");
      analogWrite(RED_LED,anal_val/4);
      delay(1000);
  }

  
 
 


}
