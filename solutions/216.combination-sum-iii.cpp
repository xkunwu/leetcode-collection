#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 216. Combination Sum III
	 * https://leetcode.com/problems/combination-sum-iii/description/
	 */
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> vx(k);
		for (int i = 0; i < k; ++i) vx[i] = 9 - i;
		int sum = 0;
		for (const int& x: vx) sum += x;
		if (n == sum) return {vx};
		if (n > sum) return {};
		for (int i = 0; i < k; ++i) vx[i] = i;
		sum = 0;
		for (const int& x: vx) sum += x;
		for (int i = 0; i >= 0;) {
			++vx[i];
			sum += 1;
			if (10 == vx[i] || n < sum) {
				if (0 == i) break;
				for (int j = i; j < k; ++j) {
					sum += vx[j - 1] + 1 - vx[j];
					vx[j] = vx[j - 1] + 1;
				}
				--i;
			} else if (i < (k - 1)) {
				++i;
			} else {
				if (n == sum) {
					res.push_back(vx);
				}
			}
		}
		return res;
	}
};

int main(void)
{
	Solution solution;
	vector<vector<int>> res = solution.combinationSum3(4, 54);
//	vector<vector<int>> res = solution.combinationSum3(2, 18);
//	vector<vector<int>> res = solution.combinationSum3(4, 1);
//	vector<vector<int>> res = solution.combinationSum3(3, 9);
//	vector<vector<int>> res = solution.combinationSum3(3, 7);
	
	for (const vector<int>& xv: res) {
		for (const int& x: xv) {
			cout << x << ' ';
		}
		cout << endl;
	}
}
