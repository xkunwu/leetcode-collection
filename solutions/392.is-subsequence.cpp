class Solution {
    /** 392. Is Subsequence
     * https://leetcode.com/problems/is-subsequence/
     */
public:
    bool isSubsequence(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        for (; i >= 0 && j >= 0; --j) {
            if (s[i] == t[j]) --i;
        }
        return 0 > i;
    }
};