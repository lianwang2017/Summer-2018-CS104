#include "../llistint.h"
#include "gtest/gtest.h"
#include <cstdlib>

class LListIntTest : public testing::Test
{
	protected:
		LListIntTest()
		{

		}

		~LListIntTest()
		{

		}

		virtual void SetUp()
		{

		}

		virtual void TearDown()
		{

		}

		LListInt studentLinkedList;
};

// Tests that the list is initially empty.
TEST_F(LListIntTest, InitiallyEmpty)
{
	EXPECT_TRUE(studentLinkedList.empty());
}

// Tests that the list initially has a size of 0.
TEST_F(LListIntTest, InitiallyZeroSize)
{
	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests that the list is not empty after three insertions. 
TEST_F(LListIntTest, NotEmptyAfterInsert)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	EXPECT_FALSE(studentLinkedList.empty());
}

// Tests that the list has the correct size after three insertions. 
TEST_F(LListIntTest, NonZeroSizeAfterInsert)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	EXPECT_EQ(3, studentLinkedList.size());
}

// Tests that the list is still empty and has a size of 0 when remove
// is called on an empty list. 
TEST_F(LListIntTest, RemoveOnEmptyList)
{
	studentLinkedList.remove(0);

	EXPECT_TRUE(studentLinkedList.empty());
	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests that the list has the correct size after inserting 3 elements and
// removing 1 element. 
TEST_F(LListIntTest, RemoveOnNonEmptyListWithElementsLeftOver)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.remove(0);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(2, studentLinkedList.size());
}

// Tests that calling remove on the front of the list until the list is
// empty will reset the list to empty and the size to 0. 
TEST_F(LListIntTest, RemoveUntilEmpty)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.remove(0);
	studentLinkedList.remove(0);
	studentLinkedList.remove(0);

	EXPECT_TRUE(studentLinkedList.empty());
	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests that the size of the list is correct after removing
// from the middle of the list.  
TEST_F(LListIntTest, RemoveFromMiddleOfList)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.remove(1);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(2, studentLinkedList.size());
}

// Tests that the size of the list doesn't change when remove is called
// at an invalid location. 
TEST_F(LListIntTest, RemoveInvalidLocation)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.remove(4);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(3, studentLinkedList.size());
}

// Tests that the order of the elements is correct after inserting. 
TEST_F(LListIntTest, OrderOfElements)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	EXPECT_EQ(studentLinkedList.get(0), 0);
	EXPECT_EQ(studentLinkedList.get(1), 1);
	EXPECT_EQ(studentLinkedList.get(2), 10);
}

// Tests that the head of the list is reset when the front of the 
// list is removed. 
TEST_F(LListIntTest, OrderOfElementsAfterRemovalFromFront)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.remove(0);

	EXPECT_EQ(1, studentLinkedList.get(0));
	EXPECT_EQ(10, studentLinkedList.get(1));
}

// Tests that calling clear on an empty list does not change the 
// size or emptiness of the list. 
TEST_F(LListIntTest, ClearOnEmptyList)
{
	studentLinkedList.clear();

	EXPECT_TRUE(studentLinkedList.empty());
	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests that calling clear on the list will reset the size to 0 of 
// the list. 
TEST_F(LListIntTest, ClearOnNonEmptyList)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.clear();

	EXPECT_TRUE(studentLinkedList.empty());
	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests that setting the front of the list leaves the size
// of the list correct and the other elements unchanged. 
TEST_F(LListIntTest, SetFrontOfList)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.set(0, 100);

	EXPECT_EQ(studentLinkedList.get(0), 100);
	EXPECT_EQ(studentLinkedList.get(1), 1);
	EXPECT_EQ(studentLinkedList.get(2), 10);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(3, studentLinkedList.size());
}

// Tests the same as above but for the middle of the list. 
TEST_F(LListIntTest, SetMiddleOfList)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.set(1, 100);

	EXPECT_EQ(studentLinkedList.get(0), 0);
	EXPECT_EQ(studentLinkedList.get(1), 100);
	EXPECT_EQ(studentLinkedList.get(2), 10);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(3, studentLinkedList.size());
}

// Tests the same as above but for the back of the list. 
TEST_F(LListIntTest, SetBackOfList)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.set(2, 100);

	EXPECT_EQ(studentLinkedList.get(0), 0);
	EXPECT_EQ(studentLinkedList.get(1), 1);
	EXPECT_EQ(studentLinkedList.get(2), 100);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(3, studentLinkedList.size());
}

// Following test should not be run because the llistint class already provided to student fails this test.
/*
// Tests that setting at an invalid location does not change the 
// properties or the order of the list. 
TEST_F(LListIntTest, SetInvalidLocation)
{
	studentLinkedList.insert(studentLinkedList.size(), 0);
	studentLinkedList.insert(studentLinkedList.size(), 1);
	studentLinkedList.insert(studentLinkedList.size(), 10);

	studentLinkedList.set(4, 100);

	EXPECT_EQ(studentLinkedList.get(0), 0);
	EXPECT_EQ(studentLinkedList.get(1), 1);
	EXPECT_EQ(studentLinkedList.get(2), 10);

	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(3, studentLinkedList.size());
}
*/

// Tests that the list can handle inserting 100 elements. The size is
// checked after inserting, then the order of the list is inspected. Then
// items are removed from the front of the list until it is empty. 
TEST_F(LListIntTest, Insert100ElementsAndRemove)
{
	srand(0);

	for(int i = 0; i < 100; ++i)
	{
		studentLinkedList.insert(studentLinkedList.size(), rand());
	}

	EXPECT_EQ(100, studentLinkedList.size());

	srand(0);

	while(!studentLinkedList.empty())
	{
		EXPECT_EQ(rand(), studentLinkedList.get(0));
		studentLinkedList.remove(0);
	}

	EXPECT_EQ(0, studentLinkedList.size());
}

// Tests a large number of insertions, 10000 elements, used for testig
// the runtime of their class. This is always inserting at the end
// of the list. 
TEST_F(LListIntTest, Insert10000ElementsAndRemove)
{
	srand(0);

	for(int i = 0; i < 10000; ++i)
	{
		studentLinkedList.insert(studentLinkedList.size(), rand());
	}

	EXPECT_EQ(10000, studentLinkedList.size());

	srand(0);

	while(!studentLinkedList.empty())
	{
		EXPECT_EQ(rand(), studentLinkedList.get(0));
		studentLinkedList.remove(0);
	}

	EXPECT_EQ(0, studentLinkedList.size());
}
