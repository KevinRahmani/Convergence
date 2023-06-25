#!/bin/bash

a=-1    #var a is the exercise
b=-1    #var b is the question
f="result/use.dat" #real data file


#function to get parameters
exercice () {
   a=$( sed -n '1p' result/data.dat | cut -d ' ' -f1 )
}

question () {
    b=$(sed -n '1p' result/data.dat | cut -d ' ' -f2 )
}

proba () {
    p=$(sed -n '1p' result/data.dat | cut -d ' ' -f3)
}

redirect () {
    sed '1d' result/data.dat > $f
}

reset () {
    if [ -d result ]
    then 
        rm -rf result
    fi
    mkdir result 
}

graphique () {  
    echo "set terminal jpeg size 800,600" > gnuplot_script
    echo "set output 'graphe.jpeg'" >> gnuplot_script
}

#exercise 1 =


exo1q1 () {
    echo "set title 'Simulation Loi de Bernoulli avec p = $p'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Effectif'" >> gnuplot_script
    echo "set xr [-1:2]" >> gnuplot_script
    echo "set xtics -1,1,2" >> gnuplot_script
    echo "set yr [0:2]" >> gnuplot_script
    echo "set ytics 0,1,1" >> gnuplot_script
    echo "set boxwidth 1" >> gnuplot_script
    echo "set style fill solid 1 border 0" >> gnuplot_script
    echo "plot '$f' with histograms title 'Valeur'" >> gnuplot_script
}

exo1q2 () {
    n=$(sed -n '1p' result/data.dat | cut -d ' ' -f4)
    echo "set title 'Moyenne des effectifs de la Loi Binomiale pour 1000 simulations avec p = $p et n = $n'" >> gnuplot_script
    echo "set xlabel 'Nombre de succes'" >> gnuplot_script
    echo "set ylabel 'Effectif succes'" >> gnuplot_script
    echo "set xr [0:$maxX+10]" >> gnuplot_script
    echo "set yr [0:$max+15]" >> gnuplot_script
    echo "set boxwidth 1" >> gnuplot_script
    echo "set style fill solid 1 border 0" >> gnuplot_script
    echo "plot '$f' with histograms" >> gnuplot_script
}

exo1q3 () {
    echo "set title 'Simulation de la Loi Geometrique avec p = $p'" >> gnuplot_script
    echo "set xlabel 'Nombre d essais avant succes'" >> gnuplot_script
    echo "set ylabel 'Effectif'" >> gnuplot_script
    echo "set xr [0:$maxX]" >> gnuplot_script
    echo "set yr [0:$max+10]" >> gnuplot_script     
    echo "set boxwidth 1" >> gnuplot_script
    echo "set style fill solid 1 border 0" >> gnuplot_script
    echo "plot '$f' with histograms" >> gnuplot_script
}

exo1q4 () {
    echo "set title 'Simulation de la Loi Uniforme Discrète avec k = $p'" >> gnuplot_script
    echo "set xlabel 'Nombre d essais (X)'" >> gnuplot_script
    echo "set ylabel 'Frequence moyenne pour 100000 simulations'" >> gnuplot_script
    echo "set style fill solid 1 border 0" >> gnuplot_script
    echo "set yr [0:$max*2]" >> gnuplot_script
    echo "set xr [-1:$maxX]" >> gnuplot_script
    echo "plot '$f' with histograms" >> gnuplot_script
}

exo1q5 () {
    echo "set title 'Simulation de la Loi Uniforme Continue entre [-1;1]'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Effectifs moyens'" >> gnuplot_script
    echo "set yrange [0:1]" >> gnuplot_script
    echo "set xrange [-3:3]" >> gnuplot_script
    echo "set key off" >> gnuplot_script
    echo "plot '$f' using 1:2 with boxes, [-1:1] 0.5 with l lw 3 lc 2, [-3:-1] 0 with l lw 3 lc 2, [1:3] 0 with l lw 3 lc 2" >> gnuplot_script
    #fonction densité : 1/2 sur [-1,1], O sinon
}

#EXERCISE 2

exo2q3 () {
    echo "set title 'Simulation de la Loi de Poisson'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Effectif'" >> gnuplot_script
    echo "set xr [-1:$maxX]" >> gnuplot_script
    echo "set yr [0:$max+10]" >> gnuplot_script
    echo "set boxwidth 1" >> gnuplot_script
    echo "set style fill solid 1 border 0" >> gnuplot_script
    echo "plot '$f' with histograms" >> gnuplot_script
}

