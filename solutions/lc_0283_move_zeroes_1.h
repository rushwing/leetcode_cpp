// LeetCode 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/
//
// Tags: Array, Two Pointers
//
// Problem:
//     Given an integer array nums, move all 0's to the end of it while maintaining
//     the relative order of the non-zero elements.
//     Note: You must do this in-place without making a copy of the array.
//
// Solution:
//     - Use two pointers approach (slow and fast)
//     - slow_ptr points to the first zero found
//     - fast_ptr searches for the next non-zero element
//     - When a non-zero is found, swap it with the zero at slow_ptr
//     - Continue until all elements are processed
//
// Time Complexity: O(n)
//     - Each element is visited at most twice (once by slow, once by fast)
//
// Space Complexity: O(1)
//     - In-place algorithm using only pointer variables
//
// Pitfalls:
//     - Must maintain relative order of non-zero elements
//     - Must modify array in-place
//     - Edge cases: all zeros, no zeros, single element
//     - After finding a zero, fast_ptr must continue from where it left off

#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace leetcode {

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int slow_ptr = 0;
        int fast_ptr = 0;
        int n = nums.size();
        for (; slow_ptr < n; slow_ptr++) {
            if (nums[slow_ptr] != 0) {
                fast_ptr = slow_ptr + 1;
                continue;
            }
            printVector(nums);
            std::cout << "slow_ptr = " << slow_ptr << ", fast_ptr = " << fast_ptr << std::endl;

            for (; fast_ptr < n; fast_ptr++) {
                if (nums[fast_ptr] == 0) {
                    continue;
                }
                int temp = nums[slow_ptr];
                nums[slow_ptr] = nums[fast_ptr];
                nums[fast_ptr] = temp;
                break;
            }
            printVector(nums);
            std::cout << "slow_ptr = " << slow_ptr << ", fast_ptr = " << fast_ptr << std::endl;
        }
    }

private:
    void printVector(std::vector<int>& nums) {
        std::string out = "[";
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                out = out + std::to_string(nums[i]);
            } else {
                out = out + std::to_string(nums[i]) + ",";
            }
        }
        out = out + "]";
        std::cout << out << std::endl;
    }
};

}  // namespace leetcode
