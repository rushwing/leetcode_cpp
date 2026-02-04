// LeetCode 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
//
// Tags: Array, Stack, Monotonic Stack
//
// Problem:
//     Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//
//     Example 1:
//     Input: heights = [2,1,5,6,2,3]
//     Output: 10
//     Explanation: The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units.
//
//     Example 2:
//     Input: heights = [2,4]
//     Output: 4
//
//     Constraints:
//     - 1 <= heights.length <= 10^5
//     - 0 <= heights[i] <= 10^4
//
// Solution:
//     This problem can be solved efficiently using a monotonic stack. The stack will store indices of the `heights` array, maintaining a strictly increasing order of heights.
//     1. Iterate through the heights. For each bar `i`, while the stack is not empty and the current bar's height `heights[i]` is less than the height of the bar at the stack's top, we have found the right boundary for the bar at the top of the stack.
//     2. When a bar is popped from the stack, calculate the area of the rectangle with this bar as the smallest height.
//        - The height `h` is `heights[popped_index]`.
//        - The right boundary is the current index `i`.
//        - The left boundary is the index of the new element at the top of the stack.
//        - The width `w` is `right_boundary - left_boundary - 1`.
//     3. After the loop, some bars might remain in the stack. These are bars that extend to the end of the histogram. We process them similarly, but their right boundary is the total number of bars `n`.
//
// Time Complexity: O(N)
//     - Each index is pushed onto and popped from the stack at most once. This results in a single pass through the array.
//
// Space Complexity: O(N)
//     - In the worst case (a strictly increasing histogram), the stack can hold all N indices.
//
// Pitfalls:
//     - Correctly calculating the width of the rectangle is the main challenge. The width is determined by the first smaller bar to the left and the first smaller bar to the right.
//     - Handling the case where the stack becomes empty (meaning the rectangle extends to the beginning of the histogram).
//     - Processing the remaining elements in the stack after the main loop finishes.

#pragma once

#include <vector>
#include <stack>
#include <algorithm>

namespace leetcode {

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stk;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                // Right boundary is i, left boundary is the new stk.top()
                int w = stk.empty() ? i : (i - stk.top() - 1);
                max_area = std::max(max_area, w * h);
            }
            stk.push(i);
        }

        // Process remaining bars in the stack. These bars extend to the end.
        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            // Right boundary is n, left boundary is the new stk.top()
            int w = stk.empty() ? n : (n - stk.top() - 1);
            max_area = std::max(max_area, w * h);
        }
        return max_area;
    }
};

}  // namespace leetcode