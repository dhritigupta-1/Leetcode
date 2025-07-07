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
    void helper(List<Integer> ans, TreeNode root)
    {
        if(root == null)
            return;
        if(root.left == null && root.right == null)
            ans.add(root.val);
        helper(ans, root.left);
        helper(ans, root.right);
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> ans1 = new ArrayList<>();
        List<Integer> ans2 = new ArrayList<>();
        helper(ans1, root1);
        helper(ans2, root2);
        if(ans1.equals(ans2))
            return true;
        return false;
    }
}