#!/bin/bash

read -r -p 'Dictionary: ' -s "DICTION" && echo "$DICTION"
read -r -p 'Grid: ' -s "GRID" && echo "$GRID"

RUN1=`./a.out "$DICTION" "$GRID" | tail -1`
RUN2=`./a.out "$DICTION" "$GRID" | tail -1`
RUN3=`./a.out "$DICTION" "$GRID" | tail -1`
RUN4=`./a.out "$DICTION" "$GRID" | tail -1`
RUN5=`./a.out "$DICTION" "$GRID" | tail -1`

AVG= expr "($RUN1+$RUN2+$RUN3+$RUN4+$RUN5)/5" | bc

echo $AVG
