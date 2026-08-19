package LinkedList;

class Solution {

    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        return swapFn(head);
        
    }
    private ListNode swapFn(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        ListNode headNext = head.next;
        ListNode tail =  swapFn(head.next.next);
        head.next.next = head;
        head.next = tail;
        return headNext;
    }
}