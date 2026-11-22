/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	/** 61. Rotate List
	 * https://leetcode.com/problems/rotate-list/
	 */
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (nullptr == head) return head;
        int len = 1;
        ListNode* pend = head;
        while (nullptr != pend->next) {
            pend = pend->next;
            ++len;
        }
        k %= len;
        k = len - k;
        pend->next = head;
        while (--k) {
            head = head->next;
        }
        pend = head->next;
        head->next = nullptr;
        return pend;
    }
};