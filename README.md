# perceptron

### A basic implementation of a Perceptron in C

https://en.wikipedia.org/wiki/Perceptron

This binary classifier is capable of learning to perform the logical OR and AND operations!

*Clever girl...*

## Installation

  1. Clone this repository
     ```
     # git clone git@github.com:johnreynolds3d/perceptron.git
     ```
  2. cd into the source directory
     ```
     # cd perceptron
     ```
  3. Run make (on Linux; not sure about Windows atm...)
     ```
     # make -C build/linux
     ```
     or, if you're on a Mac
     ```
     # make -C build/mac
     ```
  4. Then run the program (on Linux) with
     ```
     # ./bin/linux/perceptron
     ```
     on Mac
     ```
     # ./bin/mac/perceptron
     ```

## Tests

I've been using Valgrind to highlight potential memory issues. 

On Linux, run
```
# sh test/runtests.sh
```

## Credits

This is based on Penny de Byl's fabulous https://www.udemy.com/course/machine-learning-with-unity/

## Built with

  * Pop!\_OS 20.10
  * Vim 8.2
  * Valgrind 3.18.0
  * gcc 10.2.0
