#ifndef __EXO1_H__
#define __EXO1_H__

float rand_0_1();
float verifyFloat();
int verifyK();
int verify_integer();
int Reduct(int *array, int n);

int Bernoulli(float successProbability);
int *arrayBernoulli(int b);

int *Binomiale(int n, float p);
int *ArrangeBinomialArray2(int n, float p);

int geom(float p);
int *GeometricArray(float p);

int Uniform(int k);
double *ReArrangedUniform(int n);

float Uniform1_1();
void Uni_repartitionNormale(FILE *inputFile);

#endif