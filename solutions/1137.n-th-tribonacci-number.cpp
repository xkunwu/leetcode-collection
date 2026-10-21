#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 1137. N-th Tribonacci Number
	    https://leetcode.com/problems/n-th-tribonacci-number/
	 */
public:
	int tribonacci(int n) {
		if (0 == n) return 0;
		if (1 == n || 2 == n) return 1;
		vector<int> T(n + 1);
		T[0] = 0; T[1] = 1; T[2] = 1;
		if (3 > n) return T[n];
		for (int i = 3; i <= n; ++i) {
			T[i] += T[i - 1];
			T[i] += T[i - 2];
			T[i] += T[i - 3];
		}
		return T[n];
	}
};

int main(void)
{
	const int n = 25; // 1389537
//	const int n = 4; // 4

	Solution solution;
	cout << solution.tribonacci(n) << endl;
}
