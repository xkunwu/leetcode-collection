class Solution {
	/** #72. Edit Distance
		https://leetcode.com/problems/edit-distance/
		Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

		You have the following 3 operations permitted on a word:

			1. Insert a character
			2. Delete a character
			3. Replace a character

		Comments:
		Recursive solution:
        Worst case O(3^max{n1, n2}), if none of the characters is the same.
	*/
    int min3(const int &v1, const int &v2, const int &v3) {
        return min(min(v1, v2), v3);
    }
public:
    int minDistance(string word1, string word2) {
        const size_t n1 = word1.length();
        const size_t n2 = word2.length();
        if (0 == n1) return n2;
        if (0 == n2) return n1;
        if (word1[0] == word2[0])
            return minDistance(word1.substr(1), word2.substr(1));
        const int nins = minDistance(word1.substr(), word2.substr(1));
        const int ndel = minDistance(word1.substr(1), word2.substr(0));
        const int nrep = minDistance(word1.substr(1), word2.substr(1));
        return 1 + min3(nins, ndel, nrep);
    }
};

class Solution {
    /** DP solution:
        O(n1 * n2) time and space.
    **/
public:
    int minDistance(string word1, string word2) {
        const size_t n1 = word1.length();
        const size_t n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (size_t i = 0; i <= n1; ++i) dp[i][0] = i;
        for (size_t j = 1; j <= n2; ++j) dp[0][j] = j;
        for (size_t i = 1; i <= n1; ++i) {
            for (size_t j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1], // replace
                        dp[i - 1][j], // delete
                        dp[i][j - 1] // insert
                        });
                }
            }
            // for (const int& d: dp[i]) { cout << d << ' '; } cout << endl;
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t n1 = word1.length();
        const size_t n2 = word2.length();
        vector<int> dp(n2 + 1);
        for (size_t j = 1; j <= n2; ++j) dp[j] = j;
        for (size_t i = 0; i < n1; ++i) {
            int nul = i; // upper left neighbor
            dp[0] = i + 1;
            for (size_t j = 1; j <= n2; ++j) {
                // cout << "(" << word1[i] << ", " << j << "): " << nul << ' ' << dp[j] << " -> ";
                int nu = dp[j]; // upper neighbor
                if (word1[i] == word2[j - 1]) {
                    dp[j] = nul;
                } else {
                    dp[j] = 1 + min({
                        nul, // replace
                        nu, // delete
                        dp[j - 1] // insert
                        });
                }
                nul = nu;
                // cout << nul << ' ' << dp[j] << endl;
            }
            // for (const int& d: dp) { cout << d << ' '; } cout << endl;
        }
        return dp[n2];
    }
};