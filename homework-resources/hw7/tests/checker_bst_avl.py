# CS104 Spring 2017: Homework 6 Grading Script
# Run with the command: python checker_bst_avl.py

import sys, os
sys.path.insert(0, '/')
import cs_grading as CS

# Problem 3: Binary Search Tree Iterators.
CS.run_gtest(
	output_file_name_base = 'bst',                  # Do not change.
	         source_files = 'bst_gtest.cpp',        # Do not change.
	                flags = '-g -Wall -std=c++11',  # Flags use for compilation.
	         use_valgrind = 1,                      # Change to 0 to turn off valgrind.
	         open_results = 1,                      # Change to 0 to stop result files from opening automatically.
	          clean_files = 1                       # Change to 0 if you don't want intermediary files cleaned up. 
)

# Problem 4: AVL Trees.
CS.run_gtest(
	output_file_name_base = 'avl',                  # Do not change.
	         source_files = 'avl_gtest.cpp',        # Do not change.
	                flags = '-g -Wall -std=c++11',  # Flags use for compilation.
	         use_valgrind = 1,                      # Change to 0 to turn off valgrind.
	         open_results = 1,                      # Change to 0 to stop result files from opening automatically.
	          clean_files = 1                       # Change to 0 if you don't want intermediary files cleaned up. 
)

