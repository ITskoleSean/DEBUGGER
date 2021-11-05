CC = gcc
CFLAG = -O0 -Wall -std=c11
FILENAME = pgdbglog

all:
	$(CC) $(CFLAG) -c $(FILENAME).c
	$(CC) -o PgDbgLog $(FILENAME).o main.c

clean:
	rm -rf *.o
	rm -rf $(FILENAME)
	rm -rf ./debug/*

exe:
	./$(FILENAME)