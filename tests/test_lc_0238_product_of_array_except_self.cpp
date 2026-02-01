#include <gtest/gtest.h>
#include "solutions/lc_0238_product_of_array_except_self_1.h"

using namespace leetcode;

class ProductOfArrayExceptSelfTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(ProductOfArrayExceptSelfTest, Example1) {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> expected = {24, 12, 8, 6};
    auto result = solution.productExceptSelf(nums);
    EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, Example2) {
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> expected = {0, 0, 9, 0, 0};
    auto result = solution.productExceptSelf(nums);
    EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, TwoElements) {
    std::vector<int> nums = {2, 3};
    std::vector<int> expected = {3, 2};
    auto result = solution.productExceptSelf(nums);
    EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, ContainsOneZero) {
    std::vector<int> nums = {1, 2, 0, 4};
    std::vector<int> expected = {0, 0, 8, 0};
    auto result = solution.productExceptSelf(nums);
    EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, ContainsMultipleZeros) {
    std::vector<int> nums = {1, 0, 3, 0};
    std::vector<int> expected = {0, 0, 0, 0};
    auto result = solution.productExceptSelf(nums);
    EXPECT_EQ(result, expected);
}