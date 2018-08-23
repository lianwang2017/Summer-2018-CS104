#!/bin/bash
mkdir -p problem8_output
mkdir -p problem8_results
for i in {1..6}; do 
	./problem8 "laundry$i.in" "problem8_output/student_output$i.out";
	diff "laundry$i.out" "problem8_output/student_output$i.out" > "problem8_results/sol_diff$i.txt"; 
done; 
subl problem8_output problem8_results