#include <gtest/gtest.h>
#include "0283_move_zeroes.h"

class MoveZeroesTest : public ::testing::Test {
protected:
    Solution solution;

    void expectMoveZeroesResult(std::vector<int> nums, std::vector<int> expected) {
        solution.moveZeroes(nums);
        EXPECT_EQ(nums, expected);
    }
};

TEST_F(MoveZeroesTest, Example1) {
    expectMoveZeroesResult({0, 1, 0, 3, 12}, {1, 3, 12, 0, 0});
}

TEST_F(MoveZeroesTest, Example2) {
    expectMoveZeroesResult({0}, {0});
}

TEST_F(MoveZeroesTest, NoZeroes) {
    expectMoveZeroesResult({1, 2, 3}, {1, 2, 3});
}

TEST_F(MoveZeroesTest, AllZeroes) {
    expectMoveZeroesResult({0, 0, 0}, {0, 0, 0});
}

TEST_F(MoveZeroesTest, SingleNonZero) {
    expectMoveZeroesResult({1}, {1});
}

TEST_F(MoveZeroesTest, ZeroesAtEnd) {
    expectMoveZeroesResult({1, 2, 0, 0}, {1, 2, 0, 0});
}

TEST_F(MoveZeroesTest, ZeroesAtStart) {
    expectMoveZeroesResult({0, 0, 1, 2}, {1, 2, 0, 0});
}

TEST_F(MoveZeroesTest, Empty) {
    expectMoveZeroesResult({}, {});
}
