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
    /** 102. Binary Tree Level Order Traversal
     * https://leetcode.com/problems/binary-tree-level-order-traversal/
     */
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (nullptr == root) return res;
        vector<TreeNode*> cur({root});
        vector<int> lo({root->val});
        while (!cur.empty()) {
            res.push_back(move(lo));
            vector<TreeNode*> nxt;
            for (TreeNode* tn: cur) {
                if (nullptr != tn->left) {
                    nxt.push_back(tn->left);
                    lo.push_back(tn->left->val);
                }
                if (nullptr != tn->right) {
                    nxt.push_back(tn->right);
                    lo.push_back(tn->right->val);
                }
            }
            cur = move(nxt);
        }
        return res;
    }
};