class SolutionSimu {
    /** 1071. Greatest Common Divisor of Strings
     * https://leetcode.com/problems/greatest-common-divisor-of-strings/
     */
public:
    string gcdOfStrings(string str1, string str2) {
        const size_t N1 = str1.size(), N2 = str2.size();
        size_t n = 0, k;
        string res, nxt, tstr;
        for (size_t i = 0, j = 0; i < N1 && j < N2; ++i, ++j) {
            if (str1[i] != str2[j]) break;
            ++n; nxt += str1[i];
            if (0 != N1 % n || 0 != N2 % n) continue;
            tstr = "";
            for (k = 0; k != N1; k += n) {
                tstr += nxt;
            }
            if (tstr != str1) continue;
            tstr = "";
            for (k = 0; k != N2; k += n) {
                tstr += nxt;
            }
            if (tstr != str2) continue;
            res = nxt;
        }
        return res;
    }
};

class Solution {
    /** 1071. Greatest Common Divisor of Strings
     * https://leetcode.com/problems/greatest-common-divisor-of-strings/
     */
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};