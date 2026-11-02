class Solution {
    /** 1679. Max Number of K-Sum Pairs
     * https://leetcode.com/problems/max-number-of-k-sum-pairs/
     */
public:
    int maxOperations(vector<int>& nums, int k) {
        ranges::sort(nums);
        int i = 0, j = nums.size() - 1;
        int res = 0;
        while (i < j) {
            const int sij = nums[i] + nums[j];
            if (sij == k) {
                ++res; ++i; --j;
            } else if (sij > k) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};