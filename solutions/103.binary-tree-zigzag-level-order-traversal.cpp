/**
 * Definition for a binary tree cur[i].
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
    /** 103. Binary Tree Zigzag Level Order Traversal
     * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (nullptr == root) return res;
        vector<TreeNode*> cur;
        cur.push_back(root);
        int d = 1;
        while (!cur.empty()) {
            vector<TreeNode*> nxt;
            const int N = cur.size();
            vector<int> vv(N);
            for (int i = 0; i < N; ++i) {
                TreeNode* node = cur[i];
                if (1 == d) vv[i] = node->val;
                else vv[N - 1 - i] = node->val;
                if (nullptr != cur[i]->left) nxt.push_back(cur[i]->left);
                if (nullptr != cur[i]->right) nxt.push_back(cur[i]->right);
            }
            d = 1 - d;
            res.push_back(move(vv));
            cur = move(nxt);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (nullptr == root) return res;
        deque<TreeNode*> cur;
        cur.push_back(root);
        int d = 1;
        while (!cur.empty()) {
            deque<TreeNode*> nxt;
            vector<int> vv;
            if (1 == d) {
                for (int i = 0; i < cur.size(); ++i) {
                    vv.push_back(cur[i]->val);
                    if (nullptr != cur[i]->left) nxt.push_back(cur[i]->left);
                    if (nullptr != cur[i]->right) nxt.push_back(cur[i]->right);
                }
            } else {
                for (int i = cur.size() - 1; i >= 0; --i) {
                    vv.push_back(cur[i]->val);
                    if (nullptr != cur[i]->right) nxt.push_front(cur[i]->right);
                    if (nullptr != cur[i]->left) nxt.push_front(cur[i]->left);
                }
            }
            // const int s = (1 == d) ? 0 : cur.size() - 1;
            // const int e = s + cur.size() * d;
            // cout << s << ',' << e << ',' << d << ':';
            // for (auto x: cur) { cout << x->val << ','; } cout << endl;
            // for (int i = s; i != e; i += d) {
            //     vv.push_back(cur[i]->val);
            //     if (nullptr != cur[i]->left) nxt.push_back(cur[i]->left);
            //     if (nullptr != cur[i]->right) nxt.push_back(cur[i]->right);
            // }
            d *= -1;
            res.push_back(move(vv));
            cur = move(nxt);
        }
        return res;
    }
};

// root = [1,2,3,4,null,null,5];
// root = [0,2,4,1,null,3,-1,5,1,null,6,null,8];