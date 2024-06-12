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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return NULL;
       ListNode * temp = head;
        for(int i = 0;i<k;i++){
            if(!temp)return head;
            temp=temp->next;
        }
       ListNode *prev= nullptr,*nxt=nullptr,*cur=head;
       int i=0;
        while(i<k){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            i++;
        }
         head->next = reverseKGroup(temp,k);
         return prev;
        
        


        
    }
};