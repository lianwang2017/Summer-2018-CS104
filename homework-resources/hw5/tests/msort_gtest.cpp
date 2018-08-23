/*
	Google Test file for templated merge sort. There are three main test areas, testing integers,
	strings, and DateTime objects, respectively. 

	Intended to run using student mergesort implementation as well as student DateTime objects. 
*/

#include "../msort.h"		// Student mergesort implementation.
#include "gtest/gtest.h"
#include <functional>		// For std::greater and std::less comparators. 

/*
	These are all of the options we have given the students for implementing merge sort.
	Their merge sort algorithm should work with one of these containers, although most
	students will probably have a vector implementation. 
*/
#include <list>
#include <deque>
#include <vector>

#include <string>		// For string tests.
#include "../datetime.h"	// For DateTime tests. 

using namespace std;

/*
	If students are using a container type other than vector, change the container type here.
	The tests use iterators to check contents, so making a single change here will keep the
	validity of the tests. 
*/
typedef vector<int> IntContainer;
typedef vector<string> StringContainer;
typedef vector<DateTime> DateTimeContainer;

/*
	Students are not required to have an operator==() defined. This is defined here so 
	that Google Tests can run properly with EXPECT_EQ() tests. 
*/
bool operator==(const DateTime& date1, const DateTime& date2)
{
	if(date1.year != date2.year) return false;
	else if(date1.month != date2.month) return false;
	else if(date1.day != date2.day) return false;
	else if(date1.hour != date2.hour) return false;
	else if(date1.min != date2.min) return false;
	else if(date1.sec != date2.sec) return false;
	else return true;
}

/*
	Students are not required to have an operator>() defined. This is defined here so 
	that the std::greater<DateTime> tests can be run. 
*/
bool operator>(const DateTime& date1, const DateTime& date2)
{
	if(date1.year > date2.year) return true;
	else if(date1.year < date2.year) return false;

	if(date1.month > date2.month) return true;
	else if(date1.month < date2.month) return false;

	if(date1.day > date2.day) return true;
	else if(date1.day < date2.day) return false;

	if(date1.hour > date2.hour) return true;
	else if(date1.hour < date2.hour) return false;

	if(date1.min > date2.min) return true;
	else if(date1.min < date2.min) return false;

	if(date1.sec > date2.sec) return true;
	else if(date1.sec < date2.sec) return false;

	return false;
}

/*
	Testing environment. 
*/
class MSortTest : public testing::Test
{
	protected:
		MSortTest()
		{

		}

		~MSortTest()
		{

		}

		virtual void SetUp()
		{

		}

		virtual void TearDown()
		{

		}

		IntContainer intContainer;
		StringContainer stringContainer;
		DateTimeContainer datetimeContainer;
};

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

/*
	These are tests for integers. In total, there are 12 tests for the integers. They are:

	1. IntInOrderLess -- Checks on list that is already sorted in increasing order.
	2. IntInOrderGreater -- Checks on list that is already sorted in decreasing order. 
	3. IntScrambledLess -- Checks on list with scrambled integers, and looks for increasing order. 
	4. IntScrambledGreater -- Checks on list with scrambled integers, and looks for decreasing order.
	5. IntDuplicateLess -- Checks on list with scrambled integers containing duplicates, looking for increasing.
	6. IntDuplicateGreater -- Checks on list with scrambled integers containing duplicates, looks for decreasing.
	7 - 9. IntLarge*Less -- Inserts 10,000/100,000/1,000,000 random integers and looks for increasing order.
	10 - 12. IntLarge*Greater -- Inserts 10,000/100,000/1,000,000 random integers and looks for decreasing order. 
*/


TEST_F(MSortTest, IntInOrderLess_01)
{
	intContainer.push_back(0);
	intContainer.push_back(1);
	intContainer.push_back(2);
	intContainer.push_back(3);
	intContainer.push_back(4);
	intContainer.push_back(5);

	less<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++it, ++i)
	{
		EXPECT_EQ(*it, i);
	}
}

TEST_F(MSortTest, IntInOrderGreater_02)
{
	intContainer.push_back(5);
	intContainer.push_back(4);
	intContainer.push_back(3);
	intContainer.push_back(2);
	intContainer.push_back(1);
	intContainer.push_back(0);

	greater<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++it, ++i)
	{
		EXPECT_EQ(*it, 5 - i);
	}
}

TEST_F(MSortTest, IntScrambledLess_03)
{
	intContainer.push_back(0);
	intContainer.push_back(5);
	intContainer.push_back(3);
	intContainer.push_back(2);
	intContainer.push_back(4);
	intContainer.push_back(1);

	less<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++it, ++i)
	{
		EXPECT_EQ(*it, i);
	}
}

