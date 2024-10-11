CC = gcc
CFLAGS = -Wall -g

all: sokoban

sokoban: main.o sokoban.o
	$(CC) -o sokoban main.o sokoban.o

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

sokoban.o: sokoban.c header.h
	$(CC) $(CFLAGS) -c sokoban.c

clean:
	rm -f *.o sokoban
