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
    string smallest;
     void helper(TreeNode* root, string ans) {
        if (root == NULL) return;
        ans = char('a' + root->val) + ans;
        if (root->left == NULL && root->right == NULL) {
            if (smallest.empty() || ans < smallest)
                smallest = ans;
        }
        helper(root->left, ans);
        helper(root->right, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        smallest = "";
        helper(root, "");
        return smallest;
    }
};