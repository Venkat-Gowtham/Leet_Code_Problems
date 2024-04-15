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
    int sumNumbers(TreeNode* curr, int num = 0) {
        return (!curr->left&& !curr->right) ? num *10 + curr->val :(curr->left?sumNumbers(curr->left, num*10 + curr->val):0) + (curr->right?sumNumbers(curr->right, num*10 + curr->val):0);
    }
};
