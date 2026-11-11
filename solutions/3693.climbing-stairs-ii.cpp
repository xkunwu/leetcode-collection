class Solution {
    /** 3693. Climbing Stairs II
     * https://leetcode.com/problems/climbing-stairs-ii/
     */
public:
    int climbStairs(int n, vector<int>& costs) {
        if (1 == n) return costs[0] + 1;
        if (2 == n) return min(costs[0] + 2, 4) + costs[1];
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = min(costs[0] + 2, 4) + costs[1];
        for (int i = 3; i <= n; ++i) {
            dp[i] = min({
                dp[i - 3] + 9,
                dp[i - 2] + 4,
                dp[i - 1] + 1,
            }) + costs[i - 1];
        }
        // for (int v: dp) { cout << v << ","; } cout << endl;
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (1 == n) return costs[0] + 1;
        if (2 == n) return min(costs[0] + 2, 4) + costs[1];
        int dp0 = 0;
        int dp1 = costs[0] + 1;
        int dp2 = min(costs[0] + 2, 4) + costs[1];
        int res;
        for (int i = 3; i <= n; ++i) {
            res = min({dp0 + 9, dp1 + 4, dp2 + 1}) + costs[i - 1];
            dp0 = dp1;
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp0 = 0, dp1 = 0, dp2 = 0;
        int res;
        for (int i = 1; i <= n; ++i) {
            res = min({dp0 + 9, dp1 + 4, dp2 + 1}) + costs[i - 1];
            dp0 = dp1;
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp0 = 0, dp1 = 0, dp2 = 0;
        int res;
        for (const auto& c: costs) {
            res = min(min(dp0 + 9, dp1 + 4), dp2 + 1) + c;
            dp0 = dp1;
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};