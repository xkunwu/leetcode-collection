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
    int min3(const int &v1, const int &v2, const int &v3) {
        return min(min(v1, v2), v3);
    }
public:
    int minDistance(string word1, string word2) {
        const size_t n1 = word1.length();
        const size_t n2 = word2.length();
        if (0 == n1) return n2;
        if (0 == n2) return n1;
        vector<vector<int>> dpTab(n1 + 1);
        for (auto &vec : dpTab) vec.resize(n2 + 1);
        for (size_t ii = 0; ii <= n1; ++ii) {
            for (size_t jj = 0; jj <= n2; ++jj) {
                if (0 == ii) dpTab[ii][jj] = jj;
                else if (0 == jj) dpTab[ii][jj] = ii;
                else if (word1[ii - 1] == word2[jj - 1])
                    dpTab[ii][jj] = dpTab[ii - 1][jj - 1];
                else dpTab[ii][jj] = 1 + min3(
                    dpTab[ii][jj - 1], // insert
                    dpTab[ii - 1][jj], // delete
                    dpTab[ii - 1][jj - 1] //replace
                );
            }
        }
        return dpTab[n1][n2];
    }
};