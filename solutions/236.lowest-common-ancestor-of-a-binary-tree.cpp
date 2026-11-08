/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    /** 236. Lowest Common Ancestor of a Binary Tree
     * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
     */
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        auto dfsFind = [&](this auto&& self, TreeNode* rn, TreeNode* q) -> bool {
            if (nullptr == rn) return false;
            if (rn == q) return true;
            return self(rn->left, q) || self(rn->right, q);
        };
        if (nullptr != root->left) res = lowestCommonAncestor(root->left, p, q);
        if (nullptr != res) return res;
        if (nullptr != root->right) res = lowestCommonAncestor(root->right, p, q);
        if (nullptr != res) return res;
        if (dfsFind(root, p) && dfsFind(root, q)) {
            cout << root->val << endl;
            res = root;
            return res;
        }
        return res;
    }
};

class Solution {
    /** 236. Lowest Common Ancestor of a Binary Tree
     * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
     */
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (nullptr == root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (nullptr != l && nullptr != r) return root;
        if (nullptr != l) return l;
        return r;
    }
};