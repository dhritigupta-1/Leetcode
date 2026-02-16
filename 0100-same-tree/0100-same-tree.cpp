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
    // void helper(vector<int>& ans, TreeNode* root)
    // {
    //     if(root == NULL)
    //     {
    //         ans.push_back(INT_MAX);
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     helper(ans, root->left);
    //     helper(ans, root->right);
    // }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    //     vector<int> ans1, ans2;
    //     helper(ans1, p);
    //     helper(ans2, q);
    //     if(ans1 == ans2)
    //         return true;
    //     return false;
    // }
    if( p == NULL && q == NULL) return true;
    if( p == NULL || q == NULL) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};