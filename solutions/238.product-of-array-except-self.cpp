#include <iostream>
#include <vector>
using namespace std;

class SolutionSimu {
	/** 238. Product of Array Except Self
	 * https://leetcode.com/problems/product-of-array-except-self/
	 */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> res(nums);
        int n;
        res[N - 1] = res[0];
        res[0] = 1;
        for (int i = 1; i < N; ++i) {
            n = res[N - 1];
            res[N - 1] = res[i];
            res[i] = res[i - 1] * n;
        }
        nums[0] = nums[N - 1];
        nums[N - 1] = 1;
        for (int i = N - 2; i >= 0; --i) {
            n = nums[0];
            nums[0] = nums[i];
            nums[i] = nums[i + 1] * n;
        }
        for (int i = 0; i < N; ++i) {
            res[i] *= nums[i];
        }
        return res;
    }
};

class Solution {
	/** 238. Product of Array Except Self
	 * https://leetcode.com/problems/product-of-array-except-self/
	 */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> res(N, 1);
        int lprod = 1, rprod = 1;
        for (int l = 0, r = N - 1; l < N; ++l, --r) {
            res[l] *= lprod; res[r] *= rprod;
            lprod *= nums[l]; rprod *= nums[r];
        }
        return res;
    }
};

int main(void)
{
	vector<int> nums = {1,2,3,4}; // 24,12,8,6
	Solution solution;
	vector<int> res = solution.productExceptSelf(nums);
	
	for (const int& x: res) {
		cout << x << ' ';
	}
	cout << endl;
}
