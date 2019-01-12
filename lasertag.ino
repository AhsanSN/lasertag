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
  pinMode(11, OUTPUT); //gun deactive (motor)

  pinMode(8, OUTPUT); //gun POWER (motor)

  //level lights
  pinMode(12, OUTPUT); //gun active  lvl 3
  pinMode(10, OUTPUT); //gun deactive ) lvl 2
  pinMode(9, OUTPUT); //gun deactive  lvl 1
  analogWrite(11, 255);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //gun activity light
  if(isGunActive == true)
  {  
    digitalWrite(13, HIGH); //turn green light on
    digitalWrite(14, LOW); //turn red light off
    
  }

  if(isGunActive)
  {
    //detct enemy fire
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    if (sensorValue > 50) //threshold
    {
        isGunActive = false;
        digitalWrite(14, HIGH); //turn red light on
        digitalWrite(13, LOW); //turn green light off
        Serial.print("\' Fire detected. Level:  \'");
        Serial.print(hitCount);
        //digitalWrite(11, HIGH); //turn motor on
        analogWrite(11, 0);
        hitCount = hitCount + 1;
        delay(4000); //5 seconds delay
        //digitalWrite(11, LOW); //turn motor off
        analogWrite(11, 255);
        digitalWrite(13, HIGH); //turn green light on
        delay(3000); //5 seconds delay
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
  if(hitCount>=9){
    digitalWrite(12, HIGH); //level 3 light
  }
  if(hitCount>=10){
     digitalWrite(9, HIGH); //level 3 light
    digitalWrite(10, HIGH); //level 3 light
    digitalWrite(12, HIGH); //level 3 light
    delay(400); //5 seconds delay
    digitalWrite(9, LOW); //level 3 light
    digitalWrite(10, LOW); //level 3 light
    digitalWrite(12, LOW); //level 3 light
    delay(400);                       // wait for a second
    isGunActive = false;
    Serial.print("\' Person dead  \'"); 
    digitalWrite(13, LOW); //turn green light off  
  }

  
}

