#include <iostream>
#include <string>
using namespace std;

class Solution {
	/** 1768. Merge Strings Alternately
	 *  https://leetcode.com/problems/merge-strings-alternately/
	 */
public:
    string mergeAlternately(string word1, string word2) {
        size_t i = 0, j = 0;
        const size_t w1n = word1.size(), w2n = word2.size();
        string output(w1n + w2n, ' ');
        int k = 0;
        for (; i < w1n && j < w2n;) {
            output[k++] = word1[i++];
            output[k++] = word2[j++];
        }
        while (i < w1n) output[k++] = word1[i++];
        while (j < w2n) output[k++] = word2[j++];
		return output;
    }
};

int main(void)
{
	string word1 = "ab", word2 = "pqrs"; // apbqrs
	// string word1 = "abc", word2 = "pqr"; // apbqcr
	
	Solution solution;
	cout << solution.mergeAlternately(word1, word2) << endl;
}
