
#!/bin/bash
#mplayer http://204.178.9.51$(curl --data "voice=rich&txt=master,  now is exactly six'o clock. please wake up!. Here, i will turn on the radio and weather!&speakButton=SPEAK" "http://204.178.9.51/tts/cgi-bin/nph-nvttsdemo"|grep ".wav" |cut -d\" -f2)

mplayer -volume 100 ~/음악/interface/effect69.mp3
#mplayer -volume 100 "http://translate.google.com/translate_tts?tl=en&q=Good morning. The time now is 7:00 a.m., I will inform weather information"
#chromium-browser saycast.sayclub.com/saycast/widget/widgetMini/ch07&
#chromium-browser saycast.sayclub.com/saycast/widget/widgetMini/yes1959&
#chromium-browser --app=https://www.google.co.kr/search?q=weather&
#mplayer http://popballad.saycast.com
#mplayer -volume 40 http://yes1959.saycast.com&
~/jarvis/.weather
mplayer -volume 100 ~/음악//interface/effect56.mp3 
