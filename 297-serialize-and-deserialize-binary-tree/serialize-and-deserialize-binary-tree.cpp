/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr){
                res += to_string(curr->val)+",";
                q.push(curr->left);
                q.push(curr->right);
            }
            else res += "N,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<string> vals;
        string temp;
        for(char c : data){
            if(c == ','){
                vals.push_back(temp);
                temp = "";
            }
            else{
                temp += c;
            }
        }
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i<vals.size()){
            TreeNode* curr = q.front();
            q.pop();
            if(vals[i] != "N"){
                curr->left = new TreeNode(stoi(vals[i]));
                q.push(curr->left);
            }
            i++;
             if(i < vals.size() && vals[i] != "N"){
                curr->right = new TreeNode(stoi(vals[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));