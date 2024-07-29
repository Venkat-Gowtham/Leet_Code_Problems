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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris algo for find inorder withot xtra space 
        vector<int>inorder;
        TreeNode * cur = root;
        while(cur !=nullptr){
            // if cur->left exists
            if(cur->left){
                // go for the rightmost child of cur->left
                // and attach cur as its successor
                TreeNode* predecessor = cur->left;
                while(predecessor->right and predecessor->right!=cur){
                    predecessor = predecessor->right;
                }
                // if pre->rigght not exists attach cur as its succsr
                if(predecessor->right == nullptr){
                    predecessor->right = cur;
                    // go for the left sub tree of cur to do same
                    cur = cur->left;
                }
                else{
                    // already there's a conn to cur remove it 
                    // to get the original tree struc
                    predecessor->right = nullptr;
                    // take cur ->node valu
                    inorder.push_back(cur->val);
                    // go for right of cur
                    cur = cur->right;
                }
            }
            else{
                // if left sub doesnt exists take curVal and go for rig
                inorder.push_back(cur->val);
                cur = cur ->right;
            }
        }
        return inorder;
    }
};