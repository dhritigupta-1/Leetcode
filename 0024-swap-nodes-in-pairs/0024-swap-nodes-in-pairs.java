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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode temp = dummy;
        ListNode curr = head;
        while(curr != null && curr.next != null)
        {
            ListNode first = curr;
            ListNode second = curr.next;
            first.next = second.next;
            second.next = first;
            temp.next = second;
            temp = first;
            curr = first.next;
        }
        return dummy.next;
    }
}