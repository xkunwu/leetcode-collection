/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    /** 138. Copy List with Random Pointer
     * https://leetcode.com/problems/copy-list-with-random-pointer/
     */
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) return nullptr;
        Node* res = new Node(head->val);
        unordered_map<Node*, Node*> M;
        M[head] = res;
        if (nullptr == head->random) {
            res->random = nullptr;
        } else if (head->random == head) {
            res->random = res;
        } else {
            res->random = new Node(head->random->val);
            M[head->random] = res->random;
        }
        Node* c = res;
        for (Node* p = head->next; nullptr != p; p = p->next) {
            if (M.contains(p)) c->next = M[p];
            else {
                c->next = new Node(p->val);
                M[p] = c->next;
            }
            c = c->next;
            if (nullptr == p->random) {
                c->random = nullptr;
            } else if (M.contains(p->random)) {
                c->random = M[p->random];
            } else {
                c->random = new Node(p->random->val);
                M[p->random] = c->random;
            }
        }
        return res;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) return nullptr;
        Node* res = new Node(head->val);
        unordered_map<Node*, Node*> M;
        M[head] = res;
        Node* p = head->next;
        Node* c = res;
        for (; nullptr != p; p = p->next) {
            c->next = new Node(p->val);
            c = c->next;
            M[p] = c;
        }
        for (p = head, c = res; nullptr != p; p = p->next, c = c->next) {
            c->random = M[p->random];
        }
        return res;
    }
};