class Solution {
    /** 2124. Check if All A's Appears Before All B's
     * https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs/
     */
public:
    bool checkString(string s) {
        int i = 0;
        while (i < s.size() && 'a' == s[i]) ++i;
        if (i == s.size()) return true;
        while (i < s.size() && 'b' == s[i]) ++i;
        return (i == s.size());
    }
};

class Solution {
public:
    bool checkString(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if ('b' == s[i - 1] && 'a' == s[i]) return false;
        }
        return true;
    }
};