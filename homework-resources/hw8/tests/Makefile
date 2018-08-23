CXX=g++
CXXFLAGS=-g -Wall -std=c++11
FLAGS_DELUXE=-DDEBUG -fmax-errors=2
GTEST =-I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: tests

tests: 
	python hw8_checker.py 1 1 1 1 1

heap:
	python hw8_checker.py 1 0 0 0 0

trending:
	python hw8_checker.py 0 1 0 0 0

hash:
	python hw8_checker.py 0 0 1 0 0

usrpwd:
	python hw8_checker.py 0 0 0 1 0

splay:
	python hw8_checker.py 0 0 0 0 1
