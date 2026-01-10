#include <gtest/gtest.h>

namespace dp {
    int fib(int n);
}

TEST(TestDP, Fibonacci) {
    ASSERT_EQ(dp::fib(3), 2);
}