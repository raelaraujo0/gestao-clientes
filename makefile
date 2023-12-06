all: main

main: telas.o validadores.o main.o menuvendas.o menuusuarios.o logicausuarios.o logicavendas.o
	gcc telas.o validadores.o main.o menuvendas.o menuusuarios.o logicausuarios.o logicavendas.o -o main

telas.o: telas.c telas.h
	gcc -c telas.c

logicausuarios.o: logicausuarios.c logicausuarios.h
	gcc -c logicausuarios.c

logicavendas.o: logicavendas.c logicavendas.h
	gcc -c logicavendas.c

validadores.o: validadores.c validadores.h
	gcc -c validadores.c

menuvendas.o: menuvendas.c menuvendas.h
	gcc -c menuvendas.c

menuusuarios.o: menuusuarios.c menuusuarios.c
	gcc -c menuusuarios.c

main.o: main.c telas.h validadores.h menuusuarios.h menuvendas.h logicausuarios.h logicavendas.h
	gcc -c main.c

clean:
	rm -rf *.o main

run: main
	./main
