class SolutionDFS {
	/** 17. Letter Combinations of a Phone Number
	 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
	 */
private:
	vector<vector<char>> d2c = {
		{'a', 'b', 'c',},
		{'d', 'e', 'f',},
		{'g', 'h', 'i',},
		{'j', 'k', 'l',},
		{'m', 'n', 'o',},
		{'p', 'q', 'r', 's',},
		{'t', 'u', 'v',},
		{'w', 'x', 'y', 'z',},
	};
	
	void dfs(const string& digits, const int& n, string& x, vector<string>& res)
	{
		if (0 == n) {
			// cout << x << endl << endl;
			res.push_back(x);
			return;
		}
		const vector<char>& vc = d2c[digits[n - 1] - '2'];
		for (const char& c: vc) {
			x[n - 1] = c;
			dfs(digits, n - 1, x, res);
			// cout << x << endl;
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		string x(digits.size(), '.');
		dfs(digits, digits.size(), x, res);
		return res;
	}
};

class SolutionLambda {
	/** 17. Letter Combinations of a Phone Number
	 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
	 */
public:
	vector<string> letterCombinations(string digits) {
        vector<vector<char>> d2c = {
            {'a', 'b', 'c',},
            {'d', 'e', 'f',},
            {'g', 'h', 'i',},
            {'j', 'k', 'l',},
            {'m', 'n', 'o',},
            {'p', 'q', 'r', 's',},
            {'t', 'u', 'v',},
            {'w', 'x', 'y', 'z',},
        };

        vector<string> res;
		string x(digits.size(), '.');
        auto dfs = [&](this auto&& dfs, const int& n)
        {
            if (0 == n) {
                // cout << x << endl << endl;
                res.push_back(x);
                return;
            }
            const vector<char>& vc = d2c[digits[n - 1] - '2'];
            for (const char& c: vc) {
                x[n - 1] = c;
                dfs(n - 1);
                // cout << x << endl;
            }
        };
        dfs(digits.size());
		return res;
	}
};

class Solution {
	/** 17. Letter Combinations of a Phone Number
	 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
	 */
public:
	vector<string> letterCombinations(string digits) {
        vector<vector<char>> d2c = {
            {'a', 'b', 'c',},
            {'d', 'e', 'f',},
            {'g', 'h', 'i',},
            {'j', 'k', 'l',},
            {'m', 'n', 'o',},
            {'p', 'q', 'r', 's',},
            {'t', 'u', 'v',},
            {'w', 'x', 'y', 'z',},
        };

		vector<string> res{""}, nxt;
        for (const auto& d: digits) {
            const vector<char>& vc = d2c[d - '2'];
            for (const string& cur: res) {
                for (const char& c: vc) {
                    nxt.push_back(cur + c);
                }
            }
            res = move(nxt);
        }
		return res;
	}
};
