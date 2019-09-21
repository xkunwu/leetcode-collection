/** 2. Add Two Numbers
	https://leetcode.com/problems/add-two-numbers/
	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::deque<int> res;
        ListNode* retl = NULL;
        if (NULL == l1->next || NULL == l2->next) return retl;
        int val = l1->val + l2->val;
        if (9 < val) { res.push_back(1); res.push_back(val - 10); }
        else res.push_back(val);
        while (true) {
            if (NULL == l1->next && NULL != l2->next) return retl;
            if (NULL == l2->next && NULL != l1->next) return retl;
            if (NULL == l1->next && NULL == l2->next) break;
            l1 = l1->next; l2 = l2->next;
            val = l1->val + l2->val;
            if (9 < val) { res.back() += 1; res.push_back(val - 10); }
            else res.push_back(val);
        }

        for (int ii = 0; ii < res.size(); ++ii) {
            if (NULL == retl) retl = new ListNode(res[ii]);
            else retl->next = new ListNode(res[ii]);
        }
        return retl
    }
};
