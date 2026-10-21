#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 746. Min Cost Climbing Stairs
	    https://leetcode.com/problems/min-cost-climbing-stairs/
	 */
public:
	int minCostClimbingStairs(vector<int>& cost) {
		const size_t N = cost.size();
		for (size_t i = 2; i < N; ++i) {
			cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
		}
		return min(cost[N - 1], cost[N - 2]);
	}
};

int main(void)
{
	vector<int> cost = {1,100,1,1,1,100,1,1,100,1}; // 6
//	vector<int> cost = {10,15,20}; // 15

	Solution solution;
	cout << solution.minCostClimbingStairs(cost) << endl;
}
