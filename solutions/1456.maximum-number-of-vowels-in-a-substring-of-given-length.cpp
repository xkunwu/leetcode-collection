class SolutionStr {
    /** 1456. Maximum Number of Vowels in a Substring of Given Length
     * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
     */
public:
    int maxVowels(string s, int k) {
        const string vowels = "aeiou";
        int j = 0, res = 0;
        for (; j < k; ++j) {
            if (string::npos != vowels.find(s[j])) {
                ++res;
                if (res == k) return k;
                s[j] = '.';
                // cout << res << ": " << j << endl;
            }
        }
        int n = res;
        for (; j < s.size(); ++j) {
            if (string::npos != vowels.find(s[j])) {
                s[j] = '.';
                ++n;
            }
            n -= ('.' == s[j - k]);
            if (n > res) {
                res = n;
                if (res == k) return k;
            }
            // cout << res << "-" << n << ": " << i << ", " << j << endl;
        }
        return res;
    }
};

class Solution {
    /** 1456. Maximum Number of Vowels in a Substring of Given Length
     * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
     */
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](const char& c) -> bool {
            return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
        };
        int j = 0, res = 0;
        for (; j < k; ++j) {
            res += isVowel(s[j]);
        }
        if (res == k) return k;
        int n = res;
        for (; j < s.size(); ++j) {
            n += isVowel(s[j]) - isVowel(s[j - k]);
            if (n > res) {
                res = n;
                if (res == k) return k;
            }
        }
        return res;
    }
};