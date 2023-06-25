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


//float *p ==> tableau qui contient les probabilités des évènements pk= P(X=k)
//n nb essais
//X = x1,x2,x3 support de X

/*--------------------------------------Inversion----------------------------------------------*/


float P(float *X, int n, float *p){
    int i=1;
    float u = rand_0_1(),F=p[0],x;

    while(i<n && u>F){
        i++;
        F+=p[i];
    }
    if(u>F){
        printf("x indefini\n");
        exit(0);
    }else{
        x=X[i];
    }
    return x;
}

/*--------------------------------------BERNOULLI----------------------------------------------*/
int I_Bernoulli(float p){
    int x;
    float u = rand_0_1();
    if(u>=1-p){
        return x=1;
    }else{
        return x=0;
    }

    
}

void exo2EspVar(float p){
    double esperance =0;
    double variance =0;
    float *resultBer=malloc(1000 * sizeof(int));
    float u;
    for (int i=0 ; i<1000 ; i++){
        resultBer[i]=I_Bernoulli(p);
        esperance += resultBer[i];
    }
    esperance/=1000;
    for (int i=0 ; i<1000 ; i++){
        variance += pow((resultBer[i]-esperance),2);

    }    
    variance/=(1000-1);

    printf("esperance : %lf\nvariance : %lf\n", esperance, variance);
}




/*--------------------------------------Geometric----------------------------------------------*/

int Geometric(float p){
    int x = 1;
    float pk = p, u = rand_0_1(), F = pk;
    while(u > F){
        x++;
        pk*=(1-p);
        F+=pk;
    }
    return x;
}

int ReductGeoArray(int *array){
    int position = 0;
    for(int i=500;i>0;i--){
        if(array[i] != 0){
            position = i+1; // return last index which value isnt null
            break;
        }
    }
    return position;
}

int *Geometric_Array(float p){
    int *array = calloc(500, sizeof(int));
    int k = 0; //nb tirages avant succes
    for(int i=0; i<500; i++){ //on fait 500 tirages
        k= Geometric(p);
        array[k]++;
    }
    return array;
}

int *ReArrangedGeo(int *array, int n){
    int *reArranged = malloc(n * sizeof(int));
    for(int l = 0;l<n;l++){
        reArranged[l]=array[l];
    }
    return reArranged;
}

/*--------------------------------------Poisson----------------------------------------------*/
float verifyFloatPoisson(){        //verify if input is a float
    char *str, *endPtr;
    float chosenFloat;
    bool test = false;
    do
    {
        str = readStdin();
        chosenFloat = strtof(str,&endPtr);
        if( endPtr == str){
            printf("Veuillez reessayer correctement svp\n");
        }else{
            if(chosenFloat <  0.0){
                printf("Veuillez reessayer correctement\n");
            }else{
                test = true;
            }
        }
    } while (test != true);
    
    return chosenFloat;
}


int Poisson_Law(float lambda){  //calculate the probability

    int x=0;
    float u =rand_0_1(), pk = exp(-lambda), F = pk;

    while(u>F){
        x++;
        pk = pk * lambda/x;
        F+=pk;
    }
    return x;
}

int *Array_Poisson(float lambda){       //put 500 probability in an array
    int *array=calloc(TEST,sizeof(int));
    int k=0;
    for(int i=0;i<TEST;i++){
        k=Poisson_Law(lambda);
        array[k]++;
    }
    return array;
}

/*--------------------------------------Exp----------------------------------------------*/

float verifyFloatExp(){        //verify if input is a float
    char *str, *endPtr;
    float chosenFloat;
    bool test = false;
    do
    {
        str = readStdin();
        chosenFloat = strtof(str,&endPtr);
        if( endPtr == str){
            printf("Veuillez reessayer correctement svp\n");
        }else{
            test = true;
        }
    } while (test != true);
    
    return chosenFloat;
}

float Exponential(float lambda){  //return x 
    float u = rand_0_1();
    return -log(1-u)/lambda;
}

float law_Exponential(float lambda, float x){   //return probability of exponential law
    return lambda*exp(-lambda*x);
}

float *Array_Exponential(float lambda){
    double esperance=0;
    double variance=0;
    float *array=malloc(10000*sizeof(float));
    for(int i=0;i<10000;i++){
        array[i] = Exponential(lambda);
    }
    return array;
}