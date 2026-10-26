#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
	/** 334. Increasing Triplet Subsequence
	 * https://leetcode.com/problems/increasing-triplet-subsequence/
	 * 
	 * Unexpected solution - easier than I thought.
	 */
public:
	bool increasingTriplet(vector<int>& nums) {
		int min0 = std::numeric_limits<int>::max(), min1 = min0;
		for (const int& n: nums) {
			if (n > min1) return true;
			else if (n <= min0) min0 = n;
			else min1 = n;
		}
		return false;
	}
};

int main(void)
{
	vector<int> nums = {2,1,5,0,4,6}; // T
//	vector<int> nums = {5,4,3,2,1}; // F
//	vector<int> nums = {1,2,3,4,5}; // T

	Solution solution;
	cout << solution.increasingTriplet(nums) << endl;
}
