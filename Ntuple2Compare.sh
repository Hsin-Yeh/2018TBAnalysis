#!/bin/bash

ntuple_output=./output_root/
plot=root_plot/plot_
file=$( cut -d / -f 3 <<< $1 )

ls $1 > data_input.txt
./makePlots -n 0
ls ${ntuple_output}${file} > data_input.txt
./makePlots -m
ls ${plot}${file} > data_input.txt
root -q -b ./Compare_DataMC.C 


