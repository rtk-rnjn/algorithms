# 2. Add Two Numbers

from __future__ import annotations


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self) -> str:
        return f"{self.val} -> {self.next}"


class Solution:
    def addTwoNumbers(
        self, l1: ListNode | None, l2: ListNode | None
    ) -> ListNode | None:
        # O(n) solution
        dummy = ListNode()
        curr = dummy
        carry = 0

        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            curr.next = ListNode((x + y + carry) % 10)
            curr = curr.next
            carry = (x + y + carry) // 10

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        if carry > 0:
            curr.next = ListNode(carry)

        return dummy.next


if __name__ == "__main__":
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))

    solution = Solution()
    print(solution.addTwoNumbers(l1, l2))
