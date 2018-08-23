# CS104 Summer 2015: Homework 7 Grading Script
# Run with the command: python checker_sat.py

import sys, os
sys.path.insert(0, '/')		# Adds the current directory to the system path so that the cs_grading
import cs_grading as CS 	# library of functions can be imported here. 

std_source_code = '../sat_solver.cpp'
std_executable = 'std_executable'

# General script information. Used to change which text editor you would like to use, whether or not to 
# run valgrind on the student's code, and whether to run specific tests. 
text_editor = 'subl'			# Change to your preferred text editor. 
use_valgrind = 1;				# Change to 1 to use valgrind. 
run_tests = 1				# Change to 0 to leave the scc test out of a run.
automatically_open_files = 1	# Change to 0 to turn of automatic opening of result files. 


# Information for testing strongly connected components.
input_files = ['test1.cnf', 			# The files which contain the student's output for
				'test2.cnf', 	# strongly connected components. These must be generated
				'test3.cnf', # from the student's front-end Qt GUI.
				'test4.cnf',
				'test5.cnf',
				'test6.cnf',
				'test7.cnf',
				'test8.cnf',
				'uf20-01.cnf',
				'uf20-07.cnf']

solution_files = ['test1.out', 			# The files which contain the student's output for
				  'test2.out', 	# strongly connected components. These must be generated
				  'test3.out', # from the student's front-end Qt GUI.
				  'test4.out',
				  'test5.out',
				  'test6.out',
				  'test7.out',
				  'test8.out',
				  'uf20-01.out',
				  'uf20-07.out']

student_output_files = ['test1_std.out', 			# The files which contain the student's output for
						'test2_std.out', 	# strongly connected components. These must be generated
						'test3_std.out', # from the student's front-end Qt GUI.
						'test4_std.out',
						'test5_std.out',
						'test6_std.out',
						'test7_std.out',
						'test8_std.out',
						'uf20-01_std.out',
						'uf20-07_std.out']

results_file = ['results_file1.txt',
				'results_file2.txt',
				'results_file3.txt',
				'results_file4.txt',
				'results_file5.txt',
				'results_file6.txt',
				'results_file7.txt',
				'results_file8.txt',
				'results_uf20-01.txt',
				'results_uf20-07.txt']

# Running test for strongly connected components.
if run_tests:
		# Removes previous results files. 
	CS.remove_file('results_*.txt')
	os.system('g++ -Wall -g -std=c++11 -o ' + std_executable + ' ' + std_source_code)

	# Iterates through all databased mentioned. 
	for i in range(0, len(input_files)):
		os.system('./' + std_executable + ' ' + input_files[i] + ' ' + student_output_files[i])
		errors = CS.compare_files_without_order(solution_files[i], student_output_files[i], results_file[i])
		#print '' + errors[0] + ' ' + errors[1]
		if errors[1] == 0 and errors[2] == 0:
			CS.write_message(results_file[i], '\n\nPASSED TEST')
		else:
			CS.write_message(results_file[i], '\n\nFAILED TEST')
		message = '\n\nThere were ' + str(errors[1]) + ' sets missing and ' + str(errors[2]) + ' extra sets.\n'
		CS.write_message(results_file[i], message)
		CS.write_footer(results_file[i])

if automatically_open_files:
	os.system(text_editor + ' results_*.txt')
