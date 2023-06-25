#ifndef __EXO2_H__
#define __EXO2_H__

#define TEST 500
float P(float *X, int n, float *p);

int I_Bernoulli(float p);
void exo2EspVar(float p);
int Geometric(float p);
int ReductGeoArray(int *array);
int *Geometric_Array(float p);
int *ReArrangedGeo(int *array, int n);

float verifyFloatPoisson();
int Poisson_Law(float lambda);
int *Array_Poisson(float lambda);

float verifyFloatExp();
float Exponential(float lambda);
float law_Exponential(float lambda, float x);
float *Array_Exponential(float lambda);

#endif