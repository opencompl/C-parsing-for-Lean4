#!/bin/bash

for dir in ./Group*
do
  for nont in $dir/*
  do
    echo $(basename $nont),$(ls $nont | wc -l)
  done
done
