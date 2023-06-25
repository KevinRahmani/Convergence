//libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

//dependencies 
#include "../h/accueil.h"
#include "../h/exo1.h"
#include "../h/exo2.h"
#include "../h/exo3.h"
#include "../h/exo4.h"
#include "../h/exo5.h"


//global variables
#define _s1kb 1024  

char *readStdin() {     //get input from any sizestream and securize it 

    size_t s = _s1kb; 
    char c;
    char *input = malloc(sizeof(char) * s);
    char *curr = input, *tmp = NULL;
    while ((c = getchar()) != '\n' && c != EOF) {
        *curr++ = c;
        if ((curr - input) % _s1kb == 0) {
            s += _s1kb;
            if ((tmp = realloc(input, s * sizeof(char))) == NULL) {
                free(input);
                return NULL;
            }
            input = tmp;
        }
    }
    *curr = '\0';
    if ((tmp = realloc(input, (s + 1) * sizeof(char))) == NULL) {
        free(input);
        return NULL;
    }
    return input;
}

int verify(int a, int b){       //verify input between 2 numbers
    char *str;
    long choice;
    bool test = false;
    do
    {   
        str = readStdin();
        choice = strtol(str,NULL,10);
        if(choice < a || choice > b){
            printf("Choix invalide, veuillez rentrer un nombre entre %d et %d\n", a, b);
            
        }else{
            test = true;
        }
    } while (test != true);

    return choice;
}

