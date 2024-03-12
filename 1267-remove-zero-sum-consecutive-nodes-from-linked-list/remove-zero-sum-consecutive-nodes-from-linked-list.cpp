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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,int>mp;
        int s = 0;
        ListNode * temp = head, *st = head;
        while(temp){
            s+=temp->val;
            if(s == 0){
                head = temp -> next; 
                temp = head;
                st = temp;
                mp.clear();
            }
            else if(mp.find(s)!=mp.end()){
                int store = 0;
                while(s!=0 ){
                    // if(mp[s]>0)mp.erase(s);
                    s-=st->val;
                    store += st->val;
                    if(s!=0)st = st->next;
                }
                // cout<<st->val<<" "<<temp->val<<endl;
                st->next = temp ->next;
                temp = temp ->next;
                // head = st;
                st = head ;
                s = store ;
            }
            else{
                mp[s]++;
                 temp = temp ->next;
            }
        }
        return head;
    }
};