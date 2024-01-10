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
   int result=INT_MIN;
  TreeNode * store=NULL;
  void dfs(TreeNode *root ,map<int,TreeNode*>&mp,int sec)
  {
       result=max(result,sec);
      if(!root)return;
      int x=root->val;
      root->val*=-1;
      sec++;
      if(root->left and root->left->val>0)dfs(root->left,mp,sec);
      if(root->right and root->right->val>0)dfs(root->right,mp,sec);
      if( mp[x] and mp[x]->val>0 )dfs(mp[x],mp,sec);
      sec--;
  }
        void find(TreeNode * root, int target,map<int,TreeNode*>&mp)
  {
      if(!root)return;
      if(root->val==target){
          store=root;
        //   int sec=0;
        //   dfs(root,prev,sec);
        //   return ;
      }
      if(root->left)
      {
          mp[root->left->val]=root;
        //   mp[root->data][1]=root->left;
          find(root->left,target,mp);
      }
      if(root->right)
      {
          mp[root->right->val]=root;
        //   mp[root->data][2]=root->right;
          find(root->right,target,mp);
      }
  }
    int amountOfTime(TreeNode* root, int target) {
          map<int,TreeNode*>mp;
       find(root,target,mp);
          int sec=0;
          dfs(store,mp,sec);
       return result;
    }
};