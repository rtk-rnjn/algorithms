from __future__ import annotations


class Node:
    def __init__(self, data: int, next_node: Node = None) -> None:
        self.data = data
        self.next = next_node

    def __repr__(self) -> str:
        return f"<Node data: {self.data}>"



class LinkedListIterator:
    def __init__(self, head: Node) -> None:
        self.current = head

    def __next__(self) -> Node:
        if self.current is None:
            raise StopIteration
        data = self.current.data
        self.current = self.current.next
        return data


class LinkedList:
    def __init__(self, head: Node = None) -> None:
        self.head = head
        self.size = 0

    def __repr__(self) -> str:
        return f"<LinkedList size: {self.size}>"

    def is_empty(self) -> bool:
        return self.size == 0

    def add(self, data: int) -> None:
        """Adds a new node containing data at the head of the list."""
        new_node = Node(data, self.head)
        self.head = new_node
        self.size += 1

    def search(self, key: int) -> bool:
        """Searches for the first node containing data that matches the key."""
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def remove(self, key: int) -> None:
        """Removes the first occurrence of a node that contains the key."""
        current = self.head
        previous = None
        while current:
            if current.data == key:
                if previous:
                    previous.next = current.next
                else:
                    self.head = current.next
                self.size -= 1
                return
            previous = current
            current = current.next

    def reverse(self) -> None:
        """Reverses the order of the nodes in the list."""
        current = self.head
        previous = None
        while current:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node
        self.head = previous

    def __iter__(self) -> LinkedListIterator:
        return LinkedListIterator(self.head)

    def pop(self, index: int = None) -> int:
        """Removes the node at the given index and returns its data."""
        if index is None:
            index = self.size - 1
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range.")
        current = self.head
        previous = None
        for _ in range(index):
            previous = current
            current = current.next
        if previous:
            previous.next = current.next
        else:
            self.head = current.next
        self.size -= 1
        return current.data
