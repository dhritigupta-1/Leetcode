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
    void helper(vector<int>& sum, vector<vector<int>>& ans, TreeNode* root, int targetSum)
    {
        if(root == NULL)
            return;
        sum.push_back(root->val);
        targetSum -= root->val;
        if(root->left==NULL && root->right == NULL && targetSum == 0)
        {
            ans.push_back(sum);
        }
        helper(sum, ans, root->left, targetSum);
        helper(sum, ans, root->right, targetSum);
        sum.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> sum;
        helper(sum, ans, root, targetSum);
        return ans;
    }
};