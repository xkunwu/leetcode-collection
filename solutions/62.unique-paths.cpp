class SolutionDP2d {
	/** 62. Unique Paths
	 * https://leetcode.com/problems/unique-paths/
	 */
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> P(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				P[i][j] = P[i - 1][j] + P[i][j - 1];
			}
		}
		return P[m - 1] [n - 1];
	}
};

class Solution {
	/** 62. Unique Paths
	 * https://leetcode.com/problems/unique-paths/
	 */
public:
	int uniquePaths(int m, int n) {
		vector<int> P(n, 1);
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				P[j] = P[j - 1] + P[j];
			}
		}
		return P[n - 1];
	}
};
