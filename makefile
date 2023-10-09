all: telas.o main.o
	gcc telas.o main.o -o main

telas.o:	telas.h
	gcc -c telas.c

clean:
	rm -rf *.o

run:
	./main
