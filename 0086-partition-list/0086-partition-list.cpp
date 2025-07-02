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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* curr1 = left;
        ListNode* right = new ListNode(0);
        ListNode* curr2 = right;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val < x)
            {
                curr1->next = temp;
                curr1 = curr1->next;
            }
            else
            {
                curr2->next = temp;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }
        curr2->next = NULL;
        curr1->next = right->next;
        return left->next;
    }
};