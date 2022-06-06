CC = cc
CFLAGS = -std=c99 -pedantic -Wall
OBJECTS = gameOfLife.o board.o cell.o

all: gameOfLife

gameOfLife.o: src/gameOfLife.c
	$(CC) $(CFLAGS) -c src/board.c src/cell.c src/gameOfLife.c

gameOfLife: $(OBJECTS)
	$(CC) $(OBJECTS) -o gameOfLife

clean:
	rm -f *.o gameOfLife
