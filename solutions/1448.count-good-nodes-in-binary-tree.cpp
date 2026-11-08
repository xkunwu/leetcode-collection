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
    /** 1448. Count Good Nodes in Binary Tree
     * https://leetcode.com/problems/count-good-nodes-in-binary-tree/
     */
public:
    int goodNodes(TreeNode* root) {
        int ngood = 0;
        auto dfs = [&](this auto&& self, TreeNode* rn, int mp) ->void {
            if (rn->val >= mp) {
                ++ngood;
                mp = rn->val;
            }
            if (nullptr != rn->left) { self(rn->left, mp); }
            if (nullptr != rn->right) { self(rn->right, mp); }
        };
        dfs(root, -10000);
        return ngood;
    }
};