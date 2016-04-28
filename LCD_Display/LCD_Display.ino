//
//  Launchpad LCD
//
//

// Include application, user and local libraries
 #include "LCD_Launchpad.h"
#include "Wire.h"

// Variables
LCD_LAUNCHPAD myLCD;


// Add setup code
void setup() {
    Wire.begin(8);                // join i2c bus with address #8
    Wire.onReceive(receiveEvent); // register event
    Serial.begin(9600);           // start serial for output
    Serial.println("SetUp");
    myLCD.init();
   
    myLCD.showSymbol(LCD_SEG_RADIO, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_TX, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_RX, 1);
    delay(400);
    myLCD.showSymbol(LCD_SEG_CLOCK, 1);
    delay(400);
    myLCD.displayScrollText("FLAMESense", 250);
    myLCD.displayText("NoFire");
    delay(200);
}

// Add loop code
void loop() {
 // Serial.println("loop");
  delay(100);
  //Serial.println("nope");
  //receiveEvent(1);
  LCD_Display_Location(15, 25, 1000);
}

void LCD_Display_Location(int x, int y, int wait) {
    myLCD.clear();
    myLCD.showSymbol(LCD_SEG_MARK, 1);
    myLCD.displayText("Fire");
    delay(wait);
    myLCD.clear();
    myLCD.showSymbol(LCD_SEG_MARK, 1);
    myLCD.showChar('X', 4);
   myLCD.displayText(String(x));
    delay(wait);
    myLCD.clear();
    myLCD.showSymbol(LCD_SEG_MARK, 1);
    myLCD.showChar('Y', 4);
    myLCD.displayText(String(y));
   delay(wait);
    myLCD.clear();
    
}


void receiveEvent(int howMany) {
    Serial.print("Recerved");
  // loop through all but the last
  while(1 < Wire.available()) 
  {
    char c = Wire.read(); // read byte as a character
    Serial.print(c);      // print the character
  }
  int x = Wire.read(); // receive byte as an integer
  Serial.println(x);   // print the integer
}
