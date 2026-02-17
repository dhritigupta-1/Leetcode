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
    void helper(TreeNode* root, int target, int sum, bool& found){
        if(!root) return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == target){
            found = true;
            return;
        }
        helper(root->left, target, sum, found);
        helper(root->right, target, sum, found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = 0;
        helper(root, targetSum, 0, found);
        return found;
    }
};