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
    void dfs(TreeNode *root,vector<int>&nodes){
        if(!root)return ;
        dfs(root->left,nodes);
        nodes.push_back(root->val);
        dfs(root->right,nodes);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>nodes;
        dfs(root,nodes);
        int mi = 0 , ma = 0,n=1e6;
        vector<vector<int>>ans;
        for(auto it : queries){
            auto ind = lower_bound(begin(nodes),end(nodes),it);
            if(ind == nodes.end()){
                ans.push_back({nodes.back(),-1});
            }
            else{
                if(*ind==it){
                    cout<<it;
                    ans.push_back({*ind,*ind});
                }
               else {
                int i = ind-nodes.begin();
                int a = -1,b=-1;
                if(i>0)a=nodes[i-1];
                b=nodes[i];
                ans.push_back({a,b});
                }
            }
        }

        return ans;
    }
};