#pragma once

#include <vector>
#include <string>

using namespace std;

// LeetCode 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow_ptr = 0;
        int fast_ptr = 0;
        int n = nums.size();
        for (; slow_ptr < n; slow_ptr++) {
            if (nums[slow_ptr] != 0) {
                fast_ptr = slow_ptr + 1;
                continue;
            }
            printVector(nums);
            cout << "slow_ptr = " << slow_ptr << ", fast_ptr = " << fast_ptr << endl;

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
            cout << "slow_ptr = " << slow_ptr << ", fast_ptr = " << fast_ptr << endl;
        }
    }

private:
    void printVector(vector<int>& nums) {
        string out = "[";
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                out = out + to_string(nums[i]);
            } else {
                out = out + to_string(nums[i]) + ",";
            }
        }
        out = out + "]";
        cout << out << endl;
    }
};
