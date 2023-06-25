#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "h/accueil.h"
#include "h/exo1.h"



int main(int argc, char *argv[]){

    srand(time(NULL));
    FILE *inputFile = fopen("result/data.dat", "w+");
    if(inputFile == NULL){
        printf("Error opening");
        exit(1);
    }
    printf("Bonjour, vous avez lancé le TP de Simulation noté de Kevin RAHMANI, Tess Czaplinski et Yixin Liang\nVeuillez choisir l'exercice que vous voulez tester\n\n1.Simulation de variable aléatoire de loi\n2.Simulation par inversion\n3.Simulation LGN\n4.Simulation TCL\n5.Simulation Méthode de Box Muller\n");
    int chosenExercise = verify(1,5);
    caseSwitch(chosenExercise, inputFile);
    fclose(inputFile);

    return 0;
}