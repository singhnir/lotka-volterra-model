set terminal png size 1200,600
set output "lvm1.png"
set multiplot layout 1,2 title "Lotka Volterra Model I" font ",16"
set grid

set title "Change in the population over time" font ",16"
set xlabel "time scale (t)" font ",16"
set ylabel "x(t) and y(t)" font ",16"
plot "lvm.txt" u 1:2 w l lc 8 t "prey x(t)",'' u 1:3 w l lc 7 t "predator y(t)"

set title "Phase Space for Prey-Predator System" font ",16"
set xlabel "prey population x(t)" font ",16"
set ylabel "predator population y(t)" font ",16"
set autoscale
plot "lvm.txt" u 2:3 w dots lc 7 t "x(0) > y(0)",'' u 4:5 w dots lc 8 t "x(0) = y(0)",'' u 6:7 w dots lc 2 t "x(0) < y(0)"