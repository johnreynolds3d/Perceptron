apps/perceptron : src/main.c build/perceptron.o
	gcc -Wall -o apps/perceptron src/main.c build/perceptron.o

build/perceptron.o : libs/perceptron.c libs/headers/perceptron.h
	gcc -c -Wall -Werror -fpic -o build/perceptron.o libs/perceptron.c

clean : 
	rm apps/perceptron build/perceptron.o
