class Solution {
    /** 2243. Calculate Digit Sum of a String
     * https://leetcode.com/problems/calculate-digit-sum-of-a-string/
     */
public:
    string digitSum(string s, int k) {
        for (; s.size() > k;) {
            string ans;
            int sum = 0, i = 0;
            for (auto c: s) {
                sum += c - '0';
                ++i;
                if (k == i) {
                    ans += to_string(sum);
                    i = 0; sum = 0;
                }
            }
            if (0 < i) ans += to_string(sum);
            s = move(ans);
            // cout << s << endl;
        }
        return s;
    }
};