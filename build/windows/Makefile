CFLAGS = -std=c17 -Wall -Werror -Wextra -Wpedantic -g -O2

../../bin/windows/perceptron.exe : ../../src/main.c ../../build/windows/perceptron.o
	x86_64-w64-mingw32-gcc -o ../../bin/windows/perceptron.exe ../../src/main.c ../../build/windows/perceptron.o

../../build/windows/perceptron.o : ../../lib/perceptron.c ../../lib/headers/perceptron.h
	x86_64-w64-mingw32-gcc -c -fpic -o ../../build/windows/perceptron.o ../../lib/perceptron.c

clean : 
	rm ../../bin/windows/perceptron_win64.exe ../../build/windows/perceptron.o
