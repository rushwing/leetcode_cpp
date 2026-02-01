// LeetCode 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
//
// Tags: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
//
// Problem:
//     Given an integer array nums and an integer k, return the k most frequent elements.
//     You may return the answer in any order.
//
//     Example 1:
//     Input: nums = [1,1,1,2,2,3], k = 2
//     Output: [1,2]
//
//     Example 2:
//     Input: nums = [1], k = 1
//     Output: [1]
//
//     Constraints:
//     - 1 <= nums.length <= 10^5
//     - -10^4 <= nums[i] <= 10^4
//     - k is in the range [1, the number of unique elements in the array]
//     - It is guaranteed that the answer is unique
//
//     Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
// Solution:
//     - [To be implemented]
//
// Time Complexity: O(?)
//     - [To be analyzed]
//
// Space Complexity: O(?)
//     - [To be analyzed]
//
// Pitfalls:
//     - [To be identified]

#pragma once

#include <vector>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        std::unordered_map<int, int> freq_map;
        std::vector<int> result;
        for (int& num : nums) {
            if (freq_map.find(num) == freq_map.end()) {
                freq_map[num] = 1;
            } else {
                freq_map[num] += 1;
            }
        }

        for (auto& [num, freq] : freq_map) {
            buckets[freq].push_back(num);
        }

        int bucket_len = buckets.size();
        for (int i = bucket_len -1; i >=0; i--) {
            if (buckets[i].size() > 0) {
                for (int j = 0; j < buckets[i].size(); j++) {
                    result.push_back(buckets[i][j]);
                    if (result.size() == k) {
                        return result;
                    }
                }
            }
        }

        return result;
    }
};

}  // namespace leetcode
