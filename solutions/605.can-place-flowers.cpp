#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 605. Can Place Flowers
		https://leetcode.com/problems/can-place-flowers/
	 */
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int lb = -1, ub = 0;
		const int nfb = flowerbed.size();
		for (; ub < nfb; ++ub) {
			if (0 >= n) return true;
			const int& f = flowerbed[ub];
			if (0 == f) continue;
			n -= (ub - lb - 1) / 2;
			lb = ub + 1;
		}
		if (lb < ub) n -= (ub - lb) / 2;
		if (0 >= n) return true;
		else return false;
	}
};

int main(void)
{
	vector<int> flowerbed = {1,0,0,0,1,0,0}; // T
	const int n = 2;
	
//	vector<int> flowerbed = {1,0,0,0,0,1}; // F
//	const int n = 2;
	
//	vector<int> flowerbed = {1,0,0,0,1}; // T
//	const int n = 1;
	
//	vector<int> flowerbed = {1,0,0,0,1}; // F
//	const int n = 2;
	
//	vector<int> flowerbed = {0,0,0,0,1}; // T
//	const int n = 2;
	
	Solution solution;
	cout << solution.canPlaceFlowers(flowerbed, n) << endl;
}
