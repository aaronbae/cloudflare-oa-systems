all: main.o
	g++ -Wall -g -o main main.o
main.o: main.cpp
	g++ -Wall -g -o main.o -c main.cpp
clean:
	rm -f main *.o