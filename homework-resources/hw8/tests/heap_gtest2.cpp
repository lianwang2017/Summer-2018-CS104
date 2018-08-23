/*
	Google Test for testing a student's templated m-Ary heap. There are four main test
	areas, testing strings, doubles, integers, and more integers. 

	Interface functions given for students to implement:

		Heap(int m, Comparator c);
	  	~Heap();
	  	void push(const T& item);
	  	T const & top() const;
	  	void pop();
	  	bool empty() const;
*/

#include "gtest/gtest.h"
#include "../heap.h"			// Student's templated m-Ary heap implementation.
#include <functional>		// Included for std::greater and std::less.
#include <string>
#include <sstream>			// For generating random strings. 

using namespace std;

/*
	Testing setup area. Here, the four types of heaps are declared and initialized. 

	intBinaryMaxHeap is a binary max-heap storing integers.
	stringBinaryMinHeap is a binary min-heap storing strings.
	doubleTrinaryMinHeap is a trinary min-heap storing doubles. 
	intTwentySevenaryMaxHeap is a rand-ary max-heap storing integers. 
*/
class HeapTest : public testing::Test 
{
	protected:
		HeapTest() : intBinaryMaxHeap(2, std::greater<int>()),
					 doubleTrinaryMinHeap(3, std::less<double>()),
					 stringBinaryMinHeap(2, std::less<std::string>()),
					 intTwentySevenaryMaxHeap(27, std::greater<int>())
		{
	
		}

		~HeapTest() 
		{

		}

		virtual void SetUp() 
		{

		}

		virtual void TearDown() 
		{

		}
		Heap<int, std::equal_to<int>, std::greater<int> > intBinaryMaxHeap;
		Heap<double, std::equal_to<double>, std::less<double> > doubleTrinaryMinHeap;
		Heap<std::string, std::equal_to<std::string>, std::less<std::string> > stringBinaryMinHeap;
		Heap<int, std::equal_to<int>, std::greater<int>, std::hash<int>> intTwentySevenaryMaxHeap;
};

/*
	These are the tests for the integer, binary, max-heap. The tests are:

	1. IntEmpty_01: Checks that the heap is initially empty.
	2. IntPushEmpty_02: Checks that the heap is not empty after pushing 1 item.
	3. IntPushTop_03: Checks that the top is correct after pushing 1 item. 
	4. IntPushPopEmpty_04: Checks that the heap is empty after pushing 1 item and poping the heap.
	5. IntMultiplePushInOrderPop_05: Pushes 5 elements in max order, checks as they are pushed to the 
									 heap, checks the heap is not empty, pops items and checks their
									 order as they are poped, and finally checks the heap is empty. 
	6. IntRandomPushOrder_06: Pushes 100 random numbers using rand() and pops to check their comparative
							  status, looking that they are >= as we top()/pop().
	7 - 9. IntRuntime*RandomPush_*: Pushes 10,000, 100,000, and 1,000,000 random elements to the heap,
									and top()/pop() to check their order. Used to test runtime of the heap. 
*/

TEST_F(HeapTest, IntEmpty_01)
{
	EXPECT_TRUE(intBinaryMaxHeap.empty());
}

TEST_F(HeapTest, IntPushEmpty_02)
{
	intBinaryMaxHeap.push(0);
	EXPECT_FALSE(intBinaryMaxHeap.empty());
}

TEST_F(HeapTest, IntPushTop_03)
{
	intBinaryMaxHeap.push(0);
	EXPECT_EQ(intBinaryMaxHeap.top(), 0);
}

TEST_F(HeapTest, IntPushPopEmpty_04)
{
	intBinaryMaxHeap.push(0);
	intBinaryMaxHeap.pop();
	EXPECT_TRUE(intBinaryMaxHeap.empty());
}

TEST_F(HeapTest, IntMultiplePushInOrderPop_05)
{
	int numberOfInserts = 5;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intBinaryMaxHeap.push(i);
		EXPECT_EQ(intBinaryMaxHeap.top(), i);
	}

	EXPECT_FALSE(intBinaryMaxHeap.empty());

	for(int i = 0; i < numberOfInserts; ++i)
	{
		EXPECT_EQ(intBinaryMaxHeap.top(), numberOfInserts - i - 1);
		intBinaryMaxHeap.pop();
	}

	EXPECT_TRUE(intBinaryMaxHeap.empty());
}

TEST_F(HeapTest, IntRandomPushOrder_06)
{
	int numberOfInserts = 100;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intBinaryMaxHeap.push(rand());
	}

	while(!intBinaryMaxHeap.empty())
	{
		int top = intBinaryMaxHeap.top();
		intBinaryMaxHeap.pop();
		if(!intBinaryMaxHeap.empty())
		{
			EXPECT_GE(top, intBinaryMaxHeap.top());
		}
	}
}

