# 61. Rotate List

from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T")


class ListNode(Generic[T]):
    def __init__(self, val: T, next: ListNode[T] | None = None):
        self.val = val
        self.next = next
    def __repr__(self) -> str:
        return f"{self.val} -> {self.next}"


class Solution:
    def rotateRight(self, head: ListNode[int], k: int) -> ListNode[int] | None:
        if not head:
            return head
        length = 1
        old_tail = head
        while old_tail.next:
            old_tail = old_tail.next
            length += 1

        old_tail.next = head
        new_tail = head
        for _ in range(length - (k % length) - 1):
            if new_tail.next:
                new_tail = new_tail.next

        new_head = new_tail.next
        new_tail.next = None
        return new_head


if __name__ == "__main__":
    sol = Solution()
    linked_list = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    print(sol.rotateRight(linked_list, 9))
