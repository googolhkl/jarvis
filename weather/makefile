cc = g++

wearther: weather.o weathers.o jarvis.o randmusic.o weathermake.o
	$(cc) -o weather weather.o weathers.o jarvis.o randmusic.o weathermake.o
weather.o: weather.cpp weathers.cpp jarvis.cpp randmusic.cpp weathermake.cpp
	$(cc) -c weather.cpp weathers.cpp jarvis.cpp randmusic.cpp weathermake.cpp
clean:
	rm -r weather weather.o weathers.o jarvis.o randmusic.o weathermake.o test.wav
