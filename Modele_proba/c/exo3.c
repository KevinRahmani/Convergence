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



/*----------------------------------------question1----------------------------------------------------*/


float *uni(int N){
    float *X = malloc(N*sizeof(float)); //les X suivent la loi uniforme [0,1]
    float *Xmoy = malloc(N*sizeof(float));//valeurs de Sn/n en fonction de n (n allant de 1 a N)
    // On veut Xmoy[0]=X1/1, Xmoy[1]=(X1+X2)/2, Xmoy[2]=(X1+X2+X3)/3    
    
    X[0]=rand_0_1();
    Xmoy[0]=X[0]; // on a besoin d'initialiser Xmoy avant la boucle
    for (int i=1;i<N;i++){ //penser a bien faire aller les abscisses de 1 a N dans gnuplot
        X[i] = rand_0_1();
        Xmoy[i] = Xmoy[i-1]+X[i];
        Xmoy[i-1]=Xmoy[i-1]/i;
        
    }    
    Xmoy[N-1]=Xmoy[N-1]/N;
    return Xmoy;
}

/*----------------------------------------question2----------------------------------------------------*/

float *expo(float lambda, int N){
    float *X = Array_Exponential(lambda); // on réutilise la simulation de l'exercice 2
    float m = 1/lambda;
    float *Xmoy = malloc(N*sizeof(float));//valeurs de Sn/n en fonction de n (n allant de 1 a N)
    Xmoy[0]=X[0]; // on a besoin d'initialiser Xmoy avant la boucle
    for (int i=1;i<N;i++){ //penser a bien faire aller les abscisses de 1 a N dans gnuplot
        Xmoy[i] = Xmoy[i-1]+X[i];
        Xmoy[i-1]=Xmoy[i-1]/i;
        
    }
    Xmoy[N-1]=Xmoy[N-1]/N;
    return Xmoy;
}

/*----------------------------------------question3----------------------------------------------------*/

float *f2x(int N){
    float *X = malloc(N*sizeof(float)); //les X suivent la loi uniforme [0,1]
    float *Xmoy = malloc(N*sizeof(float));//valeurs de Sn/n en fonction de n (n allant de 1 a N)
    // On veut Xmoy[0]=X1/1, Xmoy[1]=(X1+X2)/2, Xmoy[2]=(X1+X2+X3)/3    
    
    X[0]=F_inv();
    Xmoy[0]=X[0]; // on a besoin d'initialiser Xmoy avant la boucle
    for (int i=1;i<N;i++){ //penser a bien faire aller les abscisses de 1 a N dans gnuplot
        X[i] = rand_0_1();
        Xmoy[i] = Xmoy[i-1]+X[i];
        Xmoy[i-1]=Xmoy[i-1]/i;
        
    }    
    Xmoy[N-1]=Xmoy[N-1]/N;
    return Xmoy;
}
