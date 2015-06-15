#include"jarvis.h"

		Jarvis::Jarvis()
		{
			//myString="mplayer http://204.178.9.51$(curl --data \"voice=rich&txt=replace&speakButton=SPEAK\" \"http://204.178.9.51/tts/cgi-bin/nph-nvttsdemo\"|grep \".wav\" |cut -d\\\" -f2)";
			myString="mplayer 'http://translate.google.com/translate_tts?tl=en&q=replace'///////////";
			replaceString = "hello master ";
			//findString = "txt=";
			//endString = "&speakButton";
			findString = "n&q=";
			endString = "'///////////";
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
			replaceString = word;
		}
		int Jarvis::Write(char const * word)
		{
			
			string temp(word,0,100);
			replaceString = temp;
		}
		

		int Jarvis::Tts()
		{
			int pos1;
			int pos2;
			pos2 = myString.find(endString);
			pos1 = myString.find(findString);
			myString.erase(pos1+4,pos2-pos1-4);
			cout<<myString<<endl;
			myString.insert(pos1+4,replaceString);
			cout<<myString<<endl;
			system(myString.c_str());
		}


