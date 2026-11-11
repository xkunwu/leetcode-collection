class Solution {
    /** 3789. Minimum Cost to Acquire Required Items
     * https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
     */
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        const int smaller = min(need1, need2);
        long long res = min((long long)cost1 + cost2, (long long)costBoth) * smaller;
        res += (long long)(need1 - smaller) * min(cost1, costBoth);
        res += (long long)(need2 - smaller) * min(cost2, costBoth);
        return res;
    }
};