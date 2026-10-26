#include <iostream>
#include <vector>
using namespace std;

class SolutionSimu {
	/** 790. Domino and Tromino Tiling
	 *  https://leetcode.com/problems/domino-and-tromino-tiling/
	 *
	 *  Use math to simplify the recurrence relation and achieve better performance.
	 */
public:
    int numTilings(int n) {
        if (1 == n) return 1;
        if (2 == n) return 2;
        const int M = 1000000007;
        vector<int> T(n + 1);
        T[0] = 1; T[1] = 1; T[2] = 2;
		long long sum;
        for (int i = 3; i <= n; ++i) {
			// T(n) = T(n-1) + T(n-2) + \sum_{i=0}^{n-3} 2 * T(i)
        	sum = 
				T[i - 1] // 2x1 vertical
				+ T[i - 2]; // 2x1 horizontal
			for (int k = i - 3; k >= 0; --k) {
				sum += T[k] * 2; // L
			}
			T[i] = sum % M;
//			cout << T[i] << endl;
		}
		return T[n];
    }
};

class Solution {
	/** 790. Domino and Tromino Tiling
	    https://leetcode.com/problems/domino-and-tromino-tiling/
	 */
public:
	int numTilings(int n) {
		if (1 == n) return 1;
		if (2 == n) return 2;
		const int M = 1000000007;
		vector<int> T(n + 1);
		T[0] = 1; T[1] = 1; T[2] = 2;
		long long sum;
		for (int i = 3; i <= n; ++i) {
			// T(n) = T(n-1) + T(n-2) + \sum_{i=0}^{n-3} 2 * T(i)
			// T(n-1) = T(n-2) + T(n-3) + \sum_{i=0}^{n-4} 2 * T(i)
			// T(n) - T(n-1) = T(n-1) - T(n-3) + 2 * T(n-3)
			// T(n) = 2 * T(n-1) * T(n-3)
			sum = T[i - 3];
			sum += 2 * T[i - 1];
			T[i] = sum % M;
//			cout << T[i] << endl;
		}
		return T[n];
	}
};

int main(void)
{
	int n = 6; // 53
//	int n = 5; // 24
//	int n = 4; // 11
//	int n = 3; // 5

	Solution solution;
	cout << solution.numTilings(n) << endl;
}
