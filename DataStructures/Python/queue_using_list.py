from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T", bound=int | float)


class Queue(Generic[T]):
    def __init__(self, size: int) -> None:
        self.size = size
        self.__queue: list[T | None] = [None] * size
        self.front = self.rear = -1

    def enqueue(self, item: T) -> None:
        if self.rear == self.size - 1:
            raise IndexError("Queue is full")
        if self.front == -1:
            self.front = 0
        self.rear += 1
        self.__queue[self.rear] = item

    def dequeue(self) -> T | None:
        if self.front == -1:
            raise IndexError("Queue is empty")

        item = self.__queue[self.front]
        self.front += 1
        if self.front > self.rear:
            self.front = self.rear = -1
        return item

    def __repr__(self) -> str:
        return f"Queue({self.__queue})"

