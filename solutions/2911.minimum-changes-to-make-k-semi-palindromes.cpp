class Solution {
	/** 2911. Minimum Changes to Make K Semi-palindromes
	 * https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/
	 */
public:
    int minimumChanges(string s, int k) {
        auto spc = [](const string& s, int fr, int to) -> int {
            const int N = to - fr;
            int res = N;
            for (int d = 1; d <= N / 2; ++d) {
                if (N % d) continue;
                int cc = 0;
                for (int b = 0; b < d; ++b) {
                    for (int l = fr + b, r = to - d + b; l < r; l += d, r -= d) cc += (s[l] != s[r]);
                }
                if (cc < res) res = cc;
            }
            return res;
        };
        const int N = s.size();
        vector<vector<int>> v(N - 1, vector<int>(N));
        for (int r = 0; r < N - 1; ++r) {
            for (int c = r + 1; c < N; ++c) {
                v[r][c] = spc(s, r, c + 1);
            }
        }
        // for (int r = 0; r < N; ++r) { for (int c = 0; c < N; ++c) { cout << v[r][c] << ','; } cout << endl; } cout  << endl;
        vector<vector<int>> dp(k, vector<int>(N));
        for (int j = 0; j <= N - 2; ++j) {
            dp[0][j] = v[j][N - 1];
            // cout << dp[0][j] << ',';
        }
        // cout << endl;
        for (int i = 1; i < k; ++i) {
            const int je = N - 2 * (i + 1);
            for (int j = 0; j <= je; ++j) {
                int& mc = dp[i][j];
                mc = N;
                // cout << '(' << i << ',' << j << ':';
                const int xe = N - 2 * i - 1;
                for (int x = j + 1; x <= xe; ++x) {
                    mc = min(mc, v[j][x] + dp[i - 1][x + 1]);
                    // cout << mc << ',';
                }
                // cout << ')';
                // cout << mc << ',';
            }
            // cout << endl;
        }
        return dp[k - 1][0];
    }
};

class Solution {
	/** 2911. Minimum Changes to Make K Semi-palindromes
	 * https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/
	 */
public:
    int minimumChanges(string s, int k) {
        auto spc = [](const string& s, int fr, int to) -> int {
            const int N = to - fr;
            int res = N;
            for (int d = 1; d <= N / 2; ++d) {
                if (N % d) continue;
                int cc = 0;
                for (int b = 0; b < d; ++b) {
                    for (int l = fr + b, r = to - d + b; l < r; l += d, r -= d) cc += (s[l] != s[r]);
                }
                if (cc < res) res = cc;
            }
            return res;
        };
        const int N = s.size();
        vector<vector<int>> v(N - 1, vector<int>(N));
        for (int r = 0; r < N - 1; ++r) {
            for (int c = r + 1; c < N; ++c) {
                v[r][c] = spc(s, r, c + 1);
            }
        }
        // for (int r = 0; r < N - 1; ++r) { for (int c = 0; c < N; ++c) { cout << v[r][c] << ','; } cout << endl; } cout  << endl;
        vector<int>& dp = v[0];
        for (int i = 1; i < k; ++i) {
            const int je = 2 * (i + 1);
            for (int j = N; j >= je; --j) {
                int& mc = dp[j - 1];
                mc = N;
                // cout << '(' << i << ',' << j << ':';
                const int xe = 2 * i;
                for (int x = j - 2; x >= xe; --x) {
                    mc = min(mc, v[x][j - 1] + dp[x - 1]);
                    // cout << mc << ',';
                }
                // cout << ')';
                // cout << mc << ',';
            }
            // cout << endl;
        }
        return dp[N - 1];
    }
};