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
    /** 450. Delete Node in a BST
     * https://leetcode.com/problems/delete-node-in-a-bst/
     */
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto dfs = [](this auto&& self, TreeNode* &rn, const int& key) -> void {
            if (key < rn->val) {
                if (nullptr != rn->left) self(rn->left, key);
            } else if (key > rn->val) {
                if (nullptr != rn->right) self(rn->right, key);
            } else {
                TreeNode* min_node = nullptr, *pn = nullptr;
                if (nullptr != rn->right) {
                    min_node = rn->right;
                    while (nullptr != min_node->left) {
                        pn = min_node;
                        min_node = min_node->left;
                        // cout << min_node->val << ',';
                    }
                    // cout << rn->val << " <-> " << min_node->val << endl;
                    rn->val = min_node->val;
                    if (nullptr != pn) {
                        pn->left = min_node->right;
                        // cout << pn->val << '<' << min_node->val << endl;
                    } else {
                        // min_node = rn->right;
                        rn->right = min_node->right;
                        // cout << rn->val << '>' << min_node->val << endl;
                    }
                    delete min_node;
                    min_node = nullptr;
                } else if (nullptr != rn->left) {
                    min_node = rn->left;
                    while (nullptr != min_node->right) {
                        pn = min_node;
                        min_node = min_node->right;
                        // cout << min_node->val << ',' << endl;
                    }
                    // cout << rn->val << " <-> " << min_node->val << endl;
                    rn->val = min_node->val;
                    if (nullptr != pn) {
                        pn->right = min_node->left;
                        // cout << pn->val << '>' << min_node->val << endl;
                    } else {
                        // min_node = rn->left;
                        rn->left = min_node->left;
                        // cout << rn->val << '<' << min_node->val << endl;
                    }
                    delete min_node;
                    min_node = nullptr;
                } else {
                    // cout << rn->val << endl;
                    delete rn;
                    rn = nullptr;
                }
            }
        };
        if (nullptr == root) return nullptr;
        dfs(root, key);
        return root;
    }
};

class Solution {
    /** 450. Delete Node in a BST
     * https://leetcode.com/problems/delete-node-in-a-bst/
     */
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (nullptr == root->left && nullptr == root->right) {
                delete root;
                root = nullptr;
                return nullptr;
            }
            if (nullptr == root->left) {
                TreeNode* t = root->right;
                delete root;
                root = nullptr;
                return t;
            } else if (nullptr == root->right) {
                TreeNode* t = root->left;
                delete root;
                root = nullptr;
                return t;
            }
            TreeNode* m = root->right;
            while (nullptr != m->left) m = m->left;
            root->val = m->val;
            root->right = deleteNode(root->right, m->val);
        }
        return root;
    }
};