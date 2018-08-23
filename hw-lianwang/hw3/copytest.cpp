#include "lliststr.h"
#include "gtest/gtest.h"

class LListStrTest : public testing::Test {
protected:
	LListStrTest() {
		// You can do set-up work for each test here.
	}

	virtual ~LListStrTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).

		// list.add(1);
		// list.add(2);
		// list.add(3);
		// list.add(4);
		// list.add(5);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	LListStr list;
};

TEST_F(LListStrTest, General) {
	// Check if list is empty
	EXPECT_EQ(0, list.size());
	EXPECT_EQ(true, list.empty());

	list.insert(0, "Hello");
	EXPECT_EQ("Hello", list.get(0));

	list.insert(1, " World\n");
	EXPECT_EQ(" World\n", list.get(1));

	// Check if list is empty
	EXPECT_EQ(2, list.size());

	// Test pushback
	list.push_back("Pushback");
	EXPECT_EQ(3, list.size());
	EXPECT_EQ("Pushback", list.get(2));

	// Test Remove
	list.remove(0);
	EXPECT_EQ(2, list.size());
	EXPECT_EQ(" World\n", list.get(0));
	EXPECT_EQ("Pushback", list.get(1));

	list.remove(1);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(" World\n", list.get(0));

	list.remove(0);
	EXPECT_EQ(0, list.size());
	EXPECT_EQ(true, list.empty());
}

TEST_F(LListStrTest, CopyConstructors) {
	list.insert(0, "Test item 1");
	list.push_back("Test item 2");
	list.push_back("Test item 3");
	EXPECT_EQ(3, list.size());

	// Use copy constructor to create new list2
	LListStr list2(list);
	EXPECT_EQ(3, list2.size());
	EXPECT_EQ("Test item 1", list2.get(0));
	EXPECT_EQ("Test item 2", list2.get(1));
	EXPECT_EQ("Test item 3", list2.get(2));

	// Remove original list
	list.remove(0);
	list.remove(0);
	list.remove(0);
	EXPECT_EQ(0, list.size());
	EXPECT_EQ(true, list.empty());

	// Check test2 to see if it still exists
	EXPECT_EQ("Test item 1", list2.get(0));
	EXPECT_EQ("Test item 2", list2.get(1));
	EXPECT_EQ("Test item 3", list2.get(2));
}

TEST_F(LListStrTest, AssignmentConstructor) {
	list.insert(0, "Test item 1");
	list.push_back("Test item 2");
	list.push_back("Test item 3");
	EXPECT_EQ(3, list.size());

	// Use copy constructor to create new list2
	LListStr list2(list);

	// Add new item to list2
	list2.push_back("Test item 4");

	// Use assignment operator to create new list3 from list2
	LListStr list3 = list2;

	// Remove list and list2
	list.remove(0);
	list.remove(0);
	list.remove(0);
	list2.remove(0);
	list2.remove(0);
	list2.remove(0);
	list2.remove(0);
	EXPECT_EQ(0, list.size());
	EXPECT_EQ(true, list.empty());
	EXPECT_EQ(0, list2.size());
	EXPECT_EQ(true, list2.empty());

	// Check test3 to see if it still exists
	EXPECT_EQ("Test item 1", list3.get(0));
	EXPECT_EQ("Test item 2", list3.get(1));
	EXPECT_EQ("Test item 3", list3.get(2));
	EXPECT_EQ("Test item 4", list3.get(3));
}