/*
 * Main Fire Source Location Program
 * This code will 
 * drive the board that will collect data from the IR/UV sensors
 * This code will then use this data to calculate the location
 * This code will then send coordinates to RC control board and to the LCD board
 * This code will also send coordinates to website (if time permits)
 * 
 * Hardwired serial port is used for RC control output
 * Software "mySerial" port is used for 
 */

#include <SoftwareSerial.h>
#include <Servo.h>
#include <SPI.h>
#include "Wire.h"


//Global variables
const float Pi = 3.14159;
const int DISTANCE = 33;
const int slaveSelectPin = 10;

//PIN Declarations
int servoPins[4]= {9, 3, 0, 0};
int sensorPins[4] = {8, 7, 0, 0};
int alarmPin = 13;
int UVSensor = 12;
int DockPin = 5;

int initial_angles[4] = {0, 0, 0, 0};  //initial angles of servos
int xCoordinate = 0;  //get from David's Servo code
int yCoordinate = 0;  //get from David's Servo code
int SetupAngle = 90;

//Boolean variables for logic and debugging
int ServoMoved[4] = {0, 0, 0, 0};     //holds boolean indicating movement each servo 
bool UV_Flame = 0;                      //if UV Sensor detects a flame, this value goes high
int servoFlames[4] = {0, 0, 0, 0};
bool LocationFound = 0;                 //If fire location has been calculated, this goes high
bool calculate = 0;                     //?

//Variables for serial communication of coordinates
uint16_t coordinates = 0000; 
uint16_t mask = B11111111;
uint8_t x = 0;
uint8_t y = 0;

//Declare servo objects
Servo servo0;   // create servo object to control servo on the left
Servo servo1;   // create servo object to control servo on the right 
Servo servo2;
Servo servo3;
Servo servo5;

uint8_t ServoX = 0;
uint8_t ServoY = 0;

int alpha = 0;          //variable to store the servo posistion 
int alpha_check = 0;    //used to check angle accuracy
int beta = 0;         //variable to store the servo position 
int beta_check = 0;   //variable to check angle accuracy
int Timeout_Count = 0;
int Timeout_Delay = 10000;

void setup()
{
  // put your setup code here, to run once:
  
  pinMode(alarmPin, OUTPUT);
  pinMode(UVSensor, INPUT);
  Serial.begin(9600); //begin serial
  //Print Information About Project
  Serial.println("FLAMESense");
  Serial.println("Northern Illinois University, Spring 2016");
  ServoSetup();
  DockSetup();
  //mySerial.begin(9600);   //software Serial port initializer (not needed yet)
  // set the slaveSelectPin as an output:
  //pinMode(slaveSelectPin, OUTPUT);
  // initialize SPI:
  //SPI.begin();
  //Wire.begin();
}

void loop()
  {
  beta_check = 180;
  RotateDock();
  //checkforFire();
  delay(2000);
    //check UV sensor for flame
 
  

  if(UV_Flame) {        //need UVSensor class for UV sensor with boolean variable indicating if flame is detected
    //start servo motors
        ServoScan();
        Timeout_Count = 0;
        } 
  else  {
    Timeout_Count++; 
    if (Timeout_Count >= 500000){
     // Serial.println("Timeout delay");
      delay(Timeout_Delay);
      }
    }
 // delay(1000);
//  Serial.println("Servo Reads: ");
//  Serial.println(servo0.read());
//  Serial.println(servo1.read());
//  Serial.println(" ");
  //delay(1000);
  if(LocationFound){
      digitalWrite(alarmPin, HIGH);   // sets the LED on
 
      coordinates = (xCoordinate * 100 + yCoordinate);
      Serial.print("Cordinates to be sent: ");
      Serial.println(coordinates);
      
      //Separate coordinates
      x = coordinates >> 8;
      y = coordinates & mask;
//      delay(1000);                  // waits for a second
//      digitalWrite(alarmPin, LOW);    // sets the LED off
//      delay(5000);
      //Write coordinates to RC board (regular serial port) and to LCD board (mySerial port)
     // Serial.write(x);
     // mySerial.write(x);
      //Serial.write(y);
     // mySerial.write(y);
  
     Serial.println("Sending Location..");
     SendLocation(8, 15);
  }
  Serial.println("Iteration");
}


