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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next)return {-1,-1};
        if(!head->next->next)return {-1,-1};
        int prev = head ->val;
        ListNode *temp = head->next;
        int minabs=INT_MAX,maxabs=INT_MIN,stmin=-1, stmax=-1,c=2,rm=-1;
        while(temp->next){
            if(temp->val>prev and temp->val > temp->next->val){
                if(rm==-1)rm=c;
                else if(rm!=-1){
                    minabs=min(minabs,c-rm);
                    rm=c;
                }
                if(stmax==-1)stmax=c;
                else maxabs=max(maxabs,c-stmax);
            }
            else if(temp->val<prev and temp->val<temp->next->val){
                if(rm==-1)rm=c;
                else if(rm!=-1){
                   minabs=min(minabs,c-rm);
                    rm=c;
                }
                if(stmax==-1)stmax = c;
                else maxabs=max(maxabs,c-stmax);
            }
            cout<<rm<<" "<<c<<endl;
            c++;
            prev=temp->val;
            temp = temp->next;
        }
        return {minabs==INT_MAX?-1:minabs,maxabs==INT_MIN?-1:maxabs};
    }
};