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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL)return root;
        queue<TreeNode*>st;
        st.push(root);
        int l=0;
        vector<int>pre;
        while(!st.empty()){
            vector<int>cur;
            int n=st.size();
            for(int i=0;i<n;i++){
                TreeNode * temp=st.front();
                if(l==0){
                    if(temp->left){
                        st.push(temp->left);
                        cur.push_back(temp->left->val);
                        pre.push_back(temp->left->val);
                    }
                    if(temp->right){
                            st.push(temp->right);
                            cur.push_back(temp->right->val);
                            pre.push_back(temp->right->val);
                    }  
                }
                else{
                       if(temp->left){
                        st.push(temp->left);
                        cur.push_back(temp->left->val);
                       // pre.push_back(temp->left->val);
                        }
                      if(temp->right){
                            st.push(temp->right);
                            cur.push_back(temp->right->val);
                           // pre.push_back(temp->right>val);
                     }    
                        temp->val=pre.back();
                        pre.pop_back();
                }
                st.pop();
            }
            if(l==1){
                for(int i=0;i<cur.size();i++){
                    pre.push_back(cur[i]);
                }
            }
            l=!l;
        }
        return root;
    }
};