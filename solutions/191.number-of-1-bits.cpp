class Solution {
    /** 191. Number of 1 Bits
     * https://leetcode.com/problems/number-of-1-bits/
     */
public:
    int hammingWeight(int n) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            res += (n & 1);
            n >>= 1;
            // cout << n << ',';
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        return popcount((unsigned)n);
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (0 < n) {
            n &= (n - 1);
            ++res;
            // cout << n << ',';
        }
        return res;
    }
};