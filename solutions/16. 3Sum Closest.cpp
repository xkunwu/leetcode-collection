class Solution {
	/** #16. 3Sum Closest
		https://leetcode.com/problems/3sum-closest/
		Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
	*/
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret;
        size_t dist = numeric_limits<int>::max();
        const int nn = nums.size();
        for (int ni = 0; ni < nn; ++ni) {
            // cout << ni << ": ";
            int ll = 0, rr = nums.size() - 1;
            while (ll < rr) {
                // cout << ll << ", " << rr << " -> ";
                if (ni == ll) { ++ll; continue; }
                if (ni == rr) { --rr; continue; }
                int sum = nums[ll] + nums[rr] + nums[ni];
                const size_t dd = abs(sum - target);
                if (dd < dist) { dist = dd; ret = sum; }
                if (sum < target) ++ll;
                else if (sum > target) --rr;
                else return ret;
            }
        }
        return ret;
    }
};