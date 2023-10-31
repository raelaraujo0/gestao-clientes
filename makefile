all: main

main: telas.o subtelas.o validadores.o main.o
	gcc telas.o subtelas.o validadores.o main.o -o main

telas.o: telas.c telas.h
	gcc -c telas.c

subtelas.o: subtelas.c subtelas.h
	gcc -c subtelas.c

validadores.o: validadores.c validadores.h
	gcc -c validadores.c

main.o: main.c telas.h subtelas.h validadores.h
	gcc -c main.c

subdivisoes.o: subdivisoes.c subdivisoes.h
	gcc -c subdivisoes.c

clean:
	rm -rf *.o main

run: main
	./main
