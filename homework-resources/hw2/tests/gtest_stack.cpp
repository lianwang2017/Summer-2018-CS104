#include "../llistint.h"
#include "../stackint.h"
#include "gtest/gtest.h"
#include <cstdlib>

class StackIntTest : public testing::Test
{
	protected:
		StackIntTest()
		{

		}

		~StackIntTest()
		{

		}

		virtual void SetUp()
		{

		}

		virtual void TearDown()
		{

		}

		StackInt studentStack;
};

// Tests that the stack is initially empty.
TEST_F(StackIntTest, InitiallyEmpty)
{
	EXPECT_TRUE(studentStack.empty());
}

// Tests that the stack is not empty after 3 pushes. 
TEST_F(StackIntTest, NotEmptyAfterPushing)
{
	studentStack.push(0);
	studentStack.push(1);
	studentStack.push(10);

	EXPECT_FALSE(studentStack.empty());
}

// Tests that the stack is not changed after poping on an empty stack. 
TEST_F(StackIntTest, PopOnEmptyStack)
{
	studentStack.pop();

	EXPECT_TRUE(studentStack.empty());
}

// Tests that the stack is not empty after pushing 3 items, and that after
// calling pop 3 times that it is again empty.  
TEST_F(StackIntTest, PopUntilEmpty)
{
	studentStack.push(0);
	studentStack.push(1);
	studentStack.push(10);

	EXPECT_FALSE(studentStack.empty());

	studentStack.pop();
	studentStack.pop();
	studentStack.pop();

	EXPECT_TRUE(studentStack.empty());
}

// Tests that the order of the elements on the stack is correct. 
TEST_F(StackIntTest, OrderOfElementsOnStack)
{
	studentStack.push(0);
	studentStack.push(1);
	studentStack.push(10);

	EXPECT_EQ(10, studentStack.top());
	studentStack.pop();
	EXPECT_EQ(1, studentStack.top());
	studentStack.pop();
	EXPECT_EQ(0, studentStack.top());
	studentStack.pop();

	EXPECT_TRUE(studentStack.empty());
}

// Tests the poping mechanism using the empty() member function. 
TEST_F(StackIntTest, PopUntilEmptyInAWhileLoop)
{
	studentStack.push(0);
	studentStack.push(1);
	studentStack.push(10);

	EXPECT_FALSE(studentStack.empty());

	while(!studentStack.empty())
	{
		studentStack.pop();
	}

	EXPECT_TRUE(studentStack.empty());
}

// Pushes and pops 100 elements to the stack. This test, and the subsequent
// tests are used for testing the runtime of the stack class. Using valgrind
// on this and checking the runtimes can give a fast indication as to 
// whether or not the runtime is indeed O(1).
TEST_F(StackIntTest, PushAndPop_100_Elements)
{
	for(int i = 0; i < 100; ++i)
	{
		studentStack.push(i);
	}

	int value = 99;

	while(!studentStack.empty())
	{
		EXPECT_EQ(value--, studentStack.top());
		studentStack.pop();
	}

	EXPECT_TRUE(studentStack.empty());
}

// Increases the number of push/pop by a factor of 10. 
TEST_F(StackIntTest, PushAndPop_1000_Elements)
{
	for(int i = 0; i < 1000; ++i)
	{
		studentStack.push(i);
	}

	int value = 999;

	while(!studentStack.empty())
	{
		EXPECT_EQ(value--, studentStack.top());
		studentStack.pop();
	}

	EXPECT_TRUE(studentStack.empty());
}

// Increases by another factor of 10. 
TEST_F(StackIntTest, PushAndPop_10000_Elements)
{
	for(int i = 0; i < 10000; ++i)
	{
		studentStack.push(i);
	}

	int value = 9999;

	while(!studentStack.empty())
	{
		EXPECT_EQ(value--, studentStack.top());
		studentStack.pop();
	}

	EXPECT_TRUE(studentStack.empty());
}

// Increases by one final factor of 10. 
TEST_F(StackIntTest, PushAndPop_100000_Elements)
{
	for(int i = 0; i < 100000; ++i)
	{
		studentStack.push(i);
	}

	int value = 99999;

	while(!studentStack.empty())
	{
		EXPECT_EQ(value--, studentStack.top());
		studentStack.pop();
	}

	EXPECT_TRUE(studentStack.empty());
}