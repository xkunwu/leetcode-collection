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
    /** 872. Leaf-Similar Trees
     * https://leetcode.com/problems/leaf-similar-trees/
     */
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto dfs = [](this auto&& self, const TreeNode* root, vector<int>& ls) -> void {
            bool is_leaf = true;
            if (nullptr != root->left) { self(root->left, ls); is_leaf = false; }
            if (nullptr != root->right) { self(root->right, ls); is_leaf = false; }
            if (is_leaf) ls.push_back(root->val);
        };
        vector<int> ls1;
        ls1.reserve(101);
        dfs(root1, ls1);
        // for (const int& v: ls1) { cout << v << ','; } cout << endl;
        vector<int> ls2;
        ls2.reserve(101);
        dfs(root2, ls2);
        // for (const int& v: ls2) { cout << v << ','; } cout << endl;
        return ls1 == ls2;
    }
};

class Solution {
    /** 872. Leaf-Similar Trees
     * https://leetcode.com/problems/leaf-similar-trees/
     */
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto dfsFill = [](this auto&& self, const TreeNode* root, vector<int>& ls) -> void {
            bool is_leaf = true;
            if (nullptr != root->left) { self(root->left, ls); is_leaf = false; }
            if (nullptr != root->right) { self(root->right, ls); is_leaf = false; }
            if (is_leaf) ls.push_back(root->val);
        };
        vector<int> ls;
        ls.reserve(101);
        dfsFill(root1, ls);
        // for (const int& v: ls) { cout << v << ','; } cout << endl;
        size_t lsi = 0;
        bool is_similar = true;
        auto dfsComp = [&](this auto&& self, const TreeNode* root) -> void {
            bool is_leaf = true;
            if (nullptr != root->left) {
                self(root->left);
                is_leaf = false;
            }
            if (!is_similar) return;
            if (nullptr != root->right) {
                self(root->right);
                is_leaf = false;
            }
            if (!is_similar) return;
            if (is_leaf) {
                if (ls.size() == lsi) is_similar = false;
                if (ls[lsi++] != root->val) is_similar = false;
            }
        };
        dfsComp(root2);
        if (ls.size() > lsi) return false;
        return is_similar;
    }
};