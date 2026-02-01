// String Permutations
//
// Tags: Backtracking, String, Recursion, Stack
//
// Problem:
//     Given a string, generate all permutations of its characters.
//     Handle duplicate characters by using a seen set to avoid duplicate permutations.
//
// Solution:
//     Two approaches provided:
//
//     1. Iterative (using stack):
//        - Use a State struct to track current path and used character indices
//        - Push initial empty state onto stack
//        - For each state, try adding each unused character
//        - Use seen map to avoid generating duplicate permutations
//        - When path length equals input length, add to results
//
//     2. Recursive (backtracking):
//        - Build permutation character by character
//        - Track used indices with boolean vector
//        - Use backtracking: try each character, recurse, then undo choice
//        - Use seen map to avoid duplicate permutations
//        - Base case: when path length equals input length, add to results
//
// Time Complexity: O(n! * n)
//     - n! permutations to generate
//     - Each permutation takes O(n) to build
//
// Space Complexity: O(n! * n)
//     - Store n! permutations, each of length n
//     - Recursion stack depth: O(n)
//     - Used array and seen map: O(n)
//
// Pitfalls:
//     - Must handle duplicate characters properly with seen set
//     - Don't forget to backtrack (restore state) in recursive approach
//     - Stack-based approach requires careful state copying
//     - Seen map prevents duplicate permutations but adds overhead

#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>

namespace leetcode {
namespace practice {

struct State {
    std::string path;
    std::vector<bool> used;
};

class Solution {
public:
    std::vector<std::string> get_permutations_interative(const std::string& input) {
        std::vector<std::string> res;
        std::stack<State> intermediate;
        std::unordered_map<std::string, bool> seen;
        int n = input.length();
        intermediate.push({"", std::vector<bool>(n, false)});

        while (!intermediate.empty()) {
            auto cur = intermediate.top();
            intermediate.pop();

            if (cur.path.length() == n) {
                std::cout << "Found new result string " << cur.path << std::endl;
                res.push_back(cur.path);
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (cur.used[i] == true) {
                    continue;
                }
                State next = cur;
                next.path = cur.path + input[i];
                if (seen.find(next.path) != seen.end()) {
                    continue;
                }
                next.used[i] = true;
                std::cout << "Push new intermediate {path = " + next.path << ", used index = " << i << "}" << "to the stack" << std::endl;
                seen[next.path] = true;
                intermediate.push(next);
            }
        }
        return res;
    }

    std::vector<std::string> get_permutations_recursive(const std::string& input) {
        std::vector<std::string> res;
        std::unordered_map<std::string, bool> seen;
        int n = input.length();
        std::vector<bool> used(n, false);
        std::string path;

        backtrack(res, seen, input, used, path);
        return res;
    }

private:
    void backtrack(
        std::vector<std::string>& res,
        std::unordered_map<std::string, bool>& seen,
        const std::string& input,
        std::vector<bool>& used,
        std::string& path
    ) {
        if (path.length() == input.length()) {
            if (seen.find(path) == seen.end()) {
                seen[path] = true;
                res.push_back(path);
            }
            return;
        }

        for (int i = 0; i < input.length(); i++) {
            if (used[i] == true) {
                continue;
            }

            used[i] = true;
            path.push_back(input[i]);
            backtrack(res, seen, input, used, path);
            path.pop_back();
            used[i] = false;
        }
    }
};

}  // namespace practice
}  // namespace leetcode
