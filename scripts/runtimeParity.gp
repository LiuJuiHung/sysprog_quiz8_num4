reset
set xlabel 'numerical distribution'
set ylabel 'times(nsec)'
set title 'performance analysis'
set term png enhanced font 'Times_New_Roman,12'
set output 'runtimeParity.png'

plot [:][:] 'parity.txt' using 1:2 with points title ''
