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
    void helper(vector<string>& ans, TreeNode* root, string a)
    {
        if(root == NULL)
            return;
        if(! a.empty())
            a += "->";
        a += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(a);
            return;
        }
        helper(ans, root->left, a);
        helper(ans, root->right, a);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(ans, root, "");
        return ans;
    }
};