#include <gtest/gtest.h>
#include "solutions/lc_0084_largest_rectangle_in_histogram_1.h"

using namespace leetcode;

class LargestRectangleInHistogramTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(LargestRectangleInHistogramTest, Example1) {
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    EXPECT_EQ(solution.largestRectangleArea(heights), 10);
}

TEST_F(LargestRectangleInHistogramTest, Example2) {
    std::vector<int> heights = {2, 4};
    EXPECT_EQ(solution.largestRectangleArea(heights), 4);
}

TEST_F(LargestRectangleInHistogramTest, SingleBar) {
    std::vector<int> heights = {5};
    EXPECT_EQ(solution.largestRectangleArea(heights), 5);
}

TEST_F(LargestRectangleInHistogramTest, EmptyInput) {
    std::vector<int> heights = {};
    EXPECT_EQ(solution.largestRectangleArea(heights), 0);
}

TEST_F(LargestRectangleInHistogramTest, IncreasingHeights) {
    std::vector<int> heights = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.largestRectangleArea(heights), 9);
}

TEST_F(LargestRectangleInHistogramTest, DecreasingHeights) {
    std::vector<int> heights = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.largestRectangleArea(heights), 9);
}

TEST_F(LargestRectangleInHistogramTest, AllSameHeight) {
    std::vector<int> heights = {2, 2, 2, 2};
    EXPECT_EQ(solution.largestRectangleArea(heights), 8);
}

TEST_F(LargestRectangleInHistogramTest, VHistogram) {
    std::vector<int> heights = {4, 2, 0, 3, 2, 5};
    EXPECT_EQ(solution.largestRectangleArea(heights), 6);
}