class Solution {
    /** 1318. Minimum Flips to Make a OR b Equal to c
     * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
     */
public:
    int minFlips(int a, int b, int c) {
        bitset<32> a2(a), b2(b), c2(c);
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (0 == c2[i]) {
                if (a2[i]) ++res;
                if (b2[i]) ++res;
            } else {
                if (!a2[i] && !b2[i]) ++res;
            }
        }
        return res;
    }
};

class Solution {
    /** 1318. Minimum Flips to Make a OR b Equal to c
     * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
     */
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (; a || b || c;) {
            int a1 = a & 1, b1 = b & 1, c1 = c & 1;
            if (0 == c1) {
                res += a1 + b1;
            } else {
                if (!a1 && !b1) ++res;
            }
            a >>= 1; b >>= 1; c >>= 1;
        }
        return res;
    }
};