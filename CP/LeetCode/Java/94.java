// 94. Binary Tree Inorder Traversal

import java.util.ArrayList;
import java.util.List;

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

    public List<Integer> inorderTraversal(final TreeNode root) {
        List<Integer> res = new ArrayList<>();
        inorder(root, res);
        return res;
    }

    private void inorder(final TreeNode root, final List<Integer> res) {
        if (root == null) {
            return;
        }
        inorder(root.left, res);
        res.add(root.val);
        inorder(root.right, res);
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        System.out.println(sol.inorderTraversal(root));
    }
}
