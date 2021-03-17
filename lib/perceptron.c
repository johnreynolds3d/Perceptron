#include "headers/perceptron.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TrainingSet *TrainingSet_create(int i1, int i2, int op) {

  struct TrainingSet *ts = malloc(sizeof(struct TrainingSet));
  assert(ts != NULL);

  ts->inputs[0] = i1;
  ts->inputs[1] = i2;
  ts->output = op;

  return ts;
}

void TrainingSet_destroy(struct TrainingSet *ts) {
  assert(ts != NULL);
  free(ts);
}

void TrainingSet_print(struct TrainingSet *ts) {
  printf("\t[%d %d] %d\n", ts->inputs[0], ts->inputs[1], ts->output);
}

void initialise_weights(int sw, double *w, double *b) {

  for (int i = 0; i < sw; i++) {
    w[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
  }

  *b = (double)rand() / RAND_MAX * 2.0 - 1.0;
}

double dot_product_bias(int sw, double *w, int si, double *inp, double *b) {

  if (w == NULL || inp == NULL) {
    return 1;
  }

  if (sw != si) {
    return 1;
  }

  double d = 0;

  for (int i = 0; i < sw; i++) {
    d += w[i] * inp[i];
  }

  d += *b;
  return d;
}

int calc_output(int sw, double *w, double i1, double i2, double *b) {

  double inp[] = {i1, i2};
  double dp =
      dot_product_bias(sw, w, (int)(sizeof(inp) / sizeof(double)), inp, b);

  return (dp > 0) ? 1 : 0;
}

void update_weights(struct TrainingSet **tsa, int sw, double *w, double *b,
                    double *te, int j) {

  double error = tsa[j]->output -
                 calc_output(sw, w, tsa[j]->inputs[0], tsa[j]->inputs[1], b);

  *te += fabs(error);

  for (int i = 0; i < sw; i++) {
    w[i] = w[i] + error * tsa[j]->inputs[i];
  }

  *b += error;
}

void train(int ns, struct TrainingSet **tsa, int sw, double *w, double *b,
           double *te, int e) {

  printf("I start out by setting my weights and bias to random numbers between "
         "-1 and 1:\n\n");

  initialise_weights(sw, w, b);

  printf("\tWeights: %9f  %9f    Bias: %9f\n\nThen the training begins...\n\n",
         w[0], w[1], *b);

  for (int i = 0; i < e; i++) {

    printf("\tEpoch %d:\n", i + 1);

    *te = 0;

    for (int j = 0; j < ns; j++) {
      update_weights(tsa, sw, w, b, te, j);
      printf("\tWeights: %9f  %9f    Bias: %9f\n", w[0], w[1], *b);
    }

    printf("\tTotal Error: %d\n\n", (int)*te);
  }
}
