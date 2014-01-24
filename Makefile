CC=gcc
CFLAGS=-g
all:
	$(CC) $(CFLAGS) test.c parser.c Person.c -o parser