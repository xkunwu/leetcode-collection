#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    /** 1541. Minimum Insertions to Balance a Parentheses String
        https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
        Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

        - Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
        - Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.

        In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

        - For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
        You can insert the characters '(' and ')' at any position of the string to balance it if needed.

        Return the minimum number of insertions needed to make s balanced.

        Constraints:

            1 <= s.length <= 105
            s consists of '(' and ')' only.
    */
public:
    static int minInsertions(string s) {
        stack<int> lrs;
        int nr = 0;
        int num_in = 0;
        string::iterator si;
        for (si = s.begin(); si != s.end(); ++si) {
            if ('(' == *si) {
                if (1 == nr) {
                    if (!lrs.empty()) { // '()('
                        lrs.pop();
                    } else { // ')('
                        num_in += 2;
                    }
                    nr = 0;
                }
                lrs.push(1);
            } else if (')' == *si) {
                ++nr;
                if (2 == nr) {
                    if (lrs.empty()) ++num_in;
                    else {
                        --num_in;
                        lrs.pop();
                    }
                    nr = 0;
                } else if (!lrs.empty()) {
                    ++num_in;
                }
            }
        }
        if (1 == nr) {
            if (!lrs.empty()) lrs.pop();
            else { // ')'
                num_in += 2;
            }
        }
        return num_in + lrs.size() * 2;
    }
};

int main(void)
{
    cout << Solution::minInsertions(")))())()()())()((()((()((())))()((") << endl; // 23
    cout << Solution::minInsertions("))))()))())") << endl; // 4
    cout << Solution::minInsertions("()())))()") << endl; // 3
    cout << Solution::minInsertions(")))))))") << endl; // 5
    cout << Solution::minInsertions("(()))") << endl; // 1
    cout << Solution::minInsertions("())") << endl; // 0
    cout << Solution::minInsertions("))())(") << endl; // 3
}