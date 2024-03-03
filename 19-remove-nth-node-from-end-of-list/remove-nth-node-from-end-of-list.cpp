/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head->next) return NULL;
         ListNode * temp=head,*q=head,*p=head;
        int c = 0;
        while(temp){
            if(temp->next==NULL)break;
            temp=temp->next->next;
            q=q->next;
            c+=1;
        }
       int total= c*2;
        if(temp)total+=1;
        total-=n;
        temp = head;
        if(total == 0) {
            head = head->next;
            return head;
        }
        while(total>1)
        {
            temp = temp->next;
            total--;
        }
       if(temp->next) temp->next= temp->next->next;
        return head;
        
        
        
    }
};