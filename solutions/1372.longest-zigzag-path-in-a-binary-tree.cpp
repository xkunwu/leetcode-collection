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
    /** 1372. Longest ZigZag Path in a Binary Tree
     * https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
     */
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        auto dfs = [&res](this auto&& self, TreeNode* rn, const int dir) -> int {
            int l = 0, r = 0;
            if (nullptr != rn->left) {
                l = self(rn->left, 0) + 1;
            }
            if (nullptr != rn->right) { 
                r = self(rn->right, 1) + 1;
            }
            res = max({res, l, r});
            // cout << dir << "@" << res << ": " << l << ',' << r << endl;
            if (dir) return l;
            else return r;
        };
        dfs(root, 0);
        return res;
    }
};