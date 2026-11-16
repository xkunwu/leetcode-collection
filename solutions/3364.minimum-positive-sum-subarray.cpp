class Solution {
    /** 3364. Minimum Positive Sum Subarray 
     * https://leetcode.com/problems/minimum-positive-sum-subarray/
     */
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = 100000;
        const int N = nums.size();
        for (int i = 1; i < N; ++i) nums[i] += nums[i - 1];
        nums.insert(nums.begin(), 0);
        for (int len = l; len <= r && len <= N; ++len) {
            for (int j = len; j <= N; ++j) {
                const int sum = nums[j] - nums[j - len];
                if (0 >= sum) continue;
                if (sum < res) res = sum;
            }
        }
        if (100000 == res) res = -1;
        return res;
    }
};