// LeetCode 0253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/
//
// Tags: Array, Sorting, Heap (Priority Queue), Greedy, Prefix Sum
//
// Problem:
//     Given an array of meeting time intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of conference rooms required.
//
//     Example 1:
//     Input: intervals = [[0,30],[5,10],[15,20]]
//     Output: 2
//     Explanation:
//     Meeting [0, 30] needs a room.
//     Meeting [5, 10] needs another room.
//     Meeting [15, 20] can use the room from [5, 10] after it ends.
//     So, 2 rooms are needed.
//
//     Example 2:
//     Input: intervals = [[7,10],[2,4]]
//     Output: 1
//     Explanation: Since [7,10] and [2,4] don't overlap, one room is sufficient.
//
//     Constraints:
//     - 1 <= intervals.length <= 10^4
//     - 0 <= start_i < end_i <= 10^6
//
// Solution:
//     This problem can be solved greedily using a min-heap.
//     1. Sort the meeting intervals based on their start times. This allows us to process meetings in chronological order.
//     2. Use a min-heap to keep track of the end times of meetings currently in progress. The top of the heap will always be the meeting that finishes earliest.
//     3. Iterate through the sorted intervals. For each meeting:
//        a. Check if any room has become free. A room is free if the earliest-ending meeting (the top of the heap) has an end time less than or equal to the current meeting's start time.
//        b. If a room is free, we can reuse it. We simulate this by popping the end time from the heap.
//        c. The current meeting now occupies a room (either a reused one or a new one). We push its end time onto the heap.
//     4. The minimum number of rooms required is the maximum number of concurrent meetings, which is equivalent to the maximum size the heap ever reached. The final size of the heap represents this peak.
//
// Time Complexity: O(N log N)
//     - Sorting the intervals takes O(N log N) time.
//     - Iterating through N intervals involves N heap operations (push and pop). Each heap operation takes O(log K) time, where K is the size of the heap (number of rooms). In the worst case, K can be N. So, the loop takes O(N log N) time.
//     - The total complexity is dominated by sorting.
//
// Space Complexity: O(N)
//     - In the worst-case scenario where all meetings overlap, the min-heap will store the end times for all N meetings.
//
// Pitfalls:
//     - Forgetting to sort the intervals by start time is a common mistake.
//     - Using a max-heap instead of a min-heap would be incorrect, as we need to find the room that frees up the earliest.
//     - The condition for reusing a room must be `heap.top() <= interval.start`, not `<`. If a meeting starts exactly when another ends, the room can be reused.

#pragma once

#include <vector>
#include <algorithm>
#include <queue>

namespace leetcode {

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (const auto& interval : intervals) {
            if (!min_heap.empty() && min_heap.top() <= interval[0]) {
                min_heap.pop();
            }
            min_heap.push(interval[1]);
        }
        return min_heap.size();
    }
};

}  // namespace leetcode