# 144. Binary Tree Preorder Traversal

from __future__ import annotations


class TreeNode:
    def __init__(
        self, val: int = 0, left: TreeNode | None = None, right: TreeNode | None = None
    ):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> list[int]:
        # Time Complexity of recursive solution is O(n) and Space Complexity is O(n)

        # if not root:
        #     return []
        # return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)

        # ---

        # Time Complexity of iterative solution is O(n) and Space Complexity is O(n)

        res = []
        stack = [root] if root else []

        while stack:
            _root = stack.pop()
            res.append(_root.val)
            if _root.right:
                stack.append(_root.right)
            if _root.left:
                stack.append(_root.left)

        return res


if __name__ == "__main__":
    new_root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
    sol = Solution()

    print(sol.preorderTraversal(new_root))
