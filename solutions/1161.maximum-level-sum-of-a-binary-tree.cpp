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
	/** 1161. Maximum Level Sum of a Binary Tree
	 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
	 */
public:
	int maxLevelSum(TreeNode* root) {
		vector<TreeNode*> q;
		q.reserve(10000);
		int depth = 1, sum = 0, maxDepth = 0, maxSum = -100000000;
		int l = 0, r = 1, nxt = 1;
		q.push_back(root);
		while (nxt != l) {
			// cout << l << ',' << r << ',' << nxt << ": ";
			// for (TreeNode* n: q) { cout << n->val << ' '; } cout << endl;
			sum += q[l]->val;
			if (nullptr != q[l]->left) {
				q.push_back(q[l]->left);
				++nxt;
			}
			if (nullptr != q[l]->right) {
				q.push_back(q[l]->right);
				++nxt;
			}
			++l;
			if (l != r) continue;
			if (sum > maxSum) {
				maxSum = sum;
				maxDepth = depth;
			}
			++depth;
			sum = 0;
			r = nxt;
		}
		return maxDepth;
	}
};
