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
set xlabel 't' font ",30" offset 0,-1.0,0
set ylabel 'Net Charge x > 0' font ",30" offset -3.0,0,0


plot "netChargeEvolution.txt" with lines title ""
set out