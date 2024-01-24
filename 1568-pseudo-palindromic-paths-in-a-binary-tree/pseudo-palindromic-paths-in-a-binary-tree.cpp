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
    int findall(TreeNode* root, int res)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left and !root->right)
        {
           if(res&(1<<root->val))
           {
               res-=(1<<root->val);
           }
           else res+=1<<root->val;
            int f=0;
            for(int i=0;i<=9;i++)
            {
                if(res&(1<<i))
                {
                    if(!f)f=1;
                    else {res-=(1<<i);return 0;}
                }
            }
            if(res&(1<<root->val))
           {
               res-=(1<<root->val);
           }
           else res+=1<<root->val;
            return 1;
        }
        if(res&(1<<root->val))
           {
               res-=(1<<root->val);
           }
        else res+=1<<root->val;
        int l=findall(root->left,res);
        int r=findall(root->right,res);
       if(res&(1<<root->val))
           {
               res-=(1<<root->val);
           }
           else res+=1<<root->val;
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
     int res=0;
       return findall(root,res);
    }
};