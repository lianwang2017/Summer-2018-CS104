#include "../alistint.h"
#include "gtest/gtest.h"
#include <cstdlib>

class AListIntTest : public testing::Test
{
	protected:
		AListIntTest()
		{

		}

		~AListIntTest()
		{

		}

		virtual void SetUp()
		{
			defaultStudentArrayList = new AListInt();
			customStudentArrayList = new AListInt(5);
		}

		virtual void TearDown()
		{
			delete defaultStudentArrayList;
			delete customStudentArrayList;
		}

		AListInt *defaultStudentArrayList;
		AListInt *customStudentArrayList;

};

// Tests that the list is initially empty.
TEST_F(AListIntTest, InitiallyEmpty)
{
	EXPECT_TRUE(defaultStudentArrayList->empty());
	EXPECT_TRUE(customStudentArrayList->empty());
}

// Tests that the list initially has a size of 0.
TEST_F(AListIntTest, InitiallyZeroSize)
{
	EXPECT_EQ(0, defaultStudentArrayList->size());
	EXPECT_EQ(0, customStudentArrayList->size());
}

TEST_F(AListIntTest, Resize)
{
	for(int i = 0; i < 15; ++i)
	{
		defaultStudentArrayList->insert(defaultStudentArrayList->size(), i);
		customStudentArrayList->insert(customStudentArrayList->size(), i);
	}

	EXPECT_EQ(15, defaultStudentArrayList->size());
	EXPECT_EQ(15, customStudentArrayList->size());
}

// Tests that the list is not empty after three insertions. 
TEST_F(AListIntTest, NotEmptyAfterInsert)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_FALSE(customStudentArrayList->empty());
}

// Tests that the list has the correct size after three insertions. 
TEST_F(AListIntTest, NonZeroSizeAfterInsert)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	EXPECT_EQ(3, defaultStudentArrayList->size());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests that the list is still empty and has a size of 0 when remove
// is called on an empty list. 
TEST_F(AListIntTest, RemoveOnEmptyList)
{
	defaultStudentArrayList->remove(0);
	customStudentArrayList->remove(0);

	EXPECT_TRUE(defaultStudentArrayList->empty());
	EXPECT_EQ(0, defaultStudentArrayList->size());

	EXPECT_TRUE(customStudentArrayList->empty());
	EXPECT_EQ(0, customStudentArrayList->size());
}

// Tests that the list has the correct size after inserting 3 elements and
// removing 1 element. 
TEST_F(AListIntTest, RemoveOnNonEmptyListWithElementsLeftOver)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->remove(0);
	customStudentArrayList->remove(0);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(2, defaultStudentArrayList->size());

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(2, customStudentArrayList->size());
}

// Tests that calling remove on the front of the list until the list is
// empty will reset the list to empty and the size to 0. 
TEST_F(AListIntTest, RemoveUntilEmpty)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->remove(0);
	defaultStudentArrayList->remove(0);
	defaultStudentArrayList->remove(0);

	customStudentArrayList->remove(0);
	customStudentArrayList->remove(0);
	customStudentArrayList->remove(0);

	EXPECT_TRUE(defaultStudentArrayList->empty());
	EXPECT_EQ(0, defaultStudentArrayList->size());

	EXPECT_TRUE(customStudentArrayList->empty());
	EXPECT_EQ(0, customStudentArrayList->size());
}

// Tests that the size of the list is correct after removing
// from the middle of the list.  
TEST_F(AListIntTest, RemoveFromMiddleOfList)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->remove(1);
	customStudentArrayList->remove(1);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(2, defaultStudentArrayList->size());

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(2, customStudentArrayList->size());
}

// Tests that the size of the list doesn't change when remove is called
// at an invalid location. 
TEST_F(AListIntTest, RemoveInvalidLocation)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->remove(4);
	customStudentArrayList->remove(4);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(3, defaultStudentArrayList->size());

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests that the order of the elements is correct after inserting. 
TEST_F(AListIntTest, OrderOfElements)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	EXPECT_EQ(defaultStudentArrayList->get(0), 0);
	EXPECT_EQ(defaultStudentArrayList->get(1), 1);
	EXPECT_EQ(defaultStudentArrayList->get(2), 10);

	EXPECT_EQ(customStudentArrayList->get(0), 0);
	EXPECT_EQ(customStudentArrayList->get(1), 1);
	EXPECT_EQ(customStudentArrayList->get(2), 10);
}

// Tests that the head of the list is reset when the front of the 
// list is removed. 
TEST_F(AListIntTest, OrderOfElementsAfterRemovalFromFront)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->remove(0);
	customStudentArrayList->remove(0);

	EXPECT_EQ(1, defaultStudentArrayList->get(0));
	EXPECT_EQ(10, defaultStudentArrayList->get(1));

	EXPECT_EQ(1, customStudentArrayList->get(0));
	EXPECT_EQ(10, customStudentArrayList->get(1));
}

/*
// Tests that calling clear on an empty list does not change the 
// size or emptiness of the list. 
TEST_F(AListIntTest, ClearOnEmptyList)
{
	defaultStudentArrayList->clear();
	customStudentArrayList->clear();

	EXPECT_TRUE(defaultStudentArrayList->empty());
	EXPECT_EQ(0, defaultStudentArrayList->size());

	EXPECT_TRUE(customStudentArrayList->empty());
	EXPECT_EQ(0, customStudentArrayList->size());
}
*/

/*
// Tests that calling clear on the list will reset the size to 0 of 
// the list. 
TEST_F(AListIntTest, ClearOnNonEmptyList)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->clear();
	customStudentArrayList->clear();

	EXPECT_TRUE(defaultStudentArrayList->empty());
	EXPECT_EQ(0, defaultStudentArrayList->size());

	EXPECT_TRUE(customStudentArrayList->empty());
	EXPECT_EQ(0, customStudentArrayList->size());
}
*/

