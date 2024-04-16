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
    void modifyTree(TreeNode* root , int val , int depth){
        if(!root) return ;
        if(depth - 1 == 1){
            TreeNode *n1 = new TreeNode(val);
            TreeNode *n2 = new TreeNode(val);
            TreeNode *temp1 = root->left;
            TreeNode *temp2 = root->right;
            root->left = n1;
            n1 ->left = temp1;
            root->right = n2;
            n2->right = temp2;
        }
        modifyTree(root->left , val ,depth-1);
        modifyTree(root->right,val,depth -1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode * nn = new TreeNode(val);
            nn -> left = root;
            return nn;
        }
         modifyTree(root,val,depth);
        return root;
    }
};