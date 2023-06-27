#include <gtest/gtest.h>
#include "function.cpp"

TEST(ExampleTest, BasicTest) {
EXPECT_EQ(2, 1 + 1);
EXPECT_TRUE(true);
}

TEST(ArrayTest, AverageTest) {
arSize = 5;
arr = new int[arSize];
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
arr[3] = 4;
arr[4] = 5;

thread th(average);

th.join();

EXPECT_EQ(3, av);

delete[] arr;
}

TEST(ArrayTest, MinMaxTest) {
arSize = 5;
arr = new int[arSize];
arr[0] = 2;
arr[1] = 5;
arr[2] = 1;
arr[3] = 4;
arr[4] = 3;

thread th(min_max);

th.join();

EXPECT_EQ(1, minimum);
EXPECT_EQ(5, maximum);
EXPECT_EQ(2, minIdx);
EXPECT_EQ(1, maxIdx);

delete[] arr;
}