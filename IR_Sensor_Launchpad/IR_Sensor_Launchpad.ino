/*
 The circuit:
 * Potentiometer attached to analog input 0?
 * center pin of the potentiometer to the analog pin?
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.
 */

int samples = 0;
int sum = 0;
int ambient = 0;

int sensorPin = A3;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
//int sensorMin = 1023;        // minimum sensor value
//int sensorMax = 0;           // maximum sensor value
int sensorValue = 0;  // variable to store the value coming from the sensor
int IRDelta = 0;
int IRValue = 0;  // variable to store the value coming from the sensor
int buttonPin = 2;
int restart;
int resetCount = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  // open the serial port at 9600 bps:
  restart = 0;
  buttonPin = 2;
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  //code that runs all the time
  if (samples == 0) {
    while (samples < 30) {
      sensorValue = analogRead(sensorPin);
      Serial.print("Sensor Value: ");
      Serial.println(sensorValue);
      sum = sum + sensorValue;
      samples++;
      delay(100);
    }
    ambient = sum / samples;
  }
  if (samples == 30) {
    Serial.print("Sum: ");  //display ambient IR levels
    Serial.print(sum);
    Serial.print("\t");
    Serial.print("Samples: ");  //display ambient IR levels
    Serial.print(samples);
    Serial.print("\t");
    Serial.print("Ambient: ");  //display ambient IR levels
    Serial.println(ambient);
    Serial.println(" ");
    samples++;
    sum = 0;
  }

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  IRDelta = sensorValue - ambient;

  Serial.print("\t");
  Serial.print("Ambient Value: ");
  Serial.print(ambient);
  Serial.print("\t");
  IRValue = IRDelta;
  Serial.print("IR Value: ");
  Serial.println(IRValue);
  delay(1000);
  
  //check if button is pressed
  if(digitalRead(buttonPin) == LOW) {
    Serial.println("PRESSED");
    resetCount++;
  }
  else {
     if(resetCount > 0) {
     resetCount--;
     }
  }
  if(resetCount > 5)
    {
    samples = 0;
    resetCount = 0;
    Serial.println("RESET");
    }
  Serial.print("Reset Count; ");
  Serial.println(resetCount);
}
