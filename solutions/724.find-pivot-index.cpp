class SolutionPrefixSum {
    /** 724. Find Pivot Index
     * https://leetcode.com/problems/find-pivot-index/
     */
public:
    int pivotIndex(vector<int>& nums) {
        const int N = nums.size();
        vector<int> lsum(nums);
        for (int i = 1, last = 0; i < N; ++i) {
            tie(last, lsum[i]) = make_pair(lsum[i], lsum[i - 1] + last);
        }
        lsum[0] = 0;
        // for (const int& n: lsum) { cout << n << ' '; } cout << endl;
        for (int i = N - 2, last = 0; i >= 0; --i) {
            tie(last, nums[i]) = make_pair(nums[i], nums[i + 1] + last);
        }
        nums[N - 1] = 0;
        // for (const int& n: nums) { cout << n << ' '; } cout << endl;
        for (int i = 0; i < N; ++i) {
            if (lsum[i] == nums[i]) return i;
        }
        return -1;
    }
};

class Solution {
    /** 724. Find Pivot Index
     * https://leetcode.com/problems/find-pivot-index/
     */
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (const int& n: nums) sum += n;
        int lsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((lsum << 1) + nums[i] == sum) return i;
            lsum += nums[i];
        }
        return -1;
    }
};