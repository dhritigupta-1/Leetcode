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
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> tree;
        if(start > end){
            tree.push_back(NULL);
            return tree;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = build(start, i-1);
            vector<TreeNode*> right = build(i+1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n);
    }
};