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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head , *prev = nullptr,*less=nullptr,*lp=nullptr,*pr=nullptr,*ct;
    while(temp){
        ListNode * cur = temp;
        while(cur and cur->val<x){
            pr=cur;
            cur = cur->next;
        }
        if(cur!=temp){
            if(!less){
                less=temp;
                lp=pr;
            }
            else{
                lp->next = temp;
                lp = pr;
            }
            temp=cur;
        }
        else{
            if(!prev){prev=cur;ct=prev;}
           else {ct->next=cur;
            ct=ct->next;}
            temp=temp->next;
        }
       
    }
    if(lp){
        cout<<lp->val;
        lp->next=prev;
        if(ct)ct->next=nullptr;
        head=less;
    }
    return head;
    }
};