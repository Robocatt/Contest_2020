   #include<AccelStepper.h>
   #define IN1 8
   #define IN2 9
   #define IN3 10
   #define IN4 11
   #define HALL_PIN A0
   #define nmeas 125     
   #define cal 0.349 // calibration constant in mT per ADC count. nominal (5.0/1024)/0.014=0.349:               
   #define PERIOD_1 50
   AccelStepper stepper(8, IN1, IN3, IN2, IN4);
  float offset=511.0; // nominal 511: halfway 0 and 1024
  char buffer[15];
  int G = 0;
  unsigned long time1;
  float B_DC=0;


void setup() {
  Serial.begin(19200);
  
  pinMode(HALL_PIN,INPUT); //pullup increases current and reduces noise
  stepper.setMaxSpeed(600.0);
  stepper.setAcceleration(600.0);
}

void loop() {
  if (G == 0)
  {
    stepper.move(4076);
    G++;
  }
  
stepper.run();
if (millis()- time1 > PERIOD_1)
 {    
 time1 = millis();
 if (stepper.distanceToGo() != 0 )
  {
  long unsigned int sum=0;
   for (int imeas=0; imeas<nmeas; imeas++)
   {
    long int val= analogRead(A0);
    sum=sum+val;
   }
  B_DC=(float(sum)/nmeas-offset)*cal;
  Serial.print("#S|HALL|[");
  Serial.print(B_DC);
  Serial.println("]#");
  Serial.print("#S|STEPPERF|[");
  Serial.print(stepper.currentPosition()*360/4076);
  Serial.println("]#");
  }
 }
}
