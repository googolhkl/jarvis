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
	    utt_started = FALSE;
		system("mplayer ~/음악/interface/effect17.mp3");
	    printf("소리내어서 저를 깨워주세요\n");

	    for (;;) {

		if ((k = ad_read(ad, adbuf, 2048)) < 0)
		    E_FATAL("Failed to read audio\n");
		ps_process_raw(ps, adbuf, k, FALSE, FALSE);
		in_speech = ps_get_in_speech(ps);
		if (in_speech && !utt_started) {
		    utt_started = TRUE;
		    printf("듣는중...\n");
		}
		printf("1111111111111111111111111111111111111111111111111111111\n");

		if (!in_speech && utt_started) {//////////////////////////////////////////////////////////////

		    /* speech -> silence transition, time to start new utterance  */
		    ps_end_utt(ps);
		    hyp = ps_get_hyp(ps, NULL );

		    if ((hyp != NULL)&& (count>0)){
		        printf("                                                                       i hear [%s]			\n", hyp);        //  RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
			}
		    if(hyp==NULL)
		    {
			    printf("BREATH\nBREATH\nBREATH\nBREATH\nBREATH\n");
			    hyp ="breath";
		    }
		printf("1111111111111111111111111111111111111111111111111111111\n");

	if(count>0)	/////////////////////////////////////////////////////////////////
	{
		if(count>=1000)
			count==1;


	//jarvis.Write(hyp);
	//jarvis.Tts();



	if(!strcmp(hyp,"shutdown"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write(" ok master. i am offline");
	jarvis.Tts();
	return -1	;
	}

	else if(!strcmp(hyp,"left"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("turn left!");
	jarvis.Tts();
	return 0;
	}


	else if(!strcmp(hyp,"right"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("turn right!");
	jarvis.Tts();
	return 0;
	}


	else if(!strcmp(hyp,"friday"))
	{
		system("mplayer ~/음악/interface/effect69.mp3");
	jarvis.Write("yes master!");
	jarvis.Tts();
	return 0;
	}

	else if(!strcmp(hyp,"internet"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	system("chromium-browser &");
	jarvis.Write("I will connect to the chrome web browser!");
	jarvis.Tts();
	system("mplayer ~/음악/interface/effect56.mp3");
	return 0;
	}

	else if(!strcmp(hyp,"arm"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("my arm!");
	jarvis.Tts();
	return 0;
	}

	else if(!strcmp(hyp,"shoulder"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
	jarvis.Write("my shoulder!");
	jarvis.Tts();
	return 0;
	}

	else if(!strcmp(hyp,"finger"))
	{
		system("mplayer ~/음악/interface/effect56.mp3");
	jarvis.Write("my finger!");
	jarvis.Tts();
	return 0;
	}

	else if(!strcmp(hyp,"radio"))
	{
		//system("mplayer http://rainnara.saycast.com &");
		system("mplayer ~/음악/interface/effect56.mp3");
		system("chromium-browser saycast.sayclub.com/saycast/widget/widgetMini/ch07&");
		jarvis.Write("i will turn on the  radio");
		jarvis.Tts();
		jarvis.Write("and.. i am offline!");
		jarvis.Tts();

		return -1;
	}

	else if(!strcmp(hyp,"weather"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser https://www.google.co.kr/search?q=weather --start-fullscreen&");
		jarvis.Write("Today's Weather!");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	else if((!strcmp(hyp,"map"))||(!strcmp(hyp,"maps")))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser https://www.google.co.kr/maps --start-fullscreen&");
		jarvis.Write("i will connect to the satellite. please wait!");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}
	else if(!strcmp(hyp,"location history"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser https://maps.google.com/locationhistory/b/0 --start-fullscreen&");
		jarvis.Write("ok. i am connecting location history information");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}
	else if(!strcmp(hyp,"open video"))
	{
		system("mplayer ~/음악/interface/effect19.mp3");
		system("chromium-browser  https://www.youtube.com/playlist?list=PLVNz_u6rUR6H1Pg2lWYFW3n_pyK_CJQRL --start-fullscreen&");
		jarvis.Write("ok. i am connecting youtube");
		jarvis.Tts();
		system("mplayer ~/음악/interface/effect56.mp3");
		return 0;
	}

	break;
	}


		    if (ps_start_utt(ps) < 0)
		        E_FATAL("Failed to start utterance\n");
		    utt_started = FALSE;
		    cout<<"깨어 났습니다"<<endl<<"명령을 내려주세요"<<endl;
		
		printf("2222222222222222222222222222222222222222222222222222222222222222222222\n");

	count++;
		       
		        
		}///////////////////////////////////////////////////////////////////////
	
		sleep_msec(100);

	
	    }
	    ad_close(ad);
	}


#endif
