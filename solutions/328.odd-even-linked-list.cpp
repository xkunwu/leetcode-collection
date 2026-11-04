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
	/** 328. Odd Even Linked List
	 * https://leetcode.com/problems/odd-even-linked-list/
	 */
public:
    ListNode* oddEvenList(ListNode* head) {
        if (nullptr == head) return head; // 0
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        while (nullptr != even && nullptr != even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};