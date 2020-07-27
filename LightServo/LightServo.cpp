//CODE FOR ARDUINO UNO

#include <Arduino.h>

//set the servo motor interaction pin to pin 4
#define SERVO_PIN 4

//define the threshold value for the photoresistor
#define MIN_LIGHT 600

void setup()
{
	//set the servo motor interaction pin to OUTPUT so we can send pulses to servo
	pinMode(SERVO_PIN, OUTPUT);
}

//servos are controlled by sending them a 20ms pulse
int periodMicroSec = 20 * 1000;

//1.0 ms HIGH at the start of pulse will turn the servo to the 0 degree position
int pulseMicroSec = 1.8 * 1000;

void loop()
{
	//read in the value from pin A1 (value of resistance from photoresistor)
	int sensor_value = analogRead(A1);

	//check the
	if (sensor_value > MIN_LIGHT)// the point at which the state of LEDs change
    {
		//if there's enough light coming in, shake the servo arm back and forth
		myservo.write(90);
		delay(200);
		myservo.write(106);
		delay(200);
    }
	//ELSE don't move the servo arm
}
