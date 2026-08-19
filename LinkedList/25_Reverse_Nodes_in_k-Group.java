package LinkedList;

class Solution {
    int listLength = 1;
    ListNode resultHead = null;
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head.next == null) return head;
        ListNode reverseHead = reverseLinkedList(head);
        ListNode ptr = reverseHead;
        ListNode tail = null;
        for(int i = 1; i<= (listLength%k) ; i++){
            tail = ptr;
            ptr = ptr.next;
        }
        if(tail != null) tail.next = null;
        ListNode temp = resultList(ptr,k);
        if(listLength%k == 0) return resultHead;
        reverseHead = reverseLinkedList(reverseHead);
        temp.next = reverseHead;
        return resultHead;
        
    }
    private ListNode reverseLinkedList(ListNode head){
            if(head.next == null) return head;
            ListNode reverseHead = reverseLinkedList(head.next);
            head.next.next = head;
            head.next = null;
            listLength++;
            return reverseHead;
    }
    private ListNode resultList(ListNode first , int k){
        ListNode last = first;
        
        for(int i = 1 ; i < k ; i++){
            last = last.next;
        }
        if(last.next == null){
            resultHead = first;
            return last;
        }
        ListNode lastNode = resultList(last.next,k);
        lastNode.next = first;
        last.next = null;
        return last;
    }
}