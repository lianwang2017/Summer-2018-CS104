#include "setstr.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

class SetStrTest : public testing::Test {
protected:
	SetStrTest() {
		// You can do set-up work for each test here.
	}

	virtual ~SetStrTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
};

TEST_F(SetStrTest, General) {
	SetStr set;

	// Check if set is empty
	EXPECT_EQ(0, set.size());
	EXPECT_EQ(true, set.empty());

	// Inserting item
	set.insert("Test item 1");
	EXPECT_EQ(1, set.size());
	EXPECT_EQ(true, set.exists("Test item 1"));
    
    //cout << "insertion complete" << endl;

	// Remove bogus item
	set.remove("Bogus item");
	EXPECT_EQ(1, set.size());
    EXPECT_EQ(true, set.exists("Test item 1"));
    
    //cout << "removal 1 complete" << endl;

	// Remove actual item
	set.remove("Test item 1");
	EXPECT_EQ(0, set.size());
    EXPECT_EQ(false, set.exists("Test item 1"));
    
    //cout << "removal 2 complete" << endl;
}

TEST_F(SetStrTest, FirstAndNext) {
	SetStr set;
	
	// Check if set is empty
	EXPECT_EQ(0, set.size());
	EXPECT_EQ(true, set.empty());

	// Inserting item
	set.insert("Test item 1");
	set.insert("Test item 2");
	set.insert("Test item 3");
	set.insert("Test item 4");


	// Check first and next, make sure it resets on first
	EXPECT_EQ("Test item 1", *(set.first()));
	EXPECT_EQ("Test item 2", *(set.next()));
	EXPECT_EQ("Test item 3", *(set.next()));
	EXPECT_EQ("Test item 4", *(set.next()));

	EXPECT_EQ("Test item 1", *(set.first()));
	EXPECT_EQ("Test item 2", *(set.next()));
	EXPECT_EQ("Test item 3", *(set.next()));
	EXPECT_EQ("Test item 4", *(set.next()));

	// // Removing an item
	set.remove("Test item 2");
	EXPECT_EQ("Test item 1", *(set.first()));
	set.remove("Test item 4");
	EXPECT_EQ("Test item 3", *(set.next()));
}

TEST_F(SetStrTest, SetUnionTwoUnique) {
	// Populate set1
	SetStr set1;
	set1.insert("Set1 test item 1");
	set1.insert("Set1 test item 2");
	set1.insert("Set1 test item 3");
	set1.insert("Set1 test item 4");

	// Populate set2
	SetStr set2;
	set2.insert("Set2 test item 1");
	set2.insert("Set2 test item 2");
	set2.insert("Set2 test item 3");
	set2.insert("Set2 test item 4");


	// Check size for 8 unique elements
    SetStr set3 = set1.setUnion(set2);
    EXPECT_EQ(8, set3.size());

	// Check values
	EXPECT_EQ("Set1 test item 1", *(set3.first()));
	EXPECT_EQ("Set1 test item 2", *(set3.next()));
	EXPECT_EQ("Set1 test item 3", *(set3.next()));
	EXPECT_EQ("Set1 test item 4", *(set3.next()));
	EXPECT_EQ("Set2 test item 1", *(set3.next()));
	EXPECT_EQ("Set2 test item 2", *(set3.next()));
	EXPECT_EQ("Set2 test item 3", *(set3.next()));
	EXPECT_EQ("Set2 test item 4", *(set3.next()));
}

TEST_F(SetStrTest, SetUnionTwoSame) {
	SetStr set1;
	set1.insert("Set test item 1");
	set1.insert("Set test item 2");
	set1.insert("Set test item 3");
	set1.insert("Set test item 4");

	SetStr set2;
	set2.insert("Set test item 1");
	set2.insert("Set test item 2");
	set2.insert("Set test item 3");
	set2.insert("Set test item 4");

	// Check size for 4 unique elements
	SetStr set3 = set1.setUnion(set2);
	EXPECT_EQ(4, set3.size());
	EXPECT_EQ("Set test item 1", *(set3.first()));
	EXPECT_EQ("Set test item 2", *(set3.next()));
	EXPECT_EQ("Set test item 3", *(set3.next()));
	EXPECT_EQ("Set test item 4", *(set3.next()));
}

