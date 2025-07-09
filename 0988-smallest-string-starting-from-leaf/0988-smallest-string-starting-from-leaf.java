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
    String smallest = null;
    void helper(StringBuilder temp, TreeNode root)
    {
        if(root == null)
            return;
        temp.append((char)('a' + root.val));
        if(root.left == null && root.right == null)
        {
            StringBuilder sb = new StringBuilder(temp);
            sb.reverse(); // Leaf-to-root string
            String curr = sb.toString();
            if (smallest == null || curr.compareTo(smallest) < 0) 
                smallest = curr;
        }
        helper(temp, root.left);
        helper(temp, root.right);
        temp.deleteCharAt(temp.length() - 1);
    }
    public String smallestFromLeaf(TreeNode root) {
        helper(new StringBuilder(), root);
        return smallest;
    }
}