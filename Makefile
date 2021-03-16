CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

apps/perceptron : src/main.c build/perceptron.o
	gcc -o apps/perceptron src/main.c build/perceptron.o

build/perceptron.o : libs/perceptron.c libs/headers/perceptron.h
	gcc -c -fpic -o build/perceptron.o libs/perceptron.c

clean : 
	rm apps/perceptron build/perceptron.o
