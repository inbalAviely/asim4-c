all: main.o funcs.o
	gcc main.o funcs.o -o graph

clean:
	rm -f *.o

main: main.c define_func.h
	gcc -c main.c

funcs.o: funcs.c define_func.h
	gcc -c funcs.c

