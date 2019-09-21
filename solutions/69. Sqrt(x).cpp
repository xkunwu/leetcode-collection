/** 69. Sqrt(x)
	https://leetcode.com/problems/sqrtx/
	Implement int sqrt(int x).

	Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

	Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (2 > x) return x;
        long res = 0;
        while ((res + 1) * (res + 1) <= x) ++res;
        return res;
    }
};

class Solution {
    /** Using Babylonian method
    **/
public:
    int mySqrt(int x) {
        if (2 > x) return x;
        int d = 0;
        int lx = x;
        while (1 < lx) { lx = lx >> 1; ++d; }
        d /= 2;
        int low = 1 << d; // lower bound
        int upper = x / low;
        //cout << low << " " << upper << endl;
        while (low + 1 < upper) {
            low = (low + upper) >> 1;
            upper = x / low;
            if (low > upper) swap(low, upper);
            //cout << low << " " << upper << endl;
        }
        return low;
    }
};

class Solution {
    /** Using Babylonian method
    **/
public:
    int mySqrt(int x) {
        if (2 > x) return x;
        int low = 2; // lower bound
        int upper = x / low;
        //cout << low << " " << upper << endl;
        while (low + 1 < upper) {
            low = (low + upper) >> 1;
            upper = x / low;
            if (low > upper) swap(low, upper);
            //cout << low << " " << upper << endl;
        }
        return low;
    }
};

class Solution {
    /** Using binary search
    **/
public:
    int mySqrt(int x) {
        if (2 > x) return x;
        int d = 0;
        int lx = x;
        while (1 < lx) { lx >>= 1; ++d; }
        d >>= 1;
        int low = 1 << d; // lower bound
        int upper = low << 1; // upper bound
        //cout << low << " " << upper << endl;
        while (low + 1 < upper) {
            long mid = (low + upper) >> 1;
            long msq = mid * mid;
            if (msq == x) return mid;
            else if (msq < x) low = mid;
            else upper = mid;
            //cout << low << " " << upper << endl;
        }
        return low;
    }
};
