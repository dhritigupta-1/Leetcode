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
    void helper(int[] sum, TreeNode root)
    {
        if(root == null)
            return;
            if(root.left != null && root.left.left == null && root.left.right == null)
                sum[0] += root.left.val;
            helper(sum, root.left);
            helper(sum, root.right);
    }
    public int sumOfLeftLeaves(TreeNode root) {
        int[] sum = new int[1];
        helper(sum, root);
        return sum[0];
    }
}