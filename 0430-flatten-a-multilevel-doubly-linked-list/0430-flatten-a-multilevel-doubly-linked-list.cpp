/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                Node* tail = curr->child;
                while(tail->next) tail = tail->next;
                if(next){
                    tail->next = next;
                    next->prev = tail;
                }
                curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};