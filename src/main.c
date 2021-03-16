#include "perceptron.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TrainingSet {
  int inputs[2];
  int output;
};

int main() {

  srand(time(NULL));

  double weights[2];

  int sw = (int)(sizeof(weights) / sizeof(double));
  int epochs = 6;
  int numSets = 4;

  for (int i = 0; i < 2; i++) {

    struct TrainingSet *ts_arr[numSets];

    double *bias = malloc(sizeof(double));
    double *totalError = malloc(sizeof(double));

    if (i == 0) {

      printf("\nHi there! I'm a Perceptron. Watch me learn a logical OR "
             "function!\n\n");

      ts_arr[0] = TrainingSet_create(0, 0, 0);
      ts_arr[1] = TrainingSet_create(0, 1, 1);
      ts_arr[2] = TrainingSet_create(1, 0, 1);
      ts_arr[3] = TrainingSet_create(1, 1, 1);

    } else {

      printf("\nNOW watch me learn a logical AND function!\n\n");

      ts_arr[0] = TrainingSet_create(0, 0, 0);
      ts_arr[1] = TrainingSet_create(0, 1, 0);
      ts_arr[2] = TrainingSet_create(1, 0, 0);
      ts_arr[3] = TrainingSet_create(1, 1, 1);
    }

    printf("Here's the training set, i.e. the thing I'm trying to learn:\n\n");

    for (int j = 0; j < numSets; j++) {
      TrainingSet_print(ts_arr[j]);
    }

    printf("\nNow for the learning part... Wish me luck!\n\n");

    train(numSets, ts_arr, sw, weights, bias, totalError, epochs);

    printf("And here's where I show what I've learnt:\n\n");

    printf("\tTest [0 0] %d\n", calc_output(sw, weights, 0, 0, bias));
    printf("\tTest [0 1] %d\n", calc_output(sw, weights, 0, 1, bias));
    printf("\tTest [1 0] %d\n", calc_output(sw, weights, 1, 0, bias));
    printf("\tTest [1 1] %d\n\n", calc_output(sw, weights, 1, 1, bias));

    for (int k = 0; k < numSets; k++) {
      TrainingSet_destroy(ts_arr[k]);
    }

    free(bias);
    free(totalError);
  }

  return 0;
}
