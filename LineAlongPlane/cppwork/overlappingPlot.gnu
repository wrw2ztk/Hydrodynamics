unset label
unset terminal
set pointsize 0.75
unset yrange
unset xrange
set key top right
set key font ",15"
set lmargin 15
set bmargin 7
set tics font ", 15"
set xlabel 'x' font ",30" offset 0,-1.0,0
set ylabel 'Overdensity' font ",30" offset -3.0,0,0


plot "lineAlongPlane_t0.txt" with lines title "t = 0", "lineAlongPlane_t1.txt" with lines title "= 1", "lineAlongPlane_t2.txt" with lines title "= 2", "lineAlongPlane_t3.txt" with lines title "= 3", "lineAlongPlane_t4.txt" with lines title "= 4", "lineAlongPlane_t5.txt" with lines title "= 5"#, "lineAlongPlane_t10.txt" with lines title "= 10", "lineAlongPlane_t20.txt" with lines title "= 20" 
set out