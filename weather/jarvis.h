#ifndef __JARVIS_H__
#define __JARVIS_H__
#include<iostream>
#include<string>
#include<cstdlib>


using namespace::std;

class Jarvis
{
	private:
		string myString;
		string replaceString;
		string findString;
		string endString;
	public:
		Jarvis(); //생성자
		~Jarvis(); //소멸자
		int Hear(); // 후입력
		int Write(string); //선입력
		int Write(const char*);
		int Tts(); 
};


#endif
