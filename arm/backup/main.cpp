
#include"arduino_serial.h"
using namespace std;


int main(int argc, char *argv[]) 
{
	int i;
	
	/*
	for( i=0;i<argc;i++)
	{
		cout<<argc<<endl;
		cout<<argv[i]<<endl;
	}

	char * array[i];
	for( i=0;i<argc;i++)
	{
		array[i]=argv[i];
	}
	arm(argc,array);
	*/
	char * array[9];
	cout<<"Light=";
	char str[10];
	cin>>str;
	array[0]="./arduino-serial";
	array[1]="-b";
	array[2]="9800";
	array[3]="-p";
	array[4]="/dev/ttyACM0";
	array[5]="-d";
	array[6]="1500";
	array[7]="-s";
	array[8]=str;


	//char * array[9]={"./arduino-serial","-b","9800","-p","/dev/ttyACM0",
		//"-d","1500","-s","0"};
	arm(9,array);
}


