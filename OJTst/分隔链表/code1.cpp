/*attention for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**/
class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
            ListNode* ptmp=head;
            ListNode* pre=NULL;
            ListNode* label=NULL;
            ListNode  vhead;
            bool flag=true;
    
            vhead.val=x-1;
            vhead.next=head;
            pre=&vhead;
            
    
            while(ptmp && ptmp->val<x)
            {
                        pre=ptmp;
                        ptmp=ptmp->next;
                    }
    
            if (!ptmp || !ptmp->next)
            {
                        return head;
                    }
        
            label=pre;
            pre=ptmp;
            ptmp=ptmp->next;
    
            while(ptmp)
            {
                        if (ptmp->val<x)
                        {
                                        pre->next=ptmp->next;
                                        ptmp->next=label->next;
                                        label->next=ptmp;
                                        label=ptmp;
                                        ptmp=pre->next;
                                        continue;
                                    }
                        pre=ptmp;
                        ptmp=ptmp->next;
                    }
            
            return vhead.next;
        }
};
