CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

../../bin/linux/perceptron : ../../src/main.c ../../build/linux/perceptron.o
	gcc -o ../../bin/linux/perceptron ../../src/main.c ../../build/linux/perceptron.o

../../build/linux/perceptron.o : ../../lib/perceptron.c ../../lib/headers/perceptron.h
	gcc -c -fpic -o ../../build/linux/perceptron.o ../../lib/perceptron.c

clean : 
	rm ../../bin/linux/perceptron ../../build/linux/perceptron.o
