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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head,*nn,*x;
        while(temp->next){
            int c = __gcd(temp->val,temp->next->val);
            nn = new ListNode(c);
            x = temp->next;
            temp->next = nn;
            nn->next = x; 
            temp = x;
        }
        return head;
        // 18 6 2 10 1 3
        //   6 6
    }
};