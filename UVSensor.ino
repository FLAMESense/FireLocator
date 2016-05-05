void checkforFire(){
  //code to check for fire and set UV_Flame to 1 if fire is found
  
  if (digitalRead(UVSensor) == HIGH)  {
    UV_Flame = 1;
    Serial.println("UV Flame Detected");
  }
  else {
  UV_Flame = 0; 
  Serial.println("UV Flame NOT Detected");
  }
}
