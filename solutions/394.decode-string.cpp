class Solution {
    /** 394. Decode String
     * https://leetcode.com/problems/decode-string/
     */
public:
    string decodeString(string s) {
        string res;
        vector<int> vc;
        vector<string> vs;
        auto is_digit = [](const char& c) { return '0' <= c && '9' >= c; };
        auto rep_str = [](const string& t, int c) { string rep; while (c--) rep += t; return move(rep); };
        for (size_t i = 0; i < s.size(); ++i) {
            if (is_digit(s[i])) {
                vs.push_back(res);
                // t = s[i];
                // while (is_digit(s[++i])) t += s[i];
                // vc.push_back(stoi(t));
                res = "";
                int cnt = s[i] - '0';
                while (is_digit(s[++i])) {
                    cnt = cnt * 10 + s[i] - '0';
                }
                vc.push_back(cnt);
            } else if (']' == s[i]) {
                res = vs.back() + rep_str(res, vc.back());
                vc.pop_back();
                vs.pop_back();
            } else {
                res += s[i];
            }
            // cout << s[i] << '@' << i << ": " << res << ", " << t << " | ";
            // for (string& vsi: vs) { cout << vsi << ' '; } cout << "-> ";
            // for (int& vci: vc) { cout << vci << ' '; } cout << endl;
        }
        return res;
    }
};