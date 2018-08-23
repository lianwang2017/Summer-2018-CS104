CXX      = g++
CPPFLAGS = -g -Wall
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread
ALL = copytest settest majors

all: $(ALL)

copytest: copytest.cpp lliststr.o
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

lliststr.o: lliststr.cpp lliststr.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

settest: settest.cpp setstr.o lliststr.o
	$(CXX) $(CPPFLAGS) $^ $(GTEST_LL) -o $@

setstr.o: setstr.cpp setstr.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

majors: majors.cpp setstr.o lliststr.o
	$(CXX) $(CPPFLAGS) $^ -o $@