from __future__ import annotations


class DoublyNode:
    def __init__(
        self, data: int, next_node: DoublyNode = None, previous_node: DoublyNode = None
    ) -> None:
        self.data = data
        self.next = next_node
        self.previous = previous_node

    def __repr__(self) -> str:
        return f"<Node data={self.data}>"


class DoublyLinkedListIterator:
    def __init__(self, head: DoublyNode) -> None:
        self.current = head

    def __next__(self) -> DoublyNode:
        if self.current is None:
            raise StopIteration
        data = self.current.data
        self.current = self.current.next
        return data


class DoublyLinkedList:
    def __init__(self, head: DoublyNode = None) -> None:
        self.head = head
        self.size = 0

    def __repr__(self) -> str:
        return f"<LinkedList size: {self.size}>"

    def is_empty(self) -> bool:
        return self.size == 0

    def add(self, data: int) -> None:
        """Adds a new node containing data at the head of the list."""
        new_node = DoublyNode(data, self.head)
        if self.head:
            self.head.previous = new_node
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
                    if current.next:
                        current.next.previous = previous
                else:
                    self.head = current.next
                    if current.next:
                        current.next.previous = None
                self.size -= 1
                return
            previous = current
            current = current.next

    def __iter__(self) -> DoublyLinkedListIterator:
        return DoublyLinkedListIterator(self.head)

    def __len__(self) -> int:
        return self.size

    def __getitem__(self, index: int) -> DoublyNode:
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        current = self.head
        for _ in range(index):
            current = current.next
        return current

    def __setitem__(self, index: int, data: int) -> None:
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        current = self.head
        for _ in range(index):
            current = current.next
        current.data = data

    def insert(self, index: int, data: int) -> None:
        """Inserts a new node containing data at the given
        index position."""

        if index < 0 or index > self.size:
            raise IndexError("Index out of range")

        if index == 0:
            self.add(data)
            return

        current = self.head
        for _ in range(index - 1):
            current = current.next
        new_node = DoublyNode(data, current.next, current)
        if current.next:
            current.next.previous = new_node
        current.next = new_node
        self.size += 1

    def pop(self, index: int = None) -> int:
        """Removes the node at the given index position and returns its data.
        If no index is specified, removes and returns the last item in the list."""
        if index is None:
            index = self.size - 1
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")

        current = self.head
        for _ in range(index):
            current = current.next
        data = current.data
        if current.previous:
            current.previous.next = current.next
        else:
            self.head = current.next
        if current.next:
            current.next.previous = current.previous
        self.size -= 1
        return data
