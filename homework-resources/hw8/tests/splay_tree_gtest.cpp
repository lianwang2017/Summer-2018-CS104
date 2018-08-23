/*
	Google Test for splayTreeStringDoubleing a student's templated splay tree. The splay tree used for splayTreeStringDoubleing
	uses a string for the key and a double for the value. 

	Interface functions given for students to implement:

		void insert(const std::pair<Key, Value>& keyValuePair);
  		void clear();
  		iterator find(const Key& k);
*/

#include "gtest/gtest.h"
#include "../splay_tree.h"
#include <functional>

class SplayTest : public testing::Test 
{
	protected:
		SplayTest()
		{
	
		}

		~SplayTest() 
		{

		}

		virtual void SetUp() 
		{
			
		}

		virtual void TearDown() 
		{

		}

		SplayTree<std::string, double> splayTreeStringDouble;
};

// Tests behavior for find on an empty tree. Should be equal to the 
// end of the tree. 
TEST_F(SplayTest, FindOnEmptyTree)
{
	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.find("AAA");
	EXPECT_EQ(it, splayTreeStringDouble.end());
}

// Tests the case for ZigLeft. Also iterates through the tree from 
// the beginning to make sure that the inorder traversal is functioning
// properly. 
TEST_F(SplayTest, ZigLeft) 
{
	splayTreeStringDouble.insert(std::make_pair("Betty", 10));
	splayTreeStringDouble.insert(std::make_pair("Aaron", 20));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	SplayTree<std::string, double>::iterator end = splayTreeStringDouble.end();
	EXPECT_EQ(it, end);
}

// Tests the same as above but for the right case. 
TEST_F(SplayTest, ZigRight) 
{
	splayTreeStringDouble.insert(std::make_pair("Aaron", 10));
	splayTreeStringDouble.insert(std::make_pair("Betty", 20));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	SplayTree<std::string, double>::iterator end = splayTreeStringDouble.end();
	EXPECT_EQ(it, end);
}

// Tests for the ZigZigLeft scenario, and also iterates from the 
// beginning of the tree to see if the inorder traversal is working 
// properly. 
TEST_F(SplayTest, ZigZigLeft) 
{
	splayTreeStringDouble.insert(std::make_pair("Aaron", 10));
	splayTreeStringDouble.insert(std::make_pair("Betty", 20));
	splayTreeStringDouble.insert(std::make_pair("AAA", 30));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "AAA");
	++it;
	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	SplayTree<std::string, double>::iterator end = splayTreeStringDouble.end();
	EXPECT_EQ(it, end);
}

// Tests the same as above but for the right case. 
TEST_F(SplayTest, ZigZigRight) 
{
	splayTreeStringDouble.insert(std::make_pair("Betty", 10));
	splayTreeStringDouble.insert(std::make_pair("Aaron", 20));
	splayTreeStringDouble.insert(std::make_pair("Carla", 30));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	EXPECT_EQ(it->first, "Carla");
	++it;
	SplayTree<std::string, double>::iterator end = splayTreeStringDouble.end();
	EXPECT_EQ(it, end);
}

// Tests the ZigZagRight case and again uses the iterator to go 
// through the entire tree. 
TEST_F(SplayTest, ZigZagRight) 
{
	splayTreeStringDouble.insert(std::make_pair("Betty", 10));
	splayTreeStringDouble.insert(std::make_pair("Aaron", 20));
	splayTreeStringDouble.insert(std::make_pair("BAA", 30));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "BAA");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	SplayTree<std::string, double>::iterator end = splayTreeStringDouble.end();
	EXPECT_EQ(it, end);
}

// Tests same as above but for the left case. 
TEST_F(SplayTest, ZigZagLeft) 
{
	splayTreeStringDouble.insert(std::make_pair("Aaron", 10));
	splayTreeStringDouble.insert(std::make_pair("Betty", 20));
	splayTreeStringDouble.insert(std::make_pair("Albert", 30));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "Aaron");
	++it;
	EXPECT_EQ(it->first, "Albert");
	++it;
	EXPECT_EQ(it->first, "Betty");
	++it;
	EXPECT_EQ(it, splayTreeStringDouble.end());
}

// Tests with multiple insertions and checks that the iterator
// goes through all of the expected values in the right order. 
TEST_F(SplayTest, MultipleInsertIterator)
{
	splayTreeStringDouble.insert(std::make_pair("AAA", 10));
	splayTreeStringDouble.insert(std::make_pair("GGG", 10));
	splayTreeStringDouble.insert(std::make_pair("EEE", 10));
	splayTreeStringDouble.insert(std::make_pair("ZZZ", 10));
	splayTreeStringDouble.insert(std::make_pair("WWW", 10));
	splayTreeStringDouble.insert(std::make_pair("FFF", 10));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "AAA"); ++it;
	EXPECT_EQ(it->first, "EEE"); ++it;
	EXPECT_EQ(it->first, "FFF"); ++it;
	EXPECT_EQ(it->first, "GGG"); ++it;
	EXPECT_EQ(it->first, "WWW"); ++it;
	EXPECT_EQ(it->first, "ZZZ"); ++it;
	EXPECT_EQ(it, splayTreeStringDouble.end());
}

