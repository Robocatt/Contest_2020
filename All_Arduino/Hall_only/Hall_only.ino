#define SENSOR_PIN A0
void setup()
{
 Serial.begin(19200);
}
void loop()
{
 delay(1000);
 long val = 0;
 for (int i=0; i<100; ++i) {
 val = val + analogRead(SENSOR_PIN);
 }
 val = val/100;
 Serial.println(val);
}
