CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

bin/perceptron : src/main.c build/perceptron.o
	gcc -o bin/perceptron src/main.c build/perceptron.o -lm

build/perceptron.o : lib/perceptron.c lib/headers/perceptron.h
	gcc -c -fpic -o build/perceptron.o lib/perceptron.c

clean : 
	rm bin/perceptron build/perceptron.o
