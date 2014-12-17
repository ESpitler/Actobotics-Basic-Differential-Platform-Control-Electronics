/*
This sketch receives commands from a serial source such as an 
Arduino using the Transmitter_Serial_4A_2D sketch and defines
their behavior on a RedBot Main Board.
*/



//inclusions
#include <RedBot.h> //invoke the RedBot Library

//objects
RedBotMotor motor; //instantiate the motor object

//constants

//variables
char q = 0; //serial receipt variable will receive an ASCII character in binary

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    q=Serial.read();
    switch(q)
    {
      case 65://A - Full Forward
        motor.drive(255);
        delay(10);
        break;
      case 66://B - Full Astern
        motor.drive(-255);
        delay(10);
        break;
      case 67://C - Slow forward
        motor.drive(127);
        delay(10);
        break;
      case 68://D - Slow Astern
        motor.drive(-127);
        delay(10);
        break;
      case 69://E - Spin Left
        motor.pivot(-255);
        delay(10);
        break;
      case 70://F - Spin Right
        motor.pivot(255);
        delay(10);
        break;
      case 71://G - Veer Left
        motor.rightDrive(127);
        motor.leftDrive(255);
        delay(10);
        break;
      case 72://H - Veer Left Astern
        motor.rightDrive(-127);
        motor.leftDrive(-255);
        delay(10);
        break;
      case 73://I - Veer Right
        motor.rightDrive(255);
        motor.leftDrive(127);
        delay(10);
        break;
      case 74://J - Veer Right Astern
        motor.rightDrive(-255);
        motor.leftDrive(-127);
        delay(10);
        break;
      case 75://K - Unused
       break;
      case 76://L - Unused
        break;
      case 77://M - Unused
        break;
      case 78://N - Unused
        break;
      case 88://X - Full Stop
        motor.brake();
        delay(10);
        break;
      case 97://a - Unused
        break;
      case 98://b - Unused
        break;
    }
  }
}
