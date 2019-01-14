#makefile for count.c

CC = gcc

all: count

#To be used when compiling count.c
count: count.c
	$(CC) -o count count.c

#To be used when removing count.
clean: 
	rm count
