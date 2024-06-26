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
        vector<int>inorder;
        stack<TreeNode*>st;
        st.push(root);
        if(!root)return {};
        while(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            TreeNode * child = temp->left;
            TreeNode *rc = temp->right;
            if(!temp->left and !temp->right){
            // if(temp->val == 1)cout<<"hl";
                inorder.push_back(temp->val);
                continue;
            }
            temp->left = nullptr;
            temp->right = nullptr;
            if(child)cout<<child->val;
            if(!child)inorder.push_back(temp->val);
            if(rc)st.push(rc);
            if(child)st.push(temp);
           if(child) st.push(child);
            // while(child){ 
            //     st.push(child);
            //     child = child->left;
            // }
        }
        return inorder;
    }
};