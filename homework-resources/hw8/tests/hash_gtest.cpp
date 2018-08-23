/*
	Google Test for testing a student's hash.cpp. 

	Interface functions given for students to implement:

		calculateHash(string mystring);

	Solution functions given:

		solHash(string mystring);
*/

#include "gtest/gtest.h"
#include "../hash.h"		// Student's hash.h
#include "sol_hash.h"
#include <string>
#include <sstream>			// For generating random strings. 

using namespace std;

class HashTest : public testing::Test 
{
	protected:
		HashTest()
		{

		}

		~HashTest() 
		{

		}

		virtual void SetUp() 
		{

		}

		virtual void TearDown() 
		{

		}
};

/*
	Tests:
		1. Empty String
		2. Small String
		3. Medium String
		4. Large String
		5. String with Special Character
		6. Strings with Random Chars, 1000
		7. Strings with Random Chars, 100000

*/

TEST_F(HashTest, EmptyString_01)
{
	string test = "";
	EXPECT_EQ(calculateHash(test),solHash(test));
}

TEST_F(HashTest, SmallString_02)
{
	string test = "hi";
	EXPECT_EQ(calculateHash(test),solHash(test));
}

TEST_F(HashTest, MediumString_03)
{
	string test = "fifth";
	EXPECT_EQ(calculateHash(test),solHash(test));
}

TEST_F(HashTest, LargeString_04)
{
	string test = "ZELLWORD";
	EXPECT_EQ(calculateHash(test),solHash(test));
}

TEST_F(HashTest, SpecialCharString_05)
{
	string test = "Z@77WO4D";
	EXPECT_EQ(calculateHash(test),solHash(test));
}

TEST_F(HashTest, RandomChars1000_06)
{
	vector<string> tests;
	int num_strings = 1000;
	for(int i = 0; i < num_strings; i++){
		int size = (rand() % 8)+1;
		string tmp = "";
		for(int j = 0; j < size; j++)
		{
			tmp += (static_cast<char>(rand()/128));
		}
		tests.push_back(tmp);
	}
	for(size_t i = 0; i < tests.size(); i++){
		EXPECT_EQ(calculateHash(tests[i]),solHash(tests[i]));
	}
}


TEST_F(HashTest, RandomChars100000_07)
{
	vector<string> tests;
	int num_strings = 100000;
	for(int i = 0; i < num_strings; i++){
		int size = (rand() % 8)+1;
		string tmp = "";
		for(int j = 0; j < size; j++)
		{
			tmp += static_cast<char>(rand()/128);
		}
		tests.push_back(tmp);
	}
	for(size_t i = 0; i < tests.size(); i++){
		EXPECT_EQ(calculateHash(tests[i]),solHash(tests[i]));		
	}
}