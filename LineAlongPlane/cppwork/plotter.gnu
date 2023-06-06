unset label
unset terminal
set pointsize 0.75
set yrange [-2.0:2.0]
unset xrange
set key top right
set key font ",30"
set lmargin 15
set bmargin 7
set tics font ", 15"
set xlabel 'x' font ",30" offset 0,-1.0,0
set ylabel 'Overdensity' font ",30" offset -3.0,0,0


plot "lineAlongPlane_t20.txt" with lines title "t = 20"
set out