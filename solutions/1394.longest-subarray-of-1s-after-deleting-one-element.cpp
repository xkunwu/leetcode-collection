class Solution2Stages {
    /** 1493. Longest Subarray of 1's After Deleting One Element
     * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
     */
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        const int N = nums.size();
        int i = 0, j = 0;
        while (j < N && nums[j++]) ++res;
        // cout << i << ',' << j << ": " << res << endl;
        if (N == j) return res - nums[N - 1];
        for (; j < N; ++j) {
            // cout << i << ',' << j << ": " << res << ' ' << n;
            if (nums[j]) {
                res = max(res, j - i);
            } else {
                while (nums[i++]);
            }
            // cout << " -> " << res << ' ' << n << endl;
        }
        return res;
    }
};

class Solution {
    /** 1493. Longest Subarray of 1's After Deleting One Element
     * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
     */
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        const int N = nums.size();
        int i = 0, j = 0;
        int n0 = 0;
        for (; j < N; ++j) {
            if (!nums[j]) ++n0;
            while (1 < n0) n0 -= 1 - nums[i++];
            res = max(res, j - i);
        }
        return res;
    }
};