/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        q.push(root);
        while(!q.empty()){
            TreeNode *node;
            int x = q.size();
            long long s = 0;
            for(int i = 0;i<x;i++){
                node = q.front();
                s+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            pq.push(-s);
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        
        if(pq.size()<k) return -1;
        return pq.top()*-1;
    }
};