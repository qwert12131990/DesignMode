/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptmp=head;
        ListNode* pre=head;

        if (!ptmp)
        {
            return head;
        }

        ptmp=ptmp->next;

        while(ptmp)
        {
            if (ptmp->val == pre->val)
            {
                pre->next=ptmp->next;
            }
            else
            {
                pre=ptmp;
            }
            ptmp=ptmp->next;
        }

        return head;
    }
};
