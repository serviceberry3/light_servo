//CODE FOR ARDUINO UNO

#include <Arduino.h>

//define the threshold value for the photoresistor
#define MIN_LIGHT 600

void setup()
{
	//set the servo motor interaction pin (we'll use pin 4) to OUTPUT so we can send pulses to servo
	//DDRD is the Port D Data Direction Register (pins 0-7), a register that tells the chip whether these pins
	//are configured as input (1) or output (0). DDR4 evaluates to the constant int 4.
	DDRD |= (1<<DDR4);
}

//servos are controlled by sending them a 20ms pulse
int periodMicroSec = 20 * 1000;

//0.7 ms HIGH at the start of pulse will turn the servo to the 0 degree position
//keep the signal HIGH for 0.7 ms, which is equivalent to setting servo to 0 degrees (2.45 ms is equivalent to setting ot 180 degrees)
int pulseHighMicroSec = 0.7 * 1000;

//keep the signal low for rest of the servo period
int pulseLowMicroSec;

//on each loop let's up the HIGH duration by 0.01 ms, which is approximately equivalent to moving servo arm by 1 degree on each loop (2450-700)/180
int angleIncrement = 0.01 * 1000;

void loop()
{
	//read in the value from pin A1 (value of resistance from photoresistor)
	int sensor_value = analogRead(A1);

	//check to see if the resistance value from photoresistor is above threshold
	if (sensor_value > MIN_LIGHT)
    {
		//if there's enough light coming in, shake the servo arm back and forth

		//increase the amt of time the servo signal is kept high by 0.01 ms each time
		pulseHighMicroSec += angleIncrement;

		//set voltage HIGH to start the servo period and pulse
		digitalWrite(SERVO_PIN, HIGH);

		//delay for length of pulse (1.8 ms)
		delayMicroseconds(pulseHighMicroSec);

		//set voltage LOW for remainder of servo pulse
		digitalWrite(SERVO_PIN, LOW);

		//delay for remainder of servo period so that next signal starts on time
		delayMicroseconds(periodMicroSec - pulseHighMicroSec);

		//this controls speed at which arm moves
		delay(0.5);

		//if we've reached 180 degrees, start coming back; if reached 0, also reverse
		if (pulseHighMicroSec >= 2450 || pulseHighMicroSec <=700) {
			angleIncrement = -angleIncrement;
		}
    }
	//ELSE don't move the servo arm
}
