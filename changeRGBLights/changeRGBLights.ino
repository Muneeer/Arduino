#include <time.h>
#include <stdlib.h>
#define RED_LED 13
#define GREEN_LED 12
#define BLUE_LED 11
int color[12][3]={{254,26,27},{179,117,180},{211,246,251},
{256,255,255},{14,219,133},{246,241,237},
{206v3v163},{}
}


void setup()
{
  Serial.begin(9650);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  int i,j;

for(i=0;i<12;i++){
  for(j=0;j<3;j++){
    color[i][j]=rand()%255+1;
  }
}
}

void loop()
{
  int k;
  for(k=0;k<12;k++)
  {
    Serial.print("{");
    Serial.print(color[k][0]);
    Serial.print(" ");
    Serial.print(color[k][1]);
    Serial.print(" ");
    Serial.print(color[k][2]);
    Serial.print("}");
    Serial.println();
    //delay(1000);
    digitalWrite(RED_LED, color[k][0]);
    digitalWrite(GREEN_LED, color[k][1]);
    digitalWrite(BLUE_LED, color[k][2]);
    delay(1000);
  }
  
}
