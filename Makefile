a.out: main.cpp
	g++ main.cpp -lpthread

clean:
	rm a.out

zip:
	zip pthread_example *.cpp Makefile