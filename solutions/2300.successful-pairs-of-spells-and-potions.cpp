#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/** 2300. Successful Pairs of Spells and Potions
        https://leetcode.com/problems/successful-pairs-of-spells-and-potions
        You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

		You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

		Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
     */
private:
	int searchSuccess(const long long& siv, const vector<int>& potions, const long long success, const int& l, const int& r) {
		if (l > r) return 0;
		const int mid = (l + r) / 2;
		const long long prod = siv * potions[mid];
		int rnum = 0;
		if (success <= prod) {
			rnum += r - mid + 1;
			rnum += searchSuccess(siv, potions, success, l, mid - 1);
		} else {
			rnum += searchSuccess(siv, potions, success, mid + 1, r);
		}
		return rnum;
	}
	
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		sort(potions.begin(), potions.end());
		const size_t n = spells.size();
		const size_t m = potions.size();
		vector<int> pairs(n, 0);
		if (0 == m) return pairs;
		for (size_t ni = 0; ni < n; ++ni) {
			pairs[ni] = searchSuccess(spells[ni], potions, success, 0, m - 1);
		}
		return pairs;
	}
};

int main(void)
{
	vector<int> spells = {3,1,2}; // [2,0,2]
	vector<int> potions = {8,5,8};
	long long success = 16;
	
//	vector<int> spells = {5,1,3}; // [4,0,3]
//	vector<int> potions = {1,2,3,4,5};
//	long long success = 7;
	
	Solution solution;
	vector<int> pairs = solution.successfulPairs(spells, potions, success);
	for (int p: pairs) {
		cout << p << endl;
	}
}
