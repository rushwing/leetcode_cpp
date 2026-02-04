#include <gtest/gtest.h>
#include "solutions/lc_0200_number_of_islands_1.h"

using namespace leetcode;

class NumberOfIslandsTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(NumberOfIslandsTest, Example1) {
    std::vector<std::vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    EXPECT_EQ(solution.numIslands(grid), 1);
}

TEST_F(NumberOfIslandsTest, Example2) {
    std::vector<std::vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    EXPECT_EQ(solution.numIslands(grid), 3);
}

TEST_F(NumberOfIslandsTest, NoIslands) {
    std::vector<std::vector<char>> grid = {
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    EXPECT_EQ(solution.numIslands(grid), 0);
}

TEST_F(NumberOfIslandsTest, AllLand) {
    std::vector<std::vector<char>> grid = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    EXPECT_EQ(solution.numIslands(grid), 1);
}

TEST_F(NumberOfIslandsTest, EmptyGrid) {
    std::vector<std::vector<char>> grid = {};
    EXPECT_EQ(solution.numIslands(grid), 0);
}

TEST_F(NumberOfIslandsTest, SingleRow) {
    std::vector<std::vector<char>> grid = {
        {'1','0','1','1','0','1'}
    };
    EXPECT_EQ(solution.numIslands(grid), 3);
}

TEST_F(NumberOfIslandsTest, SingleColumn) {
    std::vector<std::vector<char>> grid = {
        {'1'},
        {'0'},
        {'1'},
        {'1'},
        {'0'},
        {'1'}
    };
    EXPECT_EQ(solution.numIslands(grid), 3);
}