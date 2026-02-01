#include <gtest/gtest.h>
#include "solutions/lc_0056_merge_intervals_1.h"

using namespace leetcode;

class MergeIntervalsTest : public ::testing::Test {
protected:
    Solution solution;

    void expectMergeResult(std::vector<std::vector<int>> intervals, std::vector<std::vector<int>> expected) {
        auto result = solution.merge(intervals);
        EXPECT_EQ(result, expected);
    }
};

TEST_F(MergeIntervalsTest, Example1) {
    // [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]
    expectMergeResult({{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}});
}

TEST_F(MergeIntervalsTest, Example2) {
    // [[1,4],[4,5]] -> [[1,5]]
    expectMergeResult({{1, 4}, {4, 5}}, {{1, 5}});
}

TEST_F(MergeIntervalsTest, SingleInterval) {
    expectMergeResult({{1, 5}}, {{1, 5}});
}

TEST_F(MergeIntervalsTest, NoOverlap) {
    expectMergeResult({{1, 2}, {4, 5}, {7, 8}}, {{1, 2}, {4, 5}, {7, 8}});
}

TEST_F(MergeIntervalsTest, AllOverlap) {
    expectMergeResult({{1, 10}, {2, 6}, {3, 5}}, {{1, 10}});
}

TEST_F(MergeIntervalsTest, UnsortedInput) {
    expectMergeResult({{8, 10}, {1, 3}, {2, 6}}, {{1, 6}, {8, 10}});
}

TEST_F(MergeIntervalsTest, Empty) {
    expectMergeResult({}, {});
}
