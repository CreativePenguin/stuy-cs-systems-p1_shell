ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o args.o
	$(CC) -o prog.out main.o args.o

main.o: main.c
	$(CC) -c main.c

args.o: args.c args.h
	$(CC) -c args.c args.h

run:
	./prog
	make clean

clean:
	rm *.o *.out