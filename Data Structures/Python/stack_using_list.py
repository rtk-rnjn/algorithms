from __future__ import annotations


class Stack:
    def __init__(self, size: int) -> None:
        self.__size = size
        self.__stack = [None] * self.__size
        self.__top = -1

    def push(self, item: int) -> None:
        """Pushes an item onto the stack."""
        if self.is_full():
            raise OverflowError("Stack is full.")
        self.__top += 1
        self.__stack[self.__top] = item

    def pop(self) -> int:
        """Pops an item off the stack."""
        if self.is_empty():
            raise IndexError("Stack is empty.")
        item = self.__stack[self.__top]
        self.__top -= 1
        return item

    def peek(self) -> int:
        """Returns the top item without removing it."""
        if self.is_empty():
            raise IndexError("Stack is empty.")
        return self.__stack[self.__top]

    def is_empty(self) -> bool:
        """Returns True if the stack is empty."""
        return self.__top == -1

    def is_full(self) -> bool:
        """Returns True if the stack is full."""
        return self.__top == self.__size - 1

    def __len__(self) -> int:
        """Returns the number of items in the stack."""
        return self.__top + 1

    def __repr__(self) -> str:
        return f"<Stack size={self.__size} top={self.__top}>"
