 #include<AccelStepper.h>
   #define IN1 8
   #define IN2 9
   #define IN3 10
   #define IN4 11
   AccelStepper stepper(8, IN1, IN3, IN2, IN4);
#define SENSOR_PIN A0
#define PERIOD_1 400
int i = 0;
int j = 0;
int G = 0;
int n = 0;
char buffer[5];
unsigned long time1;

void setup(){
Serial.begin(9600);
stepper.setMaxSpeed(600.0);
stepper.setAcceleration(600.0);
}
   void loop(){
if (G == 0){
stepper.move(4076);
G++;
}
    if (millis()- time1 > PERIOD_1){    
    time1 = millis();
if(stepper.distanceToGo()!=0){
  float val = analogRead(SENSOR_PIN);
Serial.print("#S|HALL|[");
Serial.print((((1.4*abs(val-512))/512)/1.4));
Serial.println("]#");
Serial.print("#S|STEPPERF|[");
Serial.print(itoa((stepper.currentPosition()*360/4076), buffer, 10));
Serial.println("]#");

}
    }
if (stepper.distanceToGo()==0 and n !=1){
  float val = analogRead(SENSOR_PIN);
 Serial.print("#S|HALL|[");
Serial.print((((1.4*abs(val-512))/512)/1.4));
Serial.println("]#");
  n++;
  }
if (stepper.distanceToGo()==0 and G == 1 and j == 0) {
   Serial.print("#S|STEPPERF|[");
Serial.print(itoa((stepper.currentPosition()*360/4076), buffer, 10));
Serial.println("]#");
   j++;
  }
stepper.run();


   }
