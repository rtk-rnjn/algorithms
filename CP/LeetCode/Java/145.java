// 145. Binary Tree Postorder Traversal

import java.util.ArrayList;
import java.util.List;

class Solution {
    static class TreeNode {
        // CSOFF: VisibilityModifier
        int val;
        TreeNode left;
        TreeNode right;

        // CSOFF: VisibilityModifier
        TreeNode(final int x) {
            val = x;
        }
    }

    public List<Integer> postorderTraversal(final TreeNode root) {
        List<Integer> result = new ArrayList<>();
        postorderTraversal(root, result);
        return result;
    }

    private void postorderTraversal(final TreeNode root, final List<Integer> result) {
        if (root == null) {
            return;
        }
        postorderTraversal(root.left, result);
        postorderTraversal(root.right, result);
        result.add(root.val);
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        System.out.println(solution.postorderTraversal(root));
    }
}
