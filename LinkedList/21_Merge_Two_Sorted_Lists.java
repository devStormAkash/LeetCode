// Definition for singly-linked list.
package LinkedList;


/*class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head;
        if(list1 == null && list2 == null) return null;
        if(list1 == null) return list2;
        if(list2 == null) return list1;
        ListNode ptr ;
        if(list1.val<=list2.val){
                ptr = new ListNode();
                ptr.val = list1.val;
                list1 = list1.next;
                head = ptr;
            }
            else {
                ptr = new ListNode();
                ptr.val = list2.val;
                list2 = list2.next;
                head = ptr;
            }

        ListNode temp;
        while(list1!=null && list2!=null){
            if(list1.val<=list2.val){
                temp = new ListNode();
                temp.val = list1.val;
                list1 = list1.next;
            }
            else {
                temp = new ListNode();
                temp.val = list2.val;
                list2 = list2.next;
            }
            ptr.next = temp;
            ptr = temp;
        }
        while(list1!=null){
            temp = new ListNode();
            temp.val = list1.val;
            list1 = list1.next;
            ptr.next = temp;
            ptr = temp;
        }
        while(list2!=null){
            temp = new ListNode();
            temp.val = list2.val;
            list2 = list2.next;
            ptr.next = temp;
            ptr = temp;
        }
        return head;
    }
}*/
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0); // dummy node to make life easy
        ListNode current = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                current.next = list1;
                list1 = list1.next;
            } else {
                current.next = list2;
                list2 = list2.next;
            }
            current = current.next;
        }

        // Attach the leftover list
        if (list1 != null) current.next = list1;
        if (list2 != null) current.next = list2;

        return dummy.next; // skip dummy, return real head
    }
}
