#include "setstr.h"
#include "gtest/gtest.h"
#include <cstdlib>
#include <iostream>
#include <string>

class SetStrTest : public testing::Test
{
	protected:
		SetStrTest()
		{

		}

		~SetStrTest()
		{

		}

		virtual void SetUp()
		{

		}

		virtual void TearDown()
		{

		}

		SetStr studentSet;
};

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

TEST_F(SetStrTest, GoodInitialEmpty_01)
{
	EXPECT_TRUE(studentSet.empty());
}

TEST_F(SetStrTest, GoodInitialSize_02)
{
	EXPECT_EQ(studentSet.size(), 0);
}

TEST_F(SetStrTest, GoodInsertExistsSizeEmpty_03)
{
	studentSet.insert("Aaron");
	EXPECT_TRUE(studentSet.exists("Aaron"));
	EXPECT_FALSE(studentSet.empty());
	EXPECT_EQ(studentSet.size(), 1);
}

TEST_F(SetStrTest, GoodInsertRemoveExistsSizeEmpty_04)
{
	studentSet.insert("Aaron");
	studentSet.remove("Aaron");
	EXPECT_FALSE(studentSet.exists("Aaron"));
	EXPECT_EQ(studentSet.size(), 0);
	EXPECT_TRUE(studentSet.empty());
}

TEST_F(SetStrTest, BadInitialExists_05)
{
	EXPECT_FALSE(studentSet.exists("Aaron"));
}

TEST_F(SetStrTest, BadInitialRemoveExistsEmptySize_06)
{
	studentSet.remove("Aaron");

	EXPECT_FALSE(studentSet.exists("Aaron"));
	EXPECT_EQ(studentSet.size(), 0);
	EXPECT_TRUE(studentSet.empty());
}

TEST_F(SetStrTest, GoodMultipleInsertFirstNextOrder_07)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
}

TEST_F(SetStrTest, BadMultipleInsertFirstNextOrderFirstNextOrder_08)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
}

TEST_F(SetStrTest, BadInitialFirst_09)
{
	const std::string *first = studentSet.first();
	EXPECT_FALSE(first);
}

TEST_F(SetStrTest, BadInitialNext_10)
{
	const std::string *next = studentSet.next();
	EXPECT_FALSE(next);
}

TEST_F(SetStrTest, BadMultipleInsertFirstNextPastEnd_11)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
	EXPECT_FALSE(studentSet.next());
}

TEST_F(SetStrTest, BadMultipleInsertFirstNextPastEndResetFirstNext_12)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
	EXPECT_FALSE(studentSet.next());
	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
}

TEST_F(SetStrTest, GoodMultipleInsertRemoveHeadFirstNextOrderSizeEmpty_13)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	studentSet.remove("Aaron");

	EXPECT_EQ(*studentSet.first(), "Betty");
	EXPECT_EQ(*studentSet.next(), "Carla");
	EXPECT_EQ(studentSet.size(), 2);
	EXPECT_FALSE(studentSet.empty());
}

TEST_F(SetStrTest, GoodMultipleInsertRemoveMiddleFirstNextOrderSizeEmpty_14)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	studentSet.remove("Betty");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Carla");
	EXPECT_EQ(studentSet.size(), 2);
	EXPECT_FALSE(studentSet.empty());
}

TEST_F(SetStrTest, GoodMultipleInsertRemoveTailFirstNextOrderSizeEmpty_15)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	studentSet.remove("Carla");

	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(*studentSet.next(), "Betty");
	EXPECT_EQ(studentSet.size(), 2);
	EXPECT_FALSE(studentSet.empty());
}

TEST_F(SetStrTest, BadRemoveFirstOrderExistsSizeEmpty_16)
{
	studentSet.insert("Aaron");
	studentSet.remove("Betty");

	EXPECT_TRUE(studentSet.exists("Aaron"));
	EXPECT_EQ(*studentSet.first(), "Aaron");
	EXPECT_EQ(studentSet.size(), 1);
	EXPECT_FALSE(studentSet.empty());
}

