class Solution {
    /** 151. Reverse Words in a String
     * https://leetcode.com/problems/reverse-words-in-a-string/
     */
public:
    string reverseWords(string s) {
        string res;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (' ' == s[i]) continue;
            string t;
            while (0 <= i && ' ' != s[i]) {
                t = s[i--] + t;
            }
            res += move(t) + ' ';
            // cout << res << endl;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};