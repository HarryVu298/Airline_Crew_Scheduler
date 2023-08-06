main: main.o functions.o
	g++ -std=c++14 main.o functions.o -o main

main.o: main.cpp functions.h
	g++ -std=c++14 -Wall -c main.cpp

functions.o: functions.cpp functions.h
	g++ -std=c++14 -Wall -c functions.cpp

clean :
	rm *.o main 