void caseSwitch(int chosenExercise, FILE *inputFile){    //core function of the program which contains all the programs
    switch(chosenExercise){
        case 1: 
        {  
            printf("\nVous avez choisi l'exo 1 :\n\n1.Bernoulli parametre p\n2.Binomiale parametre n,p\n3.Geometrique parametre p\n4.Uniforme sur 1;k avec k=>2\n5.Uniforme sur -1:1 avec histogramme et densité\n");
            int chosenQuestion = verify(1,5);
            switch(chosenQuestion){
                case 1:
                {
                    printf("\nVous avez choisi la loi de Bernoulli, veuillez rentrer un flotant entre 0 et 1 qui représente la probabilité de réussite :\n");
                    float f = verifyFloat();
                    int *array = arrayBernoulli(Bernoulli(f));
                    fprintf(inputFile, "%d %d %f\n",chosenExercise,chosenQuestion, f);
                    for(int i = 0; i < 2;i++){
                        fprintf(inputFile, "%d\n",array[i]);
                    }
                    free(array);
                    break;
                }
                
                case 2: 
                {
                    printf("\nVous avez choisi la loi Binomiale, veuillez rentrer la probabilité de succes p et le nombre d'essai n :\n");
                    float p = verifyFloat();
                    int n = verify_integer();
                    int *finalArray = ArrangeBinomialArray2(n,p);
                    fprintf(inputFile, "%d %d %f %d\n",chosenExercise,chosenQuestion, p, n);
                    for(int i=0; i<=n; i++){
                        fprintf(inputFile,"%d\n", finalArray[i]);
                    }
                    free(finalArray);
                    break;
                }
                case 3: 
                {
                    printf("\nVous avez choisi la loi géométrique, veuillez rentrer la proba de succes p :\n");
                    float x = verifyFloat();
                    int *array = GeometricArray(x);
                    int n = ReductGeoArray(array); 
                    int *tab = ReArrangedGeo(array,n);
                    fprintf(inputFile, "%d %d %f\n",chosenExercise,chosenQuestion, x);
                    for(int i=0; i<=n; i++){
                        fprintf(inputFile,"%d\n", tab[i]);
                    }
                    free(array);
                    free(tab);
                    break;
                } 
                case 4: 
                {
                    printf("\nVous avez choisi la loi uniforme sur [1;k] avec k>=2, veuillez rentrer k\n");
                    int k =verifyK();
                    double *array=ReArrangedUniform(k);
                    fprintf(inputFile, "%d %d %d\n",chosenExercise,chosenQuestion, k);
                    for(int i=0; i<k; i++){
                        fprintf(inputFile,"%lf\n", array[i]);
                    }
                    free(array);
                    break;
                }
                case 5: 
                {
                    printf("Vous avez choisi la loi uniforme sur [-1;1]\n");
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    Uni_repartitionNormale(inputFile);
                    break;
                }
            }
            break;
        }     
        case 2: 
        {
            printf("\nVous avez choisi l'exo 2 :\n\n1.Bernoulli parametre p\n2.Loi Géométrique de paramètre p\n3.Loi de poisson avec paramètre lambda\n4.Loi Exponentielle de paramètre lambda\n");
            int chosenQuestion = verify(1,4);
            switch(chosenQuestion){
                case 1:
                {
                    printf("Veuillez rentrer la probabilité de la loi de Bernoulli\n");
                    float p =verifyFloat();                
                    int *array = arrayBernoulli(I_Bernoulli(p));
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i = 0; i < 2;i++){
                        fprintf(inputFile, "%d\n",array[i]);
                    }
                    exo2EspVar(p);
                    break;
                }
                case 2:
                {
                    printf("\nVous avez choisi la loi géométrique, veuillez rentrer la proba de succes p :\n");
                    int *array = Geometric_Array(verifyFloat());
                    int n = ReductGeoArray(array); 
                    int *tab = ReArrangedGeo(array,n);
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i=0; i<n; i++){
                        fprintf(inputFile,"%d\n", tab[i]);
                    }
                    break;
                }
                case 3:
                {
                    printf("Vous avez choisi la loi de Poisson, rentrer lambda\n");
                    int *array=Array_Poisson(verifyFloatPoisson());
                    int n = ReductGeoArray(array); 
                    int *tab = ReArrangedGeo(array,n);
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i=0; i<n; i++){
                        fprintf(inputFile,"%d\n", tab[i]);
                    }
                    break;
                }
                case 4:
                {
                    printf("Vous avez choisi la loi exponentielle, veuillez rentrer le flottant lambda\n");
                    float lambda = verifyFloatExp();
                    double esperance=0;
                    double variance=0;
                    fprintf(inputFile, "%d %d %f\n",chosenExercise,chosenQuestion, lambda);
                    float *x=malloc(10000*sizeof(float));
                    for(int i=0; i<10000; i++){
                        x[i] = Exponential(lambda);
                        float y = law_Exponential(lambda, x[i]);
                        esperance+= x[i];
                        fprintf(inputFile,"%f %f\n", x[i], y);
                    }
                    esperance/=10000;
                    for(int i=0; i<10000; i++){
                        variance += pow((x[i]-esperance),2);
                    }
                    variance/=9999;
                    printf("esperance : %lf\nvariance : %lf\n", esperance, variance);

                    break;  
                }
            }
            break;
        }    
        case 3: 
        {
            printf("\nVous avez choisi l'exo 3 :\n\n1.Simulation pour la loi uniforme pour N variables aléatoires\n2.Simulation pour la loi exponentielle\n3.Simulation pour des variables à densité par méthode d'inversion\n");
            int chosenQuestion = verify(1,3);
            switch(chosenQuestion){
                case 1:
                {
                    printf("On va simuler la loi uniforme pour N variables aléatoires\nOn prendra N = 1000\n");
                    int N=1000;
                    float *Xmoy = uni(N);
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i = 0; i < N;i++){
                        fprintf(inputFile, "%f\n",Xmoy[i]);
                    }
                    break;
                }
                case 2:
                {   
                    printf("On va simuler la loi expontentielle\nOn prendra N = 1000\n");
                    printf("Veuillez rentrer le flottant lambda\n");
                    float lambda = verifyFloat();
                    int N=1000;
                    float *Xmoy = expo(lambda, N);
                    fprintf(inputFile, "%d %d %f\n",chosenExercise,chosenQuestion, 1/lambda);
                    for(int i = 0;i<N;i++){
                        fprintf(inputFile, "%f\n",Xmoy[i]);
                    }
                    break;
                }
                case 3:
                {
                    printf("On va simuler f(x) = 2x\nOn prendra N = 1000\n");
                    int N = 1000;
                    float *Xmoy = f2x(N);
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i = 0;i<N;i++){
                        fprintf(inputFile, "%f\n",Xmoy[i]);
                    }
                    break;
                }
            }
            break;
        } 
        case 4: 
        {
            printf("\nVous avez choisi l'exo 4 :\n\n1.Loi Normale\n2.Convergence en loi\n3.Loi exponentielle\n4.Inversion de 2x\n");
            int chosenQuestion = verify(1,4);
            switch(chosenQuestion){
                case 1:
                {
                    printf("Vous avez choisi la simulation du TCL ie : bonnes simulations pour n environ 12\n");
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    for(int i=0;i<10000;i++){
                        double x = normale();
                        double y = Normal(x);
                        fprintf(inputFile, "%lf %lf\n",x, y);
                    }
                    break;
                }
                case 2:
                {
                    printf("Vous avez choisi la simulation de la convergence en loi\n");
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    repartitionNormale(inputFile);
                    break;
                }
                case 3:
                {
                    printf("Vous avez choisi la loi Expo, rentrer lambda\n");
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    float lambda = verifyFloatExp();
                    ExprepartitionNormale(inputFile, lambda);
                    break;
                }
                case 4:
                {
                    printf("Vous avez choisi f(x) = 2x sur [0;1]\n");
                    fprintf(inputFile, "%d %d\n",chosenExercise,chosenQuestion);
                    F_repartitionNormale(inputFile);
                    break;
                }
            }
            break;
        }
        case 5: 
        {
            printf("\nVous avez choisi l'exo 5 : Simulation de Box Muller avec la méthode de Box-Muller\n");
            fprintf(inputFile, "%d %d\n",chosenExercise,1);
            for(int i = 0; i < 10000; i++){
                double x = BoxMuller();
                double y = Normal(x);
                fprintf(inputFile, "%lf %lf\n", x, y);
            }
            break;
        }
    }
}
