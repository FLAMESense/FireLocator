/*
 * Main Fire Source Location Program
 * This code will drive the board that will collect data from the IR/UV sensors
 * This code will then use this data to calculate the location
 * This code will then send coordinates to RC control board and to the LCD board
 * This code will also send coordinates to website (if time permits)
 * 
 * Hardwired serial port is used for RC control output
 * Software "mySerial" port is used for 
 */
#include <SoftwareSerial.h>

//coordinates of fire
int xCoordinate = 0;  //get from David's Servo code
int yCoordinate = 0;  //get from David's Servo code

uint16_t coordinates = 0000; 
uint16_t mask = B11111111;
uint8_t x = 0;
uint8_t y = 0;
int [2] 

void setup()
{
  // put your setup code here, to run once:
  
  Serial.begin(9600); //begin serial
  //Serial.println("FLAMESense");
  //Serial.println("Northern Illinois University, Spring 2016");
  //delay(1000);
  //start

  mySerial.begin(9600);
}

void loop()
{
  //check for UV sensor
  if(UVSensor.Flame()) {        //need UVSensor class for UV sensor with boolean variable indicating if flame is detected
    //start servo motors
      ServoScan.Start();       //need ServoScan class with class method start() that will start scanning

      //Get angles from servo motor to initatiate location approximation
      ServoScan.Angles();     //need class method Angles() that will return array with angles of each servo motor
     
      //calculate location
      Triangulation(
        
      coordinates = xCoordinate * 100 + yCoordinates);
      
      //OR get coordinates from Servo driver
      xCoordinate = ServoScan.getX();
      yCoordinate = ServoScar.getY();
      coordinates = xCoordinate * 100 + yCoordinates);

     
      //Separate coordinates
      x = coordinates >> 8;
      y = coordinates & mask;

      //Write coordinates to RC board (regular serial port) and to LCD board (mySerial port)
      Serial.write(x);
      mySerial.write(x);
      Serial.write(y);
      mySerial.write(y);
  }
}

/*****************************************************************************************
 * Fuctions
 ****************************************************************************************/
void Triangulation (float d, float a, float b, int ref1, int ref2)  {
  double sina=sin(a);
  double sinb=sin(b);
  double sinab=sin(a+b);
  double tana=tan(a);
  
 yCoordinate = d * sina * sinb / sinab;
 xCoordinate = y / tana;

 if (ref1==0 && ref2 == 3){
  double temp = xCoordinate;
  xCoordinate = yCoordinate;
  yCoordinate = temp;
 }
 if (ref1 == 1 && ref2 == 2)  {
  double temp = xCoordinate;
  xCoordinate = d - yCoordinate;
  yCoordinate = temp;
 }
 if (ref1 == 2 && ref2 == 3)  {
  xCoordinate = d - xCoordinate;
  yCoordinate = d - yCoordinate;
 }
}


