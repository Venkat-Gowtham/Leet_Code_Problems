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
    map<int,vector<pair<int,int>>>adj;
    TreeNode *construct (TreeNode*root , int node ){
        for(auto it : adj[node]){
            if(it.second == 0){
                root->right = new TreeNode(it.first);
                TreeNode * r = construct(root->right,it.first);
            }
            else{
                root->left = new TreeNode(it.first);
                TreeNode * r = construct(root->left,it.first);
            }
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,int>mp;
        for(int i = 0;i<d.size();i++){
            mp[d[i][1]]++;
            adj[d[i][0]].push_back({d[i][1],d[i][2]});
        }
        int node  =0; 
        for(int i = 0;i<d.size();i++){
            if(!mp.count(d[i][0])) {
                node = d[i][0];
                break;
            }
            else if(!mp.count(d[i][1])){
                node = d[i][1];
                break;
            }
        }
        cout<<node;
        TreeNode * root = new TreeNode(node);
        return construct(root,node);
    }
};