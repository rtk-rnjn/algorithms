from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T")


class TreeNode(Generic[T]):
    def __init__(
        self,
        data: T | None,
        *,
        left: TreeNode[T] | None = None,
        right: TreeNode[T] | None = None,
    ) -> None:
        self.data = data
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f"TreeNode({self.data}, left={self.left}, right={self.right})"


class Tree(Generic[T]):
    def __init__(self, ls: list[T]) -> None:
        self.__ls = ls

    def build_tree(self) -> TreeNode[T] | None:
        return self.__build_tree(0)

    def __build_tree(self, index: int) -> TreeNode[T] | None:
        if index >= len(self.__ls):
            return None
        return TreeNode[T](
            self.__ls[index],
            left=self.__build_tree(2 * index + 1),
            right=self.__build_tree(2 * index + 2),
        )

    def __repr__(self) -> str:
        return f"Tree({self.__ls})"

    def __str__(self):
        """Tree in a pretty format"""
        return self.__pretty_format(self.build_tree())

    def __pretty_format(
        self, root: TreeNode[T] | None, prefix: str = "", is_left: bool = True
    ) -> str:
        if root is None:
            return ""
        string = ""
        string += self.__pretty_format(
            root.right, prefix + ("│   " if is_left else "    "), False
        )
        string += prefix + ("└── " if is_left else "┌── ") + str(root.data) + "\n"
        string += self.__pretty_format(
            root.left, prefix + ("    " if is_left else "│   "), True
        )
        return string

    def inorder_travel(self):
        self.__inorder_travel(self.build_tree())

    def __inorder_travel(self, root: TreeNode[T] | None):
        if root is None:
            return
        self.__inorder_travel(root.left)
        print(root.data, end=" ")
        self.__inorder_travel(root.right)

    def preorder_travel(self):
        self.__preorder_travel(self.build_tree())

    def __preorder_travel(self, root: TreeNode[T] | None):
        if root is None:
            return
        print(root.data, end=" ")
        self.__preorder_travel(root.left)
        self.__preorder_travel(root.right)

    def postorder_travel(self):
        self.__postorder_travel(self.build_tree())

    def __postorder_travel(self, root: TreeNode[T] | None):
        if root is None:
            return
        self.__postorder_travel(root.left)
        self.__postorder_travel(root.right)
        print(root.data, end=" ")


if __name__ == "__main__":
    tree = Tree([True])
    print(tree)
    print(tree.build_tree())

    print("Inorder Travel:")
    tree.inorder_travel()

    print("\nPreorder Travel:")
    tree.preorder_travel()

    print("\nPostorder Travel:")
    tree.postorder_travel()
