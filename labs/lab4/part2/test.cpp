#include "arraylist.h"
#include "gtest/gtest.h"

class ArrayListTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	ArrayListTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ArrayListTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		list.add(1);
		list.add(2);
		list.add(3);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	ArrayList list;
};

TEST_F(ArrayListTest, GetNominal) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	for (int i = 0 ; i < 3; i++) {
		EXPECT_EQ(i + 1, list.get(i));
	}
}

TEST_F(ArrayListTest, AddNominal) {
	list.add(4); list.add(5);
	EXPECT_EQ(5, list.size());
}

TEST_F(ArrayListTest, RemoveNominal) {
	list.remove(0);
	EXPECT_EQ(2, list.size());
	for (int i = 0; i < 2; i++) {
		EXPECT_EQ(i+2, list.get(i));
	}
}

// looking for undefined values in the fibonnaci
TEST_F(ArrayListTest, SetOffNominal) {
	list.set(0, 0);
	EXPECT_EQ(0, list.get(0));
	list.set(4, 8);
	EXPECT_EQ(8, list.get(4));
}
