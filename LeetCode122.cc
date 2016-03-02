//
//  LeetCode122.cc
//  Created by Heng-Yi Lin on 2/28/16.
//
//  title: 122. Best Time to Buy and Sell Stock II
//  Say you have an array for which the ith element is the price of a given stock on day
//  i.
//
//  Design an algorithm to find the maximum profit. You may complete as many transactions
//  as you like (ie, buy one and sell one share of the stock multiple times). However,
//  you may not engage in multiple transactions at the same time (ie, you must sell the
//  stock before you buy again).
//
//  Analysis:
//  On any day if the price is greater than the price on the previous day, sum up the
//  difference
//  *Any sub-growing range, following two way are the same:
//      say 0, 1, 2, 3, 0
//      1)buy on first day and sell in the last day of that range : 3 - 0 =3
//      2)buy, then sell and buy another in the next day: (1-0)+(2-1)+(3-2) = 3
//  -> therefore, just use greedy algorithm, loop through whole array and calculate
//      difference between each day. add to the sum if the price on the next day is
//      higher
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1])
                sum += (prices[i] - prices[i-1]);
        }
        return sum;
    }
};