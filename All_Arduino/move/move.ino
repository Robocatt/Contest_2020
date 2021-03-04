 #include<AccelStepper.h>
   #define IN1 8
   #define IN2 9
   #define IN3 10
   #define IN4 11
   #define PERIOD_1 400
   AccelStepper stepper(8, IN1, IN3, IN2, IN4);
   
   unsigned long time1;
   int G = 0;
   int n = 0;
   
void setup() {
Serial.begin(9600);
stepper.setMaxSpeed(600.0);
stepper.setAcceleration(600.0);
}

void loop() {
  
if (G == 0){
  stepper.move(4076);
  G++;
}
if (millis()- time1 > PERIOD_1){    
    time1 = millis();
    if(stepper.distanceToGo()!=0){
      Serial.println(stepper.currentPosition()*360/4076);
    }
}
if (stepper.distanceToGo()==0 and n !=1){
  n++;
  Serial.println(stepper.currentPosition()*360/4076);

  
}


stepper.run();
}
