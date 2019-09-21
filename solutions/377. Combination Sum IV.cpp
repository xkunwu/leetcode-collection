/** 377. Combination Sum IV
	https://leetcode.com/problems/combination-sum-iv/
	Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
*/

class Solution {
    /** Recursive DP
        Problem: Time Limit Exceeded!
    **/
    typedef set<int, greater<int>> cont;
    int comboDP(const int& target, cont& nset) {
        cont::iterator it = nset.lower_bound(target);
        int nn = 0;
        for (; it != nset.end(); ++it) {
            int newtar = target - *it;
            if (0 == newtar) ++nn;
            // cout << target << ": " << *it << ", " << newtar << " -> " << nn << endl;
            nn += comboDP(newtar, nset);
        }
        return nn;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        cont nset(nums.begin(), nums.end(), greater<int>());
        return comboDP(target, nset);
    }
};

class Solution {
    /** Lookup table DP
    **/
    typedef set<int, greater<int>> cont;
public:
    int combinationSum4(vector<int>& nums, int target) {
        cont nset(nums.begin(), nums.end(), greater<int>());
        vector<unsigned long long> count(target + 1, 0);
        cont::iterator it = nset.lower_bound(target);
        if (it == nset.end()) return 0;
        for (; it != nset.end(); ++it) {
            count[*it] = 1;
        }
        for (int ti = 1; ti <= target; ++ti) {
            it = nset.lower_bound(ti);
            // cout << " ==== " << ti << " ==== " << endl;
            for (; it != nset.end(); ++it) {
                int newtar = ti - *it;
                count[ti] += count[newtar];
                // cout << *it << ", " << newtar << " -> " << count[ti] << endl;
            }
        }
        return count[target];
    }
};
