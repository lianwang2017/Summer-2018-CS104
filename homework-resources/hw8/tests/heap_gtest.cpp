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

// ///////


TEST_F(HeapTest, StringRandomPushOrder100_01)
{
	int numberOfInserts = 100;
	vector<std::string> vals;
	vector<std::string> new_vals;
	stringstream ss;
	stringstream strstr;

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		vals.push_back(randomString);
		stringBinaryMinHeap.push(randomString);
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		stringBinaryMinHeap.decreaseKey(vals[i], randomString);
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


TEST_F(HeapTest, StringRandomPushOrder1000_02)
{
	int numberOfInserts = 1000;
	vector<std::string> vals;
	vector<std::string> new_vals;
	stringstream ss;
	stringstream strstr;

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		vals.push_back(randomString);
		stringBinaryMinHeap.push(randomString);
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		stringBinaryMinHeap.decreaseKey(vals[i], randomString);
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


TEST_F(HeapTest, StringRandomPushOrder10000_03)
{
	int numberOfInserts = 10000;
	vector<std::string> vals;
	vector<std::string> new_vals;
	stringstream ss;
	stringstream strstr;

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		vals.push_back(randomString);
		stringBinaryMinHeap.push(randomString);
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int randomNumber = rand();
		ss << randomNumber;
		string randomString = ss.str();
		stringBinaryMinHeap.decreaseKey(vals[i], randomString);
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

///// //

/*
	These are the tests for the int, TwentySeven-ary, max-heap. The tests are:

	22. IntTwentySevenEmpty_18: Checks that the heap is initially empty.
	23. IntTwentySevenPushEmpty_23: Checks that the heap is not empty after pushing 1 item.
	24. IntTwentySevenPushTop_24: Checks that the top is correct after pushing 1 item. 
	25. IntTwentySevenPushPopEmpty_25: Checks that the heap is empty after pushing 1 item and poping the heap.
	26. IntTwentySevenMultiplePushInOrderPop_26: Pushes 5 elements in max order, checks as they are pushed to the 
									 	 heap, checks the heap is not empty, pops items and checks their
									 	 order as they are poped, and finally checks the heap is empty. 
	TwentySeven. IntTwentySevenRandomPushOrder_TwentySeven: Pushes 100 random ints using rand(),
								  pops to check their comparative status, looking that they are >= as we top()/pop(). \	  
*/

// ///////

TEST_F(HeapTest, IntTwentySevenRandomPushOrder100_04)
{
	int numberOfInserts = 100;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		intTwentySevenaryMaxHeap.push(vals.back());
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.decreaseKey(vals[i], rand());
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

TEST_F(HeapTest, IntTwentySevenRandomPushOrder1000_05)
{
	int numberOfInserts = 1000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		intTwentySevenaryMaxHeap.push(vals.back());
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.decreaseKey(vals[i], rand());
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


TEST_F(HeapTest, IntTwentySevenRandomPushOrder10000_06)
{
	int numberOfInserts = 10000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		intTwentySevenaryMaxHeap.push(vals.back());
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.decreaseKey(vals[i], rand());
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


TEST_F(HeapTest, IntTwentySevenRandomPushOrder100000_07)
{
	int numberOfInserts = 100000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		intTwentySevenaryMaxHeap.push(vals.back());
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.decreaseKey(vals[i], rand());
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

TEST_F(HeapTest, IntTwentySevenRandomPushOrder1000000_08)
{
	int numberOfInserts = 1000000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		intTwentySevenaryMaxHeap.push(vals.back());
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		intTwentySevenaryMaxHeap.decreaseKey(vals[i], rand());
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

///// //

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

TEST_F(HeapTest, TagDataBinaryRandomPushOrder100_14)
{
	int numberOfInserts = 100;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataBinaryMinHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran < vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}	}

	while(!tagDataBinaryMinHeap.empty())
	{
		int top = tagDataBinaryMinHeap.top().num;
		tagDataBinaryMinHeap.pop();
		if(!tagDataBinaryMinHeap.empty())
		{
			EXPECT_LE(top, tagDataBinaryMinHeap.top().num);
		}
	}
}

TEST_F(HeapTest, TagDataBinaryRandomPushOrder1000_15)
{
	int numberOfInserts = 1000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataBinaryMinHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran < vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}	}

	while(!tagDataBinaryMinHeap.empty())
	{
		int top = tagDataBinaryMinHeap.top().num;
		tagDataBinaryMinHeap.pop();
		if(!tagDataBinaryMinHeap.empty())
		{
			EXPECT_LE(top, tagDataBinaryMinHeap.top().num);
		}
	}
}

TEST_F(HeapTest, TagDataBinaryRandomPushOrder10000_16)
{
	int numberOfInserts = 10000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataBinaryMinHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran < vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}	}

	while(!tagDataBinaryMinHeap.empty())
	{
		int top = tagDataBinaryMinHeap.top().num;
		tagDataBinaryMinHeap.pop();
		if(!tagDataBinaryMinHeap.empty())
		{
			EXPECT_LE(top, tagDataBinaryMinHeap.top().num);
		}
	}
}


TEST_F(HeapTest, TagDataBinaryRandomPushOrder100000_17)
{
	int numberOfInserts = 100000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataBinaryMinHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran < vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}
	}

	while(!tagDataBinaryMinHeap.empty())
	{
		int top = tagDataBinaryMinHeap.top().num;
		tagDataBinaryMinHeap.pop();
		if(!tagDataBinaryMinHeap.empty())
		{
			EXPECT_LE(top, tagDataBinaryMinHeap.top().num);
		}
	}
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

TEST_F(HeapTest, TagDataTwelveRandomPushOrder100_23)
{
	int numberOfInserts = 100;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataTwelvearyMaxHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran > vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}
	}

	while(!tagDataTwelvearyMaxHeap.empty())
	{
		int top = tagDataTwelvearyMaxHeap.top().num;
		tagDataTwelvearyMaxHeap.pop();
		if(!tagDataTwelvearyMaxHeap.empty())
		{
			EXPECT_GE(top, tagDataTwelvearyMaxHeap.top().num);
		}
	}
}

