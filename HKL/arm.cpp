#include"arm.h"

Arm::Arm()
{
	i=0;
	cout<<"arm !!"<<endl;
}
Arm::~Arm()
{
	cout<<"bye bye~"<<endl;
}


int Arm::lightOn()
{

	while(i==0)
	{
	digitalWrite(LED1,1);
	cin>>i;
	delay(10);
	}
	digitalWrite(LED1,0);
	return 0;
}

int Arm::finger()
{
	cout<<"finger hi"<<endl;

}

int Arm::wrist()
{
	cout<<"write hi"<<endl;
}

int Arm::ellbow()
{
	cout<<"ellbow hi"<<endl;
}

int Arm::vshoulder()
{
	cout<<"vshoulder hi"<<endl;
}

int Arm::hshoulder()
{
	cout<<"hshoulder hi"<<endl;
}

	

