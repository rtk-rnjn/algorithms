# 94. Binary Tree Inorder Traversal

from __future__ import annotations


class TreeNode:
    def __init__(
        self,
        val: int = 0,
        left: TreeNode | None = None,
        right: TreeNode | None = None,
    ):
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
        _root: TreeNode | None = root

        while _root or stack:
            while _root:
                stack.append(_root)
                _root = _root.left
            _root = stack.pop()
            res.append(_root.val)  # type: ignore # _root is not None
            _root = _root.right  # type: ignore # _root is not None

        # Why iterative solution is faster than recursive solution?
        # Because of the overhead of function calls in recursive solution.
        # In iterative solution, we are using a stack to keep track of the nodes to visit.

        return res


if __name__ == "__main__":
    tree = TreeNode(1, None, TreeNode(2, TreeNode(3)))

    s = Solution()
    print(s.inorderTraversal(tree))
