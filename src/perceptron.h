#ifndef perceptron_h__
#define perceptron_h__

extern struct TrainingSet *TrainingSet_create(int i1, int i2, int op);
extern void TrainingSet_destroy(struct TrainingSet *ts);
extern void TrainingSet_print(struct TrainingSet *ts);
extern void initialise_weights(int sw, double *w, double *b);
extern double dot_product_bias(int sw, double *w, int si, double *inp,
                               double *b);
extern int calc_output(int sw, double *w, double i1, double i2, double *b);
extern void update_weights(struct TrainingSet **tsa, int sw, double *w,
                           double *b, double *te, int j);
extern void train(int ns, struct TrainingSet **tsa, int sw, double *w,
                  double *b, double *te, int e);

#endif // perceptron_h__
