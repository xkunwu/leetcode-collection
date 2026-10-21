#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 198. House Robber
	    https://leetcode.com/problems/house-robber/
	 */
public:
	int rob(vector<int>& nums) {
		const size_t N = nums.size();
		if (0 == N) return 0;
		if (1 == N) return nums[0];
		if (2 == N) return max(nums[0], nums[1]);
		nums[1] = max(nums[0], nums[1]);
		for (size_t i = 2; i < N; ++i) {
			nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
		}
		return nums[N - 1];
//		vector<int> S(N + 1);
//		S[0] = 0; S[1] = nums[0];
//		for (size_t i = 2; i <= N; ++i) {
//			S[i] = max(S[i - 1], S[i - 2] + nums[i - 1]);
//		}
//		return S[N];
	}
};

int main(void)
{
	vector<int> nums = {2,1,1,2}; // 4
//	vector<int> nums = {2,7,9,3,1}; // 12
//	vector<int> nums = {1,2,3,1}; // 4
//	vector<int> nums = {1,2,3}; // 4
//	vector<int> nums = {1,2}; // 2
//	vector<int> nums = {1}; // 1

	Solution solution;
	cout << solution.rob(nums) << endl;
}
