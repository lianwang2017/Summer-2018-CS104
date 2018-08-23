# Let's declare some variables
CC       = g++
CPPFLAGS = -Wall -g
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: problem4 problem5 problem6 problem7 problem8

problem4: ../remdup.cpp
	$(CC) $(CPPFLAGS) $< -o problem4

problem5: ../llistint.cpp gtest_llistint.cpp
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o problem5

problem6: ../alistint.cpp gtest_llistarray.cpp
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o problem6

problem7: ../stackint.cpp ../llistint.cpp gtest_stack.cpp
	$(CC) $(CPPFLAGS) $^ $(GTEST_LL) -o problem7

problem8: ../laundry.cpp ../stackint.cpp ../llistint.cpp
	$(CC) $(CPPFLAGS) $^ -o problem8

.PHONY: tests clean

clean:
	-@rm -rf problem4 problem5 problem6 problem7 problem8
	-@echo "--- All Clean!---"