bool isGunActive = true;
int sensorValue;
int timeGunStopped;
  
void setup() {
  // put your setup code here, to run once:
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(13, OUTPUT); //gun active (green light)
  pinMode(14, OUTPUT); //gun deactive (red light)
}

void loop() {
  // put your main code here, to run repeatedly:

  //gun activity light
  if(isGunActive == true)
  {
    digitalWrite(13, HIGH); //turn green light on
    digitalWrite(14, LOW); //turn red light off
  }
  if(isGunActive == false)
  {
     digitalWrite(14, HIGH); //turn red light off
     digitalWrite(13, LOW); //turn green light on
     delay(500); //5 seconds delay
     isGunActive = true; //open lock
  }
  //detct enemy fire
  if(isGunActive == true)
  {
      sensorValue = analogRead(A0);
      Serial.println(sensorValue);
      if (sensorValue > 12) //threshold
      {
          isGunActive = false;
      }
  }
  
}

