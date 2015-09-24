#include"jarvis.h"
#include"weather.h"

int weathermake(int seltimes)
{
	Jarvis jarvis;
	string weatherInfo_1,weatherInfo0,weatherInfo1,weatherInfo2,weatherInfo3,weatherInfo4,weatherInfo5,weatherInfo6,weatherInfo7,weatherInfo8,weatherInfo9,weatherInfo10,weatherInfo11;
	int seltime=seltimes;
	
	fridayWeather(seltime,weatherInfo_1,weatherInfo0,weatherInfo1,weatherInfo2,weatherInfo3,weatherInfo4,weatherInfo5,weatherInfo6,weatherInfo7,weatherInfo8,weatherInfo9,weatherInfo10,weatherInfo11);  //각 변수에 Text를 저장함.


	 //TEXT-TO-SPEECH (변수에 있는 TEXT를 음성으로) 
	jarvis.Write(weatherInfo_1);
	jarvis.Tts();

	jarvis.Write(weatherInfo0);
	jarvis.Tts();

	jarvis.Write(weatherInfo1);
	jarvis.Tts();

	jarvis.Write(weatherInfo2+weatherInfo3);
	jarvis.Tts();

/*
	jarvis.Write(weatherInfo3);
	jarvis.Tts();

	jarvis.Write(weatherInfo4);
	jarvis.Tts();
  */
	

	jarvis.Write(weatherInfo4+weatherInfo5);
	jarvis.Tts();

	jarvis.Write(weatherInfo6);
	jarvis.Tts();

	jarvis.Write(weatherInfo7);
	jarvis.Tts();

	jarvis.Write(weatherInfo8);
	jarvis.Tts();

	jarvis.Write(weatherInfo10);
	jarvis.Tts();

	jarvis.Write(weatherInfo11);
	jarvis.Tts();


	/*   Showing            */
  
	cout<<weatherInfo0<<endl;
	cout<<weatherInfo0<<endl;
	cout<<weatherInfo1<<endl;
	cout<<weatherInfo2<<endl;
	cout<<weatherInfo3<<endl;
	cout<<weatherInfo4<<endl;
	cout<<weatherInfo5<<endl;
	cout<<weatherInfo6<<endl;
	cout<<weatherInfo7<<endl;
	cout<<weatherInfo8<<endl;
	cout<<weatherInfo9<<endl;
	cout<<weatherInfo10<<endl;
	cout<<weatherInfo11<<endl;
}


