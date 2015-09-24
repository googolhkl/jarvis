#include"weather.h"

string intToString(int n)
{
stringstream s;
s<<n;
return s.str();
}
string weather(int sel)
{
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t= localtime(&timer);
	string year = intToString(YEAR);	//int to string
	string month= intToString(MONTH);
	string day= intToString(DAY);
	string hour= intToString(HOUR);
	string min= intToString(MIN);
	string sec= intToString(SEC);
	
	if(MONTH<10)
		month="0"+month;
	if(DAY<10)
		day="0"+day;
	if(HOUR<10)
		hour="0"+hour;
	if(MIN<10)
		min="0"+min;
	if(SEC<10)
		sec="0"+sec;
	
	

	switch(sel)
	{
		case 1: cout<<year<<endl;
			return year;
		case 2:
			cout<<month<<endl;
			return month;
			
		case 3: cout<<day<<endl;
			return day;
		case 4: cout<<hour<<endl;
			return hour;
		case 5: cout<<min<<endl;
			return min;
		case 6: cout<<sec<<endl;
			return sec;
		
	}

	string timeinfo = year+month+day;
	int pos;
	/* Download weather information from Korea Meteorological Administration*/
	string myString="wget -O rep             http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4215057200";
	/* file name today*/
	string replaceString = timeinfo;
	while((pos = myString.find("rep")) !=string::npos)
		{
		myString.replace(pos,replaceString.length(),replaceString);
		}
	//cout<<myString<<endl;
	if(sel==0)
		system(myString.c_str());
	if(sel==7)
	{
		system(myString.c_str());
		return timeinfo;
	}
	return timeinfo;
}

