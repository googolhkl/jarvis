#include"jarvis.h"

		Jarvis::Jarvis()
		{
       myString="pico2wave --wave test.wav '####@@@@' ";
			replaceString = "####@@@@";
			findString = "####";
			endString = "@@@@";
		}
		Jarvis::~Jarvis()
		{
			cout<<""<<endl;
		}

		int Jarvis::Hear()
		{
			getline(cin,replaceString);
		}
		
		int Jarvis::Write(string word)
		{
			replaceString =  word;
		}
		int Jarvis::Write(char const * word)
		{
			
			string temp(word,0,100);
			replaceString = temp;

		}
		

		int Jarvis::Tts()
		{
      myString="pico2wave --wave test.wav '####@@@@' ";
			int pos1;
			int pos2;
			pos2 = myString.find(endString);
			pos1 = myString.find(findString);
			myString.erase(pos1,pos2-pos1+4);
			myString.insert(pos1,replaceString);
			system(myString.c_str());
      system("aplay test.wav");
      system("rm test.wav");

		}
