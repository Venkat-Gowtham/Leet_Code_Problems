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
     pair<int,int>find(TreeNode* root, int &result)
     {
         if(!root)return {0,0};
         if(!root->left and !root->right)return{root->val,root->val};
         auto it1=find(root->left,result);
         auto it2=find(root->right,result);
         int mi=0,ma=0;
         if(!root->left)
         {
               mi=min({it2.first,it2.second});
          ma=max({it2.first,it2.second});
         }
         else if(!root->right)
         {
              mi=min({it1.first,it1.second});
          ma=max({it1.first,it1.second});
         }
        else
        {
              mi=min({it1.first,it1.second,it2.first,it2.second});
           ma=max({it1.first,it1.second,it2.first,it2.second});
        }
         result=max(result,abs(root->val-mi));
          result=max(result,abs(root->val-ma));
          return {min(mi,root->val), max(ma,root->val)};
     }
    int maxAncestorDiff(TreeNode* root) {
        int result=0;
        auto it =find(root,result);
        return result;
    }
};