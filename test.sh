rm -f perceptron 

gcc -Wall -Werror -c -fpic lib_perceptron.c
gcc -shared -o lib_perceptron.so lib_perceptron.o
gcc -Wall -o perceptron perceptron.c lib_perceptron.o

valgrind --leak-check=yes -s ./perceptron 