// Tests that the iterator works properly on an empty tree. 
TEST_F(SplayTest, EmptyTreeIterator)
{
	EXPECT_EQ(splayTreeStringDouble.begin(), splayTreeStringDouble.end());
}

// Tests multiple insertions, iterator traversal, clearing the 
// tree, and reinserting the values. Also checks that the 
// assignment operator works for the iterator as it gets
// reassigned to the beginning of the tree and the traversal
// starts all over again. 
TEST_F(SplayTest, MultipleInsertClear)
{
	splayTreeStringDouble.insert(std::make_pair("AAA", 10));
	splayTreeStringDouble.insert(std::make_pair("GGG", 10));
	splayTreeStringDouble.insert(std::make_pair("EEE", 10));
	splayTreeStringDouble.insert(std::make_pair("ZZZ", 10));
	splayTreeStringDouble.insert(std::make_pair("WWW", 10));
	splayTreeStringDouble.insert(std::make_pair("FFF", 10));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "AAA"); ++it;
	EXPECT_EQ(it->first, "EEE"); ++it;
	EXPECT_EQ(it->first, "FFF"); ++it;
	EXPECT_EQ(it->first, "GGG"); ++it;
	EXPECT_EQ(it->first, "WWW"); ++it;
	EXPECT_EQ(it->first, "ZZZ"); ++it;
	EXPECT_EQ(it, splayTreeStringDouble.end());

	splayTreeStringDouble.clear();

	EXPECT_EQ(splayTreeStringDouble.begin(), splayTreeStringDouble.end());

	splayTreeStringDouble.insert(std::make_pair("AAA", 10));
	splayTreeStringDouble.insert(std::make_pair("GGG", 10));
	splayTreeStringDouble.insert(std::make_pair("EEE", 10));
	splayTreeStringDouble.insert(std::make_pair("ZZZ", 10));
	splayTreeStringDouble.insert(std::make_pair("WWW", 10));
	splayTreeStringDouble.insert(std::make_pair("FFF", 10));

	it = splayTreeStringDouble.begin();

	EXPECT_EQ(it->first, "AAA"); ++it;
	EXPECT_EQ(it->first, "EEE"); ++it;
	EXPECT_EQ(it->first, "FFF"); ++it;
	EXPECT_EQ(it->first, "GGG"); ++it;
	EXPECT_EQ(it->first, "WWW"); ++it;
	EXPECT_EQ(it->first, "ZZZ"); ++it;
	EXPECT_EQ(it, splayTreeStringDouble.end());
}

// Tests the find operation to make sure that the right
// node is being returned through the iterator, and also
// checks that the found node is equal to the node at the root
// of the tree. 
//
// Also splayTreeStringDoubles when find is done on a non-existent node, which
// should then splay the last-visited node to the top. 
TEST_F(SplayTest, Find)
{
	splayTreeStringDouble.insert(std::make_pair("AAA", 10));
	splayTreeStringDouble.insert(std::make_pair("GGG", 10));
	splayTreeStringDouble.insert(std::make_pair("EEE", 10));
	splayTreeStringDouble.insert(std::make_pair("ZZZ", 10));
	splayTreeStringDouble.insert(std::make_pair("WWW", 10));
	splayTreeStringDouble.insert(std::make_pair("FFF", 10));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.find("EEE");

	EXPECT_EQ(it->first, "EEE");
	EXPECT_EQ(splayTreeStringDouble.checkRootKey(), "EEE");

	SplayTree<std::string, double>::iterator notInTree = splayTreeStringDouble.find("ABC");

	EXPECT_EQ(notInTree, splayTreeStringDouble.end());
	EXPECT_EQ(splayTreeStringDouble.checkRootKey(), "AAA");
}

// Tests insertion and then overwriting the value with a second insertion. 
// The values are also checked agains what is in the root of the tree. 
TEST_F(SplayTest, FindThenInsertOverwrite)
{
	splayTreeStringDouble.insert(std::make_pair("AAA", 10));
	splayTreeStringDouble.insert(std::make_pair("GGG", 10));
	splayTreeStringDouble.insert(std::make_pair("EEE", 10));
	splayTreeStringDouble.insert(std::make_pair("ZZZ", 10));
	splayTreeStringDouble.insert(std::make_pair("WWW", 10));
	splayTreeStringDouble.insert(std::make_pair("FFF", 10));

	SplayTree<std::string, double>::iterator it = splayTreeStringDouble.find("EEE");

	EXPECT_EQ(splayTreeStringDouble.checkRootKey(), it->first);

	splayTreeStringDouble.insert(std::make_pair("EEE", 20));

	SplayTree<std::string, double>::iterator newValue = splayTreeStringDouble.find("EEE");

	EXPECT_EQ(splayTreeStringDouble.checkRootKey(), newValue->first);
	EXPECT_EQ(splayTreeStringDouble.checkValue("EEE"), it->second);
}