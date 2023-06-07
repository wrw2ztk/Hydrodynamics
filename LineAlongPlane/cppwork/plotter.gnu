unset label
unset terminal
set pointsize 0.75
unset yrange
unset xrange
set key top right
set key font ",30"
set lmargin 15
set bmargin 7
set tics font ", 15"
set xlabel 'x' font ",30" offset 0,-1.0,0
set ylabel 'Overdensity' font ",30" offset -3.0,0,0


plot "lineAlongPlane_t50.txt" with lines title "t = 50"
set out