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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        int k = 0;
        while(inorder[k] != rootval) k++;
        vector<int> lp(preorder.begin()+1, preorder.begin()+1+k);
        vector<int> l(inorder.begin(), inorder.begin()+k);
        vector<int> rp(preorder.begin()+1+k, preorder.end());
        vector<int> r(inorder.begin()+k+1, inorder.end());
        root->left = buildTree(lp, l);
        root->right = buildTree(rp, r);
        return root;
    }
};