TEST_F(MSortTest, IntScrambledGreater_04)
{
	intContainer.push_back(0);
	intContainer.push_back(5);
	intContainer.push_back(3);
	intContainer.push_back(2);
	intContainer.push_back(4);
	intContainer.push_back(1);

	greater<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++it, ++i)
	{
		EXPECT_EQ(*it,  5 - i);
	}
}


TEST_F(MSortTest, IntDuplicateLess_05)
{
	intContainer.push_back(0);
	intContainer.push_back(1);
	intContainer.push_back(3);
	intContainer.push_back(3);
	intContainer.push_back(1);
	intContainer.push_back(5);

	less<int> comp;
	mergeSort(intContainer, comp);

	IntContainer::iterator it = intContainer.begin();
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*it, 0);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 1);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 1);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 3);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 3);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 5);
}

TEST_F(MSortTest, IntDuplicateGreater_06)
{
	intContainer.push_back(0);
	intContainer.push_back(1);
	intContainer.push_back(3);
	intContainer.push_back(3);
	intContainer.push_back(1);
	intContainer.push_back(5);

	greater<int> comp;
	mergeSort(intContainer, comp);

	IntContainer::iterator it = intContainer.begin();
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*it, 5);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 3);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 3);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 1);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 1);
	ASSERT_FALSE(it == intContainer.end()); EXPECT_EQ(*(++it), 0);
}

TEST_F(MSortTest, IntLarge1000Less_07)
{
	for(int i = 0; i < 1000; ++i)
	{
		intContainer.push_back(rand());
	}

	less<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_LE(*it, *(++it));
	}

	EXPECT_EQ(i, 1000);
}

TEST_F(MSortTest, IntLarge10000Less_08)
{
	for(int i = 0; i < 10000; ++i)
	{
		intContainer.push_back(rand());
	}

	less<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_LE(*it, *(++it));
	}

	EXPECT_EQ(i, 10000);
}

TEST_F(MSortTest, IntLarge100000Less_09)
{
	for(int i = 0; i < 100000; ++i)
	{
		intContainer.push_back(rand());
	}

	less<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_LE(*it, *(++it));
	}

	EXPECT_EQ(i, 100000);
}

TEST_F(MSortTest, IntLarge1000Greater_10)
{
	for(int i = 0; i < 1000; ++i)
	{
		intContainer.push_back(rand());
	}

	greater<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_GE(*it, *(++it));
	}

	EXPECT_EQ(i, 1000);
}

TEST_F(MSortTest, IntLarge10000Greater_11)
{
	for(int i = 0; i < 10000; ++i)
	{
		intContainer.push_back(rand());
	}

	greater<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_GE(*it, *(++it));
	}

	EXPECT_EQ(i, 10000);
}

TEST_F(MSortTest, IntLarge100000Greater_12)
{
	for(int i = 0; i < 100000; ++i)
	{
		intContainer.push_back(rand());
	}

	greater<int> comp;
	mergeSort(intContainer, comp);

	int i = 0;
	for(IntContainer::iterator it = intContainer.begin(); it != intContainer.end(); ++i)
	{
		EXPECT_GE(*it, *(++it));
	}

	EXPECT_EQ(i, 100000);
}

/*
	These are tests for strings. In total there are 6 tests for strings. They are:

	13. StringInOrderLess -- Checks on list with strings already in increasing order, looking for increasing.
	14. StringInOrderGreater -- Checks on list with strings already inserted in decreasing order, looking for decreasing.
	15. StringScrambledLess -- Checks on list with scrambled strings order, looking for increasing.
	16. StringScrambledGreater -- Checks on list with scrambled strings order, looking for decreasing.
	17. StringDuplicateLess -- Checks on list with scrambled string order and duplicates, looking for increasing.
	18. StringDuplicateGreater -- Checks on list with scrambled string order and duplicates, looking for increasing.
*/

TEST_F(MSortTest, StringInOrderLess_13)
{
	stringContainer.push_back("Aaron");
	stringContainer.push_back("Betty");
	stringContainer.push_back("Carla");
	stringContainer.push_back("David");
	stringContainer.push_back("Esther");

	less<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Aaron");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Carla");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "David");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Esther");
}

TEST_F(MSortTest, StringInOrderGreater_14)
{
	stringContainer.push_back("Esther");
	stringContainer.push_back("David");
	stringContainer.push_back("Carla");
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");

	greater<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Esther");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "David");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Carla");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Aaron");
}

TEST_F(MSortTest, StringScrambledLess_15)
{
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");
	stringContainer.push_back("Esther");
	stringContainer.push_back("Carla");
	stringContainer.push_back("David");

	less<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Aaron");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Carla");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "David");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Esther");
}

TEST_F(MSortTest, StringScrambledGreater_16)
{
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");
	stringContainer.push_back("Esther");
	stringContainer.push_back("Carla");
	stringContainer.push_back("David");

	greater<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Esther");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "David");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Carla");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Aaron");
}

