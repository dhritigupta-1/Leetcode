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
    void helper(int sum, boolean[] found, TreeNode root, int targetSum)
    {
        if(root == null)
            return;
        sum += root.val;
        if(root.left == null && root.right == null && sum == targetSum)
        {
            found[0] = true;
            return;
        }
        helper(sum, found, root.left, targetSum);
        helper(sum, found, root.right, targetSum);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        boolean found[] = new boolean[1];
        found[0] = false;
        helper(0, found, root, targetSum);
        return found[0];
    }
}