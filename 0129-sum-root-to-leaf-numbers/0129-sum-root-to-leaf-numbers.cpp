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
    void helper(int &sum, int ans, TreeNode* root){
        if(!root) return;
        ans = ans* 10 + root->val;
        if(root->left == NULL && root->right == NULL)
            sum += ans;
        helper(sum, ans, root->left);
        helper(sum, ans, root->right);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int ans = 0;
        helper(sum, ans, root);
        return sum;
        
    }
};