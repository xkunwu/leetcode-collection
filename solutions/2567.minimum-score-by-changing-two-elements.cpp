class Solution {
	/** 2567. Minimum Score by Changing Two Elements
	 * https://leetcode.com/problems/minimum-score-by-changing-two-elements/
	 */
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return min({
            nums[nums.size() - 2] - nums[1],
            nums[nums.size() - 1] - nums[2],
            nums[nums.size() - 3] - nums[0],
        });
    }
};

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        partial_sort(nums.begin(), nums.begin() + 3, nums.end());
        partial_sort(nums.rbegin(), nums.rbegin() + 3, nums.rend() - 3, greater<int>());
        // for (auto x: nums) { cout << x << ','; } cout << endl;
        return min({
            nums[nums.size() - 2] - nums[1],
            nums[nums.size() - 1] - nums[2],
            nums[nums.size() - 3] - nums[0],
        });
    }
};