class Solution {
    /** 58. Length of Last Word
     * https://leetcode.cn/problems/length-of-last-word/
     */
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        auto it = s.rbegin();
        for (; it != s.rend(); ++it) {
            if (' ' != *it) break;
        }
        for (; it != s.rend(); ++it) {
            if (' ' != *it) ++res;
            else break;
        }
        return res;
    }
};