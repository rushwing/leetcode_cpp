#include <gtest/gtest.h>
#include "solutions/lc_0020_valid_parentheses_1.h"

using namespace leetcode;

class ValidParenthesesTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(ValidParenthesesTest, Example1) {
    EXPECT_TRUE(solution.isValid("()"));
}

TEST_F(ValidParenthesesTest, Example2) {
    EXPECT_TRUE(solution.isValid("()[]{}"));
}

TEST_F(ValidParenthesesTest, Example3) {
    EXPECT_FALSE(solution.isValid("(]"));
}

TEST_F(ValidParenthesesTest, MismatchedInner) {
    EXPECT_FALSE(solution.isValid("([)]"));
}

TEST_F(ValidParenthesesTest, UnclosedBrackets) {
    EXPECT_FALSE(solution.isValid("((("));
}

TEST_F(ValidParenthesesTest, TooManyClosingBrackets) {
    EXPECT_FALSE(solution.isValid("())"));
}

TEST_F(ValidParenthesesTest, EmptyString) {
    // An empty string is often considered valid, but the constraint is 1 <= s.length.
    // If the constraint were different, this would be a good edge case.
    // Let's test a simple valid case instead.
    EXPECT_TRUE(solution.isValid("[]"));
}

TEST_F(ValidParenthesesTest, ComplexValid) {
    EXPECT_TRUE(solution.isValid("{[()]}"));
}