#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    /** 443. String Compression
     * https://leetcode.com/problems/string-compression/
     */
public:
    int compress(vector<char>& chars) {
        char p = chars[0];
        int res = 1, n = 0;
        auto wn = [&]() {
            string str = to_string(n);
            for (const auto& s: str) {
                chars[res++] = s;
            }
        };
        for (const auto& c: chars) {
            if (c == p) {
                ++n;
                continue;
            }
            if (1 < n) wn();
            p = c;
            chars[res++] = c;
            n = 1;
        }
        if (1 < n) wn();
        return res;
    }
};

int main(void)
{
	vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'}; // "ab12"
	// vector<char> chars = {'a','a','b','b','c','c','c'}; // "a2b2c3"
	Solution solution;
	int res = solution.compress(chars);
	
	for (const auto& c: chars) {
		cout << c << ' ';
	}
	cout << endl;
}