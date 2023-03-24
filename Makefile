exc: main.o functions.o
	g++ -o exc main.o functions.o

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

