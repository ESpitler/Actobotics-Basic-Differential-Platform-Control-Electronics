/*
This sketch translates analog stick inputs into single-character 
serial signal commands.

The circuit uses two X-Y thumb joysticks, each with a pushbutton.
It uses the left joystick for drive speed and direction and the 
right stick for auxiliary controls.

*/

//pin assignments
int const LBUT = 4; //left button digital pin on digital 4
int const RBUT = 5; //right button digital pin on digital 5
int const LY = 0; //Y-axis of left stick on analog 0
int const LX = 1; //X-axis of left stick on analog 1
int const RY = 2; //Y-axis of right stick on analog 2
int const RX = 3; //X-axis of right stick on analog 3

//variables - all initialized at 0
int LxState = 0; //stores the analog state of the joysticks
int LyState = 0;
int RxState = 0;
int RyState = 0;
int leftState = 0; //stores the digital state of the buttons
int rightState = 0;

void setup()
{
  Serial.begin(9600); //initialize serial
  Serial.println("X"); //transmit all stop command to prevent unwanted movement
  pinMode(LBUT, INPUT); //set the buttons to input
  pinMode(RBUT, INPUT);
// this circuit uses external pullup resistors, so the internal 
// resistors do not need to be set.
}
void loop()
{
//read the left joystick  
  LxState = analogRead(LX);
  LyState = analogRead(LY);

//spin l/r
  if(LxState == 1023)
  {
    Serial.println("E");//spin left
    delay(1);
  }  
  if(LxState == 0)
  {
    Serial.println("F");//spin right
    delay(1);
  }
  
//forward veer l/r/slow fwd
  if(LxState > 535 && LxState < 1023 && LyState < 490)
  {
    Serial.println("G");//veer left
    delay(1);
  }
  else if(LxState < 515 && LxState > 0 && LyState < 490)
  {
    Serial.println("I");//veer right
    delay(1);
  }
  else if(LyState < 490 && LyState > 0)
  {
    Serial.println("C");//slow fwd
    delay(1);
  }
  
//astern veer l/r/slow astern  
  if(LxState > 535 && LxState < 1023 && LyState > 510)
  {
    Serial.println("H");//veer left astern
    delay(1);
  }
  else if(LxState < 515 && LxState > 0 && LyState > 510)
  {
    Serial.println("J");//veer right astern
    delay(1);
  }
  else if(LyState < 1023 && LyState > 510)
  {
    Serial.println("D");//slow astern
    delay(1);
  }
  
//full speed ahead/astern
  if(LyState == 0)
  {
    Serial.println("A");//full tilt boogie fwd
    delay(1);
  }
  if(LyState == 1023)
  {
    Serial.println("B");//back the truck up!
    delay(1);
  }

//read the right joystick
  RxState = analogRead(RX);
  RyState = analogRead(RY);
  
//right stick fwd
  if(RyState > 543)
  {
    Serial.println("K"); //flipper fwd
    delay(1);
  }
  
//right stick aft
  if(RyState < 523)
  {
    Serial.println("L"); //flipper aft
    delay(1);
  }
  
//right stick right
  if(RxState > 529)
  {
    Serial.println("N");//nc
    delay(1);
  }
  
//right stick left
  if(RxState < 509)
  {
    Serial.println("M");//nc
    delay(1);
  }

//read the buttons
  leftState = digitalRead(LBUT);
  rightState = digitalRead(RBUT);
  
//left button  
  if(!leftState)
  {
    Serial.println("a");//nc
    delay(1);
  }
  
//right button
  if(!rightState)
  {
    Serial.println("b");//nc
    delay(1);
  }
  
//full stop
  if(LyState == 500 && 
     LxState == 525 && 
     RyState == 533 &&
     RxState == 519)
  {
    Serial.println("X");//full stop
    delay(1);
  }
}
