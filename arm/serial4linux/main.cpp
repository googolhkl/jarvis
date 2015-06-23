
#include"arduino_serial.h"
using namespace std;


int main(int argc, char *argv[]) 
{
	int i;
	
	while(1)
	{
	char * array[4];
	cout<<"Light=";
	char str[10];
	cin>>str;
	array[0]="9800";
	array[1]="/dev/ttyACM0";
	array[2]="150";
	array[3]=str;
	arm(4,array);
	}

}


