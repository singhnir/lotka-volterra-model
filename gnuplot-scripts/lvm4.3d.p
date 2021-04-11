set terminal png size 1000,700
set output "3d.png"
set key font ",16"
set grid

set title "Phase Space Plot with Two Predators and One Prey"
set xlabel "x(t)"
set ylabel "y_1(t)"
set zlabel "y_2(t)"
splot "lvm4.txt" u 2:3:4 w l lc 7 t ""
