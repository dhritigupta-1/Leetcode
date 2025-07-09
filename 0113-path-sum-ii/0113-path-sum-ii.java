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
        sum.add(root.val);
        targetSum -= root.val;
        if(root.left == null && root.right == null && targetSum == 0)
            ans.add(new ArrayList<>(sum));
        helper(sum, ans, root.left, targetSum);
        helper(sum, ans, root.right, targetSum);
        sum.remove(sum.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        helper(new ArrayList<>(), ans, root, targetSum);
        return ans;
    }
}