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
class SolutionHalf {
    /** 2130. Maximum Twin Sum of a Linked List
     * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
     */
public:
    int pairSum(ListNode* head) {
        ListNode* j = head->next;
        ListNode* m = head;
        vector<int> half;
        half.push_back(m->val);
        int res = 0;
        while (nullptr != j->next) {
            m = m->next;
            j = j->next->next;
            half.push_back(m->val);
        }
        for (int i = half.size() - 1; i >= 0; --i) {
            m = m->next;
            // const long long sum = m->val;
            const int sum = m->val + half[i];
            if (sum > res) res = sum;
        }
        return res;
    }
};

class SolutionVec {
    /** 2130. Maximum Twin Sum of a Linked List
     * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
     */
public:
    int pairSum(ListNode* head) {
        ListNode* f = head;
        vector<int> half;
        while (nullptr != f) {
            half.push_back(f->val);
            f = f->next;
        }
        int res = 0;
        for (int i = 0, j = half.size() - 1; i < j; ++i, --j) {
            const int sum = half[i] + half[j];
            if (sum > res) res = sum;
        }
        return res;
    }
};

class Solution {
    /** 2130. Maximum Twin Sum of a Linked List
     * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
     */
public:
    int pairSum(ListNode* head) {
        ListNode* f = head->next;
        ListNode* m = head;
        ListNode* rev = nullptr;
        while (nullptr != f->next) {
            head = m;
            m = m->next;
            f = f->next->next;
            head->next = rev;
            rev = head;
        }
        int res = m->val + m->next->val;
        // cout << head->val << ',' << m->val << endl;
        m = m->next;
        while (nullptr != m->next) {
            m = m->next;
            const int sum = m->val + rev->val;
            if (sum > res) res = sum;
            rev = rev->next;
        }
        return res;
    }
};