string weatherInfo(int sel)
{
	string date= weather(7); // year+month+day
	ifstream OpenFile(date.c_str());
	string info;
	int i=0;

	char ch;
	while(!OpenFile.eof())
	{
		OpenFile.get(ch);
		info+=ch;
	}
	
	OpenFile.close();

	/*
	   seq = 0 0h
	   seq = 1 3h
	   seq = 2 6h
	   seq = 3 9h
	   	.
		.
	   seq = 8 24h
	   seq = 9 next day 0h
	*/
	//Cutting start today 6h infomation(6시 정보 얻어오기. 다른곳 하려면 바로위에 써놓음)
	int timeSelect= timearea();
	string::size_type num1;
	string::size_type num2;
	
	if(timeSelect==0)
	{
	num1= info.find("<data seq=\"0\">");
	num2= info.find("<data seq=\"1\">");
	}
	else if(timeSelect==1)
	{
	num1= info.find("<data seq=\"1\">");
	num2= info.find("<data seq=\"2\">");
	}

	else if(timeSelect==2)
	{
	num1= info.find("<data seq=\"2\">");
	num2= info.find("<data seq=\"3\">");
	}

	else if(timeSelect==3)
	{
	num1= info.find("<data seq=\"3\">");
	num2= info.find("<data seq=\"4\">");
	}

	else if(timeSelect==4)
	{
	num1= info.find("<data seq=\"4\">");
	num2= info.find("<data seq=\"5\">");
	}

	else if(timeSelect==5)
	{
	num1= info.find("<data seq=\"5\">");
	num2= info.find("<data seq=\"6\">");
	}
	else if(timeSelect==6)
	{
	num1= info.find("<data seq=\"6\">");
	num2= info.find("<data seq=\"7\">");
	}
	else if(timeSelect==7)
	{
	num1= info.find("<data seq=\"7\">");
	num2= info.find("<data seq=\"8\">");
	}

	string INFO;
	for(i=num1; i<num2;i++)
	{
		INFO+=info[i];
	}
	//cout<<INFO<<endl;
	//Cutting end today 6h information

	//temperature information start(현재온도)
	string::size_type tempStartNum = INFO.find("<temp>");
	string::size_type tempEndNum = INFO.find("</temp>");
	int numTemp= tempStartNum+6;
	string tempInfo;
	for(i=numTemp;numTemp<tempEndNum;numTemp++)
	{
		tempInfo+=INFO[numTemp];
	}
	//cout<<tempInfo<<endl;
	if(sel==0)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return tempInfo;
	}
	//temperature information end(현재온도)

	//max temperature information start(최고온도)
	string::size_type maxtempStartNum = INFO.find("<tmx>");
	string::size_type maxtempEndNum = INFO.find("</tmx>");
	int maxnumTemp= maxtempStartNum+5;
	string maxtempInfo;
	for(i=maxnumTemp;maxnumTemp<maxtempEndNum;maxnumTemp++)
	{
		maxtempInfo+=INFO[maxnumTemp];
	}
	//cout<<maxtempInfo<<endl;
	if(sel==1)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return maxtempInfo;
	}
	//max temperature information end(최고온도)
	

	//min temperature information start(최저온도)
	string::size_type mintempStartNum = INFO.find("<tmn>");
	string::size_type mintempEndNum = INFO.find("</tmn>");
	int minnumTemp= mintempStartNum+5;
	string mintempInfo;
	for(i=minnumTemp;minnumTemp<mintempEndNum;minnumTemp++)
	{
		mintempInfo+=INFO[minnumTemp];
	}
	//cout<<mintempInfo<<endl;
	if(sel==2)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return mintempInfo;
	}
	//min temperature information end(최저온도)

	//sky information start(하늘상태)
	/*
	   1 Clear(맑음)
	   2 Partly Cloudy(구름 조금)
	   3 Mostly Cloudy(구름 많음)
	   4 Cloudy (흐림)
	*/
	string::size_type skyStartNum = INFO.find("<sky>");
	string::size_type skyEndNum = INFO.find("</sky>");
	int skynum= skyStartNum+5;
	string skyInfo;
	for(i=skynum;skynum<skyEndNum;skynum++)
	{
		skyInfo+=INFO[skynum];
	}
	//cout<<skyInfo<<endl;
	if(sel==3)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return skyInfo;
	}
	//sky information end(하늘상태)

	//precipitation information start(강수)
	/*
	   0 clear(없음)
	   1 rain(비)
	   2 rain/snow( 비/눈)
	   3 snow/rain(눈/비)
	   4 snow(눈)
	*/
	string::size_type ptyStartNum = INFO.find("<pty>");
	string::size_type ptyEndNum = INFO.find("</pty>");
	int ptynum= ptyStartNum+5;
	string ptyInfo;
	for(i=ptynum;ptynum<ptyEndNum;ptynum++)
	{
		ptyInfo+=INFO[ptynum];
	}
	//cout<<ptyInfo<<endl;
	if(sel==4)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return ptyInfo;
	}
	//precipitation information end(강수)

	//weathery information start(날씨)
	/*
	   1 Clear(맑음)
	   2 Partly Cloudy(구름 조금)
	   3 Mostly Cloudy(구름 많음)
	   4 Cloudy (흐림)
	   5 Rain(비)
	   6 Snow/Rain(눈/비)
	   7 Snow(눈)
	*/
	string::size_type weaStartNum = INFO.find("<wfEn>");
	string::size_type weaEndNum = INFO.find("</wfEn>");
	int weanum= weaStartNum+6;
	string weaInfo;
	for(i=weanum;weanum<weaEndNum;weanum++)
	{
		weaInfo+=INFO[weanum];
	}
	//cout<<weaInfo<<endl;
	if(sel==5)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return weaInfo;
	}
	//weather information end(날씨)

	//precipitation probability information start(강수확률)
	string::size_type popStartNum = INFO.find("<pop>");
	string::size_type popEndNum = INFO.find("</pop>");
	int popnum= popStartNum+5;
	string popInfo;
	for(i=popnum;popnum<popEndNum;popnum++)
	{
		popInfo+=INFO[popnum];
	}
	//cout<<popInfo<<endl;
	if(sel==6)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return popInfo;
	}
	//precipitation probability information end(강수확률)

	//precipitation probability information start(강수량12시간)
	/*
	   12시간 예상강수량임.
	   ex) 20.346346= 12시간동안 20.346346mm 
	 */
	string::size_type r12StartNum = INFO.find("<r12>");
	string::size_type r12EndNum = INFO.find("</r12>");
	int r12num= r12StartNum+5;
	string r12Info;
	for(i=r12num;r12num<r12EndNum;r12num++)
	{
		r12Info+=INFO[r12num];
	}
	//cout<<r12Info<<endl;
	if(sel==7)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return r12Info;
	}
	//precipitation probability information end(강수량12시간)

	//amount of snow cover information start(적설량)
	/*
	   12시간 예상적설량임.
	   ex) 20.346346= 12시간동안 20.346346mm 
	 */
	string::size_type s12StartNum = INFO.find("<s12>");
	string::size_type s12EndNum = INFO.find("</s12>");
	int s12num= s12StartNum+5;
	string s12Info;
	for(i=s12num;s12num<s12EndNum;s12num++)
	{
		s12Info+=INFO[s12num];
	}
	//cout<<s12Info<<endl;
	if(sel==8)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return s12Info;
	}
	//amount of snow cover information end(적설량)

	//wind velocity information start(풍속)
	/*
	   반올림
	 */
	string::size_type wsStartNum = INFO.find("<ws>");
	string::size_type wsEndNum = INFO.find("</ws>");
	int wsnum= wsStartNum+4;
	string wsInfo;
	for(i=wsnum;wsnum<wsEndNum;wsnum++)
	{
		wsInfo+=INFO[wsnum];
	}
	//cout<<wsInfo<<endl;
	if(sel==9)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return wsInfo;
	}
	//wind velocity information end(풍속)

	//wind direction information start(풍향)
	/*
	   0~7 까지
	   (븍.북동,동,남동,남,남서,서,북서)
	 */
	string::size_type wdStartNum = INFO.find("<wd>");
	string::size_type wdEndNum = INFO.find("</wd>");
	int wdnum= wdStartNum+4;
	string wdInfo;
	for(i=wdnum;wdnum<wdEndNum;wdnum++)
	{
		wdInfo+=INFO[wdnum];
	}
	//cout<<wdInfo<<endl;
	if(sel==10)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return wdInfo;
	}
	//wind direction information end(풍향)

	//wind direction start(풍향 영어)
	/*
	   1 Clear(맑음)
	   2 Partly Cloudy(구름 조금)
	   3 Mostly Cloudy(구름 많음)
	   4 Cloudy (흐림)
	   5 Rain(비)
	   6 Snow/Rain(눈/비)
	   7 Snow(눈)
	*/
	string::size_type wdEnStartNum = INFO.find("<wdEn>");
	string::size_type wdEnEndNum = INFO.find("</wdEn>");
	int wdEnnum= wdEnStartNum+6;
	string wdEnInfo;
	for(i=wdEnnum;wdEnnum<wdEnEndNum;wdEnnum++)
	{
		wdEnInfo+=INFO[wdEnnum];
	}
	//cout<<wdEnInfo<<endl;
	if(sel==11)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return wdEnInfo;
	}
	//wind direction end(풍향 영어)

	//humidity information start(습도)
	string::size_type rehStartNum = INFO.find("<reh>");
	string::size_type rehEndNum = INFO.find("</reh>");
	int rehnum= rehStartNum+5;
	string rehInfo;
	for(i=rehnum;rehnum<rehEndNum;rehnum++)
	{
		rehInfo+=INFO[rehnum];
	}
	//cout<<rehInfo<<endl;
	if(sel==12)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return rehInfo;
	}
	//humidity probability information end(습도)

	//precipitation probability information start(강수량6시간)
	/*
	   6시간 예상강수량임.
	   ex) 20.346346= 6시간동안 20.346346mm 
	 */
	string::size_type r06StartNum = INFO.find("<r06>");
	string::size_type r06EndNum = INFO.find("</r06>");
	int r06num= r06StartNum+5;
	string r06Info;
	for(i=r06num;r06num<r06EndNum;r06num++)
	{
		r06Info+=INFO[r06num];
	}
	//cout<<r06Info<<endl;
	if(sel==13)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return r06Info;
	}
	//precipitation probability information end(강수량6시간)

	//precipitation probability information start(적설량6시간)
	/*
	   6시간 예상적설량임.
	   ex) 20.346346= 6시간동안 20.346346mm 
	 */
	string::size_type s06StartNum = INFO.find("<s06>");
	string::size_type s06EndNum = INFO.find("</s06>");
	int s06num= s06StartNum+5;
	string s06Info;
	for(i=s06num;s06num<s06EndNum;s06num++)
	{
		s06Info+=INFO[s06num];
	}
	//cout<<s06Info<<endl;
	if(sel==14)
	{
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
		return s06Info;
	}
	//precipitation probability information end(적설량6시간)

