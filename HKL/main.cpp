#include"arm.h"


int main(void)
{
	if(wiringPiSetup() == -1)
		return 1;

	pinMode(LED1,OUTPUT);
	pinMode(LED2,OUTPUT);
	pinMode(LED3,OUTPUT);
	pinMode(LED4,OUTPUT);
	pinMode(LED5,OUTPUT);
	pinMode(LED6,OUTPUT);
	pinMode(LED7,OUTPUT);

	Arm jarvis;
	jarvis.lightOn();
	jarvis.finger();
	jarvis.wrist();
	jarvis.ellbow();
	jarvis.vshoulder();
	jarvis.hshoulder();

	return 0;
}

