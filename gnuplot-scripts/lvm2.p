set terminal png size 1500,750
set output "lvm2.png"
set multiplot layout 1,2 title "Lotka Volterra Model II" font ",18"
set grid

set title "Change in the population over time" font ",18"
set xlabel "time scale (t)" font ",18"
set ylabel "x(t) and y(t)" font ",18"
plot "lvm2.txt" u 1:2 w l lc 8 t "prey x(t)",'' u 1:3 w l lc 7 t "predator y(t)","" u 1:4 w l lc 1 t "prey x(t)",'' u 1:5 w l lc 2 t "predator y(t)"

set title "Phase Space for Prey-Predator System" font ",18"
set xlabel "prey population x(t)" font ",18"
set ylabel "predator population y(t)" font ",18"
set autoscale
plot "lvm2.txt" u 2:3 w l lc 8 t "x(0)=2, y(0)=1.3",'' u 4:5 w l lc 7 t "x(0)=0.5, y(0)=0.5"