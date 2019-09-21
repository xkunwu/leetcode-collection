/** 18. 4Sum
	https://leetcode.com/problems/4sum/
	Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::set< std::vector<int> > rset;
        std::sort(nums.begin(), nums.end());
        const size_t nn = nums.size();
        for (size_t ii = 0; ii < nn - 3; ++ii) {
            for (size_t jj = ii + 1; jj < nn - 2; ++jj) {
                if (jj > ii + 1 && nums[jj] == nums[jj - 1]) continue;
                size_t kl = jj + 1, kr = nn - 1;
                while (kl < kr) {
                    const int sum = nums[ii] + nums[jj] + nums[kl] + nums[kr];
                    if (sum == target) {
                        rset.insert(
                            std::vector<int>({nums[ii], nums[jj], nums[kl], nums[kr]})
                        );
                        ++kl; --kr;
                    } else if (sum < target) ++kl;
                    else --kr;
                }
            }
        }
        return std::vector< std::vector<int> >(rset.begin(), rset.end());
    }
};
