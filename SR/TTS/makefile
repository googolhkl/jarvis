cc = g++

jarvis: jarvis.o continuous.o  arduino_serial.o
	$(cc) -g -O3  -o   jarvis jarvis.o continuous.o arduino_serial.o    \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase` &&clear && echo 'compile complete!!!' && ls --color=auto

jarvis.o: jarvis.cpp continuous.cpp arduino_serial.cpp
	$(cc) -g -O3 -c   jarvis.cpp continuous.cpp arduino_serial.cpp \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase ` && clear

clean:
	rm -r jarvis jarvis.o continuous.o arduino_serial.o && clear && \
	 echo '*.o file is deleted!! ' &&echo "current time is " &&date &&ls --color=auto
	

