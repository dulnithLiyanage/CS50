#!/bin/bash

alogrithm=$1
file=$2

time $alogrithm $file | tail --lines 0
