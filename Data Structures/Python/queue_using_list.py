from __future__ import annotations


class Queue:
    def __init__(self, size: int) -> None:
        self.size = size
        self.queue: list[int | None] = [None] * size
        self.front = self.rear = -1

    def enqueue(self, item: int) -> None:
        if self.rear == self.size - 1:
            print("Queue is full")
        else:
            if self.front == -1:
                self.front = 0
            self.rear += 1
            self.queue[self.rear] = item

    def dequeue(self) -> int | None:
        if self.front == -1:
            print("Queue is empty")
        else:
            item = self.queue[self.front]
            self.front += 1
            if self.front > self.rear:
                self.front = self.rear = -1
            return item

    def __repr__(self) -> str:
        return f"Queue({self.queue})"
