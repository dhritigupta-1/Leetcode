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
    void helper(int ans, int& sum, TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        ans = ans * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += ans;
            return;
        }
        helper(ans, sum, root->left);
        helper(ans, sum, root->right);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int ans = 0;
        helper(ans, sum, root);
        return sum;
    }
};