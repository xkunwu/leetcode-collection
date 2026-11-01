class Solution {
	/** 345. Reverse Vowels of a String
	 * https://leetcode.com/problems/reverse-vowels-of-a-string/
	 */
public:
    string reverseVowels(string s) {
        // vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        // sort(vowels.begin(), vowels.end());
        // for (const char& v: vowels) { cout << v << ' '; } cout << endl;
        auto notVowel = [vowels = "AEIOUaeiou"s](const char& c) -> bool {
            return string::npos == vowels.find(c);
        };
        for (int i = 0, j = s.size() - 1; i < j;) {
            if (notVowel(s[i])) { ++i; continue; }
            if (notVowel(s[j])) { --j; continue; }
            // cout << s[i] << " <-> " << s[j] << endl;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};