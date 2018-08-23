#include "lliststr.h"
#include "gtest/gtest.h"
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::endl;

class LListStrTest : public testing::Test
{
	protected:
		LListStrTest()
		{

		}

		~LListStrTest()
		{

		}

		virtual void SetUp()
		{

		}

		virtual void TearDown()
		{

		}

		LListStr studentLinkedList;
};

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

TEST_F(LListStrTest, GoodInitialEmpty_01)
{
	EXPECT_TRUE(studentLinkedList.empty());
}

TEST_F(LListStrTest, GoodInitialSize_02)
{
	EXPECT_EQ(studentLinkedList.size(), 0);
}

TEST_F(LListStrTest, GoodInsertSizeEmpty_03)
{
	studentLinkedList.insert(0, "Aaron");
	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(studentLinkedList.size(), 1);
}

TEST_F(LListStrTest, GoodInsertGet_04)
{
	studentLinkedList.insert(0, "Aaron");
	EXPECT_EQ(studentLinkedList.get(0), "Aaron");
}

TEST_F(LListStrTest, GoodMultipleInsertGetOrder_05)
{
	studentLinkedList.insert(0, "Aaron");
	studentLinkedList.insert(1, "Betty");
	studentLinkedList.insert(2, "Carla");

	EXPECT_EQ(studentLinkedList.get(0), "Aaron");
	EXPECT_EQ(studentLinkedList.get(1), "Betty");
	EXPECT_EQ(studentLinkedList.get(2), "Carla");
}

TEST_F(LListStrTest, GoodInsertSetGetSizeEmpty_06)
{
	studentLinkedList.insert(0, "Aaron");
	studentLinkedList.set(0, "Betty");
	EXPECT_EQ(studentLinkedList.get(0), "Betty");
}

TEST_F(LListStrTest, GoodInsertRemoveSizeEmpty_07)
{
	studentLinkedList.insert(0, "Aaron");
	studentLinkedList.remove(0);
	EXPECT_EQ(studentLinkedList.size(), 0);
	EXPECT_TRUE(studentLinkedList.empty());
}

TEST_F(LListStrTest, GoodInitialPushBackGetOrderSizeEmpty_08)
{
	studentLinkedList.push_back("Aaron");

	EXPECT_EQ(studentLinkedList.get(0), "Aaron");
	EXPECT_FALSE(studentLinkedList.empty());
	EXPECT_EQ(studentLinkedList.size(), 1);
}

TEST_F(LListStrTest, BadInitialInsertSizeEmpty_01)
{
	studentLinkedList.insert(1, "Aaron");

	EXPECT_EQ(studentLinkedList.size(), 0);
	EXPECT_TRUE(studentLinkedList.empty());
}

TEST_F(LListStrTest, BadInitialRemoveEmptySize_03)
{
	studentLinkedList.remove(0);

	EXPECT_TRUE(studentLinkedList.empty());
	EXPECT_EQ(studentLinkedList.size(), 0);
}

TEST_F(LListStrTest, GoodSpeedPushBack1000Elements)
{
	for(int i = 0; i < 1000; ++i)
	{
		studentLinkedList.push_back("A");
	}

	EXPECT_EQ(studentLinkedList.size(), 1000);
}

TEST_F(LListStrTest, GoodSpeedPushBack10000Elements)
{
	for(int i = 0; i < 10000; ++i)
	{
		studentLinkedList.push_back("A");
	}

	EXPECT_EQ(studentLinkedList.size(), 10000);
}

TEST_F(LListStrTest, GoodInitialCopyConstructorSizeEmpty_01)
{
	LListStr newList(studentLinkedList);

	EXPECT_EQ(studentLinkedList.size(), 0);
	EXPECT_TRUE(studentLinkedList.empty());

	EXPECT_EQ(newList.size(), studentLinkedList.size());
	EXPECT_EQ(newList.empty(), studentLinkedList.empty());
}

TEST_F(LListStrTest, GoodCopyConstructorSizeEmpty_02)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList(studentLinkedList);

	EXPECT_EQ(studentLinkedList.size(), 3);
	EXPECT_EQ(newList.size(), studentLinkedList.size());
	EXPECT_FALSE(newList.empty());
}

TEST_F(LListStrTest, GoodCopyConstructorGetOrder_03)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList(studentLinkedList);

	EXPECT_EQ(studentLinkedList.get(0), "Aaron");
	EXPECT_EQ(studentLinkedList.get(1), "Betty");
	EXPECT_EQ(studentLinkedList.get(2), "Carla");

	EXPECT_EQ(newList.get(0), studentLinkedList.get(0));
	EXPECT_EQ(newList.get(1), studentLinkedList.get(1));
	EXPECT_EQ(newList.get(2), studentLinkedList.get(2));
}

TEST_F(LListStrTest, GoodCopyConstructorSetDifferentValues_04)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList(studentLinkedList);

	newList.set(0, "David");
	newList.set(2, "Elfaba");

	EXPECT_NE(newList.get(0), studentLinkedList.get(0));
	EXPECT_EQ(newList.get(1), studentLinkedList.get(1));
	EXPECT_NE(newList.get(2), studentLinkedList.get(2));
}

TEST_F(LListStrTest, GoodInitialAssignmentOperatorSizeEmpty_01)
{
	LListStr newList; 
	newList = studentLinkedList;

	EXPECT_EQ(studentLinkedList.size(), 0);
	EXPECT_TRUE(studentLinkedList.empty());

	EXPECT_EQ(newList.size(), studentLinkedList.size());
	EXPECT_EQ(newList.empty(), studentLinkedList.empty());
}

TEST_F(LListStrTest, GoodAssignmentOperatorSizeEmpty_02)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList; 
	newList = studentLinkedList;

	EXPECT_EQ(studentLinkedList.size(), 3);
	EXPECT_EQ(newList.size(), studentLinkedList.size());
	EXPECT_FALSE(newList.empty());
}

TEST_F(LListStrTest, GoodAssignmentOperatorGetOrder_03)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList;
	newList = studentLinkedList;

	EXPECT_EQ(studentLinkedList.get(0), "Aaron");
	EXPECT_EQ(studentLinkedList.get(1), "Betty");
	EXPECT_EQ(studentLinkedList.get(2), "Carla");

	EXPECT_EQ(newList.get(0), studentLinkedList.get(0));
	EXPECT_EQ(newList.get(1), studentLinkedList.get(1));
	EXPECT_EQ(newList.get(2), studentLinkedList.get(2));
}

TEST_F(LListStrTest, GoodAssignmentOperatorSetDifferentValues_04)
{
	studentLinkedList.push_back("Aaron");
	studentLinkedList.push_back("Betty");
	studentLinkedList.push_back("Carla");

	LListStr newList;
	newList = studentLinkedList;

	newList.set(0, "David");
	newList.set(2, "Elfaba");

	EXPECT_NE(newList.get(0), studentLinkedList.get(0));
	EXPECT_EQ(newList.get(1), studentLinkedList.get(1));
	EXPECT_NE(newList.get(2), studentLinkedList.get(2));
}