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
    int helper(TreeNode root, int [] k)
    {
        if(root == null) return 0;
        int left = helper(root.left, k);
        if(k[0] == 0) return left;
        if(--k[0] == 0) return root.val;
        return helper(root.right, k);
    }
    public int kthSmallest(TreeNode root, int k) {
        return helper(root, new int[] {k});
    }
}