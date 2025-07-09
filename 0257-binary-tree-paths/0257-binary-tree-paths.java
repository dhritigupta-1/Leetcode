/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    void helper(List<String> ans, TreeNode root, String a)
    {
        if(root == null)
            return;
        a += String.valueOf(root.val);
        if(root.left == null && root.right == null)
        {
            ans.add(a);
            return;
        }
        helper(ans, root.left, a+"->");
        helper(ans, root.right, a+"->");
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        helper(ans, root, "");
        return ans;
    }
}