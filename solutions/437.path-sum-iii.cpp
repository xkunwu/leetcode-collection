/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    /** 437. Path Sum III
     * https://leetcode.com/problems/path-sum-iii/
     */
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> sum(1000, 0);
        int res = 0;
        auto dfs = [&](this auto&& self, TreeNode* rn, const size_t depth) ->void {
            for (size_t i = 0; i <= depth; ++i) {
                sum[i] += rn->val;
                if (targetSum == sum[i]) ++res;
                // cout << sum[i] << ' ';
            }
            // cout << endl;
            if (nullptr != rn->left) self(rn->left, depth + 1);
            if (nullptr != rn->right) self(rn->right, depth + 1);
            for (size_t i = 0; i <= depth; ++i) {
                sum[i] -= rn->val;
            }
        };
        if (nullptr != root) dfs(root, 0);
        return res;
    }
};

class Solution {
    /** 437. Path Sum III
     * https://leetcode.com/problems/path-sum-iii/
     */
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> presum;
        presum[0] = 1;
        int res = 0;
        auto dfs = [&](this auto&& self, TreeNode* rn, long long psum) ->void {
            psum += rn->val;
            if (presum.contains(psum - targetSum)) {
                res += presum[psum - targetSum];
                // cout << res << ": " << psum << ' ' << psum - targetSum << endl;
            }
            // for (const auto& [k, v]: presum) { cout << k << ',' << v << ' '; } cout << endl;
            ++presum[psum];
            if (nullptr != rn->left) self(rn->left, psum);
            if (nullptr != rn->right) self(rn->right, psum);
            --presum[psum];
        };
        if (nullptr != root) dfs(root, 0);
        return res;
    }
};