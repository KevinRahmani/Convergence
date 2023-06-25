//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

//dependencies
#include "../h/exo1.h"
#include "../h/exo2.h"
#include "../h/exo3.h"
#include "../h/exo4.h"
#include "../h/exo5.h"
#include "../h/accueil.h"

#define TWO_PI 6.2831853071795864769252866

double BoxMuller()
{
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z0 = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return z0;
}

double Normal(double x){
    return (1/sqrt(TWO_PI))*exp(-0.5*(pow(x, 2.0)));
}