TEST_F(HeapTest, IntRuntime10000RandomPush_07)
{
	int numberOfInserts = 10000;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intBinaryMaxHeap.push(rand());
	}

	while(!intBinaryMaxHeap.empty())
	{
		int top = intBinaryMaxHeap.top();
		intBinaryMaxHeap.pop();
		if(!intBinaryMaxHeap.empty())
		{
			EXPECT_GE(top, intBinaryMaxHeap.top());
		}
	}
}
TEST_F(HeapTest, IntRuntime100000RandomPush_08)
{
	int numberOfInserts = 100000;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intBinaryMaxHeap.push(rand());
	}

	while(!intBinaryMaxHeap.empty())
	{
		int top = intBinaryMaxHeap.top();
		intBinaryMaxHeap.pop();
		if(!intBinaryMaxHeap.empty())
		{
			EXPECT_GE(top, intBinaryMaxHeap.top());
		}
	}
}
TEST_F(HeapTest, IntRuntime1000000RandomPush_09)
{
	int numberOfInserts = 1000000;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intBinaryMaxHeap.push(rand());
	}

	while(!intBinaryMaxHeap.empty())
	{
		int top = intBinaryMaxHeap.top();
		intBinaryMaxHeap.pop();
		if(!intBinaryMaxHeap.empty())
		{
			EXPECT_GE(top, intBinaryMaxHeap.top());
		}
	}
}

/*
	These are the tests for the string, binary, min-heap. The tests are:

	10. StringEmpty_10: Checks that the heap is initially empty.
	11. StringPushEmpty_11: Checks that the heap is not empty after pushing 1 item.
	12. StringPushTop_12: Checks that the top is correct after pushing 1 item. 
	13. StringPushPopEmpty_13: Checks that the heap is empty after pushing 1 item and poping the heap.
	14. StringMultiplePushInOrderPop_14: Pushes 5 elements in min order, checks as they are pushed to the 
									 	 heap, checks the heap is not empty, pops items and checks their
									 	 order as they are poped, and finally checks the heap is empty. 
	15. StringRandomPushOrder_15: Pushes 100 random strings using rand() and a stringstream,
								  pops to check their comparative status, looking that they are <= as we top()/pop(). 
*/

TEST_F(HeapTest, StringEmpty_10)
{
	EXPECT_TRUE(stringBinaryMinHeap.empty());
}

TEST_F(HeapTest, StringPushEmpty_11)
{
	stringBinaryMinHeap.push("CS104");
	EXPECT_FALSE(stringBinaryMinHeap.empty());
}

TEST_F(HeapTest, StringPushTop_12)
{
	stringBinaryMinHeap.push("CS104");
	EXPECT_EQ(stringBinaryMinHeap.top(), "CS104");
}

TEST_F(HeapTest, StringPushPopEmpty_13)
{
	stringBinaryMinHeap.push("CS104");
	stringBinaryMinHeap.pop();
	EXPECT_TRUE(stringBinaryMinHeap.empty());
}

TEST_F(HeapTest, StringMultiplePushInOrderPop_14)
{
	int numberOfInserts = 5;
	stringstream ss;
	
	for(int i = 0; i < numberOfInserts; ++i)
	{
		ss << i;
		string number = ss.str();
		ss.str("");

		stringBinaryMinHeap.push("CS104_" + number);
		EXPECT_EQ(stringBinaryMinHeap.top(), "CS104_0");
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		ss << i;
		string number = ss.str();
		ss.str("");

		string top = stringBinaryMinHeap.top();
		EXPECT_EQ(top, "CS104_" + number);
		stringBinaryMinHeap.pop();
	}
}

TEST_F(HeapTest, StringRandomPushOrder_15)
{
	int numberOfInserts = 100;
	stringstream ss;

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		stringBinaryMinHeap.push(randomString);
	}

	while(!stringBinaryMinHeap.empty())
	{
		string top = stringBinaryMinHeap.top();
		stringBinaryMinHeap.pop();
		if(!stringBinaryMinHeap.empty())
		{
			EXPECT_LE(top, stringBinaryMinHeap.top());
		}
	}
}

/*
	These are the tests for the double, trinary, min-heap. The tests are:

	16. DoubleEmpty_16: Checks that the heap is initially empty.
	17. DoublePushEmpty_17: Checks that the heap is not empty after pushing 1 item.
	18. DoublePushTop_18: Checks that the top is correct after pushing 1 item. 
	19. DoublePushPopEmpty_19: Checks that the heap is empty after pushing 1 item and poping the heap.
	20. DoubleMultiplePushInOrderPop_20: Pushes 5 elements in min order, checks as they are pushed to the 
									 	 heap, checks the heap is not empty, pops items and checks their
									 	 order as they are poped, and finally checks the heap is empty. 
	21. DoubleRandomPushOrder_21: Pushes 100 random doubles using rand(),
								  pops to check their comparative status, looking that they are <= as we top()/pop(). 
*/

