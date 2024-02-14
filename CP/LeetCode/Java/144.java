// 144. Binary Tree Preorder Traversal

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

    public List<Integer> preorderTraversal(final TreeNode root) {
        List<Integer> res = new ArrayList<>();
        preorder(root, res);
        return res;
    }

    private void preorder(final TreeNode root, final List<Integer> res) {
        if (root == null) {
            return;
        }
        res.add(root.val);
        preorder(root.left, res);
        preorder(root.right, res);
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        System.out.println(sol.preorderTraversal(root));
    }
}
