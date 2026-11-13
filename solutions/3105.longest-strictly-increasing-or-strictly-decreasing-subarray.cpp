class Solution {
    /** 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
     * https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
     */
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();
        int j = 0, i0 = -1, d0 = -1;
        nums.push_back(nums.back());
        int res = 1;
        for (; j < N; ++j) {
            if (nums[j + 1] < nums[j]) {
                res = max(res, j - i0);
                // cout << res << "-:" << j << ',' << i0 << endl;
                i0 = j;
            } else if (nums[j + 1] > nums[j]) {
                res = max(res, j - d0);
                // cout << res << "+:" << j << ',' << d0 << endl;
                d0 = j;
            } else {
                res = max(res, j - i0);
                res = max(res, j - d0);
                // cout << res << "=:" << j << ',' << i0 << '|' << j << ',' << d0 << endl;
                i0 = j;
                d0 = j;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const int N = nums.size();
        int inc = 1, dec = 1;
        int res = 1;
        for (int j = 1; j < N; ++j) {
            if (nums[j - 1] < nums[j]) {
                ++inc; dec = 1;
            } else if (nums[j - 1] > nums[j]) {
                ++dec; inc = 1;
            } else {
                inc = dec = 1;
            }
            res = max(res, max(inc, dec));
        }
        return res;
    }
};