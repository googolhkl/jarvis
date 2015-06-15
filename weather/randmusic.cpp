#include<cstdlib>
#include<ctime>

int randmusic(void)
{
	 srand(time(NULL));  //rand music player start
	 int i= rand()%4;
	 switch(i)
	{
		case 0:
			system("mplayer ~/음악/effect/vacations_over.mp3&");
			return 0;
		case 1:
			system("mplayer ~/음악/effect/mark_II.mp3&");
			return 0;
		case 2:
			system("mplayer ~/음악/effect/battle_final.mp3&");
			return 0;
		case 3:
			system("mplayer ~/음악/effect/iron_man.mp3&");
			return 0;
	}    
}
