CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

../../bin/mac_os/perceptron : ../../src/main.c ../../build/mac_os/perceptron.o
	gcc -o ../../bin/mac_os/perceptron ../../src/main.c ../../build/mac_os/perceptron.o

../../build/mac_os/perceptron.o : ../../lib/perceptron.c ../../lib/headers/perceptron.h
	gcc -c -fpic -o ../../build/mac_os/perceptron.o ../../lib/perceptron.c

clean : 
	rm ../../bin/mac_os/perceptron ../../build/mac_os/perceptron.o 
