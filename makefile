ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o args.o pprocs.o
	$(CC) -o prog.out main.o args.o pprocs.o

main.o: main.c
	$(CC) -c main.c

args.o: args.c args.h
	$(CC) -c args.c args.h

pprocs.o: pprocs.c pprocs.h
	$(CC) -c pprocs.c pprocs.h

run:
	./prog.out
	make clean

clean:
	rm *.o *.out *.gch

memtest:
	valgrind --leak-check=yes ./prog.out
