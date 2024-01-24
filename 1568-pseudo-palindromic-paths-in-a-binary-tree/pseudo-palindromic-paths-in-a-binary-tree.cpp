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
    int findall(TreeNode* root, vector<int>&mp)
    {
        if(!root)
        {
            return 0;
        }
        if(!root->left and !root->right)
        {
            mp[root->val]++;
            int f=0;
            for(auto it : mp)
            {
                if(it%2)
                {
                    if(!f)f=1;
                    else {mp[root->val]--;return 0;}
                }
            }
             mp[root->val]--;
            return 1;
        }
        mp[root->val]++;
        int l=findall(root->left,mp);
        int r=findall(root->right,mp);
        mp[root->val]--;
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       vector<int>mp(10,0);
       return findall(root,mp);
    }
};