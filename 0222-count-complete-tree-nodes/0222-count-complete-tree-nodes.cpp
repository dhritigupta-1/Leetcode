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
    void Helper(vector<int>& ans, TreeNode* root)
    {
        if(root == NULL)
            return;
        Helper(ans, root->left);
        Helper(ans, root->right);
        ans.push_back(root->val);
    }
    int countNodes(TreeNode* root) {
        vector<int> ans;
        Helper(ans, root);
        return ans.size();
    }
};