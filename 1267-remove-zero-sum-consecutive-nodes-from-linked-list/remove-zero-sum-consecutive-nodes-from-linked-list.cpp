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
        map<int,int>mp; // for storing the consecutive sum 
        // u can also use set instead of map
        int s = 0;
        ListNode * temp = head, *st = head;
        /// like two pointers
        while(temp){
            // summuning up consectuive elements
            s+=temp->val;
            if(s == 0){ // if s becomes zero , 
             // then until the current ele , evrthng must be deleted
                head = temp -> next; 
                temp = head;
                st = temp;
                // all the computed sum should be cleared 
                mp.clear();
            }
            else if(mp.find(s)!=mp.end()){
                // if you found any existing sum again 
                // means there are elemets which gives sum as zero
                int store = 0;
                while(s!=0 ){
                    // moving first pointer by reducing s value - first pointer
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