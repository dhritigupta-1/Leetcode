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
class BSTIterator {
public:
    TreeNode* curr;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        int ans = -1;
        while(curr){
            if(!curr->left){
                ans = curr->val;
                curr = curr->right;
                break;
            }
            else{
                TreeNode* l = curr->left;
                while(l->right && l->right != curr) l = l->right;
                if(!l->right){
                    l->right = curr;
                    curr = curr->left;
                }
                else{
                    l->right = NULL;
                    ans = curr->val;
                    curr = curr->right;
                    break;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return curr != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */