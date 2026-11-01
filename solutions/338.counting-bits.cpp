class SolutionSim {
	/** 338. Counting Bits
	 * https://leetcode.com/problems/counting-bits/
	 */
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (1 == i % 2) res[i] = res[i - 1] + 1;
            else res[i] = res[i / 2];
        }
        return res;
    }
};

class Solution {
	/** 338. Counting Bits
	 * https://leetcode.com/problems/counting-bits/
	 */
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i / 2] + (i % 2);
        }
        return res;
    }
};