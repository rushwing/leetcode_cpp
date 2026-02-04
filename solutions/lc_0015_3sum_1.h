// LeetCode 0015. 3Sum
// https://leetcode.com/problems/3sum/
//
// Tags: Array, Two Pointers, Sorting
//
// Problem:
//     Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//     Notice that the solution set must not contain duplicate triplets.
//
//     Example 1:
//     Input: nums = [-1,0,1,2,-1,-4]
//     Output: [[-1,-1,2],[-1,0,1]]
//     Explanation: 
//     nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//     nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//     nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//     The distinct triplets are [-1,0,1] and [-1,-1,2].
//     Notice that the order of the output and the order of the triplets does not matter.
//
//     Example 2:
//     Input: nums = [0,1,1]
//     Output: []
//
//     Example 3:
//     Input: nums = [0,0,0]
//     Output: [[0,0,0]]
//
//     Constraints:
//     - 3 <= nums.length <= 3000
//     - -10^5 <= nums[i] <= 10^5
//
// Solution:
//     This problem is solved by reducing it to a series of 2Sum problems after sorting.
//     1. Sort the input array `nums`. This is crucial for the two-pointer approach and for handling duplicates efficiently.
//     2. Iterate through the array with a pointer `i`. `nums[i]` will be the first element of a potential triplet.
//     3. For each `nums[i]`, use two pointers, `left` (starting at `i+1`) and `right` (starting at the end of the array), to find two numbers that sum up to `-nums[i]`.
//     4. Move `left` and `right` inwards based on whether their sum is less than, greater than, or equal to the target.
//     5. **Duplicate Handling:**
//        - To avoid duplicate triplets for the first element, skip any `nums[i]` that is the same as the one before it.
//        - After finding a valid triplet, move the `left` and `right` pointers inward, skipping any duplicate elements to ensure the next pair is unique.
//
// Time Complexity: O(N^2)
//     - Sorting the array takes O(N log N).
//     - The main part is a nested loop. The outer loop runs N times, and the inner two-pointer `while` loop runs at most N times for each `i`. This results in O(N^2).
//     - The total complexity is O(N log N + N^2), which simplifies to O(N^2).
//
// Space Complexity: O(1) or O(log N)
//     - The space used by the sorting algorithm is typically O(log N) for `std::sort`.
//     - The output vector is not counted towards space complexity per the problem's convention.
//
// Pitfalls:
//     - Forgetting to sort the array is a primary mistake.
//     - Incorrectly handling duplicates. It's necessary to skip duplicates for the first element (`i`) and for the `left` and `right` pointers after finding a valid triplet.

#pragma once

#include <vector>
#include <algorithm>

namespace leetcode {

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left+1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right-1]) {
                        --right;
                    }

                    // Move to the next unique pair
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};

}  // namespace leetcode