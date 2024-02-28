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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>st;
        st.push(root);
        int  last ;
        while(!st.empty())
        {
            int s = st.size();
            for(int i = 0; i<s;i++)
            {
                 TreeNode * cur = st.front();
                if(i==0)last = cur->val;
                st.pop();
                if(cur->left)st.push(cur->left);
                if(cur->right)st.push(cur->right);
            }
        }
        return last;
    }
};