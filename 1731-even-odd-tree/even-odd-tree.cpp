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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>pq;
        int f = 0;
        pq.push(root);
        while(!pq.empty())
        {
            int s = pq.size(), prev;
            if(!f) prev = 0;
            else prev = INT_MAX;
            for(int i = 0; i< s; i++)
            {
                TreeNode* temp = pq.front();
                pq.pop();
                if(!f)
                {
                    if(prev<temp->val and (temp->val)%2)
                    {
                        prev = temp->val;
                        if(temp->left)
                        {
                            pq.push(temp->left);
                        }
                        if(temp->right)
                        {
                            pq.push(temp->right);
                        }
                    }
                    else return false;
                }
                else
                {
                     if(prev>temp->val  and (temp->val)%2==0)
                    {
                        prev = temp->val;
                        if(temp->left)
                        {
                            pq.push(temp->left);
                        }
                        if(temp->right)
                        {
                            pq.push(temp->right);
                        }
                    }
                    else return false;
                }
            }
            f = !f;
        }
        return true;
    }
};