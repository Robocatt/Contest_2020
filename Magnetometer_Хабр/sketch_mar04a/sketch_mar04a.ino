// Sketch for Arduino magnetometer
// Measures strength of magnetic field with SS49E hall sensor on A0
// Displays values on I2C SSD1306 128x64 0.96" monochrome OLED display
// Connect SCK to pin A5 and SDA to pin A4
// Connect null-button between GND and A1 for setting output to zero 

#include <SPI.h>
#include <Wire.h>




#define HALL_PIN A0
#define NULL_PIN A1

#define nmeas 2000      // stay below 2048 to avoid overflow  
#define cal 0.349*0.58 // calibration constant in mT per ADC count. nominal (5.0/1024)/0.014=0.349:               

float offset=511.0; // nominal 511: halfway 0 and 1024

void setup() {
  Serial.begin(9600);
  pinMode(HALL_PIN,INPUT); //pullup increases current and reduces noise
  pinMode(NULL_PIN,INPUT_PULLUP); //avoids need for external pullup resistor
}

void loop() {

  //perform the measurement. AnalogRead() takes ~100mus.
  long unsigned int sum=0;
  long unsigned int sumsq=0;
  for (int imeas=0; imeas<nmeas; imeas++){
    long int val= analogRead(A0);
    sum=sum+val;
    sumsq=sumsq+val*val;
  }

  //recalculate offset if null-button is pressed
  if(digitalRead(NULL_PIN)==0)offset=float(sum)/nmeas;
  
  //calculate DC and AC field strength. AC corresponds to RMS of the fluctuations
  float B_DC=(float(sum)/nmeas-offset)*cal;
  float B_ACsq=(float(sumsq)/nmeas-pow(float(sum)/nmeas,2))*pow(cal,2);
  float B_AC=0.0;
  if (B_ACsq>pow(0.005,2)) B_AC=pow(B_ACsq,0.5);
  pow((float(sumsq)/nmeas-pow(float(sum)/nmeas,2)),0.5)*cal;
  
  char txt[10]; //text buffer needed to print formatted float  

  Serial.println(B_DC);

}
