CPP=g++

all:
	$(CPP) example.cpp Kalman.cpp -o example

lib:
	$(CPP) -c Kalman.cpp -o Kalman.so
