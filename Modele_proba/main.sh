#!/bin/bash

source fonction.sh

if [ $# -eq 0 ]
then 
    reset
    gcc main.c c/accueil.c c/exo1.c c/exo2.c c/exo3.c c/exo4.c c/exo5.c -lm -o main 
    ./main
    redirect
    exercice
    question
    graphique
    proba
    max=$(sort -nr $f | sed -n '1p')
    maxX=$(wc -l $f | cut -d' ' -f1)
    case $a in  #exo
        1)      
            case $b in  #question
                1)
                    exo1q1
                    ;;
                2)
                    exo1q2
                    ;;
                3)
                    exo1q3
                    ;;
                4)
                    exo1q4
                    ;;
                5)
                    exo1q5
                    ;;
            esac
            ;;
        2)
            case $b in
                1)
                    exo1q1
                    ;;
                2)
                    exo1q3
                    ;;
                3)
                    exo2q3
                    ;;
                4)
                    exo2q4
                    ;;
            esac
            ;;
        3)
            case $b in 
                1)
                    exo3q1
                    ;;

                2)
                    exo3q2
                    ;;
                3)
                    exo3q3
                    ;;

            esac
            ;;
        4)
            case $b in 
                1)
                    exo4q1
                    ;;
                2)
                    exo4q2
                    ;;
                3)
                    exo4q3
                    ;;
                4)
                    exo4q4
                    ;;

            esac
            ;;
        5)
            case $b in 
            1)
                exo5q1  
                ;;
            esac
            ;;
    esac

else
    echo "Veuillez reessayer en appelant 0 argument"
fi

gnuplot gnuplot_script
mv graphe.jpeg result
rm gnuplot_script
rm result/data.dat