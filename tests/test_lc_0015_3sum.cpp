#include <gtest/gtest.h>
#include "solutions/lc_0015_3sum_1.h"
#include <algorithm>

using namespace leetcode;

class ThreeSumTest : public ::testing::Test {
protected:
    Solution solution;

    // Helper to compare results. Sorts each triplet and then the list of triplets.
    void expectThreeSumResult(std::vector<int>& nums, std::vector<std::vector<int>> expected) {
        auto result = solution.threeSum(nums);
        
        for (auto& triplet : result) {
            std::sort(triplet.begin(), triplet.end());
        }
        std::sort(result.begin(), result.end());

        for (auto& triplet : expected) {
            std::sort(triplet.begin(), triplet.end());
        }
        std::sort(expected.begin(), expected.end());

        EXPECT_EQ(result, expected);
    }
};

TEST_F(ThreeSumTest, Example1) {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, Example2) {
    std::vector<int> nums = {0, 1, 1};
    std::vector<std::vector<int>> expected = {};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, Example3) {
    std::vector<int> nums = {0, 0, 0};
    std::vector<std::vector<int>> expected = {{0, 0, 0}};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, NoSolution) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> expected = {};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, DuplicatesAndZeros) {
    std::vector<int> nums = {-2, 0, 0, 2, 2};
    std::vector<std::vector<int>> expected = {{-2, 0, 2}};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, NotEnoughElements) {
    std::vector<int> nums = {1, -1};
    std::vector<std::vector<int>> expected = {};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, RightPointerNotMoved) {
    std::vector<int> nums = {-100, -70, -60, 110, 120, 130, 160};
    std::vector<std::vector<int>> expected = {{-100,-60,160},{-70,-60,130}};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, LargeInput) {
    std::vector<int> nums;
    for (int i = -1500; i <= 1500; ++i) {
        nums.push_back(i);
    }
    std::vector<std::vector<int>> expected = {};
    for (int i = -1500; i <= 1500; ++i) {
        for (int j = i + 1; j <= 1500; ++j) {
            int k = -(i + j);
            if (k > j && k <= 1500) {
                expected.push_back({i, j, k});
            }
        }
    }
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, LeftPointerNotMoved) {
    std::vector<int> nums = {-100, -90, -80, 180, 190, 200, 210, 230};
    std::vector<std::vector<int>> expected = {{-100,-90,190},{-100,-80,180}};
    expectThreeSumResult(nums, expected);
}

TEST_F(ThreeSumTest, MultiDuplicates) {
    std::vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3,4, 4, 6, 6};
    std::vector<std::vector<int>> expected = {{-4,-2,6},{-4,0,4},{-4,1,3},{-4,2,2},{-2,-2,4},{-2,0,2}};
    expectThreeSumResult(nums, expected);
}