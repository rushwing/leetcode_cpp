// LeetCode 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//
// Tags: String, Stack
//
// Problem:
//     Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//     An input string is valid if:
//     1. Open brackets must be closed by the same type of brackets.
//     2. Open brackets must be closed in the correct order.
//     3. Every close bracket has a corresponding open bracket of the same type.
//
//     Example 1:
//     Input: s = "()"
//     Output: true
//
//     Example 2:
//     Input: s = "()[]{}"
//     Output: true
//
//     Example 3:
//     Input: s = "(]"
//     Output: false
//
//     Constraints:
//     - 1 <= s.length <= 10^4
//     - s consists of parentheses only '()[]{}'.
//
// Solution:
//     This problem is a classic use case for a stack.
//     1. Iterate through the input string `s`.
//     2. If the character is an opening bracket ('(', '[', '{'), push it onto the stack.
//     3. If the character is a closing bracket (')', ']', '}'):
//        a. Check if the stack is empty. If it is, there's no matching open bracket, so the string is invalid.
//        b. Check if the top of the stack is the corresponding opening bracket. If not, the brackets are mismatched, and the string is invalid.
//        c. If they match, pop the opening bracket from the stack.
//     4. After iterating through the entire string, if the stack is empty, it means every opening bracket had a matching closing bracket in the correct order. The string is valid.
//     5. If the stack is not empty, it means there are unclosed opening brackets, so the string is invalid.
//
// Time Complexity: O(N)
//     - We iterate through the string of length N once. Stack operations (push, pop, top) are O(1).
//
// Space Complexity: O(N)
//     - In the worst case, if the string consists of only opening brackets (e.g., "((("), the stack will store all N characters.
//
// Pitfalls:
//     - Forgetting to check if the stack is empty before checking `stack.top()` when a closing bracket is found.
//     - Forgetting to check if the stack is empty at the end. A string like "(((" should be invalid.

#pragma once

#include <string>
#include <stack>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> open_brackets;
        const std::unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

        for (const auto& c : s) {
            if (pairs.count(c)) { // It's a closing bracket
                if (open_brackets.empty() || open_brackets.top() != pairs.at(c)) {
                    return false;
                }
                open_brackets.pop();
            } else {
                open_brackets.push(c); // It's an opening bracket
            }
        }
        return open_brackets.empty();
    }
};

}  // namespace leetcode