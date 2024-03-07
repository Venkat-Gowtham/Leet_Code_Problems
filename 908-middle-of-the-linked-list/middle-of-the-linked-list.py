# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp=head
        c=0
        while(temp):
            c+=1
            temp=temp.next
        c=(c//2)+1
        q=head
        x=0
        while(q):
            if(x==c-1):
                return q
            q=q.next
            x+=1
        return q
            
            
        