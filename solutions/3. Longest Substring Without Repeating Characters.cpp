class Solution {
	/** #3. Longest Substring Without Repeating Characters
		https://leetcode.com/problems/longest-substring-without-repeating-characters/
		Given a string, find the length of the longest substring without repeating characters.
		
		Note: This one is very similar to the problem I got during the second round interview by Amazon. But I did not see the problem before the interview (I picked the problems randomly after solved #2, so as to miss this one coincidentally and even picked #4 later - that is very amusing), so I made up a solution on-site. My solution on-site is listed below, which is not very wrong except for two typos in retrospect.
		
		string UniqSub(const string &str) {
			string ret = "";
			deque<char> st; // record longest string
			unordered_set<int> seen; // check for uniqueness
			for (size_t si = 0; si < str.length(); ++si) {
				const int cc = str[si] - 'a';
				if (0 == seen.count(cc)) {
					seen.insert(cc);
					st.push_back(str[si]);
					if (ret.length() < st.size()) {
						// found one and build the string
						ostringstream oss;
						for (char ch : st) oss << ch;
						ret = oss.str();
					}
				} else {
					// pop out from the start
					while (!st.empty()) {
						int top = st.front() - 'a';
						if (top == str[si]) break;
						st.pop_front();
						seen.erase(seen.find(top));
					}
					st.pop_front(); // now equal to current or empty
					// seen.erase(seen.find(str[si])); // inserted at the back
					st.push_back(str[si])
				}
			}
			return ret;
		}
	*/
public:
    int lengthOfLongestSubstring(string str) {
        int ret = 0;
        deque<char> substr; // record longest string
        unordered_set<int> seen; // check for uniqueness
        for (auto si : str) {
            const int cc = si - 'a';
            if (0 == seen.count(cc)) {
                seen.insert(cc);
                substr.push_back(si);
                if (ret < substr.size()) {
                    // found one and build the string
                    ret = substr.size();
                }
            } else {
                // pop out from the start
                while (!substr.empty()) {
                    const char top = substr.front();
                    if (top == si) break;
                    substr.pop_front();
                    seen.erase(seen.find(top - 'a'));
                }
                substr.pop_front(); // now equal to current or empty
                // seen.erase(seen.find(si)); // inserted at the back
                substr.push_back(si);
            }
        }
        return ret;
    }
};