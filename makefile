all: main.o
	g++ -Wall -g -o main main.o -lcurl
main.o: main.cpp
	g++ -Wall -g -o main.o -c main.cpp -lcurl
clean:
	rm -f main *.o