/** 25. Reverse Nodes in k-Group
	https://leetcode.com/problems/reverse-nodes-in-k-group/
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

	k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (2 > k) return head;
        ListNode *pH = head, *pE, *p0, *pn, *pnn, *pNH = head, *pLast = NULL;
        int ki;
        while (NULL != pH) {
            for (pE = pH, ki = 0; pE != NULL && ki < k; pE = pE->next, ++ki);
            if (ki < k) break;
            //for (p0 = pH; p0 != pE; p0 = p0->next) cout<<p0->val<<" ";
            //cout<<"----"<<endl;
            p0 = pH;
            pn = p0->next;
            for (; pn != pE;) {
                //cout<<p0->val<<" "<<pn->val<<" - ";
                pnn = pn->next;
                pn->next = p0;
                p0 = pn;
                pn = pnn;
                //cout<<p0->val<<" "<<pn->val<<endl;
            }
            pH->next = pE;
            if (head == pNH) {
                pNH = p0;
            } else pLast->next = p0;
            //for (; p0 != NULL; p0 = p0->next) cout<<p0->val<<" ";
            //cout<<endl;
            //for (p0 = pNH; p0 != NULL; p0 = p0->next) cout<<p0->val<<" ";
            //cout<<endl;
            pLast = pH;
            pH = pE;
        }
        //for (p0 = pNH; p0 != NULL; p0 = p0->next) cout<<p0->val<<" ";
        //cout<<"----"<<endl;
        return pNH;
    }
};
