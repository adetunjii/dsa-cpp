#include <gtest/gtest.h>
#include <cses.h>

TEST(TestCses, TestDiceCombination) {
	ASSERT_EQ(4, cses::diceCombination(3));
}