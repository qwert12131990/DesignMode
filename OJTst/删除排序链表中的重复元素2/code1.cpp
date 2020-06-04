/*
 * tion for singly-linked list.
 * struct ListNode {
 *  *     int val;
 *   *     ListNode *next;
 *    *     ListNode(int x) : val(x), next(NULL) {}
 *     * };
*      */
class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
            ListNode* preRept=head;
            ListNode* pre=head;
            ListNode* cur=head;
            bool flag=false;
    
            /*head handle*/
            int i=0;
            while(cur)
            {
                        if (cur->next)
                        {
                                        if (cur->val == cur->next->val)
                                        {
                                                            flag=true;
                                                            cur->next=cur->next->next;
                                                            continue;
                                                        }
                                        if (flag)
                                        {
                                                            if (cur==head)
                                                            {
                                                                                    pre=cur->next;
                                                                                    cur=cur->next;
                                                                                    pre->next=cur->next;
                                                                                    head=cur;
                                                                                    flag=false;
                                                                                    continue;
                                                                                }
                                                            pre->next=cur->next;
                                                            cur=cur->next;
                                                            flag=false;
                                                            continue;
                                                        }
                                        pre=cur;
                                        cur=cur->next;
                                        continue;
                                    }
                        if (flag)
                        {
                                        if (cur==head)
                                        {
                                                            cur=cur->next;
                                                            head=cur;
                                                            flag=false;
                                                            continue;
                                                        }
                                        pre->next=cur->next;
                                        cur=cur->next;
                                        flag=false;
                                        continue;
                        
                                    }
                        cur=cur->next;
                    }
           
            return head;
        }
};
