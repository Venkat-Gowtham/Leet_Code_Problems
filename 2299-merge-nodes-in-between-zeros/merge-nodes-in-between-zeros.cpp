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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head,*prev=NULL;
        int s=0,p=0;
        while(temp->next){
            if(temp->next->val!=0){
                if(p==0){
                     s+=temp->val;
                    temp=temp->next;
                }
                else{
                     temp=temp->next;
                     p=0;
                }
               
            }
            else{
                s+=temp->val;
                temp->val=s;
                s=0;
                if(prev==NULL){
                    head=temp;
                    prev=temp;
                }
                else{
                    prev->next=temp;
                    prev=temp;
                }
                temp->next=temp->next->next;
                p=1;
            }
        }
        return head;
    }
};