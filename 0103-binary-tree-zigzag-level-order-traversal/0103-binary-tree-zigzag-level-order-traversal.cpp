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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool order = true;
        while(!q.empty())
        {
            int levelsize = q.size();
            vector<int> temp;
            for(int i=0; i<levelsize; i++)
            {
                TreeNode*curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left); 
                if(curr->right)
                    q.push(curr->right);  
            }
            if(!order)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            order = !order;
        }
        return ans;
    }
};