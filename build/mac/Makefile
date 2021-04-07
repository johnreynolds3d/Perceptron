CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

../../bin/mac/perceptron : ../../src/main.c ../../build/mac/perceptron.o
	gcc -o ../../bin/mac/perceptron ../../src/main.c ../../build/mac/perceptron.o

../../build/mac/perceptron.o : ../../lib/perceptron.c ../../lib/headers/perceptron.h
	gcc -c -fpic -o ../../build/mac/perceptron.o ../../lib/perceptron.c

clean : 
	rm ../../bin/mac/perceptron ../../build/mac/perceptron.o 
