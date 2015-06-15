
cc = g++

arm: main.o arm.o
	$(cc) -o arm main.o arm.o -lwiringPi

test.o: main.cpp arm.cpp
	$(cc) -c main.cpp arm.cpp -lwiringPi
	

clean : 
	rm -r arm main.o arm.o

