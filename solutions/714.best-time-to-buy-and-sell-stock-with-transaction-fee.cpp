class SolutionDP1d {
    /** 714. Best Time to Buy and Sell Stock with Transaction Fee
     * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
     */
public:
    int maxProfit(vector<int>& prices, int fee) {
        int P[2][prices.size()];
        P[0][0] = 0;
        P[1][0] = -prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            P[0][i] = max(P[0][i - 1], P[1][i - 1] + prices[i] - fee);
            P[1][i] = max(P[1][i - 1], P[0][i - 1] - prices[i]);
        }
        return P[0][prices.size() - 1];
    }
};

class SolutionDP0d {
    /** 714. Best Time to Buy and Sell Stock with Transaction Fee
     * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
     */
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, hold = -prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            tie(sell, hold) = make_pair(
                max(sell, hold + prices[i] - fee),
                max(hold, sell - prices[i])
            );
        }
        return sell;
    }
};

class Solution {
    /** 714. Best Time to Buy and Sell Stock with Transaction Fee
     * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
     */
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0] + fee, res = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            // cout << i << ": " << buy << ' ' << res << " -> ";
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee; // new purchase
            } else if (prices[i] > buy) {
                res += prices[i] - buy; // sell to collect profit ...
                buy = prices[i]; // ... and buy immediately (consecutive increase)
            }
            // cout << buy << ' ' << res << endl;
        }
        return res;
    }
};