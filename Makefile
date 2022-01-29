CC = gcc
CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

bin/perceptron : src/main.c obj/perceptron.o
	$(CC) $(CFLAGS) -o bin/perceptron src/main.c obj/perceptron.o -lm

obj/perceptron.o : src/perceptron.c lib/perceptron.h
	$(CC) $(CFLAGS) -c -fpic -o obj/perceptron.o src/perceptron.c

.PHONY: clean
clean : 
	rm bin/perceptron obj/perceptron.o
