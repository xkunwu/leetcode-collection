/** 501. Find Mode in Binary Search Tree
	https://leetcode.com/problems/find-mode-in-binary-search-tree/
	Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

	Assume a BST is defined as follows:

		- The left subtree of a node contains only nodes with keys less than or equal to the node's key.
		- The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
		- Both the left and right subtrees must also be binary search trees.
*/

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
    /** Traversal order: left -> middle -> right,
        then equal values are grouped together.
    **/
    deque<int> mode;
    int cnt = 0;
    int cntP = 0;
    TreeNode* P = NULL;
public:
    void sub_mode(TreeNode* N) {
        if (NULL == N) return;

        sub_mode(N->left);

        if (NULL != P && N->val == P->val) ++cntP;
        else cntP = 1;

        if (cntP == cnt) {
            mode.push_back(N->val);
        } else if (cntP > cnt) {
            mode.clear();
            mode.push_back(N->val);
            cnt = cntP;
        }

        P = N;
        sub_mode(N->right);

        for (deque<int>::iterator it = mode.begin(); it != mode.end(); ++it) cout<<*it<<" ";
        cout << ": " << N->val << ", " << cntP << " -> " << cnt << endl;
    }
    vector<int> findMode(TreeNode* root) {
        sub_mode(root);
        return vector<int>(mode.begin(), mode.end());
    }
};
