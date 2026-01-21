#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            }
        );

        vector<vector<int>> merged;
        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) {
                current[1] = max(intervals[i][1], current[1]);
            } else {
                merged.push_back(current);
                current = intervals[i];
            }
        }
        merged.push_back(current);

        return merged;
    }
};
