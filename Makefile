CC=gcc
CFLAGS=-g
all:
	$(CC) $(CFLAGS) parser.c Person.c -o parser