#!/bin/bash
# 구구단 (for, while, until 사용)

for dan in 2 3 4 5 6 7 8 9
do
    echo "=== ${dan}단 ==="
    i=1
    while [ $i -le 5 ]
    do
        echo "$dan x $i = $((dan * i))"
        i=$((i + 1))
    done
    until [ $i -gt 9 ]
    do
        echo "$dan x $i = $((dan * i))"
        i=$((i + 1))
    done
done
