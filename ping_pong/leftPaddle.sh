#!/bin/bash


terminal="/dev/pts/11"
while true;
do
  pos=$(cat $terminal | head -n 1)
  if [ $pos -lt 0 ]; then
    echo "d" > $terminal
  else
    echo "u" > $terminal
  fi


  echo "current position:" $pos
done
