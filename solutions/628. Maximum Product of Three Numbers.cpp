/** 628. Maximum Product of Three Numbers
	https://leetcode.com/problems/maximum-product-of-three-numbers/
	Given an integer array, find three numbers whose product is maximum and output the maximum product.
*/

class Solution {
    /** Proof:
        1. all-positive, none-positive: Min_{1, 2, 3}.
        2. positive + negative (+0): only one positive.
    **/
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        size_t nn = nums.size();
        return std::max<int>(
            nums[nn - 1] * nums[nn - 2] * nums[nn - 3],
            nums[0] * nums[1] * nums[nn - 1]
        );
    }
};

class Solution {
    /** Proof:
        1. all-positive, none-positive: Min_{1, 2, 3}.
        2. positive + negative (+0): only one positive.
    **/
public:
    int maximumProduct(vector<int>& nums) {
        std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());
        int min_2 = nums[0] * nums[1];
        std::partial_sort(nums.begin(), nums.begin() + 3, nums.end(), std::greater<int>());
        size_t nn = nums.size();
        int max_3 = nums[nn - 1] * nums[nn - 2] * nums[nn - 3];
        return std::max<int>(
            max_3,
            min_2 * std::max_element(nums.begin(), nums.begin() + 3)
        );
    }
};
