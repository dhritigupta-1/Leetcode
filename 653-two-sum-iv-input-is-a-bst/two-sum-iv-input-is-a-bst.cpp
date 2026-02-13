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
    stack<TreeNode*> l, r;
    void pushLeft(TreeNode* root){
        while(root){
            l.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode* root){
        while(root){
            r.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        pushLeft(root);
        pushRight(root);
        while(!l.empty() && !r.empty() && l.top() != r.top()){
            int lval = l.top()->val;
            int rval = r.top()->val;
            if(lval + rval == k) return true;
            else if(lval + rval < k){
                TreeNode* curr = l.top(); l.pop();
                pushLeft(curr->right);
            }
            else{
                TreeNode* curr = r.top(); r.pop();
                pushRight(curr->left);
            }
        }
        return false;
    }
};