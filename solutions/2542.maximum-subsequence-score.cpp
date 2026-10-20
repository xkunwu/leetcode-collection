#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class SolutionBT {
	/** 2542. Maximum Subsequence Score
	  https://leetcode.com/problems/maximum-subsequence-score/
	 */
private:
	void maxScoreRecur(const vector<pair<int, int>>& pair_arr, const int& k, const size_t& s, const int& min2, long long& score, long long& maxScore) {
		if (0 == k) {
			long long vm = score * min2;
			cout << vm << endl;
			if (vm > maxScore) maxScore = vm;
			return;
		}
		for (size_t p = s; p < pair_arr.size(); ++p) {
			score += pair_arr[p].first;
			maxScoreRecur(pair_arr, k - 1, p + 1, min2, score, maxScore);
			score -= pair_arr[p].first;
		}
	}
	
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		const size_t N = nums1.size();
		vector<pair<int, int>> pair_arr(N);
		for (size_t i = 0; i < N; ++i) {
		   pair_arr[i].first = nums1[i];
		   pair_arr[i].second = nums2[i];
		}
		sort(pair_arr.begin(), pair_arr.end(),
			 [](const auto& a, const auto& b) { return a.second < b.second; }
			 );
//		for (size_t i = 0; i < N; ++i) {
//		   nums1[i] = pair_arr[i].first;
//		   nums2[i] = pair_arr[i].second;
//		}
		long long maxScore = -1, score;
		size_t s;
		for (s = 0; s < N - k; ++s) {
			score = pair_arr[s].first;
			maxScoreRecur(pair_arr, k - 1, s + 1, pair_arr[s].second, score, maxScore);
		}
		score = 0;
		for (; s < N; ++s) {
			score += pair_arr[s].first;
		}
		score *= pair_arr[N - k].second;
		if (score > maxScore) maxScore = score;
		return maxScore;
	}
};

class Solution {
	/** 2542. Maximum Subsequence Score
		https://leetcode.com/problems/maximum-subsequence-score/
	 */
public:
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		const size_t N = nums1.size();
		size_t i;
		vector<pair<int, int>> pair_arr(N);
		for (i = 0; i < N; ++i) {
			pair_arr[i] = {nums1[i], nums2[i]};
		}
		sort(pair_arr.begin(), pair_arr.end(),
			 [&](const auto& a, const auto& b) { return a.second > b.second; }
			 );
		priority_queue<int, vector<int>, greater<int>> min_heap;
		long long maxScore = 0, score = 0;
		i = 0;
		while (k--) {
			const auto& [a, b] = pair_arr[i++];
			score += a;
			min_heap.push(a);
		}
		maxScore = score * pair_arr[i - 1].second;
		while (i < N) {
			const auto& [a, b] = pair_arr[i++];
			score += a;
			min_heap.push(a);
			score -= min_heap.top();
			min_heap.pop();
			maxScore = max(maxScore, score * b);
		}
//		const size_t ks = k;
//		for (const auto& [a, b]: pair_arr) {
//			score += a;
//			min_heap.push(a);
//			if (min_heap.size() > ks) {
//				score -= min_heap.top();
//				min_heap.pop();
//			}
//			if (min_heap.size() == ks) maxScore = max(maxScore, score * b);
//		}
		return maxScore;
	}
};

int main(void)
{
	vector<int> nums1 = {93,463,179,2488,619,2006,1561,137,53,1765,2304,1459,1768,450,1938,2054,466,331,670,1830,1550,1534,2164,1280,2277,2312,1509,867,2223,1482,2379,1032,359,1746,966,232,67,1203,2474,944,1740,1775,1799,1156,1982,1416,511,1167,1334,2344}, nums2 = {345,229,976,2086,567,726,1640,2451,1829,77,1631,306,2032,2497,551,2005,2009,1855,1685,729,2498,2204,588,474,693,30,2051,1126,1293,1378,1693,1995,2188,1284,1414,1618,2005,1005,1890,30,895,155,526,682,2454,278,999,1417,1682,995};
	int k = 42; // 26653494
	
//	vector<int> nums1 = {2,1,14,12}, nums2 = {11,7,13,6};
//	int k = 3; // 168
	
//	vector<int> nums1 = {4,2,3,1,1}, nums2 = {7,5,10,9,6};
//	int k = 1; // 30
	
//	vector<int> nums1 = {1,3,3,2}, nums2 = {2,1,3,4};
//	int k = 3; // 12

	Solution solution;
	cout << solution.maxScore(nums1, nums2, k) << endl;
}
