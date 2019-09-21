/** 902. Numbers At Most N Given Digit Set
	https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
	We have a sorted set of digits D, a non-empty subset of {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)

	Now, we write numbers using these digits, using each digit as many times as we want.  For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.

	Return the number of positive integers that can be written (using the digits of D) that are less than or equal to N.
*/

class Solution {
    /** Recursive solution.
        Runtime Error: stack-overflow, ie. require too much stack allocation.
    **/
    deque<int> digits;
    int countDigits(const int& N, const int& num, const int& nn) {
        if (num > N) return 0;
        int cnt = 0;
        for (int d : digits) {
            int num_d = num + d * pow(10, nn);
            if (num_d < N) ++cnt;
            cnt += countDigits(N, num_d, nn + 1);
        }
        return cnt;
    }
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        for (auto d : D) {
            digits.push_back(d[0] - '0');
        }
        // for (auto d : digits) cout << d << " ";
        // cout << endl;
        return countDigits(N, 0, 0);
    }
};
