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
    void helper(int[] sum, int ans, TreeNode root)
    {
        if(root == null)
            return;
        ans = ans * 10 + root.val;
        if(root.left == null && root.right == null)
        {
            sum[0] += ans;
            return;
        }
        helper(sum, ans, root.left);
        helper(sum, ans, root.right);
    }
    public int sumNumbers(TreeNode root) {
        int sum[] = new int[1];
        int ans = 0;
        helper(sum, ans, root);
        return sum[0];
    }
}