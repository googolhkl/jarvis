cc = g++

jarvis: jarvis.o continuous.o  arduino_serial.o
	$(cc) -o jarvis jarvis.o continuous.o arduino_serial.o    \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase`

jarvis.o: jarvis.cpp continuous.cpp arduino_serial.cpp
	$(cc) -c jarvis.cpp continuous.cpp arduino_serial.cpp \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase `

clean:
	rm -r jarvis jarvis.o continuous.o arduino_serial.o
