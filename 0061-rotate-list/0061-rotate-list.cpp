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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* curr = head;
        int length = 0;
        while(curr != NULL)
        {
            curr = curr->next;
            length++;
        }
        k = k % length;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<k; i++)
            fast = fast->next;
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};