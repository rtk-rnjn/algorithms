# 104. Maximum Depth of Binary Tree

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
    def maxDepth(self, root: TreeNode) -> int:
        # Time Complexity of recursive solution is O(n) and Space Complexity is O(n)

        # if not root:
        #     return 0
        # return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

        # ---

        # Time Complexity of iterative solution is O(n) and Space Complexity is O(n)

        if not root:
            return 0

        stack: list[tuple[TreeNode | None, int]] = [(root, 1)]
        depth = 0

        while stack:
            node, d = stack.pop()
            if node:
                depth = max(depth, d)
                stack.append((node.left, d + 1))
                stack.append((node.right, d + 1))

        return depth


if __name__ == "__main__":
    tree = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))

    s = Solution()
    print(s.maxDepth(tree))
