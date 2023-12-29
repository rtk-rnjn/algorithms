from __future__ import annotations


class Node:
    def __init__(self, data: int, next_node: Node = None) -> None:
        self.data = data
        self.next = next_node


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
        return f"<LinkedList size={self.size}>"

    def __iter__(self) -> LinkedListIterator:
        return LinkedListIterator(self.head)

    def is_empty(self) -> bool:
        return self.size == 0

    def add(self, data: int) -> None:
        """Adds a new node containing data at the head of the list."""
        new_node = Node(data, self.head)
        self.head = new_node
        self.size += 1

    def pop(self, index: int) -> None:
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


class Stack:
    def __init__(self, stack_size: int) -> None:
        self.__size = stack_size
        self.__stack = LinkedList()

    def push(self, key: int) -> None:
        if self.is_full():
            raise OverflowError("Stack is full.")
        self.__stack.add(key)

    def pop(self) -> int:
        if self.is_empty():
            raise IndexError("Stack is empty.")
        return self.__stack.pop(0)

    def is_empty(self) -> bool:
        return self.__stack.is_empty()

    def is_full(self) -> bool:
        return self.__stack.size == self.__size

    def __repr__(self) -> str:
        return f"<Stack size={self.__size}>"
