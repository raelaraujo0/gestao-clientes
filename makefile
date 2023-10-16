all: telas.o main.o
	gcc telas.o main.o -o main

telas.o:	telas.h
	gcc -c telas.c

subtelas.0: subtelas.h
	gcc -c subtelas.c

validadores.o:
	gcc -o validadores.c

clean:
	rm -rf *.o

run:
	./main
