class Solution {
    /** 3041. Maximize Consecutive Elements in an Array After Modification
     * https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
     */
public:
    int maxSelectedElements(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        // for (auto x: nums) { cout << x << ','; } cout << endl;
        vector<int> dp(1000002);
        for (const auto& x: nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
        }
        for (const auto& x: dp) if (x > res) res = x;
        return res;
    }
};

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for (auto x: nums) { cout << x << ','; } cout << endl;
        int keep = 1, plus = 1;
        int res = 1;
        const int N = nums.size();
        for (int i = 1; i < N; ++i) {
            const int diff = nums[i] - nums[i - 1];
            if (0 == diff) {
                plus = keep + 1;
            } else if (1 == diff) {
                ++keep; ++plus;
            } else if (2 == diff) {
                keep = plus + 1;
                plus = 1;
            } else {
                keep = 1, plus = 1;
            }
            if (keep > res) res = keep;
            if (plus > res) res = plus;
        }
        return res;
    }
};

// [1,1,3,1,1]
// [8,10,6,12,9,12,2,3,13,19,11,18,10,16]
// [12,11,8,7,2,10,18,12]
// [8,13,18,10,16,19,11,17,15,18,9,12,15,8,9,14,7]