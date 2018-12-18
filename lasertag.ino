bool isGunActive = true;
int sensorValue;
int timeGunStopped;
int hitCount = 0;


void setup() {
  // put your setup code here, to run once:
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(13, OUTPUT); //gun active (green light)
  pinMode(14, OUTPUT); //gun deactive (red light)
  pinMode(12, OUTPUT); //gun deactive (motor)

  pinMode(8, OUTPUT); //gun POWER LIGHT 

  //level lights
  pinMode(11, OUTPUT); //gun active (green light)
  pinMode(10, OUTPUT); //gun deactive (red light)
  pinMode(9, OUTPUT); //gun deactive (motor)
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH); //turn red light on
  //gun activity light
  if(isGunActive == true)
  {  
    digitalWrite(13, LOW); //turn red light on
    digitalWrite(14, LOW); //turn red light off
    
  }

  if(isGunActive)
  {
    //detct enemy fire
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    if (sensorValue > 400) //threshold
    {
        isGunActive = false;
        digitalWrite(14, HIGH); //turn . light off
        digitalWrite(13, HIGH); //turn RED light on
        Serial.print("\' Fire detected. Level:  \'");
        Serial.print(hitCount);
        digitalWrite(12, HIGH); //turn motor on
        hitCount = hitCount + 4;
        delay(1000); //5 seconds delay
        digitalWrite(12, LOW); //turn motor off
        delay(1000); //5 seconds delay
        sensorValue = 0;
        isGunActive = true; //open lock
        sensorValue = 0;
    }  
  }

  //set level lights
  if(hitCount>=3){
    digitalWrite(9, HIGH); //level 1 light
  }
  if(hitCount>=6){
    digitalWrite(10, HIGH); //level 2 light
  }
  if(hitCount>9){
    digitalWrite(11, HIGH); //level 3 light
  }
  if(hitCount>10){
    digitalWrite(9, HIGH); //level 3 light
    digitalWrite(10, HIGH); //level 3 light
    digitalWrite(11, HIGH); //level 3 light
    delay(500); //5 seconds delay
    digitalWrite(9, LOW); //level 3 light
    digitalWrite(10, LOW); //level 3 light
    digitalWrite(11, LOW); //level 3 light
    isGunActive = false;
    Serial.print("\' Person dead  \'");
  }
}

