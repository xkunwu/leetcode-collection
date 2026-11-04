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
	/** 206. Reverse Linked List
	 * https://leetcode.com/problems/reverse-linked-list/
	 */
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* revHead = nullptr;
        ListNode* nn;
        while (nullptr != head) {
            nn = head->next;
            head->next = revHead;
            revHead = head;
            head = nn;
        }
        return revHead;
    }
};