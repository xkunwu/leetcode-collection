class SolutionSim {
    /** 1004. Max Consecutive Ones III
     * https://leetcode.com/problems/max-consecutive-ones-iii/
     */
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, n0 = 0, n1 = 0, N = nums.size();
        for (; n0 < k && j < N; ++j) {
            if (nums[j]) ++n1;
            else ++n0;
        }
        if (n0 < k) return N;
        int n = n1;
        for (int i = 0; j < N; ++j) {
            if (nums[j]) {
                ++n1;
                if (n1 > n) n = n1;
            } else {
                while (nums[i++]) --n1;
            }
        }
        return n + k;
    }
};

class Solution {
    /** 1004. Max Consecutive Ones III
     * https://leetcode.com/problems/max-consecutive-ones-iii/
     */
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, n0 = 0, n = 0;
        for (int i = 0; j < nums.size(); ++j) {
            if (!nums[j]) {
                ++n0;
            }
            if (n0 > k) {
                while (nums[i++]);
                --n0;
            }
            n = max(n, j - i + 1);
        }
        return n;
    }
};