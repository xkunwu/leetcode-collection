/** 940. Distinct Subsequences II
	https://leetcode.com/problems/distinct-subsequences-ii/
	Given a string S, count the number of distinct, non-empty subsequences of S .

	Since the result may be large, return the answer modulo 10^9 + 7.
*/

class Solution {
public:
    int distinctSubseqII(string S) {
        const int MOD = 1'000'000'007;
        const size_t nS = S.length();
        std::vector<int> N(nS + 1, 1); // #0 means empty
        //// 2 ^ ii, if no repeated letter
        //for (size_t ii = 1; ii <= nS; ++ii) {
            //N[ii] = (N[ii - 1] * 2) % MOD;
        //}
        std::vector<int> C(26, 0); // count repitition
        for (size_t ii = 1; ii <= nS; ++ii) {
            const size_t ci = S[ii - 1] - 'a';
            N[ii] = (N[ii - 1] * 2) % MOD;
            N[ii] = (N[ii] + MOD - C[ci]) % MOD;
            C[ci] = N[ii - 1]; // duplicate due to latest set
        }
        return (N[nS] + MOD - 1) % MOD;
    }
};
