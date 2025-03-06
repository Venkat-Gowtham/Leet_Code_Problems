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

        if(head == nullptr || head->next==nullptr) return head;
        ListNode* small = nullptr;
        ListNode* smalltail=nullptr;

        ListNode* big = nullptr;
        ListNode* bigtail=nullptr;

        ListNode* cur=head;

        while(cur != nullptr){
            if(cur -> val < x){
                ListNode* newone=new ListNode;
                newone->val=cur->val;
                newone->next=nullptr;

                if(small == nullptr){
                    small = newone;
                    smalltail=newone;
                }
                else {
                    smalltail->next=newone;
                    smalltail=smalltail->next;
                }
            }
            else if(cur -> val >= x){
                ListNode* newone=new ListNode;
                newone->val=cur->val;
                newone->next=nullptr;
                if(big == nullptr){
                    big = newone;
                    bigtail=newone;
                }
                else {
                    bigtail->next=newone;
                    bigtail=bigtail->next;
                }
            }
            cur=cur->next;
        }
        

        
        if(small == nullptr) return big;
        else  smalltail->next=big;

        return small;


    }
};