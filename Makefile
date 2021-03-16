bin/perceptron : src/main.c build/perceptron.o
	gcc -Wall -o bin/perceptron src/main.c build/perceptron.o

build/perceptron.o : src/perceptron.c src/perceptron.h
	gcc -c -Wall -Werror -fpic -o build/perceptron.o src/perceptron.c

clean : 
	rm bin/perceptron build/perceptron.o
