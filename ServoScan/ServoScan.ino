#include <Servo.h>

Servo servoLeft;// create servo object to control servo on the left
Servo servoRight;// create servo object to control servo on the right 
//Servo servo2;
//Servo servo3;
//3, 9 servo
//7, 8 sensors

const int servoLeftPin = 3;
const int servoRightPin = 9;
const float Pi = 3.14159;
int i = 1;
int zeroAngle_R = 0;
int zeroAngle_L = 10;

int alphaL = 0; // variable to store the servo posistion 
int alphaR = 0; // variable to store the servo position 

void setup() {
  // put your setup code here, to run once:
servoLeft.attach(servoLeftPin,550, 2400); 
servoRight.attach(servoRightPin,400, 2150);

Serial.begin(9600);
delay(10);
}

void loop() 
{
  if (i%2 == 0){
  servoLeft.write(90-zeroAngle_L);
  Serial.println("Left 90");
  servoRight.write(zeroAngle_R);
  Serial.println("Right 45");
  }
  else {
    servoLeft.write(zeroAngle_L);
    Serial.println("Left 45");
    servoRight.write(90-zeroAngle_R);
    Serial.println("Right 90");
  }
  i++;
  delay(2500);
  
  /*
 for (alphaL = 90; alphaL >=0; alphaL -= 1); // goes from 90 to zero 
 {
   int fireL = digitalRead(0);
   servoLeft.write(alphaL);
   if (fireL ==0 )
   {
     alphaL = servoLeft.read();
     Serial.print("Fire detected on Left servo ");
     return;
   }
//     else;
//     Serial.print("Searching for fire...");
   }
   delay(15);
 
 for (alphaR = 0; alphaR <=0; alphaR += 1)// goes from 90 to zero 
 {
   int fireR = digitalRead(1);
   servoLeft.write(alphaR);
   if (fireR ==0)
   {
      alphaR = servoRight.read();
     Serial.print("Fire detected on Right servo ");
     break;
   }
     else;
     Serial.print("Searching for fire...");
   }
   delay(15);
 
 int d = 49;
 
 // convert to radians for computation
int alphaf = ((180-(alphaR+alphaL)) * Pi)/180; 
//int alphaR2; 
//int alphaL2 = 0;  
 int alphaR2 = ((alphaL*Pi)/180);
 int alphaL2 = (alphaR*Pi)/180;
 
 int side1 = d * (sin(alphaR)/sin(alphaf));
 int side2 = d * (sin(alphaL)/sin(alphaf));
 
 //xy coordinates
 int x = side1 * sin((Pi/2) - alphaL);
 int y = side1 * sin(alphaL);
 Serial.println(x,DEC);
 Serial.println(y,DEC);
 */
}



