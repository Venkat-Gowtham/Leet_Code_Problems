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
    string samesub(TreeNode *root , set<TreeNode*>&result, unordered_map<string,int>&mp){
        if(!root) return "#";
        string left = samesub(root->left,result,mp);
        string right = samesub(root->right,result,mp);
        string subtree=to_string(root->val)+"_"+left+"_"+right;
        if(mp[subtree]==1){
            result.insert(root);
        }
        mp[subtree]++;
        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        set<TreeNode*>result;
        unordered_map<string,int>mp;
        string x = samesub(root,result,mp);
        return vector<TreeNode*>(result.begin(),result.end());
    }
};