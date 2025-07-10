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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if(root == null) return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean order = true;
        while(!q.isEmpty())
        {
            int levelsize = q.size();
            List<Integer> temp = new LinkedList<>();
            for(int i=0; i<levelsize; i++)
            {
                TreeNode curr = q.poll();
                temp.add(curr.val);
                if(curr.left != null)
                    q.add(curr.left); 
                if(curr.right != null)
                    q.add(curr.right);  
            }
            if(!order)
                Collections.reverse(temp);
            ans.add(temp);
            order = !order;
        }
        return ans;
    }
}