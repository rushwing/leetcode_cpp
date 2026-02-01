#include <gtest/gtest.h>
#include <algorithm>
#include "solutions/lc_0001_two_sum_1.h"

using namespace leetcode;

class TwoSumTest : public ::testing::Test {
protected:
    Solution solution;

    // Helper to compare results regardless of order
    void expectTwoSumResult(std::vector<int>& nums, int target,
                           std::vector<int> expected) {
        auto result = solution.twoSum(nums, target);
        std::sort(result.begin(), result.end());
        std::sort(expected.begin(), expected.end());
        EXPECT_EQ(result, expected);
    }
};

TEST_F(TwoSumTest, Example1) {
    std::vector<int> nums = {2, 7, 11, 15};
    expectTwoSumResult(nums, 9, {0, 1});
}

TEST_F(TwoSumTest, Example2) {
    std::vector<int> nums = {3, 2, 4};
    expectTwoSumResult(nums, 6, {1, 2});
}

TEST_F(TwoSumTest, Example3) {
    std::vector<int> nums = {3, 3};
    expectTwoSumResult(nums, 6, {0, 1});
}

TEST_F(TwoSumTest, NoSolution) {
    std::vector<int> nums = {1, 2, 3};
    expectTwoSumResult(nums, 10, {});
}
