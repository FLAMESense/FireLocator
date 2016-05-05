
void DockSetup() {
  //Initialize servo motors and set to 90 degrees
  servo5.attach(DockPin); 
  servo5.write(SetupAngle);
  delay(1000);
}

void RotateDock()  {
  int DockAngle = servo5.read();
  if(DockAngle < beta_check){
  while(DockAngle < beta_check)  {
    DockAngle++;
    servo5.write(DockAngle);
    delay(50);
  }
  delay(2000);
  }
  else {
    while(DockAngle > beta_check)  {
    DockAngle--;
    servo5.write(DockAngle);
    delay(50);
    Serial.println(">180");
  }
  delay(2000);
  }
}


