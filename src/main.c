#include "../lib/headers/perceptron.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

  int num_weights = 2;
  int num_training_sets = 4;
  int num_epochs = 6;

  double weights[num_weights];

  struct TrainingSet *training_sets[num_training_sets];

  int i, j, k;

  for (i = 0; i < 2; i++) {

    double *bias = malloc(sizeof(double));
    double *total_error = malloc(sizeof(double));

    if (i < 1) {

      printf("\nHi there! I'm a Perceptron. Watch me learn the logical OR "
             "function!\n\n");

      training_sets[0] = TrainingSet_create(0, 0, 0);
      training_sets[1] = TrainingSet_create(0, 1, 1);
      training_sets[2] = TrainingSet_create(1, 0, 1);
      training_sets[3] = TrainingSet_create(1, 1, 1);

    } else {

      printf("\nNOW watch me learn the logical AND function!\n\n");

      training_sets[0] = TrainingSet_create(0, 0, 0);
      training_sets[1] = TrainingSet_create(0, 1, 0);
      training_sets[2] = TrainingSet_create(1, 0, 0);
      training_sets[3] = TrainingSet_create(1, 1, 1);
    }

    printf("Here's the training set, i.e. the thing I'm trying to learn:\n\n");

    for (j = 0; j < num_training_sets; j++) {
      TrainingSet_print(training_sets[j]);
    }

    printf("\nNow for the learning part... Wish me luck!\n\n");

    train(num_training_sets, training_sets, num_weights, weights, bias,
          total_error, num_epochs);

    printf("And here's where I show what I've learnt:\n\n");

    printf("\tTest [0 0] %d\n", calc_output(num_weights, weights, 0, 0, bias));
    printf("\tTest [0 1] %d\n", calc_output(num_weights, weights, 0, 1, bias));
    printf("\tTest [1 0] %d\n", calc_output(num_weights, weights, 1, 0, bias));
    printf("\tTest [1 1] %d\n", calc_output(num_weights, weights, 1, 1, bias));

    printf("\n");

    for (k = 0; k < num_training_sets; k++) {
      TrainingSet_destroy(training_sets[k]);
    }

    free(bias);
    free(total_error);
  }

  return 0;
}
