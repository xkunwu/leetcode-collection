class Solution {
    /** 2871. Split Array Into Maximum Number of Subarrays
     * https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/
     */
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, sa = -1;
        size_t i = 0, N = nums.size();
        for (; i < N; ++i) {
            if (0 == nums[i] && -1 == sa) {
                ++res;
                continue;
            }
            if (-1 == sa) {
                sa = nums[i];
                continue;
            }
            sa &= nums[i];
            if (0 == sa) {
                ++res;
                sa = -1;
            }
        }
        if (0 < sa && 0 == res) return 1;
        else return res;
    }
};

class Solution {
    /** 2871. Split Array Into Maximum Number of Subarrays
     * https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/
     */
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, sa = -1;
        for (const int& n: nums) {
            sa &= n;
            if (0 == sa) {
                ++res;
                sa = -1;
            }
        }
        return max(1, res);
    }
};