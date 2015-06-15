#ifndef __INIT_H__
#define __INIT_H__

#include<iostream>
#include<wiringPi.h>
/* available wiringPi GPIO
   2,3,4,5 7,8,9
*/
using namespace::std;
#define LED1 2	//for LED control
#define LED2 3	//for A 3X8 decoder
#define LED3 4
#define LED4 5
#define LED5 7	//for B 3X8 decoder
#define LED6 8
#define LED7 9

class Arm
{
	private:
		int i;
	public:
		Arm();
		~Arm();
		int lightOn();
		int finger();
		int wrist();
		int ellbow();
		int vshoulder();
		int hshoulder();

};





#endif

