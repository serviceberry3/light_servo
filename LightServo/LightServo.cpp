#include <Arduino.h>

#define SERVO_PIN 4

void setup()
{
	pinMode(SERVO_PIN, OUTPUT);
}

void loop()
{
   int sensor_value = analogRead(A1);

   if (sensor_value > 600)// the point at which the state of LEDs change
    {
      myservo.write(90);
      delay(200);
      myservo.write(106);
      delay(200);
    }
}
