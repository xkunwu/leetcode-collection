class Solution {
    /** 169. Majority Element
     * https://leetcode.com/problems/majority-element/
     */
public:
    int majorityElement(vector<int>& nums) {
        const size_t m = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        return nums[m];
    }
};