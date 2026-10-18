#!/bin/bash
# 피보나치 수열 (let, expr 사용)
# 사용법: ./fibonacci.sh 개수

n=${1:-10}
a=0
b=1
i=0

echo -n "피보나치 수열($n개): "
while [ $i -lt $n ]
do
    echo -n "$a "
    c=`expr $a + $b`
    a=$b
    b=$c
    let i=i+1
done
echo
