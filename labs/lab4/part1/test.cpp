#include "fib.h"
#include "gtest/gtest.h"

// Testing for nominal cases
TEST(FibTest, Nominal) {
	Fibonacci f;
	EXPECT_EQ(5, f.get(5));
	EXPECT_EQ(13, f.get(7));
}

// Testing for boundary cases
TEST(FibTest, Boundary) {
	Fibonacci f;
	EXPECT_EQ(1, f.get(1));
	EXPECT_EQ(1, f.get(2));
}

// Test for off-nominal cases
TEST(FibTest, OffNominal) {
	Fibonacci f;
	EXPECT_EQ(0, f.get(0));
	EXPECT_EQ(0, f.get(-1));
}
