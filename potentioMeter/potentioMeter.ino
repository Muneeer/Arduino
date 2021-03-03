const int POTENTIO=A13;
const int RED_LED=3;
int onoff=1;
int value;
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
//  Serial.print("Value = ");
//  Serial.print(anal_val,DEC);
//  Serial.print("\tVoltage = ");
//  Serial.println(f_vol,2);
  
 
     value=Serial.read();
     if(value=='o'){
      Serial.print("Light On.\n");
      
      analogWrite(RED_LED,anal_val/4);
      onoff=1;
      }
      else if(value=='f')
      {
        onoff=0;
        analogWrite(RED_LED,0);
        Serial.print("Light Off.\n");
      }
 

  if(onoff==1)
  {
  Serial.print("Value = ");
  Serial.print(anal_val,DEC);
  Serial.print("\tVoltage = ");
  Serial.println(f_vol,2);
  
  Serial.println("(V)");
  delay(1000);
  
  }


  //analogWrite(RED_LED,anal_val/4);
}
