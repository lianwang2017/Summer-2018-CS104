# CS104: Summer 2015
# Grading script for Homework 4
# Author: Aaron Cheney

# Run with the command: python hw4_checker.py
# Results will be placed in separate .txt files for each problem and will automatically
# open when the testing has been completed. 

import sys, os

# 1. The named database, as well as the named test cases. 
# 2. Options for valgrind.
# 3. Information about the student's code.
# 4. Your preferred text editor.
# 5. Option to remove .feed files when testing is complete. 

# 1. 
# The total number of command input files used for testing.
database = 'twitterLarge.dat'

test_names = [	'quit',
				'addTweet',
				'caseTestOR',
				'caseTestAND',
				'andSearchOneArg',
				'andSearchTwoArgs',
				'andSearchThreeArgs',
				'orSearchOneArg',
				'orSearchTwoArgs',
				'orSearchThreeArgs']

solution_executable = 'twitter_solution'

# 2. 
# OS Commands for running with valgrind. 
valgrind = "valgrind --tool=memcheck --leak-check=yes"
use_valgrind = bool(0) # Change to bool(1) to run with valgrind.

# 3. 
# The name of the executable that is created, as well as a list of the
# source files needed to compile in case a proper makefile is not provided.  
executable = 'twitter'
student_source_files = 'twiteng.cpp user.cpp tweet.cpp datetime.cpp util.cpp'
executable_path = './'

# 4. 
# Your preferred text editor. 
text_editor = "subl" # Or subl, gedit, etc.

# 5. 
# Remove .feed files
remove_feed = bool(1) # Change to bool(0) if you want to keep the .feed files. 



# Lists where the names of the files are stored. 
results = []
solution_files = []
output_files = []
users = []

# Populates the above lists with the properly named files. 
with open(database, 'r') as data:
	number_of_users = int(data.readline().strip())
	while number_of_users:
		user_line = data.readline().strip()
		user_list = user_line.split()
		users.append(user_list[0])
		number_of_users -= 1
for i in range(0, len(test_names)):
	results.append('results_' + test_names[i] + '.txt')
	solution_files.append([])
	for j in range(0, len(users)):
		solution_files[i].append(users[j] + '_' + test_names[i] + '.feed')

# Use if a makefile is provided, otherwise use the next line.
os.system('make')
# os.system('g++ -g -Wall ' + student_source_files + ' -o ' + executable)

