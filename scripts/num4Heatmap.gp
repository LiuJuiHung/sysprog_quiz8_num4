reset
set xlabel 'time'
set ylabel 'times(nsec)'

set title 'performance analysis'
set term png enhanced font 'Times_New_Roman,12'
set output 'num4.png'

plot [0:][0:] 'num4_heatmap.txt' using 1:2 with point title ''
