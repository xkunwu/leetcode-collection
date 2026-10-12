#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
	/** 875. Koko Eating Bananas
	 *  https://leetcode.com/problems/koko-eating-bananas
	 */
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int max_p = 0;
		for (const int& p: piles) {
			if (p > max_p) max_p = p;
		}
		int lb = 1, rb = max_p;
		while (lb <= rb) {
			const int mid = (lb + rb) / 2;
			long long t = 0;
			for (const long long p: piles) {
				t += (p + mid - 1) / mid;
			}
			if (t > h) {
				lb = mid + 1;
			} else {
				rb = mid - 1;
			}
		}
		return lb;
	}
};

int main(void)
{
//	vector<int> piles = {8,8,8}; // 3
//	int h = 10;
	
//	vector<int> piles = {805306368,805306368,805306368}; // 3
//	int h = 1000000000;
	
	vector<int> piles = {1000000000}; // 500000000
	int h = 2;
	
//	vector<int> piles = {312884470}; // 1
//	int h = 312884470;
	
//	vector<int> piles = {312884470}; // 2
//	int h = 312884469;
	
//	vector<int> piles = {312884470}; // 1
//	int h = 968709470;
	
//	vector<int> piles = {30,11,23,4,20}; // 23
//	int h = 6;
	
//	vector<int> piles = {30,11,23,4,20}; // 30
//	int h = 5;
	
//	vector<int> piles = {3,6,7,11}; // 4
//	int h = 8;
	
	Solution solution;
	cout << solution.minEatingSpeed(piles, h) << endl;
}