TEST_F(SetStrTest, SetUnionTwoSimilar) {
	SetStr set1;
	set1.insert("Set test item 1");
	set1.insert("Set test item 2");
	set1.insert("Set test item 3");
	set1.insert("Set test item 4");

	SetStr set2;
	set2.insert("Set test item 1");
	set2.insert("Set test item 2");
	set2.insert("Set test item 5");
	set2.insert("Set test item 6");

	// Check size for 4 unique elements
	SetStr set3 = set1.setUnion(set2);
	EXPECT_EQ(6, set3.size());
	EXPECT_EQ("Set test item 1", *(set3.first()));
	EXPECT_EQ("Set test item 2", *(set3.next()));
	EXPECT_EQ("Set test item 3", *(set3.next()));
	EXPECT_EQ("Set test item 4", *(set3.next()));
	EXPECT_EQ("Set test item 5", *(set3.next()));
	EXPECT_EQ("Set test item 6", *(set3.next()));
}


TEST_F(SetStrTest, SetIntersectionTwoUnique) {
	SetStr set1;
	set1.insert("Set1 test item 1");
	set1.insert("Set1 test item 2");
	set1.insert("Set1 test item 3");
	set1.insert("Set1 test item 4");

	SetStr set2;
	set2.insert("Set2 test item 1");
	set2.insert("Set2 test item 2");
	set2.insert("Set2 test item 3");
	set2.insert("Set2 test item 4");

	// Check size for 8 unique elements
	SetStr set3 = set1.setIntersection(set2);
	EXPECT_EQ(0, set3.size());
}

TEST_F(SetStrTest, SetIntersectionTwoSame) {
	SetStr set1;
	set1.insert("Set test item 1");
	set1.insert("Set test item 2");
	set1.insert("Set test item 3");
	set1.insert("Set test item 4");

	SetStr set2;
	set2.insert("Set test item 1");
	set2.insert("Set test item 2");
	set2.insert("Set test item 3");
	set2.insert("Set test item 4");

	// Check size for 8 unique elements
	SetStr set3 = set1.setIntersection(set2);
	EXPECT_EQ(4, set3.size());
	EXPECT_EQ("Set test item 1", *(set3.first()));
	EXPECT_EQ("Set test item 2", *(set3.next()));
	EXPECT_EQ("Set test item 3", *(set3.next()));
	EXPECT_EQ("Set test item 4", *(set3.next()));
}

TEST_F(SetStrTest, SetIntersectionTwoSimilar) {
	SetStr set1;
	set1.insert("Set test item 1");
	set1.insert("Set test item 2");
	set1.insert("Set test item 3");
	set1.insert("Set test item 4");

	SetStr set2;
	set2.insert("Set test item 1");
	set2.insert("Set test item 2");
	set2.insert("Set test item 5");
	set2.insert("Set test item 6");

	// Check size for 8 unique elements
	SetStr set3 = set1.setIntersection(set2);
	EXPECT_EQ(2, set3.size());
	EXPECT_EQ("Set test item 1", *(set3.first()));
	EXPECT_EQ("Set test item 2", *(set3.next()));
}

TEST_F(SetStrTest, SetUnionFromOperatorOverload) {
	// Populate set1
	SetStr set1;
	set1.insert("Set1 test item 1");
	set1.insert("Set1 test item 2");
	set1.insert("Set1 test item 3");
	set1.insert("Set1 test item 4");

	// Populate set2
	SetStr set2;
	set2.insert("Set2 test item 1");
	set2.insert("Set2 test item 2");
	set2.insert("Set2 test item 3");
	set2.insert("Set2 test item 4");

	// Check size for 8 unique elements
	SetStr set3 = set1 | set2;
	EXPECT_EQ(8, set3.size());

	// Check values
	EXPECT_EQ("Set1 test item 1", *(set3.first()));
	EXPECT_EQ("Set1 test item 2", *(set3.next()));
	EXPECT_EQ("Set1 test item 3", *(set3.next()));
	EXPECT_EQ("Set1 test item 4", *(set3.next()));
	EXPECT_EQ("Set2 test item 1", *(set3.next()));
	EXPECT_EQ("Set2 test item 2", *(set3.next()));
	EXPECT_EQ("Set2 test item 3", *(set3.next()));
	EXPECT_EQ("Set2 test item 4", *(set3.next()));
}

TEST_F(SetStrTest, SetIntersectionFromOperatorOverload) {
	SetStr set1;
	set1.insert("Set test item 1");
	set1.insert("Set test item 2");
	set1.insert("Set test item 3");
	set1.insert("Set test item 4");

	SetStr set2;
	set2.insert("Set test item 1");
	set2.insert("Set test item 2");
	set2.insert("Set test item 3");
	set2.insert("Set test item 4");

	// Check size for 8 unique elements
	SetStr set3 = set1 & set2;
	EXPECT_EQ(4, set3.size());
	EXPECT_EQ("Set test item 1", *(set3.first()));
	EXPECT_EQ("Set test item 2", *(set3.next()));
	EXPECT_EQ("Set test item 3", *(set3.next()));
	EXPECT_EQ("Set test item 4", *(set3.next()));
}