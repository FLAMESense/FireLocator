void Triangulate (int ref1, int ref2)  {
  //still not accurate enough - WORK IN PROGRESS
  double sina=sin((alpha_check)*Pi/180);
  double sinb=sin((177-beta_check)*Pi/180);
  double sinab=sin((alpha_check+(177-beta_check))*Pi/180);
  double tana=tan(alpha_check*Pi/180);
  double tant=tan((90-alpha_check)*Pi/180);
  double tanb=tan((177-beta_check)*Pi/180);
  double d = DISTANCE;
  
 yCoordinate = (d * sina * sinb) / sinab;
 xCoordinate =  yCoordinate/tanb;               
 int xCoordinate1 = yCoordinate * tant; //not accurate

/* If 4 servos are being used instead of 2
 if (ref1==0 && ref2 == 3){
  Serial.println("ref ref");
  double temp = xCoordinate;
  xCoordinate = yCoordinate;
  yCoordinate = temp;
 }
 else if (ref1 == 1 && ref2 == 2)  {
  Serial.println("ref ref");
  double temp = xCoordinate;
  xCoordinate = (d - yCoordinate);
  yCoordinate = temp;
 }
 else if (ref1 == 2 && ref2 == 3)  {
  Serial.println("ref ref");
  xCoordinate = (d - xCoordinate);
  yCoordinate = (d - yCoordinate);
 }*/
 
 LocationFound = 1;
Serial.print("Location: ");
Serial.print(xCoordinate1);
 Serial.print(", ");
 Serial.println(yCoordinate);
 Serial.print(", ");
 //Serial.println(xCoordinate);
 delay(5000);
}
