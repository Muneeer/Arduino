#define DIGIT                11
#define FREQUENCY            1000
#define FND_DIGIT_TOTAL_PIN    8
#define FND_DIGIT_START        2
#define FND_DIGIT_END        9
#define FND_COM_TOTAL_PIN    2
#define FND_COM_START        10
#define FND_COM_END            11
void setup()
{
  int numPin = 0;
  for (numPin = FND_DIGIT_START; numPin <= FND_DIGIT_END; numPin++)
    pinMode(numPin, OUTPUT);
  for (numPin = FND_COM_START; numPin <= FND_COM_END; numPin++)
    pinMode(numPin, OUTPUT);  
}
void loop()
{
  int numDigit = 0;
  int numLED   = 0;
  int numCOM   = 0;
  
  int digit[DIGIT][FND_DIGIT_TOTAL_PIN]={
    {1,1,1,1,1,1,0,0}, {0,1,1,0,0,0,0,0}, {1,1,0,1,1,0,1,0}, //0,1,2
    {1,1,1,1,0,0,1,0}, {0,1,1,0,0,1,1,0}, {1,0,1,1,0,1,1,0}, //3,4,5
    {1,0,1,1,1,1,1,0}, {1,1,1,0,0,0,0,0}, {1,1,1,1,1,1,1,0}, //6,7,8
    {1,1,1,0,0,1,1,0}, {1,1,1,0,1,1,1,0}                       //9,A
  };
  int com[DIGIT][FND_COM_TOTAL_PIN]={
    {1,1}, {1,1}, {1,1}, //0,1,2 control
    {1,1}, {1,1}, {1,1}, //3,4,5 control
    {1,1}, {1,1}, {1,1}, //6,7,8 control
    {1,1}                   //9 control
  };
    
  for(numDigit=0;numDigit<DIGIT;numDigit++){
    for(numLED=0;numLED<=FND_DIGIT_TOTAL_PIN+1;numLED++){
      digitalWrite(FND_DIGIT_START+numLED, digit[numDigit][numLED]);
    }
    for(numCOM=0;numCOM<=FND_COM_TOTAL_PIN;numCOM++){
      digitalWrite(FND_COM_START+numCOM, com[numDigit][numCOM]);
    }    
    delay(FREQUENCY);
  }
}
