// LeetCode 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// Tags: Array, Dynamic Programming
//
// Problem:
//     You are given an array prices where prices[i] is the price of a given stock on the ith day.
//     You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//     Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
//     Example 1:
//     Input: prices = [7,1,5,3,6,4]
//     Output: 5
//     Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//     Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
//
//     Example 2:
//     Input: prices = [7,6,4,3,1]
//     Output: 0
//     Explanation: In this case, no transactions are done and the max profit = 0.
//
//     Constraints:
//     - 1 <= prices.length <= 10^5
//     - 0 <= prices[i] <= 10^4
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

namespace leetcode {

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int low_day = 0;
        int high_day = 1;
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[low_day]) {
                low_day = i;
            }
            if (prices[i] > prices[high_day]) {
                high_day = i;            
            }
            if (low_day > high_day) {
                high_day = low_day;
            }
            max_profit = std::max(max_profit, prices[high_day] - prices[low_day]);
        }
        return max_profit;
    }
};

}  // namespace leetcode