TEST_F(HeapTest, DoubleEmpty_16)
{
	EXPECT_TRUE(doubleTrinaryMinHeap.empty());
}

TEST_F(HeapTest, DoublePushEmpty_17)
{
	doubleTrinaryMinHeap.push(3.14159);
	EXPECT_FALSE(doubleTrinaryMinHeap.empty());
}

TEST_F(HeapTest, DoublePushTop_18)
{
	doubleTrinaryMinHeap.push(3.14159);
	EXPECT_EQ(doubleTrinaryMinHeap.top(), 3.14159);
}

TEST_F(HeapTest, DoublePushPopEmpty_19)
{
	doubleTrinaryMinHeap.push(3.14159);
	doubleTrinaryMinHeap.pop();
	EXPECT_TRUE(doubleTrinaryMinHeap.empty());
}

TEST_F(HeapTest, DoubleMultiplePushInOrderPop_20)
{
	int numberOfInserts = 5;
	
	for(int i = 0; i < numberOfInserts; ++i)
	{
		doubleTrinaryMinHeap.push(i * 3.14159);
		EXPECT_EQ(doubleTrinaryMinHeap.top(), 0);
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		double top = doubleTrinaryMinHeap.top();
		EXPECT_EQ(top, i * 3.14159);
		doubleTrinaryMinHeap.pop();
	}
}

TEST_F(HeapTest, DoubleRandomPushOrder_21)
{
	int numberOfInserts = 100;

	for(int i = 0; i < numberOfInserts; ++i)
	{
		doubleTrinaryMinHeap.push(rand() * 3.14159);
	}

	while(!doubleTrinaryMinHeap.empty())
	{
		double top = doubleTrinaryMinHeap.top();
		doubleTrinaryMinHeap.pop();
		if(!doubleTrinaryMinHeap.empty())
		{
			EXPECT_LE(top, doubleTrinaryMinHeap.top());
		}
	}
}

/*
	These are the tests for the int, TwentySeven-ary, max-heap. The tests are:

	22. IntTwentySevenEmpty_22: Checks that the heap is initially empty.
	23. IntTwentySevenPushEmpty_23: Checks that the heap is not empty after pushing 1 item.
	24. IntTwentySevenPushTop_24: Checks that the top is correct after pushing 1 item. 
	25. IntTwentySevenPushPopEmpty_25: Checks that the heap is empty after pushing 1 item and poping the heap.
	26. IntTwentySevenMultiplePushInOrderPop_26: Pushes 5 elements in max order, checks as they are pushed to the 
									 	 heap, checks the heap is not empty, pops items and checks their
									 	 order as they are poped, and finally checks the heap is empty. 
	TwentySeven. IntTwentySevenRandomPushOrder_TwentySeven: Pushes 100 random ints using rand(),
								  pops to check their comparative status, looking that they are >= as we top()/pop(). 
*/	  

TEST_F(HeapTest, IntTwentySevenEmpty_22)
{
	EXPECT_TRUE(intTwentySevenaryMaxHeap.empty());
}

TEST_F(HeapTest, IntTwentySevenPushEmpty_23)
{
	intTwentySevenaryMaxHeap.push(0);
	EXPECT_FALSE(intTwentySevenaryMaxHeap.empty());
}

TEST_F(HeapTest, IntTwentySevenPushTop_24)
{
	intTwentySevenaryMaxHeap.push(0);
	EXPECT_EQ(intTwentySevenaryMaxHeap.top(), 0);
}

TEST_F(HeapTest, IntTwentySevenPushPopEmpty_25)
{
	intTwentySevenaryMaxHeap.push(0);
	intTwentySevenaryMaxHeap.pop();
	EXPECT_TRUE(intTwentySevenaryMaxHeap.empty());
}

TEST_F(HeapTest, IntTwentySevenMultiplePushInOrderPop_26)
{
	int numberOfInserts = 5;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.push(i);
		EXPECT_EQ(intTwentySevenaryMaxHeap.top(), i);
	}

	EXPECT_FALSE(intTwentySevenaryMaxHeap.empty());

	for(int i = 0; i < numberOfInserts; ++i)
	{
		EXPECT_EQ(intTwentySevenaryMaxHeap.top(), numberOfInserts - i - 1);
		intTwentySevenaryMaxHeap.pop();
	}

	EXPECT_TRUE(intTwentySevenaryMaxHeap.empty());
}

TEST_F(HeapTest, IntTwentySevenRandomPushOrder_27)
{
	int numberOfInserts = 100;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.push(rand());
	}

	while(!intTwentySevenaryMaxHeap.empty())
	{
		int top = intTwentySevenaryMaxHeap.top();
		intTwentySevenaryMaxHeap.pop();
		if(!intTwentySevenaryMaxHeap.empty())
		{
			EXPECT_GE(top, intTwentySevenaryMaxHeap.top());
		}
	}
}