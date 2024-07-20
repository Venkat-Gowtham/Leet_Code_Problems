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
    int gd = 0 ;
    vector<int>countGoodLeafs(TreeNode *root , int d){
        if(!root)return {};
        if(!root->left and !root->right)return {1};
        vector<int>left = countGoodLeafs(root->left , d);
        vector<int>right =countGoodLeafs(root->right ,d);
        if(right.size()!=0 and left.size()!=0){
                for(auto i : left) {
                for(auto j : right){
                    if(i+j<=d)gd++;
                }
            }
        }
        vector<int>ans;
        for(auto it : left)ans.push_back(++it);
        for(auto it : right)ans.push_back(++it);
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        countGoodLeafs(root,distance);
        return gd;
    }
};