TEST_F(HeapTest, TagDataTwelveRandomPushOrder1000_24)
{
	int numberOfInserts = 1000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataTwelvearyMaxHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran > vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}
	}

	while(!tagDataTwelvearyMaxHeap.empty())
	{
		int top = tagDataTwelvearyMaxHeap.top().num;
		tagDataTwelvearyMaxHeap.pop();
		if(!tagDataTwelvearyMaxHeap.empty())
		{
			EXPECT_GE(top, tagDataTwelvearyMaxHeap.top().num);
		}
	}
}

TEST_F(HeapTest, TagDataTwelveRandomPushOrder10000_25)
{
	int numberOfInserts = 10000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataTwelvearyMaxHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran > vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}
	}

	while(!tagDataTwelvearyMaxHeap.empty())
	{
		int top = tagDataTwelvearyMaxHeap.top().num;
		tagDataTwelvearyMaxHeap.pop();
		if(!tagDataTwelvearyMaxHeap.empty())
		{
			EXPECT_GE(top, tagDataTwelvearyMaxHeap.top().num);
		}
	}
}

TEST_F(HeapTest, TagDataTwelveRandomPushOrder100000_26)
{
	int numberOfInserts = 100000;
	vector<int> vals;
	for(int i = 0; i < numberOfInserts; ++i)
	{
		vals.push_back(rand());
		tagDataTwelvearyMaxHeap.push(TagData(to_string(vals.back()), vals.back()));
	}

	for(int i = 0; i < numberOfInserts; ++i)
	{
		int ran = rand();
		if(ran > vals[i]){
			tagDataTwelvearyMaxHeap.decreaseKey( TagData( to_string(vals[i]), vals[i] ), TagData( to_string(vals[i]), ran) );
		}
	}

	while(!tagDataTwelvearyMaxHeap.empty())
	{
		int top = tagDataTwelvearyMaxHeap.top().num;
		tagDataTwelvearyMaxHeap.pop();
		if(!tagDataTwelvearyMaxHeap.empty())
		{
			EXPECT_GE(top, tagDataTwelvearyMaxHeap.top().num);
		}
	}
}
