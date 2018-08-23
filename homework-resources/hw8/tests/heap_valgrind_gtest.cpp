/*
	Google Test for testing a student's templated m-Ary heap. There are four main test
	areas, testing strings, doubles, integers, and more integers. 

	Interface functions given for students to implement:

		Heap(int m, PComparator c, Hasher h, KComparator k);
	  	~Heap();
	  	void push(const T& item);
	  	T const & top() const;
	  	void pop();
	  	bool empty() const;
	  	void decreaseKey(T old, T newVal);
*/

#include "gtest/gtest.h"
#include "tagdata.h"
#include "../heap.h"		// Student's templated m-Ary heap implementation.
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
		HeapTest() : stringBinaryMinHeap(2, std::less<std::string>(), std::hash<std::string>(), std::equal_to<std::string>()), \
					 intTwentySevenaryMaxHeap(27, std::greater<int>(), std::hash<int>(), std::equal_to<int>()), \
					 tagDataBinaryMinHeap(2, TagIntLess(), TagStringHasher(), TagStringEqual() ), \
					 tagDataTwelvearyMaxHeap(12, TagIntGreater(), TagStringHasher(), TagStringEqual())
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

		Heap<std::string, std::equal_to<std::string>, std::less<std::string>, std::hash<std::string> > stringBinaryMinHeap;
		Heap<int, std::equal_to<int>, std::greater<int>, std::hash<int> > intTwentySevenaryMaxHeap;
		Heap<TagData, TagStringEqual, TagIntLess, TagStringHasher> tagDataBinaryMinHeap;
		Heap<TagData, TagStringEqual, TagIntGreater, TagStringHasher> tagDataTwelvearyMaxHeap;

};



TEST_F(HeapTest, TagDataBinaryEmpty_09)
{
	EXPECT_TRUE(tagDataBinaryMinHeap.empty());
}

TEST_F(HeapTest, TagDataBinaryPushEmpty_10)
{
	tagDataBinaryMinHeap.push(TagData("tag",0));
	EXPECT_FALSE(tagDataBinaryMinHeap.empty());
}

TEST_F(HeapTest, TagDataBinaryPushTop_11)
{
	tagDataBinaryMinHeap.push(TagData("tag",0));
	EXPECT_EQ(tagDataBinaryMinHeap.top().num, 0);
}

TEST_F(HeapTest, TagDataBinaryPushPopEmpty_12)
{
	tagDataBinaryMinHeap.push(TagData("tag",0));
	tagDataBinaryMinHeap.pop();
	EXPECT_TRUE(tagDataBinaryMinHeap.empty());
}

TEST_F(HeapTest, TagDataBinaryMultiplePushInOrderPop_13)
{
	int numberOfInserts = 5;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		tagDataBinaryMinHeap.push(TagData(to_string(i),2*numberOfInserts-i));
		EXPECT_EQ(tagDataBinaryMinHeap.top().num, 2*numberOfInserts-i);
	}

	EXPECT_FALSE(tagDataBinaryMinHeap.empty());

	for(int i = 0; i < numberOfInserts; ++i)
	{
		tagDataBinaryMinHeap.decreaseKey(TagData(to_string(i),2*numberOfInserts-i), TagData(to_string(i),numberOfInserts-i));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		EXPECT_EQ(tagDataBinaryMinHeap.top().num, i+1);
		tagDataBinaryMinHeap.pop();
	}

	EXPECT_TRUE(tagDataBinaryMinHeap.empty());
}


TEST_F(HeapTest, TagDataTwelveEmpty_18)
{
	EXPECT_TRUE(tagDataTwelvearyMaxHeap.empty());
}

TEST_F(HeapTest, TagDataTwelvePushEmpty_19)
{
	tagDataTwelvearyMaxHeap.push(TagData("tag",0));
	EXPECT_FALSE(tagDataTwelvearyMaxHeap.empty());
}

TEST_F(HeapTest, TagDataTwelvePushTop_20)
{
	tagDataTwelvearyMaxHeap.push(TagData("tag",0));
	EXPECT_EQ(tagDataTwelvearyMaxHeap.top().num, 0);
}

TEST_F(HeapTest, TagDataTwelvePushPopEmpty_21)
{
	tagDataTwelvearyMaxHeap.push(TagData("tag",0));
	tagDataTwelvearyMaxHeap.pop();
	EXPECT_TRUE(tagDataTwelvearyMaxHeap.empty());
}

TEST_F(HeapTest, TagDataTwelveMultiplePushInOrderPop_22)
{
	int numberOfInserts = 5;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		tagDataTwelvearyMaxHeap.push(TagData(to_string(i),i));
		EXPECT_EQ(tagDataTwelvearyMaxHeap.top().num, i);
	}

	EXPECT_FALSE(tagDataTwelvearyMaxHeap.empty());

	for(int i = 0; i < numberOfInserts; ++i)
	{
		tagDataTwelvearyMaxHeap.decreaseKey( TagData(to_string(i),i), TagData(to_string(i),numberOfInserts+i) );	
		EXPECT_EQ(tagDataTwelvearyMaxHeap.top().num, numberOfInserts+i);
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		EXPECT_EQ(tagDataTwelvearyMaxHeap.top().num, 2*numberOfInserts - i - 1);
		tagDataTwelvearyMaxHeap.pop();
	}

	EXPECT_TRUE(tagDataTwelvearyMaxHeap.empty());
}
