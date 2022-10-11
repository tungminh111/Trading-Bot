CC=g++
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

build: src/main.o 
	$(CC) -o app src/main.o -I.
