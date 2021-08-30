a.out: main.o
	g++ main.o -lpthread

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm a.out

zip:
	zip pthread_example *.cpp Makefile