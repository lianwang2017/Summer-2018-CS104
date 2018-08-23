#!/bin/bash
mkdir -p problem4_output
mkdir -p problem4_results
for i in {1..7}; do 
	./problem4 "duplicates$i.in" "problem4_output/student_output$i.out";
	diff "duplicates$i.out" "problem4_output/student_output$i.out" > "problem4_results/sol_diff$i.txt"; 
done; 
subl problem4_output problem4_results