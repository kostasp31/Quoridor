exc: ListImplementation.o listImpl.o
	g++ -o exc listImplementation.o listImpl.o

listImplementation.o: listImplementation.cpp
	g++ -c listImplementation.cpp

listImpl.o: listImpl.cpp
	g++ -c listImpl.cpp