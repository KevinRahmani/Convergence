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

int verify_integer(){       //verify is input is a number
    char *str, *endPtr;
    long integerValue;
    bool test = false;
    do{
        str = readStdin();
        integerValue = strtol(str, &endPtr,10);
        if(endPtr == str){  
            printf("Veuillez rentrer un nombre entier svp");
        }else{
            if(integerValue < 1 || integerValue > 5000){
                printf("Retry pls (not extreme value)\n");
            }else{
                test = true;
            }
        }
    }while(test != true);

    return integerValue;

}

float verifyFloat(){        //verify if input is a float
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
            if(chosenFloat <  0.0 || chosenFloat > 1.0){
                printf("Veuillez reessayer correctement\n");
            }else{
                test = true;
            }
        }
    } while (test != true);
    
    return chosenFloat;
}

float rand_0_1(){           //return a random number between 0 and 1 
    return rand()/(RAND_MAX+1.0);
}

int verifyK(){          //verify if input is an integer and if its >= 2
    bool test = false;
    int k;
    do
    {
        k = verify_integer();
        if(k>=2){
            test = true;
        }
    }while(test != true);
    return k;
}

int Reduct(int *array, int n){
    int position = 0;
    for(int i=n-1;i>=0;i--){
        if(array[i] != 0){
            position = i; // return last index which value isnt null
            break;
        }
    }
    return position+1;
}
/*-------------------------------------------------BERNOULLI------------------------------------------------*/
int Bernoulli(float p){         //return 0 if failure, 1 if success
    float randomFloat = rand_0_1();
    if( randomFloat < p){
        return 1;
    }else{
        return 0;
    }
}

int *arrayBernoulli(int b){         //stock the result in an array
    int *array = calloc(2,sizeof(int));
    if( b == 0){
        array[0]++;
    }else{
        array[1]++;
    }
    return array;
}

/*------------------------------------------------------Binomiale---------------------------------------------------*/

int *Binomiale(int n, float p){         //gives the list of 0 and 1 resulting from the simulation
    int *array = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        array[i] = Bernoulli(p);
    }
    return array;
}

int *ArrangeBinomialArray2(int n, float p){
    int *binotab=malloc(n*sizeof(int));
    int su=0;
    int *success=calloc(n+1, sizeof(int));

    for (int i=0;i<1000;i++){
        binotab=Binomiale(n,p);
        
        for (int j=0;j<n;j++){
            su+=binotab[j];
        }

        success[su]+=1;
        su=0;
    }   

    return success;
}

/*------------------------------------------------------Geometric-----------------------------------------------------*/

int geom(float p){
    int re=0;

    while(Bernoulli(p) == 0){
        re++;
    }
    return re+1;
}                       

int *GeometricArray(float p){
    int *array = calloc(500, sizeof(int));
    int k = 0; //nb tirages avant succes
    for(int i=0; i<500; i++){ //on fait 500 tirages
        k= geom(p);
        array[k]++;
    }
    return array;
}


/*-------------------------------------------------Discrete Uniform Law ------------------------------------------------*/

int Uniform(int k){
    return 1+k*rand_0_1();
}

double *ReArrangedUniform(int n){
    int k=0, nbExp = 100000;
    double *array = calloc(n,sizeof(double));
    for(int i=0;i<nbExp;i++){
        k = Uniform(n);
        array[k-1]++;
    }
    for(int i=0;i<n;i++){
        array[i]/=nbExp;
    }    
    return array;
}


/*-------------------------------------------------Continue Uniform Law------------------------------------------------*/


float Uniform1_1(){
    return -1+2*rand_0_1();
}

void Uni_repartitionNormale(FILE *inputFile){

    double tailleInterval = 2, bars = 100, cpt = 0, count = 0;
    int nbExp = 100000;
    double esperance=0;
    double variance =0;
    //faire une liste chainée sur -1;1
    double interval = tailleInterval/bars; //separation intervalles
    Interval *inter = malloc(bars * sizeof(Interval));
    double *resultUni = malloc(nbExp*sizeof(double)); //utile uniquement pour le calcul de l'esperance et de la variance
    //initialise interval
    for(int i=0; i<bars;i++){
        inter[i].interval = cpt-1;
        cpt+=interval;
        inter[i].cpt = 0;
    }
    for(int j=0;j<nbExp;j++){
        //donne X~U(-1:1)
        double u = Uniform1_1(); 
        resultUni[j] = u;
        //parcours le tableau de struct
        for(int i=1; i<bars;i++){
            if(inter[i].interval >= u && inter[i-1].interval < u){
                inter[i-1].cpt++;
                break;
            }
        }
    }
    for(int i=0;i<bars;i++){
        inter[i].cpt/=nbExp;
        inter[i].cpt/=interval;
    }

    for(int i=0;i<bars;i++){
        fprintf(inputFile,"%lf %lf\n",inter[i].interval,inter[i].cpt);
    }

    //calculs de l'esperance et de la variance
    for (int i=0 ; i<nbExp ; i++){
        esperance += resultUni[i];

    }
    esperance /= nbExp;

    for (int i=0;i<nbExp;i++){
        variance += pow((resultUni[i]-esperance), 2);
    }
    variance /= (nbExp-1);
    printf("esperance : %lf\n", esperance);
    printf("variance : %lf\n", variance);
    free(inter);    
}

