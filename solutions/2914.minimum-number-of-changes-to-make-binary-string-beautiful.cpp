class Solution {
	/** 2914. Minimum Number of Changes to Make Binary String Beautiful
	 * https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
	 */
public:
    int minChanges(string s) {
        int res = 0;
        for (auto it = s.begin(); it != s.end(); it += 2) {
            if (*it != *(it + 1)) ++res;
        }
        return res;
    }
};