TEST_F(MSortTest, StringDuplicateLess_17)
{
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");
	stringContainer.push_back("Esther");
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");

	less<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Aaron");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Aaron");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Esther");
}

TEST_F(MSortTest, StringDuplicateGreater_18)
{
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");
	stringContainer.push_back("Esther");
	stringContainer.push_back("Betty");
	stringContainer.push_back("Aaron");

	greater<string> comp;
	mergeSort(stringContainer, comp);

	StringContainer::iterator it = stringContainer.begin();
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*it, "Esther");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Betty");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Aaron");
	ASSERT_FALSE(it == stringContainer.end()); EXPECT_EQ(*(++it), "Aaron");
}

/*
	These are the tests for the DateTime object. The DateTime variables have been given names containing all
	of their information in order to make it more readable. The variable name first has the date, then 
	separated by two underscores it has the time. 

	In total there are 6 Tests. They are:

	19. DateTimeInOrderLess -- Checks list with DateTime elements already in order, looks for increasing.
	20. DateTimeInOrderGreater -- Checks list with DateTime elements already in order, looks for decreasing.
	21. DateTimeScrambledLess -- Checks for increasing DateTime order with scrambled initial input.
	22. DateTimeScrambledGreater -- Checks for decreasing DateTime order with scrambled initial input.
	23. DateTimeDuplicateLess -- Checks for increasing DateTime order with scrambled and duplicate initial input.
	24. DateTimeDuplicateGreater -- Checks for decreasing DateTime order with scrambled and duplicate initial input. 
*/

TEST_F(MSortTest, DateTimeInOrderLess_19)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(October_25_1993__05_54_54);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(February_15_2015__18_55_43);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_21_2015__07_08_54);

	less<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_25_1993__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_21_2015__07_08_54);
}


TEST_F(MSortTest, DateTimeInOrderGreater_20)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(October_21_2015__07_08_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(February_15_2015__18_55_43);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(October_25_1993__05_54_54);

	greater<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_21_2015__07_08_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_1993__05_54_54);
}

TEST_F(MSortTest, DateTimeScrambledLess_21)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_25_1993__05_54_54);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(October_21_2015__07_08_54);
	datetimeContainer.push_back(February_15_2015__18_55_43);

	less<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_25_1993__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_21_2015__07_08_54);
}

TEST_F(MSortTest, DateTimeScrambledGreater_22)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_25_1993__05_54_54);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(October_21_2015__07_08_54);
	datetimeContainer.push_back(February_15_2015__18_55_43);

	greater<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_21_2015__07_08_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_1993__05_54_54);
}

TEST_F(MSortTest, DateTimeDuplicateLess_23)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_25_1993__05_54_54);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_21_2015__07_08_54);
	datetimeContainer.push_back(February_15_2015__18_55_43);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(October_25_2014__05_54_54);

	less<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_25_1993__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_21_2015__07_08_54);
}

TEST_F(MSortTest, DateTimeDuplicateGreater_24)
{
	DateTime October_25_1993__05_54_54(5, 54, 54, 1993, 10, 25);
	DateTime October_25_2014__05_54_54(5, 54, 54, 2014, 10, 25);
	DateTime February_14_2015__17_46_54(17, 46, 54, 2015, 2, 14);
	DateTime February_15_2015__18_55_43(18, 55, 43, 2015, 2, 15);
	DateTime April_1_2015__22_22_50(22, 22, 50, 2015, 4, 1);
	DateTime April_1_2015__23_22_54(23, 22, 54, 2015, 4, 1);
	DateTime August_11_2015__01_13_54(1, 13, 54, 2015, 8, 11);
	DateTime October_21_2015__07_08_54(7, 8, 54, 2015, 10, 21);

	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_25_1993__05_54_54);
	datetimeContainer.push_back(April_1_2015__22_22_50);
	datetimeContainer.push_back(October_25_2014__05_54_54);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(April_1_2015__23_22_54);
	datetimeContainer.push_back(August_11_2015__01_13_54);
	datetimeContainer.push_back(October_21_2015__07_08_54);
	datetimeContainer.push_back(February_15_2015__18_55_43);
	datetimeContainer.push_back(February_14_2015__17_46_54);
	datetimeContainer.push_back(October_25_2014__05_54_54);

	greater<DateTime> comp;
	mergeSort(datetimeContainer, comp);

	DateTimeContainer::iterator it = datetimeContainer.begin();
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*it, October_21_2015__07_08_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), August_11_2015__01_13_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__23_22_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), April_1_2015__22_22_50);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_15_2015__18_55_43);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), February_14_2015__17_46_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_2014__05_54_54);
	ASSERT_FALSE(it == datetimeContainer.end()); EXPECT_EQ(*(++it), October_25_1993__05_54_54);
}