exo2q4 () {
    lambda=$(sed -n '1p' result/data.dat | cut -d' ' -f3)
    echo "set title 'Simulation de la Loi Exponentielle par inversion'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Densité de probabilité" >> gnuplot_script
    echo "plot '$f' using 1:2 with impulses" >> gnuplot_script
}

#EXERCISE 3

exo3q1 () {
    echo "set title 'Courbe représentative de Sn/n pour Xi suivant la loi uniforme en fonction de n'" >> gnuplot_script
    echo "set xlabel 'n'" >> gnuplot_script
    echo "set ylabel 'Valeur de Sn/n'" >> gnuplot_script
    echo "set xr [1:$maxX]" >> gnuplot_script
    echo "set yr [0:1]" >> gnuplot_script
    echo "plot '$f' with lines, 0.5" >> gnuplot_script
}

exo3q2 () {
    lambda2=$(sed -n '1p' result/data.dat | cut -d' ' -f3)
    echo "set title 'Courbe représentative de Sn/n pour Xi'" >> gnuplot_script
    echo "set xlabel 'n'" >> gnuplot_script
    echo "set ylabel 'Valeur de Sn/n'" >> gnuplot_script
    echo "set xr [1:$maxX]" >> gnuplot_script
    echo "set yr [0:$max+1]" >> gnuplot_script
    echo "plot '$f' with lines, $lambda2" >> gnuplot_script
}

exo3q3 () {
    echo "set title 'Courbe représentative de Sn/n pour Xi suivant f(x) = 2x'" >> gnuplot_script
    echo "set xlabel 'n'" >> gnuplot_script
    echo "set ylabel 'Valeur de Sn/n'" >> gnuplot_script
    echo "set xr [1:$maxX]" >> gnuplot_script
    echo "set yr [0:$max+1]" >> gnuplot_script
    echo "plot '$f' with lines, 0.5" >> gnuplot_script
}



#EXERCISE 4

exo4q1 () {
    echo "set title 'Simulation du TCL à partir de U[0;1]'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Effectifs moyens'" >> gnuplot_script
    echo "set yr [0:0.5]" >> gnuplot_script
    echo "set xrange [-5:5]" >> gnuplot_script
    echo "set key off" >> gnuplot_script
    echo "plot '$f' using 1:2 with impulses title 'TCL'" >> gnuplot_script
}

exo4q2 () {
    echo "set title 'Convergence en loi vers la loi gaussienne'" >> gnuplot_script
    echo "set xlabel 'x'" >> gnuplot_script
    echo "set ylabel 'Effectifs moyens de l evenement {Zn<x}'" >> gnuplot_script
    echo "unset key" >> gnuplot_script
    echo "set yrange [0:1]" >> gnuplot_script
    echo "set xrange [-5:5]" >> gnuplot_script
    echo "plot '$f' using 1:2 with boxes, (0.5 + 0.5*erf(x/sqrt(2))) lw 3" >> gnuplot_script
}

exo4q3 () {
    echo "set title 'Convergence en loi vers la loi gaussienne avec expo'" >> gnuplot_script
    echo "set xlabel 'x'" >> gnuplot_script
    echo "unset key" >> gnuplot_script
    echo "set ylabel 'Effectifs moyens de l evenement {Zn<x}'" >> gnuplot_script
    echo "set xrange [-5:5]" >> gnuplot_script  
    echo "set yrange [0:1]" >> gnuplot_script
    echo "plot '$f' using 1:2 with boxes , (0.5 + 0.5*erf(x/sqrt(2))) lw 3" >> gnuplot_script
}

exo4q4 () {
    echo "set title 'Convergence en loi vers la loi gaussienne avec f(x) = 2x'" >> gnuplot_script
    echo "set xlabel 'x'" >> gnuplot_script
    echo "unset key" >> gnuplot_script
    echo "set ylabel 'Effectifs moyens de l evenement {Zn<x}'" >> gnuplot_script
    echo "set xrange [-5:5]" >> gnuplot_script  
    echo "set yrange [0:1]" >> gnuplot_script
    echo "plot '$f' using 1:2 with boxes , (0.5 + 0.5*erf(x/sqrt(2))) lw 3" >> gnuplot_script
}
#EXERCISE 5

exo5q1 () {
    echo "set title 'Box-Muller'" >> gnuplot_script
    echo "set xlabel 'X'" >> gnuplot_script
    echo "set ylabel 'Probabilité'" >> gnuplot_script
    echo "set yrange [0:0.5]" >> gnuplot_script
    echo "set xrange [-4:4]" >> gnuplot_script
    echo "plot '$f' using 1:2 with impulses title 'Densité expérimental'" >> gnuplot_script
}