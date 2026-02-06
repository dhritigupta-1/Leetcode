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
    void helper(TreeNode* root, int targetSum, int sum, bool& found){
        if(!root) return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == targetSum){
            found = true;
            return;
        }
        helper(root->left, targetSum, sum, found); 
        helper(root->right, targetSum, sum, found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        helper(root, targetSum, 0, found);
        return found;
    }
};