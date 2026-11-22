class Solution {
    /** 122. Best Time to Buy and Sell Stock II
     * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
     */
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            tie(hold, sell) = make_pair(
                max(hold, sell - prices[i]),
                max(hold + prices[i], sell)
            );
            // cout << hold << ' ' << sell << endl;
        }
        return max(sell, hold);
    }
};