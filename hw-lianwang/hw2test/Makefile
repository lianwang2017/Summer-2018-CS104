CXX      = g++
CPPFLAGS = -g -Wall
ALL = testAddToEmptyList testAddToArrayList stackTest laundry

all: $(ALL)

testAddToEmptyList: testAddToEmptyList.cpp llistint.o
	$(CXX) $(CPPFLAGS) $^ -o $@

llistint.o: llistint.cpp llistint.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

testAddToArrayList: testAddToArrayList.cpp alistint.o
	$(CXX) $(CPPFLAGS) $^ -o $@

alistint.o: alistint.cpp alistint.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

stackTest: stackTest.cpp stackint.o llistint.o
	$(CXX) $(CPPFLAGS) $^ -o $@

stackint.o: stackint.cpp stackint.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

laundry: laundry.cpp stackint.o llistint.o
	$(CXX) $(CPPFLAGS) $^ -o $@