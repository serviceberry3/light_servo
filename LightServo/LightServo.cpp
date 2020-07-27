//#include <Servo.h>
#include <Arduino.h>

const int led=3; // variable which stores pin number
Servo myservo;
void setup()
{
  myservo.attach(4);
  Serial.begin(9600);
  pinMode(led, OUTPUT);  //configures pin 3 as OUTPUT
}

void loop()
{
   int sensor_value = analogRead(A1);

   Serial.println(sensor_value);
  if (sensor_value > 600)// the point at which the state of LEDs change
    {
      myservo.write(90);
      delay(200);
      myservo.write(106);
      delay(200);
    }
}
