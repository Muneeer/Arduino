
int pushButton = 8;
int buttonState=0;

// the setup routine runs once:

void setup() {

  // initialize serial communication at 9600 bits per second:

  Serial.begin(9600);

  // make the pushbutton’s pin an input:

  pinMode(pushButton, INPUT);

}

// the loop routine runs over and over again forever:

void loop() {

  // read the input pin:

  buttonState = digitalRead(pushButton);
  if(buttonState==0)
  {
     Serial.println("Button is pressed!!");
  }else
  {
    Serial.println("Button is released!!");
    }
  

  // print out the state of the button:

  Serial.println(buttonState);
  delay(1000);

 // delay(1); // delay in between reads for stability
}
