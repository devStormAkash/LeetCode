#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ans = NULL;
        ListNode* head = NULL;
        int carry = 0;

        while(ptr1!=NULL && ptr2!=NULL){
            int x = ptr1->val;
            int y = ptr2->val;
            int sum = x+y+carry;
            int node_val;

            if(sum>9){
                node_val = sum%10;
                carry = sum/10;
            }else{
                node_val = sum;
                carry = 0;
            }

            ListNode* node =  new ListNode(node_val);
            if(ans == NULL){
                ans = node;
                head = node;
            }else{
                ans->next = node;
                ans = ans->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(ptr1!=NULL){
            int x = ptr1->val;
            int sum = x+carry;
            int node_val;
            if(sum>9){
                node_val = sum%10;
                carry = sum/10;
            }else{
                node_val = sum;
                carry = 0;
            }
            ListNode* node =  new ListNode(node_val);
            ans->next = node;
            ans = ans->next;
            ptr1 = ptr1->next;
        }

        while(ptr2!=NULL){
            int x = ptr2->val;
            int sum = x+carry;
            int node_val;
            if(sum>9){
                node_val = sum%10;
                carry = sum/10;
            }else{
                node_val = sum;
                carry = 0;
            }
            ListNode* node =  new ListNode(node_val);
            ans->next = node;
            ans = ans->next;
            ptr2 = ptr2->next;
        }

        if(carry>0){
            ListNode* node =  new ListNode(carry);
            ans->next = node;
            ans = ans->next;
        }

        return head;
    }
};