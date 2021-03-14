CC= g++
CFLAGS= -g -Wall -Werror -O2 -std=c++11 -pedantic
SFLAGS= -lsfml-system

all: ED

ED:	main.o ED.o
	$(CC) main.o ED.o -o ED $(SFLAGS)

main.o: main.cpp ED.h
	$(CC) -c main.cpp ED.h $(CFLAGS)

ED.o:	ED.cpp ED.h
	$(CC) -c ED.cpp ED.h $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm ED
