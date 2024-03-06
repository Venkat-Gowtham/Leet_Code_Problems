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
    bool hasCycle(ListNode *head) {
        ListNode * slow=head, *fast=head;
        if(!head)return false;
        while(slow and fast)
        {
            slow=slow->next;
           if(fast->next)
           {
               fast=fast->next->next;
               if(!fast)return 0;
           }
           else
           {
               return 0;
           }
            if(slow==fast)
            {
                return 1;
            }
        }
        return 1;
    }
};