TEST_F(SetStrTest, GoodUnionFunctionExistsSizeEmpty_17)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("David");
	otherSet.insert("Elizabeth");
	otherSet.insert("Francis");

	SetStr unionSet; 
	unionSet = studentSet.setUnion(otherSet);

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_TRUE(unionSet.exists("David"));
	EXPECT_TRUE(unionSet.exists("Elizabeth"));
	EXPECT_TRUE(unionSet.exists("Francis"));
	EXPECT_EQ(unionSet.size(), 6);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, GoodUnionFunctionDuplicateExistsSizeEmpty_18)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("Aaron");
	otherSet.insert("Carla");
	otherSet.insert("Elizabeth");

	SetStr unionSet;
	unionSet = studentSet.setUnion(otherSet);

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_TRUE(unionSet.exists("Elizabeth"));
	EXPECT_EQ(unionSet.size(), 4);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, BadUnionFunctionEmptyExistsSizeEmpty_19)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;

	SetStr unionSet;
	unionSet = otherSet.setUnion(studentSet);

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_EQ(unionSet.size(), 3);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, GoodUnionOperatorExistsSizeEmpty_20)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("David");
	otherSet.insert("Elizabeth");
	otherSet.insert("Francis");

	SetStr unionSet; 
	unionSet = studentSet | otherSet;

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_EQ(unionSet.size(), 6);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, GoodUnionOperatorDuplicateExistsSizeEmpty_21)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("Aaron");
	otherSet.insert("Carla");
	otherSet.insert("Elizabeth");

	SetStr unionSet;
	unionSet = studentSet | otherSet;

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_TRUE(unionSet.exists("Elizabeth"));
	EXPECT_EQ(unionSet.size(), 4);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, BadUnionOperatorEmptyExistsSizeEmpty_22)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;

	SetStr unionSet;
	unionSet = otherSet | studentSet;

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_TRUE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_EQ(unionSet.size(), 3);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, GoodIntersectionFunctionExistsSizeEmpty_23)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("David");
	otherSet.insert("Elizabeth");
	otherSet.insert("Francis");

	SetStr unionSet; 
	unionSet = studentSet.setIntersection(otherSet);

	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_EQ(unionSet.size(), 0);
	EXPECT_TRUE(unionSet.empty());
}

TEST_F(SetStrTest, GoodIntersectionFunctionDuplicateExistsSizeEmpty_24)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("Aaron");
	otherSet.insert("Carla");
	otherSet.insert("Elizabeth");

	SetStr unionSet;
	unionSet = studentSet.setIntersection(otherSet);

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_FALSE(unionSet.exists("Elizabeth"));
	EXPECT_EQ(unionSet.size(), 2);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, BadIntersectionFunctionEmptyExistsSizeEmpty_25)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;

	SetStr unionSet;
	unionSet = otherSet.setIntersection(studentSet);

	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Betty"));
	EXPECT_FALSE(unionSet.exists("Carla"));
	EXPECT_EQ(unionSet.size(), 0);
	EXPECT_TRUE(unionSet.empty());
}

TEST_F(SetStrTest, GoodIntersectionOperatorExistsSizeEmpty_26)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("David");
	otherSet.insert("Elizabeth");
	otherSet.insert("Francis");

	SetStr unionSet; 
	unionSet = studentSet & otherSet;

	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_EQ(unionSet.size(), 0);
	EXPECT_TRUE(unionSet.empty());
}

TEST_F(SetStrTest, GoodIntersectionOperatorDuplicateExistsSizeEmpty_27)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;
	otherSet.insert("Aaron");
	otherSet.insert("Carla");
	otherSet.insert("Elizabeth");

	SetStr unionSet;
	unionSet = studentSet & otherSet;

	EXPECT_TRUE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Betty"));
	EXPECT_TRUE(unionSet.exists("Carla"));
	EXPECT_FALSE(unionSet.exists("Elizabeth"));
	EXPECT_EQ(unionSet.size(), 2);
	EXPECT_FALSE(unionSet.empty());
}

TEST_F(SetStrTest, BadIntersectionOperatorEmptyExistsSizeEmpty_28)
{
	studentSet.insert("Aaron");
	studentSet.insert("Betty");
	studentSet.insert("Carla");

	SetStr otherSet;

	SetStr unionSet;
	unionSet = otherSet & studentSet;

	EXPECT_FALSE(unionSet.exists("Aaron"));
	EXPECT_FALSE(unionSet.exists("Betty"));
	EXPECT_FALSE(unionSet.exists("Carla"));
	EXPECT_EQ(unionSet.size(), 0);
	EXPECT_TRUE(unionSet.empty());
}