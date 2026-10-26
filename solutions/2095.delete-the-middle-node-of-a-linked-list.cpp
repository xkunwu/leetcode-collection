#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    /** 2095. Delete the Middle Node of a Linked List
     * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
     * 
     * Bad judge mechanism - leaving dangling C pointer.
     */
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (nullptr == head) return nullptr;
        if (nullptr == head->next) return nullptr;
        // 1: 1 = 0 + 1 -> 1
        // 2: 2 = 1 + 1 -> 2
        // 3: 2 = 1 + 1 -> 2
        // 4: 3 = 2 + 1 -> 3
        // 5: 3 = 2 + 1 -> 3
        ListNode* m = head;
        ListNode* j = head;
        ListNode* m1 = head;
        while (nullptr != j && nullptr != j->next) {
            j = j->next->next;
            m1 = m;
            m = m->next;
        }
        // size_t N = 0;
        // while (nullptr != j) {
        //     j = j->next;
        //     ++N;
        //     if (0 == N % 2) {
        //         m1 = m;
        //         m = m->next;
        //     }
        // }
        m1->next = m->next;
        // delete m;
        return head;
    }
};

int main(void)
{
    ListNode* head = new ListNode(1);
	
	Solution solution;
	head = solution.deleteMiddle(head);
    while (nullptr != head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
