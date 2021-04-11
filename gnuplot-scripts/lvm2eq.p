set terminal png size 1200,600
set output "lvm2eq.png"
set multiplot layout 1,2 title "LVM II : Equilibrium State" font ",14"
set grid

set title "Change in the population over time" font ",16"
set xlabel "time scale (t)" font ",16"
set ylabel "x(t) and y(t)" font ",16"
set yrange [0.8:2.1]
plot "equi.txt" u 1:2 w l lc 8 lw 2 t "prey x(t)",'' u 1:3 w l lc 7 lw 2 t "predator y(t)"
set title "Phase Space for Prey-Predator System" font ",16"
set xlabel "prey population x(t)" font ",16"
set ylabel "predator population y(t)" font ",16"
set autoscale
plot "equi.txt" u 2:3 pt 26 lw 4 lc 8 t ""