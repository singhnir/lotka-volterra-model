set terminal png size 1200,600
set output "multi.png"
set multiplot layout 1,2 title "Lotka Volterra Model with two predators" font ",16"
set key off
set grid

set title "Phase Space Plot (Prey-Predator-1)" font ",16"
set xlabel "prey population x(t)" font ",16"
set ylabel "predator-1 population y_1(t)" font ",16"
set autoscale
plot "lvm.txt" u 2:3 w l lc 7

set title "Phase Space Plot (Prey-Predator-2)" font ",16"
set xlabel "prey population x(t)" font ",16"
set ylabel "predator-2 population y_2(t)" font ",16"
plot "lvm.txt" u 2:4 w l lc 8