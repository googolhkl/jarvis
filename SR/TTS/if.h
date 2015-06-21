#ifndef __IF_H__
#define __IF_H__

#include"stt.h"
#include"jarvis.h"
#include<cstdlib>
static int
	recognize_from_microphone()
	{
		Jarvis jarvis;
		char const * initial = "initiation";
	jarvis.Write(initial);
	    ad_rec_t *ad;
	    int16 adbuf[2048];
	    uint8 utt_started, in_speech;
	    int32 k;
	    char const *hyp;
	    int count=0;

	    if ((ad = ad_open_dev(cmd_ln_str_r(config, "-adcdev"),
		                  (int) cmd_ln_float32_r(config,
		                                         "-samprate"))) == NULL)
		E_FATAL("Failed to open audio device\n");
	    if (ad_start_rec(ad) < 0)
		E_FATAL("Failed to start recording\n");

	    if (ps_start_utt(ps) < 0)
		E_FATAL("Failed to start utterance\n");
	    //utt_started = FALSE;
		//system("mplayer ~/음악/interface/effect48.mp3&");        //          마이크 소리
	    //printf("소리내어서 저를 깨워주세요\n");

	    utt_started = TRUE;                           // real time speech on 2015/6/15
     	    in_speech = ps_get_in_speech(ps);             // real time speech on 
	    for (;;) {

		if ((k = ad_read(ad, adbuf, 2048)) < 0)
		    E_FATAL("Failed to read audio\n");
		ps_process_raw(ps, adbuf, k, FALSE, FALSE);
		in_speech = ps_get_in_speech(ps);
		if (in_speech && !utt_started) {
		    utt_started = TRUE;
		    //printf("듣는중...\n");
		}
		//printf("\n");

		if (!in_speech && utt_started) {//////////////////////////////////////////////////////////////

		    /* speech -> silence transition, time to start new utterance  */
		    ps_end_utt(ps);
		    hyp = ps_get_hyp(ps, NULL );

		    if ((hyp != NULL)&& (count>0)){
		        printf("%s\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
		        printf("%s\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
		        printf("%s\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
		        printf("%s\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
		        printf("%s\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
			}
		    if(hyp==NULL)
		    {
			    printf("BREATH\nBREATH\nBREATH\nBREATH\nBREATH\n");
			    hyp ="breath";
		    }

	if(count>0)	/////////////////////////////////////////////////////////////////
	{
		if(count>=1000)
			count==1;


	//jarvis.Write(hyp);
	//jarvis.Tts();
		string mystring;
		mystring=hyp;

		/*
		if(mystring.find("open jarvis") !=string::npos)
		{
		jarvis.Write("i am online and ready hey hey ");
		jarvis.Tts();
		return 0;
		}
		*/

/*         Arduino Serial communication               */
	char * array[4];
	char str[10];
	array[0]="9800";
	array[1]="/dev/ttyACM0";
	array[2]="150";
	//array[3]=str;
	//arm(4,array);

/*			JARVIS COMMAND					*/
	if(mystring.find("jarvis shutdown") !=string::npos)
	{
	jarvis.Write(" ok master. i am offline");
	jarvis.Tts();
		system("mplayer ~/음악/interface/effect19.mp3");
	return -1	;
	}

	else if(!strcmp(hyp,"jarvis"))
	{
		//system("mplayer ~/음악/interface/effect69.mp3");
	jarvis.Write("yes master!");
	jarvis.Tts();
	return 0;
	}

	else if(mystring.find("finger close") !=string::npos)
	{
	jarvis.Write("finger close");
	jarvis.Tts();
	return 0;
	}
	else if(mystring.find("finger open") !=string::npos)
	{
	jarvis.Write("finger open");
	jarvis.Tts();
	return 0;
	}
	else if(mystring.find("wrist down") !=string::npos)
	{
	jarvis.Write("wrist down!");
	jarvis.Tts();
	return 0;
	}

	else if(mystring.find("wrist up") !=string::npos)
	{
	jarvis.Write("wrist up!");
	jarvis.Tts();
	return 0;
	}

	else if(mystring.find("elbow down") !=string::npos)
	{
	jarvis.Write("elbow down");
	jarvis.Tts();
	return 0;
	}
	else if(mystring.find("elbow up") !=string::npos)
	{
	jarvis.Write("elbow up");
	jarvis.Tts();
	return 0;
	}
	else if(mystring.find("shoulder down") !=string::npos)
	{
		array[3]="3";
		arm(4,array);
	return 0;
	}
	else if(mystring.find("shoulder up") !=string::npos)
	{
		array[3]="2";
		arm(4,array);
	return 0;
	}

	else if(mystring.find("shoulder left") !=string::npos)
	{
		array[3]="1";
		arm(4,array);
	return 0;
	}
	else if(mystring.find("shoulder right") !=string::npos)
	{
		array[3]="0";
		arm(4,array);
	return 0;
	}

	else if(mystring.find("jarvis up") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("total up!");
	jarvis.Tts();
	return 0;
	}
	else if(mystring.find("jarvis down") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("total down!");
	jarvis.Tts();
	return 0;
	}

	
/*			OPEN COMMAND					*/
	else if(mystring.find("open command") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect60.mp3");
		system("terminator&");
		system("mplayer ~/음악/interface/effect60.mp3");
		return 0;
	}
	else if(mystring.find("open map") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser https://www.google.co.kr/maps --start-fullscreen&");
		jarvis.Write("i will connect to the satellite. please wait!");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	else if(mystring.find("open internet") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
	system("chromium-browser &");
	jarvis.Write("I will connect to the chrome web browser!");
	jarvis.Tts();
	system("mplayer ~/음악/interface/effect56.mp3");
	return 0;
	}

	else if(mystring.find("open video") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser  https://www.youtube.com/playlist?list=PLVNz_u6rUR6H1Pg2lWYFW3n_pyK_CJQRL --start-fullscreen&");
		jarvis.Write("ok. i am connecting youtube");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	else if(mystring.find("open radio") !=string::npos)
	{
		//system("mplayer http://rainnara.saycast.com &");
		//system("mplayer ~/음악/interface/effect56.mp3");
		system("chromium-browser saycast.sayclub.com/saycast/widget/widgetMini/ch07&");
		jarvis.Write("i will turn on the  radio");
		jarvis.Tts();
		jarvis.Write("and.. i am offline!");
		jarvis.Tts();

		return -1;
	}

/*			OTHER COMMAND				*/
	else if(mystring.find("weather today") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
		//system("chromium-browser https://www.google.co.kr/search?q=weather --start-fullscreen&");
		jarvis.Write("Weather information!");
		jarvis.Tts();
		system("/home/googolhkl/jarvis/.weather");
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	else if(mystring.find("location history") !=string::npos)
	{
		//system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser https://maps.google.com/locationhistory/b/0 --start-fullscreen&");
		jarvis.Write("ok. i am connecting location history information");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}
	else if(mystring.find("close jarvis") !=string::npos)
	{
		jarvis.Write("i am offline");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		system("killall jarvis");
		return 0;
	}
	else if(mystring.find("close internet") !=string::npos)
	{
		system("killall chromium-browser");
		jarvis.Write("closed chrome web browser");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}
	else if(mystring.find("close radio") !=string::npos)
	{
		system("killall mplayer");
		jarvis.Write("closed radio");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}
	else if(mystring.find("close command") !=string::npos)
	{
		system("killall terminator");
		jarvis.Write("closed command line");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	break;
	}


		    if (ps_start_utt(ps) < 0)
		        E_FATAL("Failed to start utterance\n");
		    utt_started = FALSE;
		    //cout<<"깨어 났습니다"<<endl<<"명령을 내려주세요"<<endl;
		

	count++;
		       
		        
		}///////////////////////////////////////////////////////////////////////
	
		sleep_msec(1);

	
	    }
	    ad_close(ad);
	}


#endif
