/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode left = new ListNode(0);
        ListNode right = new ListNode(0);
        ListNode curr1 = left;
        ListNode curr2 = right;
        ListNode temp = head;
        while(temp != null)
        {
            if(temp.val < x)
            {
                curr1.next = temp;
                curr1 = curr1.next;
            }
            else
            {
                curr2.next = temp;
                curr2 = curr2.next;
            }
            temp = temp.next;
        }
        curr2.next = null;
        curr1.next = right.next;
        return left.next;
    }
}