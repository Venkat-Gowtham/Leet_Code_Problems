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
    TreeNode *constructTree(vector<int>&preorder , vector<int>&inorder,unordered_map<int,int>&indexStore,int is , int ie ,int ps , int pe){
            if(is>ie or ps>pe) return nullptr;
            int index = indexStore[preorder[ps]];
            int diff = index-is;
            TreeNode *root = new TreeNode(preorder[ps]);
            root->left = constructTree(preorder,inorder,indexStore,is,index-1,ps+1,ps+diff);
            root->right = constructTree(preorder,inorder,indexStore,index+1,ie,ps+diff+1,pe);
            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>indexStore;
        for(int i = 0 ; i <n;i++){
            indexStore[inorder[i]] = i;
        }
        return constructTree(preorder,inorder,indexStore,0,n-1,0,n-1);
    }
};