# Runs all tests, and places results into output files according to the name of each test. 
number_of_failed_tests = 0
os.system('rm results_*.txt')
for i in range(0, len(test_names)):
	result_file = open(results[i], 'a')
	result_file.write('*++++++++++++++++++++++++++++++++++++++++*')
	result_file.write('\nCOMMAND FILE:\n\n')
	with open(test_names[i] + '.cmd') as command_file:
		commands = command_file.read().strip()
		result_file.write(commands)
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*\n\n\n\n\n')
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*\nSolution Console Output:\n')
	os.system('./' + solution_executable + ' ' + database + ' < ' + test_names[i] + '.cmd > temp.temp')
	with open('temp.temp') as temp:
		solution_console = temp.read().strip()
		result_file.write(solution_console)
		result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*\n\n\n\n\n')
	for j in range(0, len(users)):
		os.system('mv ' + users[j] + '.feed ' + users[j] + '_' + test_names[i] + '.feed')
	number_of_failed_feeds = 0
	if use_valgrind:
		os.system(valgrind + ' ' + executable_path + executable + ' ' + database + ' < ' + test_names[i] + '.cmd > temp.temp')
	else:
		os.system(executable_path + executable + ' ' + database + ' < ' + test_names[i] + '.cmd > temp.temp')
	result_file.write('*++++++++++++++++++++++++++++++++++++++++*\nStudent Console Output:\n')
	with open('temp.temp') as temp:
		student_console = temp.read().strip()
		result_file.write(student_console)
		result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*\n\n\n\n\n')
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*')
	result_file.write('\nFEED FILE RESULTS:\n')
	for j in range(0, len(users)):
		result_file.write('\n\n' + users[j] + '.feed:\n')
		if os.path.exists(users[j] + '.feed'):
			with open(users[j] + '.feed', 'r') as student_output, open(solution_files[i][j], 'r') as truth_output:
				student_line = student_output.readline().strip()
				solution_line = truth_output.readline().strip()
				number_of_failed_lines = 0
				while student_line and solution_line:
					if solution_line != student_line:
						number_of_failed_lines += 1
						result_file.write('\nINCORRECT: ' + student_line)
						result_file.write('\n\tEXPECTED: ' + solution_line)
					else:
						result_file.write('\nCORRECT: ' + student_line)
					student_line = student_output.readline().strip()
					solution_line = truth_output.readline().strip()
				result_file.write('\n\nResults for ' + users[j] + '.feed:')
				if number_of_failed_lines != 0:
					number_of_failed_feeds += 1
					result_file.write('\nFailed to find ' + str(number_of_failed_lines) + ' lines.\n')
				else:
					result_file.write('\nPassed test.\n')
		else:
			result_file.write('\nFailed to find ' + users[j] + '.feed output file.\n')
			number_of_failed_feeds += 1
	if number_of_failed_feeds != 0:
		result_file.write('\n\n\nFailed ' + str(number_of_failed_feeds) + 
						  ' feed files out of ' + str(len(users)) + ' total.')
	else:
		result_file.write('\n\n\nPassed all feed tests.')
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*\n\n\n\n\n')
	number_of_failed_feeds = 0
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*')
	result_file.write('\nTWEETS FOUND RESULTS:\n')
	for j in range(0, len(users)):
		number_of_failed_tweets = 0
		number_of_extra_tweets = 0
		result_file.write('\n\n' + users[j] + '.feed:\n')
		if os.path.exists(users[j] + '.feed'):
			with open(users[j] + '.feed', 'r') as student_output, open(solution_files[i][j], 'r') as truth_output:
				student_set = set()
				student_line = student_output.readline().strip()
				while student_line:
					student_set.add(student_line)
					student_line = student_output.readline().strip()

				solution_line = truth_output.readline().strip()
				while solution_line:
					if solution_line in student_set:
						result_file.write('\nFOUND: ' + solution_line)
						student_set.remove(solution_line)
					else:
						result_file.write('\nMISSING: ' + solution_line)
						number_of_failed_tweets += 1
					solution_line = truth_output.readline().strip()
				while len(student_set):
					result_file.write('\nEXTRA: ' + student_set.pop())
					number_of_extra_tweets += 1
				
				if (number_of_failed_tweets != 0) and (number_of_extra_tweets != 0):
					result_file.write('\n\nMissing ' + str(number_of_failed_tweets) + ' tweets and there are ' + str(number_of_extra_tweets) + ' extra tweets.\n')
					number_of_failed_feeds += 1
				elif (number_of_failed_tweets == 0) and (number_of_extra_tweets != 0):
					result_file.write('\n\n' + str(number_of_extra_tweets) + ' extra tweets were generated, but all correct tweets found.\n')
					number_of_failed_feeds += 1
				elif (number_of_failed_tweets != 0) and (number_of_extra_tweets == 0):
					result_file.write('\n\nMissing ' + str(number_of_failed_tweets) + ' tweets, but no extra tweets were generated.\n')
					number_of_failed_feeds += 1
				else:
					result_file.write('\n\nFound all tweets, and no extra tweets were generated.\nPassed test.\n')
		else:
			result_file.write('\nFailed to find ' + users[j] + '.feed output file.\n')
			number_of_failed_feeds += 1
	if number_of_failed_feeds != 0:
		result_file.write('\n\n\nFailed ' + str(number_of_failed_feeds) + 
					  ' feed files out of ' + str(len(users)) + ' total.')
	else:
		result_file.write('\n\n\nPassed all tweet tests.')
	result_file.write('\n*++++++++++++++++++++++++++++++++++++++++*')
	result_file.close()

for i in range(0, len(test_names)):
	os.system(text_editor + ' ' + results[i])

os.system('rm temp.temp')

if remove_feed:
	os.system('rm *.feed')