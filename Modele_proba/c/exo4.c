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

float normale(){        //bonne simulation pour n environ egale a 12;
    const int n =12;
    float m = 0.5, ecart = 1/sqrt(12);
    float Sn = 0.0;
    for(int i=0; i<n; i++){
        Sn+=rand_0_1();
    }
    return (sqrt(n)/ecart)*((Sn/n)-m);
}

//faire la fonction de repartition ie : proba que X < inf a x sachant que x appartient a [-4;4]
void repartitionNormale(FILE *inputFile){

    double tailleInterval = 10, bars = 100, cpt = 0, count = 0;
    int nbExp = 1000;
    //faire une liste chainée sur -5;5
    double interval = tailleInterval/bars; //separation intervalles
    Interval *inter = malloc(bars * sizeof(Interval)); //inter[i].interval contient la valeur de b dans l'intervalle [-5,b] et inter[i].cpt contient le nombre de Zn dans [-5,b]
    //initialise interval
    for(int i=0; i<bars;i++){
        cpt+=interval;
        inter[i].interval = cpt-5;
        inter[i].cpt = 0;
    }
    for(int j=0;j<nbExp;j++){
        //donne X~N(0,1)
        double u = normale(); 
        for(int i=0; i<bars;i++){
            //P(X < x)
            if(u <= inter[i].interval){//inter[i-1].cpt
                inter[i].cpt+=1;   
            }
        }
    }
    for(int i=0;i<bars;i++){
        inter[i].cpt/=nbExp;
    }

    for(int i=0;i<bars;i++){
        fprintf(inputFile,"%lf %lf\n",inter[i].interval,inter[i].cpt);
    }

}

double expoNormale(float lambda){ 
    const int n = 12;
    float m = 1/lambda;     //m is the mean and stddev (ecart type)
    double Sn = 0.0;
    for(int i=0;i<n;i++){
        Sn+=Exponential(lambda);
    }
    return (double) (sqrt(n)/m)*((Sn/n)-m);
}


void ExprepartitionNormale(FILE *inputFile, float lambda){

    double tailleInterval = 10, bars = 100, cpt = 0, count = 0;
    int nbExp = 1000;
    //faire une liste chainée sur -5;5
    double interval = tailleInterval/bars; //separation intervalles
    Interval *inter = malloc(bars * sizeof(Interval));
    //initialise interval
    for(int i=0; i<bars;i++){
        cpt+=interval;
        inter[i].interval = cpt-5;
        inter[i].cpt = 0;
    }
    for(int j=0;j<nbExp;j++){
        //donne X~N(0,1)
        double u = expoNormale(lambda); 
        for(int i=0; i<bars;i++){
            //P(X < x)
            if(u <= inter[i].interval){//inter[i-1].cpt
                inter[i].cpt+=1;   
            }
        }
    }
    for(int i=0;i<bars;i++){
        inter[i].cpt/=nbExp;
    }

    for(int i=0;i<bars;i++){
        fprintf(inputFile,"%lf %lf\n",inter[i].interval,inter[i].cpt);
    }

}


double F_inv(){
    double u = rand_0_1();
    double x = sqrt(u);
    return x;
}

void F_repartitionNormale(FILE *inputFile){

    double tailleInterval = 10, bars = 100, cpt = 0, count = 0;
    int nbExp = 1000;
    //faire une liste chainée sur -5;5
    double interval = tailleInterval/bars; //separation intervalles
    Interval *inter = malloc(bars * sizeof(Interval));
    //initialise interval
    for(int i=0; i<bars;i++){
        cpt+=interval;
        inter[i].interval = cpt-5;
        inter[i].cpt = 0;
    }
    for(int j=0;j<nbExp;j++){
        //donne X~N(0,1)
        double u = F_inv(); 
        for(int i=0; i<bars;i++){
            //P(X < x)
            if(u <= inter[i].interval){//inter[i-1].cpt
                inter[i].cpt+=1;   
            }
        }
    }
    for(int i=0;i<bars;i++){
        inter[i].cpt/=nbExp;
    }

    for(int i=0;i<bars;i++){
        fprintf(inputFile,"%lf %lf\n",inter[i].interval,inter[i].cpt);
    }

}

