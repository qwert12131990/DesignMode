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


/*
1->2->3->4->5->6->7，如此一个链表


代码技巧：vhead指向头部，链表如下，
vhead->1->2->3->4->5->6->7
这样可以避免头部访问时，删除和添加等特殊处理，前提得满足业务基本需求
比如，当前题目需求是小于分割符的值，因此vhead的val为x-1

算法：
1、找到第一个大于x的节点ptmp
2、标记x的前一个节点pre为label，因为后续若是发现小于x的节点需在label后插入，（即第一个大于x的节点前插入）
3、遍历ptmp后的节点，若是发现小于当前x节点，则忘label后插入，并重新标记label为插入节点（保证相对位置不变）
*/
