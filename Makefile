CC=gcc
CFLAGS=-g3
all:
	$(CC) $(CFLAGS) test.c parser.c Person.c -o parser
