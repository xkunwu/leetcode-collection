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
    /** 21. Merge Two Sorted Lists
     * https://leetcode.com/problems/merge-two-sorted-lists/
     */
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (nullptr == list1) return list2;
        if (nullptr == list2) return list1;
        ListNode* res;
        if (list1->val > list2->val) {
            res = list2;
            list2 = list2->next;
        } else {
            res = list1;
            list1 = list1->next;
        }
        ListNode* p = res;
        while (nullptr != list1 && nullptr != list2) {
            if (list1->val > list2->val) {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            } else {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
        }
        while (nullptr != list1) {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }
        while (nullptr != list2) {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
        return res;
    }
};