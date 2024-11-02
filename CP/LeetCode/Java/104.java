// 104. Maximum Depth of Binary Tree

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static class TreeNode {
        // CSOFF: VisibilityModifier
        int val;
        TreeNode left;
        TreeNode right;
        // CSON: VisibilityModifier

        TreeNode(final int x) {
            this.val = x;
        }
    }

    public int maxDepth(final TreeNode root) {
        if (root == null) {
            return 0;
        }
        int depth = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            depth++;
        }
        return depth;
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println(sol.maxDepth(root));
    }
}
