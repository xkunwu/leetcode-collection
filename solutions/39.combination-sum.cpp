class Solution {
    /** 39. Combination Sum
     * https://leetcode.com/problems/combination-sum/
     */
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // sort(candidates.rbegin(), candidates.rend());
        // for (auto x: candidates) { cout << x << ','; } cout << endl;
        vector<int> combo;
        combo.reserve(40);
        auto bt = [&res, &candidates, &combo](this auto&& bt, const int& target, const int& e) -> void {
            if (0 == target) {
                res.push_back(combo);
                return;
            }
            for (int i = e; i >= 0; --i) {
                const int c = candidates[i];
                if (c > target) continue;
                combo.push_back(c);
                bt(target - c, i);
                combo.pop_back();
            }
        };
        bt(target, candidates.size() - 1);
        return res;
    }
};