class SolutionMap {
    /** 1657. Determine if Two Strings Are Close
     * https://leetcode.com/problems/determine-if-two-strings-are-close/
     */
public:
    bool closeStrings(string word1, string word2) {
        const int N1 = word1.size(), N2 = word2.size();
        if (N1 != N2) return false;
        unordered_map<char, int> m1;
        for (const char c : word1) ++m1[c];
        vector<int> v1(m1.size());
        int i = 0;
        for (const auto [_, v] : m1) { v1[i++] = v; }
        // for (const int& a : v1) { cout << a << ' '; } cout << endl;
        unordered_map<char, int> m2;
        for (const char c : word2) ++m2[c];
        const int nv1 = v1.size();
        if (m2.size() != nv1) return false;
        vector<int> v2(nv1);
        i = 0;
        for (const auto [k, v] : m2) {
            if (!m1.contains(k)) return false;
            v2[i++] = v;
        }
        ranges::sort(v1);
        ranges::sort(v2);
        // for (const int& a : v2) { cout << a << ' '; } cout << endl;
        for (i = 0; i < nv1; ++i) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};

class Solution {
    /** 1657. Determine if Two Strings Are Close
     * https://leetcode.com/problems/determine-if-two-strings-are-close/
     */
public:
    bool closeStrings(string word1, string word2) {
        const int N1 = word1.size(), N2 = word2.size();
        if (N1 != N2) return false;
        vector<int> m1(26, 0), m2(26, 0);
        for (const char c : word1) ++m1[c - 'a'];
        for (const char c : word2) ++m2[c - 'a'];
        for (int i = 0; i < 26; ++i) {
            if ((m1[i] > 0) - (m2[i] > 0)) return false;
        }
        ranges::sort(m1);
        ranges::sort(m2);
        return m1 == m2;
    }
};