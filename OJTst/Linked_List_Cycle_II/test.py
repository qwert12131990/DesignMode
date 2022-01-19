# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head;
        
        while(fast and fast.next):
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) :
                break;
        if (not (fast and fast.next)) :
            return None;
        while(fast != head) :
            fast = fast.next;
            head = head.next;
        return head;