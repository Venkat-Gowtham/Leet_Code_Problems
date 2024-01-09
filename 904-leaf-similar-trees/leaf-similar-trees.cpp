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
   void calculate(TreeNode* root1,vector<int>&ans){
    if(root1==NULL)return;
    if(root1->left==NULL and root1->right==NULL){
        ans.push_back(root1->val);
    }
    calculate(root1->left,ans);
    calculate(root1->right,ans);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>res;
        calculate(root1,ans);
        calculate(root2,res);
        if(ans==res)return true;
        return false;        
    }
};