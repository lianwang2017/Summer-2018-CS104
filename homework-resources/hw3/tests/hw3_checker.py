# CS104: Summer 2015
# Grading script for Homework 3
# Author: Aaron Cheney

# Run with the command: python hw3_checker.py
# Results will be placed in separate .txt files for each problem and will automatically
# open when the testing has been completed. 

import sys, os

# Grading Script Options:
# 1. Turn tests on/off, or change how many tests are run.
# 2. Set flags for Google Test to run specific tests.
# 3. Valgrind and Google Test compilation commands.
# 4. Change the names of the executables, source code file names, and the
#    student's Google Test file names. 
# 5. Change the executable path for each problem. If everything compiles
#    but the executable is not run, make sure the path is correct. 
# 6. Run valgrind with the tests. 
# 7. Change your preffered text editor for automatic opening. 

# 1. 
# Each entry corresponds to problem 2 through 5.
# Use 1 to run the test for that problem, or change to 0 to turn it off.
run_tests = [1, 1, 1, 1]
# The number of tests for each problem (only change the last index).
number_of_tests = [0, 0, 0, 6]

# 2. 
# Flags for running the Google Tests.
# https://code.google.com/p/googletest/wiki/AdvancedGuide#Running_a_Subset_of_the_Tests
# --gtest_filter=*Good*:*Bad* will run all tests with Good or Bad in the name
# --gtest_filter=*Good*:-*Bad* will run all tests with Good and filter out Bad
# --gtest_filter=*Speed* will run only tests with Speed in the title. 
# --gtest_filter=* will run all tests. 
gtest_lliststr_flags = '--gtest_filter=*Good*:*Bad*'
gtest_setstr_flags = '--gtest_filter=*Good*:*Bad*'

# OS Commands for running with valgrind and gtest. 
valgrind = "valgrind --tool=memcheck --leak-check=yes"
gtest = "-I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread"
gtest_lliststr = "gtest_lliststr.cpp"
gtest_setstr = "gtest_setstr.cpp"

# 4. 
# The name of the executables for the student's code. The first, third,
# and fourth entries are given the names we asked for in their makefile
# instructions. Problem 3 does not have instructions for the makefile,
# so it does not have a unique name. 
student_executables =  ['copytest', 'problem3', 'settest', 'majors']
# The source files needed for each problem, in case a makefile is not provided. 
student_source_files = ['lliststr.cpp',
                        'lliststr.cpp setstr.cpp',
                        'lliststr.cpp setstr.cpp',
                        'majors.cpp setstr.cpp lliststr.cpp']
# The student's Google Tests files for the lliststr and setstr classes.
student_gtest_llist = 'lliststr_test.cpp'
student_gtest_set   = 'setstr_test.cpp'

# 5. 
# Path to executables. Student's makefile should create executables
# for problems 2, 4, and 5. Change accordingly to where those executables
# are placed. 
executable_paths = ['./bin/', './', './bin/', './']

# 6. 
# Toggle valgrind on/off.
use_valgrind = bool(0) # Change to bool(1) to run with valgrind.

# 7. 
# Put your preferred text editor here. 
text_editor = "subl" # Or subl, gedit, etc.

# List of the results files for each problem.
results = ['results2.txt', 'results3.txt', 'results4.txt', 'results5.txt']
# The names of the different tests for problem 5. The number of entries in this
# list should match the total number of tests for problem 5. 

major_tests = ['caseTest', 
			   'commaTest', 
			   'multiMajors',
               'multiLineMajors',
			   'oneSpaceTest', 
			   'oneTabTest', 
			   'twoSpaceTest']
input_files = []
command_files = []
output_files = []
solution_files = []

# Populates the above lists with the properly named files. 
for i in range(0, len(number_of_tests)):
    input_files.append([])
    command_files.append([])
    output_files.append([])
    solution_files.append([])
    for j in range(0, number_of_tests[i]):
        input_files[i].append(major_tests[j] + '.in')
        command_files[i].append(major_tests[j] + '.cmd')
        output_files[i].append('student_' + major_tests[j] + '.out')
        solution_files[i].append(major_tests[j] + '.out')

# Creates executables and runs tests for each problem. 
if run_tests[0]: 
    os.system("make copytest")
    # os.system("g++ -g -Wall " + student_source_files[0] + " " + student_gtest_llist + " " + gtest + " -o " + student_executables[0])
    os.system("g++ -g -Wall " + student_source_files[0] + " " + gtest_lliststr + " " + gtest + " -o " + student_executables[0] + "_test")
    if use_valgrind:
        os.system(valgrind + " " + executable_paths[0] + student_executables[0] + " > student_" + results[0])
        os.system(valgrind + " " + "./" + student_executables[0] + "_test " + gtest_lliststr_flags + " > " + results[0])
    else:
        os.system(executable_paths[0] + student_executables[0] + " > student_" + results[0])
        os.system("./" + student_executables[0] + "_test " + gtest_lliststr_flags + " > " + results[0])

