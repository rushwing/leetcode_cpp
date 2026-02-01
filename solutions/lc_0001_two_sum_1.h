// LeetCode 1. Two Sum
// https://leetcode.com/problems/two-sum/
//
// Tags: Array, Hash Table
//
// Problem:
//     Given an array of integers nums and an integer target, return indices of
//     the two numbers such that they add up to target.
//     You may assume that each input would have exactly one solution, and you
//     may not use the same element twice.
//     You can return the answer in any order.
//
// Solution:
//     - Use a hash table to store each number and its index as we iterate
//     - For each number, check if its complement (target - num) exists in the hash table
//     - If found, return the indices; otherwise, add the current number to the hash table
//
// Time Complexity: O(n)
//     - Single pass through the array
//     - Hash table lookups and insertions are O(1) on average
//
// Space Complexity: O(n)
//     - Hash table stores at most n elements
//
// Pitfalls:
//     - Don't use the same element twice (problem constraint guarantees this won't happen)
//     - Return indices, not the values themselves
//     - Order of indices in the result doesn't matter

#pragma once

#include <vector>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

}  // namespace leetcode
