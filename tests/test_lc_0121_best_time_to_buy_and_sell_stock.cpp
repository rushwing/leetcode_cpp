#include <gtest/gtest.h>
#include "solutions/lc_0121_best_time_to_buy_and_sell_stock_1.h"

using namespace leetcode;

class BestTimeToBuyAndSellStockTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(BestTimeToBuyAndSellStockTest, Example1) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(solution.maxProfit(prices), 5);
}

TEST_F(BestTimeToBuyAndSellStockTest, Example2) {
    std::vector<int> prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(solution.maxProfit(prices), 0);
}

TEST_F(BestTimeToBuyAndSellStockTest, NoProfitPossible) {
    std::vector<int> prices = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.maxProfit(prices), 0);
}

TEST_F(BestTimeToBuyAndSellStockTest, SingleDay) {
    std::vector<int> prices = {10};
    EXPECT_EQ(solution.maxProfit(prices), 0);
}

TEST_F(BestTimeToBuyAndSellStockTest, TwoDaysProfit) {
    std::vector<int> prices = {2, 5};
    EXPECT_EQ(solution.maxProfit(prices), 3);
}

TEST_F(BestTimeToBuyAndSellStockTest, FluctuatingPrices) {
    std::vector<int> prices = {3, 2, 6, 5, 0, 3};
    EXPECT_EQ(solution.maxProfit(prices), 4);
}