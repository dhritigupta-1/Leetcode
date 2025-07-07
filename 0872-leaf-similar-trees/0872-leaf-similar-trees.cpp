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
    void helper(vector<int>& ans, TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->val);
        helper(ans, root->left);
        helper(ans, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        helper(ans1, root1);
        helper(ans2, root2);
        if(ans1 == ans2)
            return true;
        return false;
    }
};