/*  Weather infomation file remove!*/
	string removeFile="rm -r ";
	removeFile=removeFile+date;
	system(removeFile.c_str());
}

string fridayWeather(int seltime,string &weatherInfo_1,string &weatherInfo0,string &weatherInfo1,string &weatherInfo2,string &weatherInfo3,string &weatherInfo4,string &weatherInfo5,string &weatherInfo6,string &weatherInfo7,string &weatherInfo8,string &weatherInfo9,string &weatherInfo10,string &weatherInfo11)
{
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t= localtime(&timer);
	int timenum=0;
	int timeto12=time12(HOUR);
	string mystring_1;
	string mystring0="Its "+ intToString(MIN)+" past "+intToString(timeto12);
	string mystring1="Current temperature is "+weatherInfo(0) +" degrees Celsius";
	string mystring2="and ";
	string mystring3="Daytime Maximum temperature is "+weatherInfo(1)+" degrees Celsius";
	string mystring4="and ";
	string mystring5="Daytime Minimum temperature is "+weatherInfo(2)+" degrees Celsius";
	string mystring6="Sky weather is "+weatherInfo(5);
	string mystring7="rainfall probability is "+weatherInfo(6)+"%.";
	string rain=weatherInfo(5);
	string mystring8;
	timenum=timearea();

	if(HOUR==seltime)  //알람음악 시간설정
	{
		mystring_1="Good Morning, i will inform you of a weather information";
		randmusic();
	}


	if(rain.compare("Rain")==0)
	{
		mystring8="expected rainfall of 12hour is "+weatherInfo(7)+" mm";
		cout<<"good"<<endl;
	}
	else if(rain.compare("Snow")==0)
	{
		mystring8="expected snowfall of 12hour is "+weatherInfo(8)+" mm";
		cout<<"good"<<endl;
	}
	else if(rain.compare("Snow/Rain")==0)
	{
		mystring8="expected rainfall and snowfall of 12hour is respectively "+weatherInfo(7)+"mm and "+weatherInfo(8)+"mm";
		cout<<"good"<<endl;
	}

	string wind=weatherInfo(10);
	string mystring9;
	if((wind.compare("E")==0)||wind.compare("2")==0)
	{
		mystring9="east";
	}
	else if((wind.compare("N")==0)||wind.compare("0")==0)
	{
		mystring9="north";
	}
	else if((wind.compare("NE")==0)||wind.compare("1")==0)
	{
		mystring9="north-east";
	}
	else if((wind.compare("NW")==0)||wind.compare("7")==0)
	{
		mystring9="north-west";
	}
	else if((wind.compare("S")==0)||wind.compare("4")==0)
	{
		mystring9="south";
	}
	else if((wind.compare("SE")==0)||wind.compare("3")==0)
	{
		mystring9="south-east";
	}
	else if((wind.compare("SW")==0)||wind.compare("5")==0)
	{
		mystring9="south-west";
	}
	else if((wind.compare("W")==0)||wind.compare("6")==0)
	{
		mystring9="west";
	}
	string mystring10="wind  blows "+mystring9+" to "+weatherInfo(9)+"m/s";
	string mystring11="lastly, humidity is "+weatherInfo(12)+"%";

	weatherInfo_1=mystring_1;
	weatherInfo0=mystring0;
	weatherInfo1=mystring1;
	weatherInfo2=mystring2;
	weatherInfo3=mystring3;
	weatherInfo4=mystring4;
	weatherInfo5=mystring5;
	weatherInfo6=mystring6;
	weatherInfo7=mystring7;
	weatherInfo8=mystring8;
	weatherInfo9=mystring9;
	weatherInfo10=mystring10;
	weatherInfo11=mystring11;
	return weatherInfo1;
}

int timearea(void)
{
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t= localtime(&timer);
	int timenum=0;
					     
	if((HOUR>=0) && (HOUR<2))
		timenum=0;
	else if((HOUR>=2) && (HOUR<5))
		timenum=1;
	else if((HOUR>=5) && (HOUR<8))
		timenum=2;
	else if((HOUR>=8) && (HOUR<11))
		timenum=3;
	else if((HOUR>=11) && (HOUR<14))
		timenum=4;
	else if((HOUR>=14) && (HOUR<17))
		timenum=5;
	else if((HOUR>=17) && (HOUR<20))
		timenum=6;
	else if((HOUR>=20) && (HOUR<23))
		timenum=7;
	else if((HOUR>=23))
		timenum=0;
	return timenum;
}

int time12(int num)
{
	switch(num)
	{
		case 13:
			return 1;
		case 14:
			return 2;
		case 15:
			return 3;
		case 16:
			return 4;
		case 17:
			return 5;
		case 18:
			return 6;
		case 19:
			return 7;
		case 20:
			return 8;
		case 21:
			return 9;
		case 22:
			return 10;
		case 23:
			return 11;
		case 24:
			return 0;
	}
}
