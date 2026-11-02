#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SolutionDP2d {
	/** 1143. Longest Common Subsequence
	 * https://leetcode.com/problems/longest-common-subsequence/
	 */
public:
	int longestCommonSubsequence(string text1, string text2) {
		const size_t m = text1.size(), n = text2.size();
		vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
		for (size_t i = 1; i <= m; ++i) {
			for (size_t j = 1; j <= n; ++j) {
				if (text1[i - 1] == text2[j - 1]) P[i][j] = P[i - 1][j - 1] + 1;
				else P[i][j] = max(P[i - 1][j], P[i][j - 1]);
				// cout << "(" << i << ", " << j << ")" << P[i][j] << endl;
			}
		}
		return P[m][n];
	}
};

class Solution {
	/** 1143. Longest Common Subsequence
	 * https://leetcode.com/problems/longest-common-subsequence/
	 */
public:
	int longestCommonSubsequence(string text1, string text2) {
		const size_t n = text2.size();
		vector<int> P(n + 1, 0);
		for (const auto& c: text1) {
			int nul = 0; // upper left neighbor
			for (size_t j = 1; j <= n; ++j) {
				int nu = P[j]; // upper neighbor
				if (c == text2[j - 1]) P[j] = nul + 1;
				else P[j] = max(P[j - 1], nu);
				nul = nu;
				// cout << "(" << c << ", " << j << "): " << P[j] << endl;
			}
		}
		return P[n];
	}
};

int main(void)
{
	Solution solution;
	cout << solution.longestCommonSubsequence("abcba", "abcbcba") << endl;
}
