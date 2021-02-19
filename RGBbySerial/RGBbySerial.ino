#define RED_LED 13
#define GREEN_LED 12
#define BLUE_LED 11
int state=-1;
int start=1;
int color[100][3];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9650);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(start)
  { 
    Serial.println("Welcome to the color game.");
    Serial.println("You use {red,green,blue,ruby,sapphire} colors.");
    Serial.println("You use {remove, reset}, \nto remove the previous or reset all LED colors.");
  }
  start=0;

    String value;

    
    value=Serial.readStringUntil('\n');
    if(value.equalsIgnoreCase("reset"))
    {
        state=-1;  
        digitalWrite(RED_LED,0);
        digitalWrite(GREEN_LED,0);
        digitalWrite(BLUE_LED,0);
        start=1;
    }
     else if(value.equalsIgnoreCase("remove"))
    {
      
      state--;  
    }
    if(value.equalsIgnoreCase("red")){
          state++;
          color[state][0]=255;
          color[state][1]=0;
          color[state][2]=0;
          Serial.println("Red");
      }
    else if(value.equalsIgnoreCase("green")){
          state++;
          color[state][0]=0;
          color[state][1]=255;
          color[state][2]=0;
          Serial.println("Green");
          
      }
    else if(value.equalsIgnoreCase("blue")){
          state++;
          color[state][0]=0;
          color[state][1]=0;
          color[state][2]=255;
          Serial.println("Blue");
         
      }
    else if(value.equalsIgnoreCase("ruby")){
          state++;
          color[state][0]=224;
          color[state][1]=17;
          color[state][2]=95;
          Serial.println("Ruby");
          
      }
     else if(value.equalsIgnoreCase("sapphire")){
            state++;
            color[state][0]=15;
            color[state][1]=82;
            color[state][2]=186;
            Serial.println("Saphire");
         
      }

    for(int i=0;i<=state;i++){
        digitalWrite(RED_LED,color[i][0]);
        digitalWrite(GREEN_LED,color[i][1]);
        digitalWrite(BLUE_LED,color[i][2]);
        delay(1000);
    }
}
