cc = g++

jarvis: jarvis.o continuous.o  
	$(cc) -o jarvis jarvis.o continuous.o    \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase`

jarvis.o: jarvis.cpp continuous.cpp 
	$(cc) -c jarvis.cpp continuous.cpp  \
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase `

clean:
	rm -r jarvis jarvis.o continuous.o 
