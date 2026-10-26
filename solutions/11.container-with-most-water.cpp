#include <iostream>
#include <vector>
using namespace std;

class Solution {
	/** 11. Container With Most Water
	 *  https://leetcode.com/problems/container-with-most-water/
	 * 
	 * A greedy strategy - it becomes obvious when you know the idea.
	 */
public:
    int maxArea(vector<int>& height) {
//        vector<int> iv = {0, height.size() - 1};
//        while (iv[0] < iv[1]) {
//            const int lr = (height[iv[0]] < height[iv[1]]) ? 0 : 1;
//			const int c = (iv[1] - iv[0]) * height[iv[lr]];
//			if (c > mc) mc = c;
//			if (0 == lr) ++iv[0];
//			else --iv[1];
//        }
		int li = 0, ri = height.size() - 1;
		int mc = 0;
		while (li < ri) {
			const int lr = (height[li] < height[ri]) ? 0 : 1;
			if (0 == lr) mc = max(mc, (ri - li) * height[li]);
			else mc = max(mc, (ri - li) * height[ri]);
			if (0 == lr) ++li;
			else --ri;
		}
		return mc;
    }
};

int main(void)
{
//	vector<int> height = {1,1}; // 1
	vector<int> height = {1,8,6,2,5,4,8,3,7}; // 49
	
	Solution solution;
	cout << solution.maxArea(height) << endl;
}
