#ifndef __EXO4_H__
#define __EXO4_H__


typedef struct Interval Interval;
struct Interval {
    double interval;
    double cpt;
};

float normale();
void repartitionNormale(FILE *f);

double expoNormale(float lambda);
void ExprepartitionNormale(FILE *inputFile, float lambda);

double F_inv();
void F_repartitionNormale(FILE *inputFile);

#endif