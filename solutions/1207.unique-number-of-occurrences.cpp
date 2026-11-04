class Solution {
	/** 1207. Unique Number of Occurrences
	 * https://leetcode.com/problems/unique-number-of-occurrences/
	 */
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (const int& n : arr) {
            ++m[n];
        }
        unordered_set<int> s;
        for (const auto& [_, value] : m) {
            if (s.contains(value)) return false;
            s.insert(value);
        }
        return true;
    }
};