if run_tests[1]:
    os.system("g++ -g -Wall " + student_source_files[1] + " " + gtest_setstr + " " + gtest + " -o " + student_executables[1])
    if use_valgrind:
        os.system(valgrind + " " + executable_paths[1] + student_executables[1] + " " + gtest_setstr_flags + " > " + results[1])
    else:
        os.system(executable_paths[1] + student_executables[1] + " " + gtest_setstr_flags + " > " + results[1])

if run_tests[2]:
    os.system("make settest")
    # os.system("g++ -g -Wall " + student_source_files[2] + " " + student_gtest_set + " " + gtest + " -o " + student_executables[2])
    if use_valgrind:
        os.system(valgrind + " " + executable_paths[2] + student_executables[2] + " > " + results[2])
    else:
        os.system(executable_paths[2] + student_executables[2] + " > " + results[2])

if run_tests[3]:
    os.system("make majors")
    # os.system("g++ -g -Wall " + student_source_files[3] + " -o " + student_executables[3])
    for i in range(0, number_of_tests[3]):
        if use_valgrind:
            os.system(valgrind + " " + executable_paths[3] + student_executables[3] + " " + input_files[3][i] + " " + command_files[3][i] + " " + output_files[3][i])
        else:
            os.system(executable_paths[3] + student_executables[3] + " " + input_files[3][i] + " " + command_files[3][i] + " " + output_files[3][i])


# Performs a check of the student's output for problem 5, which looks to see 
# that they are putting the right categories together. The order of the 
# students is independent. 
if run_tests[3]:
    test_count = 0
    result_file = open(results[3], "w")
    result_file.write("Running tests for problem 5\n\n")
    for i in range(0, number_of_tests[3]):
        testfile = open(output_files[3][i], 'r')
        truthfile = open(solution_files[3][i], 'r')

        extra_students = 0
        missing_students = 0

        result_file.write("*** Test Case " + input_files[3][i] + " ***\n\n")
        result_file.write("Student Matching:\n")

        solution_names = []
        solution_names.append(set())
        number_of_solution_sets = 0
        for line in truthfile:
            if line.strip() != '':
                line = line.strip()
                solution_names[number_of_solution_sets].add(line)
            else:
                solution_names.append(set())
                number_of_solution_sets += 1

        student_names = []
        student_names.append(set())
        number_of_student_sets = 0
        for line in testfile:
            if line.strip() != '':
                line = line.strip()
                student_names[number_of_student_sets].add(line)
            else:
                student_names.append(set())
                number_of_student_sets += 1

        for i in range(0, len(student_names)):
            while(len(student_names[i])):
                line = student_names[i].pop()
                if line in solution_names[i]:
                    result_file.write("FOUND: " + line + "\n")
                    solution_names[i].remove(line)
                else:
                    result_file.write("EXTRA: " + line + "\n")
                    extra_students += 1
            while(len(solution_names[i])):
                line = solution_names[i].pop()
                result_file.write("MISSING: " + line + "\n")
                missing_students += 1 
            result_file.write('\n')

        truthfile.seek(0)
        testfile.seek(0)
        data_truth = truthfile.read()
        data_test = testfile.read()

        result_file.write("\n------------------\n")
        result_file.write("Student Output:\n")
        result_file.write(data_test)
        result_file.write("\n------------------\n")
        result_file.write("Correct Solution:\n")
        result_file.write(data_truth)
        result_file.write("\n------------------\n")

        if (missing_students == 0) and (extra_students == 0):
            result_file.write("PASSED TEST\n")
            result_file.write("Found all students in the correct sections.\n")
            result_file.write("Still need to visually verify the major is printed at the top of each section.\n")
        elif (missing_students != 0) and (extra_students == 0):
            result_file.write("FAILED TEST\n")
            result_file.write("Some students missing, but no extra students generated.\n")
            result_file.write("Still requires visual verification.\n")
            test_count += 1
        elif (missing_students == 0) and (extra_students != 0):
            result_file.write("FAILED TEST\n")
            result_file.write("All correct students found, but extra students were printed.\n")
            result_file.write("Still requires visual verification.\n")
            test_count += 1
        else:
            result_file.write("FAILED TEST\n")
            result_file.write("Extra students were printed, and students are missing from sections.\n")
            result_file.write("Requires visual verification.\n")
            test_count += 1

        result_file.write("\n")
        testfile.close()
        truthfile.close()

    if test_count == 0:
        result_file.write("PASSED ALL TESTS")
    else:
        result_file.write("FAILED " + str(test_count) + " tests out of " + str(number_of_tests[3]))
        result_file.write("\nMay require manual check of output\n")
    result_file.close()

if run_tests[0]:
    os.system(text_editor + " " + results[0])
    os.system(text_editor + " student_results2.txt")
if run_tests[1]:
    os.system(text_editor + " " + results[1])
if run_tests[2]:
    os.system(text_editor + " " + results[2])
if run_tests[3]:
    os.system(text_editor + " " + results[3])
