// LeetCode 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/
//
// Tags: Array, Sorting
//
// Problem:
//     Given an array of intervals where intervals[i] = [start_i, end_i], merge
//     all overlapping intervals, and return an array of the non-overlapping
//     intervals that cover all the intervals in the input.
//
// Solution:
//     - Sort intervals by start time
//     - Iterate through sorted intervals, merging overlapping ones
//     - Two intervals [a, b] and [c, d] overlap if b >= c (assuming a <= c after sorting)
//     - When merging, extend the end to max(b, d)
//
// Time Complexity: O(n log n)
//     - Sorting dominates: O(n log n)
//     - Single pass to merge: O(n)
//
// Space Complexity: O(n)
//     - Result vector stores at most n intervals
//     - Sorting may use O(log n) stack space depending on implementation
//
// Pitfalls:
//     - Must sort first to identify all overlapping intervals
//     - Edge case: empty input returns empty result
//     - When merging, use max() to handle intervals fully contained within another
//     - Don't forget to add the last interval to the result

#pragma once

#include <vector>
#include <algorithm>

namespace leetcode {

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
            }
        );

        std::vector<std::vector<int>> merged;
        std::vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) {
                current[1] = std::max(intervals[i][1], current[1]);
            } else {
                merged.push_back(current);
                current = intervals[i];
            }
        }
        merged.push_back(current);

        return merged;
    }
};

}  // namespace leetcode
