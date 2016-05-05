
void ServoSetup() {
  //Initialize servo motors and set to 90 degrees
  servo0.attach(servoPins[0],550, 2400); 
  servo1.attach(servoPins[1],400, 2150);
  servo0.write(90);
  servo1.write(90);
  LocationFound = 0;
  //Serial.println("Servo Motors Initicialized at 90 degrees");
  delay(5000);
}

void ServoTest() {
  //initialize test
  Serial.println("Testing servo motors...");
  int j = 0;
  for (j; j<5; j++){
    int i = 0;
    while (i <= 180) {
      //Serial.print("Angle: ");
      //Serial.println(i);
      servo0.write(i);
      servo1.write(i);
      i = i + 45;
      delay(1000);
    }
  }
}

void ServoScan() {
  //Serial.println("Scanning now...");
  if(!LocationFound)  {
    int w = 0;
    int a = (90-w);
    int b = (90+w);
    while (w <= 90){
      a = (90 - w);
      b = (90 + w);
      //Serial.print("w = ");
      //Serial.println(w);
  
      for (int f = 0; f < 2; f++){
        servoFlames[f] = digitalRead(sensorPins[f]);
      }
      if(servoFlames[0] == LOW){
        alpha = a;
      }
      else{
        servo0.write(a);
      }
      
      if(servoFlames[1] == LOW) {
        beta = b;
      }
      else{
        servo1.write(b);
      }

    if (beta != 0 && alpha != 0) {
        //Serial.println("Fire detected by Servo0 and Servo1! ");
        delay(1000);
        alpha_check = servo0.read();
        beta_check = servo1.read();
//        Serial.print("Alpha: ");
//        Serial.print(alpha);
//        Serial.print(", ");
//        Serial.println(alpha_check);
//        Serial.print("Beta: ");
//        Serial.print(180-beta);
//        Serial.print(", ");
//        Serial.println(180-beta_check);
        Triangulate(0,1);
      }
    
    /*
    if(servoFlames[1] == 1 && &servoFlames[2] == 1) {
      Triangulate(1,2);
    } 
    if(servoFlames[2] == 1 && &servoFlames[3] == 1) {
      Triangulate(2,3);
    }
     if(servoFlames[3] == 1 && &servoFlames[1] == 1) {
      Triangulate(3,1);
    }
    */
    if(!LocationFound)    {
      w = w + 1;
    }
    else {
      w = 91;
    }
      delay(250);
  }
}
}
