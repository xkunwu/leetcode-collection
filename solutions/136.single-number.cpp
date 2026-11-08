class Solution {
    /** 136. Single Number
     * https://leetcode.com/problems/single-number/
     */
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (const int& n: nums) {
            res ^= n;
        }
        return res;
    }
};