#ifndef __WEATHER_H__
#define __WEATHER_H__

#include<iostream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace::std;

/*
	t->tm_year+   	   == year
	t->tm_mon+1        == month
	t->tm_mday         == day
	t->tm_hour         == hour
	t->tm_hour         == min
	t->tm_sec          == sec
*/
/*
   weatherInfo(int)에서 인자가 0~14까지 있음
   0 현재온도
   1 최고온도
   2 최저온도
   3 하늘상태
   4 강수
   5 날씨
   6 강수확률
   7 12시간강수량
   8 12시간적설량
   9 풍속
   10 풍향
   11 풍향영어 
   12 습도
   13 6시간강수량
   14 6시간적설량
*/

#define YEAR t->tm_year+1900
#define MONTH t->tm_mon+1
#define DAY t->tm_mday
#define HOUR t->tm_hour
#define MIN t->tm_min
#define SEC t->tm_sec

string intToString(int n);
string weather(int);
string weatherInfo(int);
string fridayWeather(int seltime,string &weatherInfo_1,string &weatherInfo0,string &weatherInfo1,string &weatherInfo2,string &weatherInfo3,string &weatherInfo4,string &weatherInfo5,string &weatherInfo6,string &weatherInfo7,string &weatherInfo8,string &weatherInfo9,string &weatherInfo10,string &weatherInfo11);
int randmusic(void);
int timearea(void);
int time12(int);
int weathermake(int);

#endif
