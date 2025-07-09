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
    void helper(int sum, bool& found, TreeNode* root, int targetSum)
    {
        if(root == NULL)
            return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == targetSum)
        {
            found = true;
            return;
        }
        helper(sum, found, root->left, targetSum);
        helper(sum, found, root->right, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        helper(0, found, root, targetSum);
        return found;
    }
};