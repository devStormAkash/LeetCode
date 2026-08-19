package LinkedList;
import java.util.*;

// Definition for singly-linked list.

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a,b) -> a.val - b.val);
        for(int i = 0 ; i < lists.length ; i++){
                if(lists[i] != null){
                    minHeap.add(lists[i]);
                }
        }
        while(minHeap.size() > 0){
            ListNode ptr = minHeap.poll();
            ListNode t = new ListNode(ptr.val);
            temp.next = t;
            temp = temp.next;
            ptr = ptr.next;
            if(ptr != null) minHeap.add(ptr);

        }
        ListNode head = dummy;

        return head.next;

    }
}