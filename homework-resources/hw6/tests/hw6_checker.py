# CS104 Summer 2018: Homework 6 Grading Script
# Run with the command: python hw6_checker.py

import sys
import subprocess
import os
sys.path.insert(0, '/')		# Adds the current directory to the system path so that the cs_grading
import cs_grading as CS 	# library of functions can be imported here. 

# General script information. Used to change which text editor you would like to use, whether or not to 
# run valgrind on the student's code, and whether to run specific tests. 
text_editor = 'subl'			# Change to your preferred text editor. 
use_valgrind = 1;				# Change to 1 to use valgrind. 
run_heap_test = 1				# Change to 0 to leave the heap test out of a run.
run_scc_test = 1				# Change to 0 to leave the scc test out of a run.
automatically_open_files = 1	# Change to 0 to turn of automatic opening of result files. 

# Problem 2: m-ary Heaps.
if run_heap_test:
        CS.run_gtest(
	        output_file_name_base = 'heap',                 # Do not change.
	         source_files = 'gtest_heap.cpp',       # Do not change.
	                flags = '-g -Wall -std=c++11',  # Flags use for compilation.
	         use_valgrind = 1,                      # Change to 0 to turn off valgrind.
	         open_results = 1,                      # Change to 0 to stop result files from opening automatically.
	          clean_files = 1                       # Change to 0 if you don't want intermediary files cleaned up. 
)

# Information for testing strongly connected components.
scc_solution_executable = 'scc_solution'				# The name of the executable containing the solution
scc_databases = ['twitter', 							# The databases to check for strongly connected components. 
				 'twitterLarge', 
				 'twitterVeryLarge',
				 'twitterNew1',
				 'twitterNew2',
				 'twitterNew3']

scc_student_output_files = ['scc_twitter.out', 			# The files which contain the student's output for
							'scc_twitterLarge.out', 	# strongly connected components. These must be generated
							'scc_twitterVeryLarge.out', # from the student's front-end Qt GUI.
							'scc_twitterNew1.out',
							'scc_twitterNew2.out',
							'scc_twitterNew3.out']

student_executable = '../twitter'
# Running test for strongly connected components.
if run_scc_test:
	# Removes previous results files. 
	CS.remove_file('scc_results_*.txt')
	# Remove all previous student output files
	CS.remove_file('scc_*.out')
	print(os.getcwd())
	curr_dir = os.getcwd().strip().split('/')[-1]
	# Generate student twitter executable
	os.chdir('..')
	print(os.getcwd())
	os.system('make clean')
	os.system('make')
	os.chdir(str(curr_dir))
	os.system('rm -rf solution student_output results valgrind')
	os.system('mkdir solution student_output results valgrind')
	# Generate output files from student twitter run_executable
	for i in range(0, len(scc_databases)):
		os.system('touch scc.cmd')
		os.system('echo SCC ' + 'student_output/scc_' + scc_databases[i] + '.out ' + ' > ' + 'scc.cmd')
		os.system('echo QUIT >> scc.cmd')
		CS.run_executable('./', student_executable, scc_databases[i] + '.dat < scc.cmd', 1, 'valgrind/' + scc_databases[i] + '_valgrind.txt')
		os.system('rm scc.cmd')
	# clean up unnecessary files 
	os.system('rm *.feed *.mentions')
	# Iterates through all databased mentioned. 
	for i in range(0, len(scc_databases)):
		results_file = 'results/scc_results_' + scc_databases[i] + '.txt'

		# Runs the solution executable to generate the solution .out files
		CS.run_executable('./', scc_solution_executable, scc_databases[i] + '.dat solution/scc_solution_' + scc_databases[i] + '.out')
		
		# Compares the solution's files to the student's files and prints the results to its own section. 
		CS.write_header(results_file)
		CS.write_message(results_file, '\nCOMPARING SCC FILES:\n\n')
		errors = CS.compare_files_with_sets('solution/scc_solution_' + scc_databases[i] + '.out', 'student_output/' + scc_student_output_files[i], results_file, '', ignore_lines_with = 'Component')
		if errors[1] == 0 and errors[2] == 0:
			CS.write_message(results_file, '\n\nPASSED TEST')
		else:
			CS.write_message(results_file, '\n\nFAILED TEST')
		message = '\n\nThere were ' + str(errors[1]) + ' sets missing and ' + str(errors[2]) + ' extra sets.\n'
		CS.write_message(results_file, message)
		CS.write_footer(results_file)

		# Writes the solution file's strongly connected components for visual checks. 
		CS.write_header(results_file)
		CS.write_message(results_file, '\nSOLUTION SCC:\n\n')
		CS.write_file_contents(results_file, 'solution/scc_solution_' + scc_databases[i] + '.out')
		CS.write_footer(results_file)

		# Writes the student's strongly connected components file for visual checks. 
		CS.write_header(results_file)
		CS.write_message(results_file, '\nSTUDENT SCC:\n\n')
		CS.write_file_contents(results_file, 'student_output/' + scc_student_output_files[i])
		CS.write_footer(results_file)

	if automatically_open_files:
		CS.open_file('results/scc_results_*.txt valgrind/*.txt')