// Tests that setting the front of the list leaves the size
// of the list correct and the other elements unchanged. 
TEST_F(AListIntTest, SetFrontOfList)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->set(0, 100);
	customStudentArrayList->set(0, 100);

	EXPECT_EQ(defaultStudentArrayList->get(0), 100);
	EXPECT_EQ(defaultStudentArrayList->get(1), 1);
	EXPECT_EQ(defaultStudentArrayList->get(2), 10);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(3, defaultStudentArrayList->size());

	EXPECT_EQ(customStudentArrayList->get(0), 100);
	EXPECT_EQ(customStudentArrayList->get(1), 1);
	EXPECT_EQ(customStudentArrayList->get(2), 10);

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests the same as above but for the middle of the list. 
TEST_F(AListIntTest, SetMiddleOfList)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->set(1, 100);
	customStudentArrayList->set(1, 100);

	EXPECT_EQ(defaultStudentArrayList->get(0), 0);
	EXPECT_EQ(defaultStudentArrayList->get(1), 100);
	EXPECT_EQ(defaultStudentArrayList->get(2), 10);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(3, defaultStudentArrayList->size());

	EXPECT_EQ(customStudentArrayList->get(0), 0);
	EXPECT_EQ(customStudentArrayList->get(1), 100);
	EXPECT_EQ(customStudentArrayList->get(2), 10);

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests the same as above but for the back of the list. 
TEST_F(AListIntTest, SetBackOfList)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->set(2, 100);
	customStudentArrayList->set(2, 100);

	EXPECT_EQ(defaultStudentArrayList->get(0), 0);
	EXPECT_EQ(defaultStudentArrayList->get(1), 1);
	EXPECT_EQ(defaultStudentArrayList->get(2), 100);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(3, defaultStudentArrayList->size());

	EXPECT_EQ(customStudentArrayList->get(0), 0);
	EXPECT_EQ(customStudentArrayList->get(1), 1);
	EXPECT_EQ(customStudentArrayList->get(2), 100);

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests that setting at an invalid location does not change the 
// properties or the order of the list. 
TEST_F(AListIntTest, SetInvalidLocation)
{
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 0);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 1);
	defaultStudentArrayList->insert(defaultStudentArrayList->size(), 10);

	customStudentArrayList->insert(customStudentArrayList->size(), 0);
	customStudentArrayList->insert(customStudentArrayList->size(), 1);
	customStudentArrayList->insert(customStudentArrayList->size(), 10);

	defaultStudentArrayList->set(4, 100);
	customStudentArrayList->set(4, 100);

	EXPECT_EQ(defaultStudentArrayList->get(0), 0);
	EXPECT_EQ(defaultStudentArrayList->get(1), 1);
	EXPECT_EQ(defaultStudentArrayList->get(2), 10);

	EXPECT_FALSE(defaultStudentArrayList->empty());
	EXPECT_EQ(3, defaultStudentArrayList->size());

	EXPECT_EQ(customStudentArrayList->get(0), 0);
	EXPECT_EQ(customStudentArrayList->get(1), 1);
	EXPECT_EQ(customStudentArrayList->get(2), 10);

	EXPECT_FALSE(customStudentArrayList->empty());
	EXPECT_EQ(3, customStudentArrayList->size());
}

// Tests that the list can handle inserting 100 elements. The size is
// checked after inserting, then the order of the list is inspected. Then
// items are removed from the front of the list until it is empty. 
TEST_F(AListIntTest, Insert100ElementsAndRemove)
{
	srand(0);

	for(int i = 0; i < 100; ++i)
	{
		defaultStudentArrayList->insert(defaultStudentArrayList->size(), rand());
		customStudentArrayList->insert(customStudentArrayList->size(), defaultStudentArrayList->get(defaultStudentArrayList->size() - 1));
	}

	EXPECT_EQ(100, defaultStudentArrayList->size());
	EXPECT_EQ(100, customStudentArrayList->size());

	srand(0);

	while(!defaultStudentArrayList->empty())
	{
		EXPECT_EQ(rand(), defaultStudentArrayList->get(0));
		EXPECT_EQ(customStudentArrayList->get(0), defaultStudentArrayList->get(0));
		defaultStudentArrayList->remove(0);
		customStudentArrayList->remove(0);
	}

	EXPECT_EQ(0, defaultStudentArrayList->size());
	EXPECT_EQ(0, customStudentArrayList->size());
}

// Tests a large number of insertions, 10000 elements, used for testig
// the runtime of their class. This is always inserting at the end
// of the list. 
TEST_F(AListIntTest, Insert10000ElementsAndRemove)
{
	srand(0);

	for(int i = 0; i < 10000; ++i)
	{
		defaultStudentArrayList->insert(defaultStudentArrayList->size(), rand());
		customStudentArrayList->insert(customStudentArrayList->size(), defaultStudentArrayList->get(defaultStudentArrayList->size() - 1));
	}

	EXPECT_EQ(10000, defaultStudentArrayList->size());
	EXPECT_EQ(10000, customStudentArrayList->size());

	srand(0);

	while(!defaultStudentArrayList->empty())
	{
		EXPECT_EQ(rand(), defaultStudentArrayList->get(0));
		EXPECT_EQ(customStudentArrayList->get(0), defaultStudentArrayList->get(0));
		defaultStudentArrayList->remove(0);
		customStudentArrayList->remove(0);
	}

	EXPECT_EQ(0, defaultStudentArrayList->size());
	EXPECT_EQ(0, customStudentArrayList->size());
}
