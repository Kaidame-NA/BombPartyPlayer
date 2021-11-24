CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

main.exe: main.o
	$(CC) -o main.exe main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c -g main.cpp
clean:
	rm -f *.o main.exe