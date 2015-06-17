#!/bin/bash

mplayer ~/음악/interface/effect31.mp3
#mplayer http://204.178.9.51$(curl --data "voice=rich&txt=hello master. allow me to load the necessary files. i am online and ready! ok. first please tell me command!&speakButton=SPEAK" "http://204.178.9.51/tts/cgi-bin/nph-nvttsdemo"|grep ".wav" |cut -d\" -f2)
 mplayer "http://translate.google.com/translate_tts?tl=en&q=hello master,allow me to load the neccesary files."
 mplayer "http://translate.google.com/translate_tts?tl=en&q=i'm online and ready!"
#~/jarvis/.weather
 mplayer "http://translate.google.com/translate_tts?tl=en&q=ok, please tell me command!"
mplayer ~/음악/interface/effect2.mp3

~/jarvis/sr/TTS/jarvis -inmic yes
