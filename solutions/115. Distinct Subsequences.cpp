/** 115. Distinct Subsequences
	https://leetcode.com/problems/distinct-subsequences/
	Given a string S and a string T, count the number of distinct subsequences of S which equals T.

	A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        const int ns = s.length();
        const int nt = t.length();
        std::vector< std::vector<int> > N(ns + 1);
        for (int ii = 0; ii <= ns; ++ii) {
            N[ii] = std::vector<int>(nt + 1, -1);
            N[ii][nt] = 1;
        }
        for (int jj = 0; jj < nt; ++jj) N[ns][jj] = 0;
		cout << N[ns - 1][nt - 1] << " " << N[ns - 1][nt] << " " << N[ns][nt - 1] << " " << N[ns][nt] << endl;
        for (int ii = ns - 1; ii >= 0; --ii) {
            for (int jj = nt - 1; jj >= 0; --jj) {
                if (s[ii] == t[jj]) N[ii][jj] = N[ii + 1][jj] + N[ii + 1][jj + 1];
                else N[ii][jj] = N[ii + 1][jj];
            }
        }
        return N[0][0];
    }
};
