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
class SolutionDFS {
    /** 700. Search in a Binary Search Tree
     * https://leetcode.com/problems/search-in-a-binary-search-tree/
     */
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (nullptr == root) return nullptr;
        if (val == root->val) return root;
        TreeNode* lsub = searchBST(root->left, val);
        if (nullptr == lsub) return searchBST(root->right, val);
        else return lsub;
    }
};

class Solution {
    /** 700. Search in a Binary Search Tree
     * https://leetcode.com/problems/search-in-a-binary-search-tree/
     */
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (nullptr != root) {
            if (val == root->val) return root;
            else if (val > root->val) root = root->right;
            else root = root->left;
        }
        return nullptr;
    }
};