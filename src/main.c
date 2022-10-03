#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/perceptron.h"

/*
 * Follow the amazing adventures of our intrepid Binary Classifier as it attempts to learn and
 * perform the logical OR and AND functions!
 *
 * Author:  John Reynolds
 * Version: 16.01.22
 */

int main() {
  srand(time(NULL));

  const uint8_t num_weights = 2;
  const uint8_t num_training_sets = 4;
  const uint8_t num_epochs = 8;

  double bias, total_error;
  double weights[num_weights];

  TrainingSet *training_sets[num_training_sets];

  register uint8_t i = 0, j = 0;

  for (i = 0; i < 2; i++) {
    bias = 0.0, total_error = 0.0;

    if (i < 1) {
      puts("\n\nHi there! I'm a Perceptron. Watch me learn the logical OR function!\n");
      training_sets[0] = TrainingSet_create(0, 0, 0);
      training_sets[1] = TrainingSet_create(0, 1, 1);
      training_sets[2] = TrainingSet_create(1, 0, 1);
      training_sets[3] = TrainingSet_create(1, 1, 1);

    } else {
      puts("\nNOW watch me learn the logical AND function!\n");
      training_sets[0] = TrainingSet_create(0, 0, 0);
      training_sets[1] = TrainingSet_create(0, 1, 0);
      training_sets[2] = TrainingSet_create(1, 0, 0);
      training_sets[3] = TrainingSet_create(1, 1, 1);
    }

    puts("Here's the training set, i.e. the thing I'm trying to learn:\n");
    for (j = 0; j < num_training_sets; j++) {
      TrainingSet_print(training_sets[j]);
    }

    puts("\n\nNow for the learning part... Wish me luck!\n");
    train(num_training_sets, training_sets, num_weights, weights, &bias, &total_error, num_epochs);

    puts("\nAnd here's where I show what I've learnt:\n");
    printf("\tTest [0 0] %d\n", calc_output(num_weights, weights, 0, 0, &bias));
    printf("\tTest [0 1] %d\n", calc_output(num_weights, weights, 0, 1, &bias));
    printf("\tTest [1 0] %d\n", calc_output(num_weights, weights, 1, 0, &bias));
    printf("\tTest [1 1] %d\n\n", calc_output(num_weights, weights, 1, 1, &bias));

    for (j = 0; j < num_training_sets; j++) {
      TrainingSet_destroy(training_sets[j]);
    }
  }

  return 0;
}
