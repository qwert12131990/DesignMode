#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                break;
            }
        }
        if (fast == NULL || fast->next == NULL) return NULL;
        
        while(head != fast){
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};