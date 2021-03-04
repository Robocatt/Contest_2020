
 #include<AccelStepper.h>
   #define IN1 8
   #define IN2 9
   #define IN3 10
   #define IN4 11
   #define PERIOD_1 400
 
   #define HALL_PIN A0
   #define nmeas 2000 
   #define cal 0.349

   AccelStepper stepper(8, IN1, IN3, IN2, IN4);
   
   unsigned long time1;
   int G = 0;
   int n = 0;

    float offset=511.0;
   

  
void setup() {
Serial.begin(9600);
stepper.setMaxSpeed(600.0);
stepper.setAcceleration(600.0);

pinMode(HALL_PIN,INPUT);


}

void loop() {

  

if (G == 0){
  stepper.move(4076);
  G++;
}

long unsigned int sum=0;
long unsigned int sumsq=0;
  for (int imeas=0; imeas<nmeas; imeas++){
    long int val= analogRead(A0);
    sum=sum+val;
    sumsq=sumsq+val*val; }
    //от положения этого куска зависит выполнение 
    // добится параллеливания
float B_DC=(float(sum)/nmeas-offset)*cal;
  float B_ACsq=(float(sumsq)/nmeas-pow(float(sum)/nmeas,2))*pow(cal,2);
  float B_AC=0.0;
  if (B_ACsq>pow(0.005,2)) B_AC=pow(B_ACsq,0.5);
  pow((float(sumsq)/nmeas-pow(float(sum)/nmeas,2)),0.5)*cal;
  
if (millis()- time1 > PERIOD_1){    
    time1 = millis();
    if(stepper.distanceToGo()!=0){
      Serial.println(stepper.currentPosition()*360/4076);  
    }
    if (stepper.distanceToGo()==0 and n !=1){
    n++;
    Serial.println(stepper.currentPosition()*360/4076); 
    }
//

  


}

stepper.run();

}
