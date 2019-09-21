/** 524. Longest Word in Dictionary through Deleting
	https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
	Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
*/

class Solution {
public:
    int isSubStr(const string& s, const string& m) {
        size_t si = 0, mi = 0;
        while (si < s.length()) {
            if (s[si] == m[mi]) {
                ++si; ++mi;
                if (m.length() <= mi) return 1;
            } else ++si;
        }
        return -1;
    }
    string findLongestWord(string s, vector<string>& d) {
        string lword = "";
        for (string w : d) {
            if (0 > isSubStr(s, w)) continue;
            if (w.length() < lword.length()) continue;
            if (w.length() == lword.length() && 0 <= w.compare(lword)) continue;
            lword = w;
        }
        return lword;
    }
};
