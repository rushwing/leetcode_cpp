#include <gtest/gtest.h>
#include <algorithm>
#include "practice/string_permutations_1.h"

using namespace leetcode::practice;

class StringPermutationsTest : public ::testing::Test {
protected:
    Solution solution;

    // Helper to compare results regardless of order
    void expectStringPermutationsResult1(std::string &input, std::vector<std::string> expected) {
        auto result = solution.get_permutations_interative(input);
        std::sort(result.begin(), result.end());
        std::sort(expected.begin(), expected.end());
        EXPECT_EQ(result, expected);
    }

    // Helper to compare results regardless of order
    void expectStringPermutationsResult2(std::string &input, std::vector<std::string> expected) {
        auto result = solution.get_permutations_recursive(input);
        std::sort(result.begin(), result.end());
        std::sort(expected.begin(), expected.end());
        EXPECT_EQ(result, expected);
    }
};

TEST_F(StringPermutationsTest, Example1) {
    std::string input = "ABC";
    expectStringPermutationsResult1(input, {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"});
}

TEST_F(StringPermutationsTest, Example2) {
    std::string input = "ABA";
    expectStringPermutationsResult1(input, {"ABA", "AAB", "BAA"});
}

TEST_F(StringPermutationsTest, Example3) {
    std::string input = "A";
    expectStringPermutationsResult1(input, {"A"});
}

TEST_F(StringPermutationsTest, Example4) {
    std::string input = "";
    expectStringPermutationsResult1(input, {""});
}

TEST_F(StringPermutationsTest, Example5) {
    std::string input = "ABC";
    expectStringPermutationsResult2(input, {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"});
}

TEST_F(StringPermutationsTest, Example6) {
    std::string input = "ABA";
    expectStringPermutationsResult2(input, {"ABA", "AAB", "BAA"});
}

TEST_F(StringPermutationsTest, Example7) {
    std::string input = "A";
    expectStringPermutationsResult2(input, {"A"});
}

TEST_F(StringPermutationsTest, Example8) {
    std::string input = "";
    expectStringPermutationsResult2(input, {""});
}

// Corner cases - Iterative
TEST_F(StringPermutationsTest, AllIdentical_Iterative) {
    std::string input = "AAA";
    expectStringPermutationsResult1(input, {"AAA"});
}

TEST_F(StringPermutationsTest, TwoIdentical_Iterative) {
    std::string input = "AA";
    expectStringPermutationsResult1(input, {"AA"});
}

TEST_F(StringPermutationsTest, TwoDistinct_Iterative) {
    std::string input = "AB";
    expectStringPermutationsResult1(input, {"AB", "BA"});
}

TEST_F(StringPermutationsTest, MultipleDuplicatePairs_Iterative) {
    std::string input = "AABB";
    expectStringPermutationsResult1(input, {"AABB", "ABAB", "ABBA", "BAAB", "BABA", "BBAA"});
}

// Corner cases - Recursive
TEST_F(StringPermutationsTest, AllIdentical_Recursive) {
    std::string input = "AAA";
    expectStringPermutationsResult2(input, {"AAA"});
}

TEST_F(StringPermutationsTest, TwoIdentical_Recursive) {
    std::string input = "AA";
    expectStringPermutationsResult2(input, {"AA"});
}

TEST_F(StringPermutationsTest, TwoDistinct_Recursive) {
    std::string input = "AB";
    expectStringPermutationsResult2(input, {"AB", "BA"});
}

TEST_F(StringPermutationsTest, MultipleDuplicatePairs_Recursive) {
    std::string input = "AABB";
    expectStringPermutationsResult2(input, {"AABB", "ABAB", "ABBA", "BAAB", "BABA", "BBAA"});
}
