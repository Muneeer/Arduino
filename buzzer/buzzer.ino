#include "pitches.h"
#define BUZZER  4
const int SW=8;
#define E_NT    250     // 팔분음표 길이
#define Q_NT    500     // 사분음표 길이
#define QH_NT   750     // 사분음표 길이 + .
#define H_NT    1000    // 이분음표 길이
#define HH_NT   1250    // 이분음표 길이 + .
// 음계
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
int song1[]={ NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0,           
             NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0,            
             NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, 0,            
             NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_C5, 0};  
int song1_time[] = { E_NT, E_NT, E_NT, E_NT, QH_NT, E_NT, 
               E_NT, E_NT, E_NT, E_NT, QH_NT, E_NT,
               E_NT, E_NT, E_NT, E_NT, QH_NT, E_NT,
               E_NT, E_NT, E_NT, E_NT, Q_NT, E_NT, E_NT};
int buttonState;

#define D8  200   
#define D4  400   
#define D2  800  
struct _note
{ 
  int note;    
  int duration;  
};

struct _note Note[] = {
  {NOTE_G3, D8}, 
  {NOTE_G3, D8},  
  {NOTE_A4, D8},  
  {NOTE_A4, D8}, 
  {NOTE_G3, D8},
  {NOTE_G3, D8},  
  {NOTE_E3, D4}, 

  {NOTE_G3, D8},  
  {NOTE_G3, D8},  
  {NOTE_E3, D8},  
  {NOTE_E3, D8},  
  {NOTE_D3, D2},  

  {NOTE_G3, D8},  
  {NOTE_G3, D8}, 
  {NOTE_A4, D8},  
  {NOTE_A4, D8},  
  {NOTE_G3, D8},  
  {NOTE_G3, D8},  
  {NOTE_E3, D4}, 

  {NOTE_G3, D8}, 
  {NOTE_E3, D8},  
  {NOTE_D3, D8}, 
  {NOTE_E3, D8},  
  {NOTE_C3, D2},  
};



void setup() {

  pinMode(SW,INPUT);
  Serial.begin(9600);

}

void loop() {

  //while(digitalRead(SW));
  buttonState=digitalRead(SW);
  delay(50);
  if(buttonState==HIGH)
  {
      int size = sizeof(Note) / sizeof(struct _note);
  for(int i =0 ; i<size ; i++)
  {
    tone(BUZZER, Note[i]. note);
    delay(Note[i].duration);
    noTone(BUZZER);
    delay(50);           
  }
  noTone(BUZZER);
  delay(2000);
  }
  else
  {
      int i;
  delay(3000);                           // 3초 후에 연주 시작
  for (i=0; i<(sizeof(song1)/sizeof(song1[0])); i++){
    tone(BUZZER, song1[i], song1_time[i]);// 배열순으로 노래 재생
    delay(song1_time[i]);                // 음의 연주시간 만큼 지연
  }
  // put your main code here, to run repeatedly:

 
}}
