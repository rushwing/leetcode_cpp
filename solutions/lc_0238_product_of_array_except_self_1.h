// LeetCode 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
//
// Tags: Array, Prefix Sum
//
// Problem:
//     Given an integer array nums, return an array answer such that answer[i] is
//     equal to the product of all the elements of nums except nums[i].
//
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//     You must write an algorithm that runs in O(n) time and without using the division operation.
//
//     Example 1:
//     Input: nums = [1,2,3,4]
//     Output: [24,12,8,6]
//
//     Example 2:
//     Input: nums = [-1,1,0,-3,3]
//     Output: [0,0,9,0,0]
//
//     Constraints:
//     - 2 <= nums.length <= 10^5
//     - -30 <= nums[i] <= 30
//     - The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//     Follow up: Can you solve the problem in O(1) extra space complexity?
//     (The output array does not count as extra space for space complexity analysis.)
//
// Solution:
//     This problem can be solved in O(n) time and O(1) extra space by making two passes over the array.
//     The product of all elements except `nums[i]` is equivalent to `(product of elements to the left of i) * (product of elements to the right of i)`.
//
//     1.  **First Pass (Prefix Products):**
//         - Initialize an output array `result` of the same size as `nums`, with all elements set to 1.
//         - Iterate from left to right. For each index `i`, first set `result[i]` to the current prefix product, then update the prefix product by multiplying it with `nums[i]`.
//         - After this pass, `result[i]` will hold the product of all elements to the left of `i`.
//
//     2.  **Second Pass (Suffix Products):**
//         - Iterate from right to left. For each index `j`, multiply `result[j]` (which already contains the prefix product) by the current suffix product. Then, update the suffix product by multiplying it with `nums[j]`.
//         - After this pass, `result[j]` will be the product of its left-side elements and its right-side elements.
//
// Time Complexity: O(?)
//     - O(n). We perform two separate passes through the `nums` array, each taking O(n) time. The total time complexity is O(n) + O(n) = O(n).
//
// Space Complexity: O(?)
//     - O(1). The problem statement specifies that the output array does not count as extra space. Besides the output array, we only use a few constant-space variables (`prefix`, `suffix`, loop counters).
//
// Pitfalls:
//     - The main challenge is to solve this without using the division operator.
//     - Handling elements that are zero. The two-pass approach correctly handles cases with one or more zeros without needing special logic. If there is one zero, the result for that index will be the product of all other numbers, and all other results will be zero. If there are multiple zeros, all results will be zero.
//     - Ensuring the prefix and suffix products are calculated correctly. In the first pass, `result[i]` is assigned the prefix *before* it's updated with `nums[i]`. Similarly, in the second pass, `result[j]` is updated with the suffix *before* the suffix is updated with `nums[j]`.

#pragma once

#include <vector>

namespace leetcode {

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            result[j] *= suffix;
            suffix *= nums[j];
        }
        return result;
    }
};

}  // namespace leetcode