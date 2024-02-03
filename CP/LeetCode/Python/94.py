# 94. Binary Tree Inorder Traversal

from __future__ import annotations


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: TreeNode) -> list[int]:
        # Time Complexity of recursive solution is O(n) and Space Complexity is O(n)

        # if not root:
        #     return []
        # return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

        # ---

        # Time Complexity of iterative solution is O(n) and Space Complexity is O(n)

        res = []
        stack = []

        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right

        # Why iterative solution is faster than recursive solution?
        # Because of the overhead of function calls in recursive solution.
        # In iterative solution, we are using a stack to keep track of the nodes to visit.

        return res


if __name__ == "__main__":
    tree = TreeNode(1, None, TreeNode(2, TreeNode(3)))

    s = Solution()
    print(s.inorderTraversal(tree))
