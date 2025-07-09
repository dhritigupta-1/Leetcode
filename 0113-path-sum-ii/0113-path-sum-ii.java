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
    void helper(List<Integer> sum, List<List<Integer>> ans, TreeNode root, int targetSum)
    {
        if(root == null)
            return;
        List<Integer> a = new ArrayList<>(sum);
        a.add(root.val);
        targetSum -= root.val;
        if(root.left == null && root.right == null && targetSum == 0)
            ans.add(new ArrayList<>(a));
        helper(a, ans, root.left, targetSum);
        helper(a, ans, root.right, targetSum);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        helper(new ArrayList<>(), ans, root, targetSum);
        return ans;
    }
}