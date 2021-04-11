set terminal png size 1000,700
set output "lvm4.png"
set grid

set title "Lotka Volterra with two predators\nChange in the population over time" font ",16"
set xlabel "time scale (t)" font ",16"
set ylabel "x(t), y_1(t) and y_2(t)" font ",16"
set xrange [-10:500]
set yrange [-0.2:2.5]
plot "lvm.txt" u 1:2 w l lc 8 t "prey x(t)",'' u 1:3 w l lc 1 t "predator y_1(t)",'' u 1:4 w l lc 7 t "predator y_2(t)"