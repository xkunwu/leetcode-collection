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
class SolutionQueue {
    /** 199. Binary Tree Right Side View
     * https://leetcode.com/problems/binary-tree-right-side-view/
     */
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (nullptr == root) return res;
        res.push_back(root->val);
        root->val = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* n = Q.front();
            Q.pop();
            if (nullptr != n->right) {
                if (res.size() < (n->val + 1)) {
                    res.push_back(n->right->val);
                }
                // cout << n->right->val << '@' << n->val + 1 << ' ';
                n->right->val = n->val + 1;
                Q.push(n->right);
            }
            if (nullptr != n->left) {
                if (res.size() < (n->val + 1)) {
                    res.push_back(n->left->val);
                }
                // cout << n->left->val << '@' << n->val + 1 << ' ';
                n->left->val = n->val + 1;
                Q.push(n->left);
            }
        }
        return res;
    }
};

class Solution {
    /** 199. Binary Tree Right Side View
     * https://leetcode.com/problems/binary-tree-right-side-view/
     */
public:
    vector<int> rightSideView(TreeNode* root) {
        if (nullptr == root) return {};
        vector<TreeNode*> cur(1, root);
        vector<int> res;
        while (!cur.empty()) {
            res.push_back(cur.back()->val);
            vector<TreeNode*> nxt;
            for (TreeNode* pn: cur) {
                if (nullptr != pn->left) nxt.push_back(pn->left);
                if (nullptr != pn->right) nxt.push_back(pn->right);
            }
            cur = move(nxt);
        }
        return res;
    }
};